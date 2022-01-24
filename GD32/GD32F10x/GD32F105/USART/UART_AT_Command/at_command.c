#include "at_command.h"

char* at_command(const char* command)
{
	if (strcmp(command,"AT") == 0){
		return "OK";
	}
	else if (strcmp(command,"AT+File") == 0){
		// 在PC下指令將<檔案名稱>.txt 存入 SD Card
		// GD32F105約用1秒時間配置記憶體空間
		// GD32F105約用1秒時間配置記憶體空間
		return "File storage task...";
	}
	else if (strcmp(command,"AT+END") == 0){
		// PC端完成傳送檔案至 SD Card 時發送 AT+END 指令
		return "END transmit task...";
	}
	else if (strcmp(command,"AT+READ") == 0){
		// 讀取 SD Card 檔案
		return "READ file task...";
	}
	else if (strcmp(command,"AT+Delete") == 0){
		// 刪除檔案
		return "Delete file task...";
	}
	else if (strcmp(command,"AT+SDSize") == 0){
		// 顯示記憶卡空間或儲存內容
		return "Show SDSize ...";
	}
	else{
		return "<Not AT Command>";
	}
}
