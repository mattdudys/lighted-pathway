#include <stdio.h>
#include "../master/command.h"

void printArgs(char** args, int argc) {
	for (int i = 0; i < argc; i++) {
		printf("`%s'\n", args[i]);
	}
}

void printImageCmd(add_image_cmd* cmd) {
	printf("cmd_id: %c\n", cmd->cmd_id);
	printf("id: %i\n", cmd->id);
	printf("rStart: %i\n", cmd->rStart);
	printf("rStep: %i\n", cmd->rStep);
	printf("rStop: %i\n", cmd->rStop);
	printf("cStart: %i\n", cmd->cStart);
	printf("cStep: %i\n", cmd->cStep);
	printf("cStop: %i\n", cmd->cStop);
	printf("loop: %c\n", cmd->loop ? '1' : '0');
	printf("imageID: %i\n", cmd->imageID);
}

void printMessageCmd(add_message_cmd* cmd) {
	printf("cmd_id: %c\n", cmd->cmd_id);
	printf("id: %i\n", cmd->id);
	printf("rStart: %i\n", cmd->rStart);
	printf("rStep: %i\n", cmd->rStep);
	printf("rStop: %i\n", cmd->rStop);
	printf("cStart: %i\n", cmd->cStart);
	printf("cStep: %i\n", cmd->cStep);
	printf("cStop: %i\n", cmd->cStop);
	printf("loop: %c\n", cmd->loop ? '1' : '0');
	printf("imageID: `%s'\n", cmd->message);
}

int main(void) {
	char buffer[200];
	char *args[10];

	// Verify split works
	strcpy(buffer, "a|b|c|1|2|3");
	split(buffer, strlen(buffer), args, 6);
	printArgs(args, 6);

	// Verify build_image works
	add_image_cmd a;
	strcpy(buffer, "i|1|2|3|4|5|6|7|1|23");
	build_image(buffer, strlen(buffer), &a);
	printImageCmd(&a);

	// Verify build_message works
	add_message_cmd m;
	strcpy(buffer, "m|1|2|3|4|5|6|7|1|This is a message");
	build_message(buffer, strlen(buffer), &m);
	printMessageCmd(&m);

	return 0;
}
