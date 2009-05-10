#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 140

#define FRAME_CMD 'f'
typedef struct {
	char cmd_id;
	int32_t frame;	
} frame_cmd;

#define ADD_MESSAGE_CMD 'm'
typedef struct {
	char cmd_id;
	uint8_t id;
	int32_t rStart;
	int32_t rStep;
	int32_t rStop;
	int32_t cStart;
	int32_t cStep;
	int32_t cStop;
	bool loop;
	char message[MESSAGE_LENGTH];
} add_message_cmd;

#define ADD_IMAGE_CMD 'i'
typedef struct {
	char cmd_id;
	uint8_t id;
	int32_t rStart;
	int32_t rStep;
	int32_t rStop;
	int32_t cStart;
	int32_t cStep;
	int32_t cStop;
	bool loop;
	uint8_t imageID;
} add_image_cmd;

#define DISABLE_CMD 'd'
#define ENABLE_CMD 'e'
#define DELETE_CMD 'x'
typedef struct {
	char cmd_id;
	uint8_t id;
} id_cmd;

#define PONG_CMD 'p'
typedef struct {
	char cmd_id;
	uint8_t paddle1_y;
	uint8_t paddle2_y;
	uint8_t ball_x;
	uint8_t ball_y;
} pong_cmd;

#define TEST_CMD 't'

int split(char *bufToParse, unsigned int bufLength, char** argv, int maxArgs) {
	// Don't try to parse commands that are too short.
	if (bufLength <= 2)
		return 0;

	// argv contains pointers to the initial character and the characters following the delimiter
	char delimiter = bufToParse[1];
	argv[0] = bufToParse;
	int argc = 1;
	int i = 1;
	while (argc < maxArgs && i < bufLength) {
		if (bufToParse[i] == delimiter) {
			bufToParse[i] = '\0';
			argv[argc++] = bufToParse + i + 1;
		}
		i++;
	}
	
	return argc;
}

add_image_cmd* build_image(char *bufToParse, unsigned int bufLength, add_image_cmd *ima) {
	char *args[10];
	split(bufToParse, bufLength, args, 10);

	ima->cmd_id = *args[0];
	ima->id = atoi(args[1]);
	ima->rStart = atoi(args[2]);
	ima->rStep = atoi(args[3]);
	ima->rStop = atoi(args[4]);
	ima->cStart = atoi(args[5]);
	ima->cStep = atoi(args[6]);
	ima->cStop = atoi(args[7]);
	ima->loop = atoi(args[8]);
	ima->imageID = atoi(args[9]);

	return ima;
}

add_message_cmd* build_message(char *bufToParse,unsigned int bufLength,add_message_cmd *a) {
	char *args[10];
	split(bufToParse, bufLength, args, 10);

	a->cmd_id = *args[0];
	a->id = atoi(args[1]);
	a->rStart= atoi(args[2]);
	a->rStep = atoi(args[3]);
	a->rStop = atoi(args[4]);
	a->cStart = atoi(args[5]);
	a->cStep = atoi(args[6]);
	a->cStop = atoi(args[7]);
	a->loop = atoi(args[8]);
	int len = strlen(args[9]);
	strncpy(a->message, args[9], len);
	return a;
}
