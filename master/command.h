#include <stdbool.h>
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
	uint8_t imageID;
	int32_t rStart;
	int32_t rStep;
	int32_t rStop;
	int32_t cStart;
	int32_t cStep;
	int32_t cStop;
	bool loop;
} add_image_cmd;

#define DELETE_CMD 'd'
typedef struct {
	char cmd_id;
	uint8_t id;
} delete_cmd;

#define PONG_CMD 'p'
typedef struct {
	char cmd_id;
	uint8_t paddle1_y;
	uint8_t paddle2_y;
	uint8_t ball_x;
	uint8_t ball_y;
} pong_cmd;
