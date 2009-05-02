//MASTER

#define F_CPU 4000000UL

#include "uart.h"
#include "rprintf.h"
#include <string.h>
#include "i2c.h"
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "command.h"


#define MAXBUF 24
#define RETURN  0x0D
#define LOCAL_ADDR 0x48
#define TARGET_ADDR 0x00
//0x45



void i2cTest(void);
void i2cSlaveReceiveService(u08 receiveDataLength, u08* receiveData);
u08 i2cSlaveTransmitService(u08 transmitDataLengthMax, u08* transmitData);
void i2cMasterSendDiag(u08 deviceAddr, u08 length, u08* data);
void showByte(u08 byte);


// local data buffer
unsigned char localBufferLength = 256;
unsigned char localBuffer[256];


int nB = 0;
int i=0;
char uBuf[MAXBUF];




int main()
{
	 uartInit();					// initialize UART (serial port)
	 uartSetBaudRate(9600);		// set UART speed to 9600 baud
	 rprintfInit(uartSendByte);  // configure rprintf to use UART for output

	 DDRC = 0xff;
	 PORTC = 0xff;


//	 i2cInit();
//	 i2cSetBitrate(400);
//	 i2cSetLocalDeviceAddr(LOCAL_ADDR, TRUE);



	 int ans = 0;
	 	i2cTest();
/*	 while(1){
		//	 rprintf("Hello World\r\n");	// send "hello world" message via serial port
		char mb;
		 if(uartReceiveByte( &mb ))
		 {
			rprintf("%c",mb);
			uBuf[nB] = mb;

			if(mb== RETURN || nB>=MAXBUF)
			{
			//	rprintf("\n\r");
			//	for(i=0;i<=nB;i++)
			//		rprintf("%c",uBuf[i]);
				
				rprintf("starting i2c\n\r");
				i2cTest();

				rprintf("\n\r");
				nB = 0;
				if(strncmp(uBuf,"hello",5)==0)	rprintf("\n\r Hi Partner!!\n\r");
				if(strncmp(uBuf,"lights",4)==0)	
				{
				rprintf("\n\r Lights\n\r");
				PORTC = 0x00;
				}
				else
				PORTC = 0xff;
			}
				else nB++;	
			
		 }


		
	}*/
}

int32_t frame = 0;

void i2cTest()
{
	u08 c=0;
	showByte(0x55);

	// initialize i2c function library
	i2cInit();

	i2cSetBitrate(100);
	// set local device address and allow response to general call
	i2cSetLocalDeviceAddr(LOCAL_ADDR, TRUE);
	// set the Slave Receive Handler function
	// (this function will run whenever a master somewhere else on the bus
	//  writes data to us as a slave)
	i2cSetSlaveReceiveHandler( i2cSlaveReceiveService );
	// set the Slave Transmit Handler function
	// (this function will run whenever a master somewhere else on the bus
	//  attempts to read data from us as a slave)
	i2cSetSlaveTransmitHandler( i2cSlaveTransmitService );

	_delay_ms(500);
	
	showByte(0xAA);

	while(1)
	{
		rprintf("Command>");
		while(!c) uartReceiveByte(&c);
		
		switch(c)
		{
		case 's':
			rprintf("Send: ");
			// get string from terminal
			localBufferLength = 0;
			c = 0;
			while((c != 0x0D) && (localBufferLength < 0x20))
			{
				while(!uartReceiveByte(&c));
				if (c == '\b')
					localBufferLength-=2;
				else
					localBuffer[localBufferLength++] = c;
				uartSendByte(c);
			}
			// switch CR to NULL to terminate string
			localBuffer[localBufferLength-1] = 0;
			// send string over I2C
			rprintfCRLF();	rprintfCRLF();
			rprintf("sending");
			rprintfStr(localBuffer);
			rprintf("\n\r");
			i2cMasterSend(TARGET_ADDR, localBufferLength, localBuffer);
			//i2cMasterSendNI(TARGET_ADDR, localBufferLength, localBuffer);
			rprintfCRLF();
			break;
		case 'r':
			rprintf("Receive: ");
			// receive string over I2C
			i2cMasterReceive(TARGET_ADDR, 0x10, localBuffer);
			//i2cMasterReceiveNI(TARGET_ADDR, 0x10, localBuffer);
			// format buffer
			localBuffer[0x10] = 0;
			rprintfStr(localBuffer);
			rprintfCRLF();
			break;
		case 'f':
			frame = 0;
			rprintf("auto scroll");
			rprintfCRLF();
			while(1)
			{

				if(uartReceiveByte(&c))
				{
				rprintf("recieve");rprintfCRLF();
					if(c == 'q')
					{
						rprintf("stop scrolling");
						rprintfCRLF();
						break;
					}
				}

				_delay_ms(100);
				frame++;
				frame_cmd f;
				f.cmd_id = FRAME_CMD;
				f.frame = frame;
				*((frame_cmd*) localBuffer) = f;
				//localBuffer[0] = 'f';
				//*((int32_t*)(localBuffer + 1))=frame;
				
				rprintf("about to send  ");
				//i2cMasterSend(TARGET_ADDR, 5, localBuffer);
				i2cMasterSendNI(TARGET_ADDR, sizeof(f), localBuffer);
				rprintf(" frame %d",frame);
				rprintfCRLF();
			//	break;
			}
			rprintf("done");
			rprintfCRLF();
			break;
		default:
			rprintf("Unknown Command!");
			break;
		}
		c = 0;
		rprintfCRLF();
	}

}



// slave operations
void i2cSlaveReceiveService(u08 receiveDataLength, u08* receiveData)
{
	u08 i;

	// this function will run when a master somewhere else on the bus
	// addresses us and wishes to write data to us

	showByte(*receiveData);
	cbi(PORTB, PB6);

	// copy the received data to a local buffer
	for(i=0; i<receiveDataLength; i++)
	{
		localBuffer[i] = *receiveData++;
	}
	localBufferLength = receiveDataLength;
}

u08 i2cSlaveTransmitService(u08 transmitDataLengthMax, u08* transmitData)
{
	u08 i;

	// this function will run when a master somewhere else on the bus
	// addresses us and wishes to read data from us

	showByte(*transmitData);
	cbi(PORTB, PB7);

	// copy the local buffer to the transmit buffer
	for(i=0; i<localBufferLength; i++)
	{
		*transmitData++ = localBuffer[i];
	}

	localBuffer[0]++;

	return localBufferLength;
}

void i2cMasterSendDiag(u08 deviceAddr, u08 length, u08* data)
{
	// this function is equivalent to the i2cMasterSendNI() in the I2C library
	// except it will print information about transmission progress to the terminal

	// disable TWI interrupt
	cbi(TWCR, TWIE);

	// send start condition
	i2cSendStart();
	i2cWaitForComplete();
	rprintf("STA-");

	// send device address with write
	i2cSendByte( deviceAddr&0xFE );
	i2cWaitForComplete();
	rprintf("SLA+W-");
	
	// send data
	while(length)
	{
		i2cSendByte( *data++ );
		i2cWaitForComplete();
		rprintf("DATA-");
		length--;
	}
	
	// transmit stop condition
	// leave with TWEA on for slave receiving
	i2cSendStop();
	while( !(inb(TWCR) & BV(TWSTO)) );
	rprintf("STO");

	// enable TWI interrupt
	sbi(TWCR, TWIE);
}
void showByte(u08 byte)
{
	// set PORTB to output
	outb(DDRB, 0xFF);
	// output byte to LEDs
	outb(PORTB, ~byte);
}
