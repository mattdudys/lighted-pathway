
#include "Pong.h"
#include "rprintf.h"
#include <stdlib.h> 



void printscore(AppState* App)
{
	rprintf("player1: %d   player2: %d \n",App->p1score,App->p2score);
}

void moveActor(AppState* App, actor_t* a,int mode)
{
	a->posx+=a->vx;
	a->posy+=a->vy;
	int dir = 0;
	
	if(random() >RANDOM_MAX/2)dir = -1;
	else dir = 1;

	switch(mode)
	{
		case bounce:
			if(a->posx>WIDTH-1)  {  a->vx = -abs(a->vx) ; a->posx=WIDTH-1; }
			if(a->posx<0)      {  a->vx =  abs(a->vx) ; a->posx=0;}
			if(a->posy>HEIGHT-1) {  a->vy = -abs(a->vy) ; a->posy=HEIGHT-1;}
			if(a->posy<0)      {  a->vy =  abs(a->vy) ;  a->posy=0; }
			break;

		case puck:
			if(a->posx>WIDTH-1) {a->posx = WIDTH/2;a->posy = HEIGHT/2; App->puck->vx=-1; App->puck->vy = dir;App->p1score++;printscore(App);} 
			if(a->posx<0)      { a->posx = WIDTH/2;a->posy = HEIGHT/2; App->puck->vx=1; App->puck->vy  = dir; App->p2score++;printscore(App);}
			if(a->posy>HEIGHT-1) {  a->vy = -abs(a->vy) ; a->posy=HEIGHT-1;}
			if(a->posy<0) {  a->vy =  abs(a->vy) ;  a->posy=0; }
			break;

		case cycle:
			if(a->posx>WIDTH-1)a->posx = 0;
			if(a->posx<0) a->posx = WIDTH;
			if(a->posy>HEIGHT-1) a->posy = 0;
			if(a->posy<0) a->posy = HEIGHT;
			break;

	}

}


void updateScreen(AppState* App)
{

if(App->puck->posx == App->player1->posx)
{
	if( 
		App->puck->posy  < App->player1->posy + App->player1->size/2 +1
		&&
		App->puck->posy  > App->player1->posy - App->player1->size/2-1
	  )
	{
		App->puck->vx = abs(App->puck->vx);
		App->puck->vy += App->player1->vy;
	}
}
if(App->puck->posx == App->player2->posx)
{
	if( 
		App->puck->posy  < App->player2->posy + App->player2->size/2+1 
		&&
		App->puck->posy  > App->player2->posy - App->player2->size/2-1
	  )
	{
		App->puck->vx = - abs(App->puck->vx);
		App->puck->vy+=App->player2->vy;
	}
	
}
//rprintf("pong: p1y %d p2y %d puckx %d pucky %d  \n",App->player1->posy,App->player2->posy,App->puck->posx,App->puck->posy);
moveActor(App,App->player1,cycle);
moveActor(App,App->player2,cycle);
moveActor(App,App->puck,puck);		
}
