#include "header.h"
#pragma warning(disable:4996) //scanf 보안 경고 제거


//명령어 1회 입력받아 처리하고 폼 형태로 return(char **형)
void _command(char** info) {//readline으로 바꾸기 나중에
	//char **info; //명령어 정리된 배열 --> 인자로 받으니 없어도 될 듯
	char commandInput[10];
	char options[10];
	char arguments[150];
	char commandstr[200]="";
	char partition[2] = "#";
	
	// main의 info 초기화 작업
	int i;
	for (i = 0; i < 10; i++)
		info[i] = NULL;

	printf("명령어 입력 >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "설명")) {
		strcat(commandstr, commandInput);
		// 이렇게 하는 건 어때?
		// 기존 cmd에서는 명령어를 한 줄로 다 받아서 파싱이 필요했지만, 지금 생각해보니 우리가 만드는 shell은
		// 명령어와 옵션을 따로따로 받아서 파싱이 필요할까 싶어..!
		// strcpy(info[0], commandInput);
		strcat(commandstr, partition);
		strcat(commandstr, partition);
		printf("설명을 출력할 명령어를 입력하세요(없으면 x입력)\n인자 입력 >>");
		scanf("%130s", arguments);
		strcat(commandstr, arguments);
		// strcpy(info[1], arguments);
		// info[2] = (char*)0;
		printf("%s ", commandstr);
	}
	else if (!strcmp(commandInput, "경로이동")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "목록")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "폴더생성")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "폴더삭제")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "명령어")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else {
		printf("존재하지 않는 명령어입니다. 다시 입력해주세요.\n");
	}

}

