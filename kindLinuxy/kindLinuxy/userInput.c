#include "header.h"
#pragma warning(disable:4996) //scanf 보안 경고 제거


//명령어 1회 입력받아 처리하고 폼 형태로 return(char **형)
void _command() {//readline
	//char **info; //명령어 정리된 배열
	char commandInput[10];

	printf("명령어 입력 >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "설명")) {
		printf("설명인식\n");
	}
	else if (!strcmp(commandInput, "경로이동")) {
		printf("경로이동인식\n");
	}
	else if (!strcmp(commandInput, "목록")) {
		printf("목록인식\n");
	}
	else if (!strcmp(commandInput, "폴더생성")) {
		printf("폴더생성인식\n");
	}
	else if (!strcmp(commandInput, "폴더삭제")) {
		printf("폴더삭제인식\n");
	}
	else if (!strcmp(commandInput, "명령어")) {
		printf("명령어인식\n");
	}
	else {
		printf("존재하지 않는 명령어입니다. 다시 입력해주세요.\n");
	}

	//return info;
}

void _parse(char *str, char *buf) {


}