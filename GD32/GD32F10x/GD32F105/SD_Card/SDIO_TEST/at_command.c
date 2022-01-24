#include "at_command.h"

char* at_command(const char* command)
{
	if (strcmp(command,"AT") == 0){
		return "OK";
	}
	else{
		return "<Not AT Command>";
	}
}
