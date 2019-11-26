#include "header.h"
#pragma warning(disable:4996) //scanf 보안 경고 제거


//명령어 1회 입력받아 처리하고 폼 형태로 return(char **형)
void _command() {//readline으로 바꾸기 나중에
	//char **info; //명령어 정리된 배열
	char commandInput[10];
	char options[10];
	char arguments[150];
	char commandstr[200]="";
	char partition[2] = "#";

	printf("명령어 입력 >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "설명")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
		strcat(commandstr, partition);
		printf("설명을 출력할 명령어를 입력하세요(없으면 x입력)\n인자 입력 >>");
		scanf("%130s", arguments);
		strcat(commandstr, arguments);
		printf("%s", commandstr);
	}
	else if (!strcmp(commandInput, "경로이동")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "목록")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "폴더생성")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "폴더삭제")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "명령어")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else {
		printf("존재하지 않는 명령어입니다. 다시 입력해주세요.\n");
	}

	//return info;
}

void _parse(char *str, char *buf) {


}