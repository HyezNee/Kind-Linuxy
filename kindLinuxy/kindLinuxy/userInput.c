#include "header.h"
#pragma warning(disable:4996) //scanf 보안 경고 제거


//명령어 1회 입력받아 처리하고 폼 형태로 return(char **형)
void _command(char** info) {//readline으로 바꾸기 나중에
	//char **info; //명령어 정리된 배열 --> 인자로 받으니 없어도 될 듯
	char commandInput[10];
	char options[11];
	char arguments[150];
	
	// main의 info 초기화 작업
	info = (char**)malloc(sizeof(char*) * 4);
	info[3] = NULL;

	printf("명령어 입력 >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "설명")) {
		info[0] = commandInput;
		info[1] = "\0";
		printf("설명을 출력할 명령어를 입력하세요(없으면 x입력)\n인자 입력 >>");
		scanf("%130s", arguments);
		info[2] = arguments;
		
	}
	else if (!strcmp(commandInput, "경로이동")) {
		info[0] = commandInput;
		info[1] = "\0";
		printf("이동할 경로명 입력 >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "목록")) {
		info[0] = commandInput;
		printf("원하는 옵션을 띄어쓰기 없이(0.옵션없음|1.길게 출력|2.수정시간순|3.크기순|4.모든파일출력|5.역순)");
		info[2] = "\0";
	}
	else if (!strcmp(commandInput, "폴더생성")) {
		info[0] = commandInput;
		printf("생성 폴더명 입력 >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "폴더삭제")) {
		info[0] = commandInput;
		printf("삭제할 입력 >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "명령어")) {
		info[0] = commandInput;
		info[1] = "\0";
		info[2] = "\0";
	}
	else {
		printf("존재하지 않는 명령어입니다. 다시 입력해주세요.\n");
	}

}

