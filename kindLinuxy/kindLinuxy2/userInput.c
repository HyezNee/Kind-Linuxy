#include "header.h"
#pragma warning(disable:4996) //scanf 보안 경고 제거


//명령어 1회 입력받아 처리하고 폼 형태로 return(char **형)
void _command(char** info) {//readline으로 바꾸기 나중에
	//char **info; //명령어 정리된 배열 --> 인자로 받으니 없어도 될 듯
	char commandInput[10];
	char options[12];
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
		scanf("%11s", options);
		if (!strcmp(options, "0")) {
			options[1] = "\0";
		}
		int optionsize = sizeof(options) / sizeof(char);
		//엄밀하게 예외처리는 안했음 사용자가 형식에 맞게 입력할거라는 가정하에 진행.
		if (optionsize % 2 != 1) {
			printf("옵션을 형식에 맞춰 입력해주세요");
			info[0] = "-1";
		}
		else {
			info[1] = "#";	//option의 시작은 #으로...
			//일단 우리는 입력한거 파싱만 하고 옵션 충돌오류는 os 터미널에게 명령 줘서 오류났을때 그대로 사용자에게 출력하는걸로 하는게 어떨까함
			for (int i = 0; i < (optionsize+1)/2; i++) {
				if (options[2 * i] == '1') {
					strcat(info[1], "l");
				}
				else if (options[2 * i] == '2') {
					strcat(info[1], "t");
				}
				else if (options[2 * i] == '3') {
					strcat(info[1], "S");
				}
				else if (options[2 * i] == '4') {
					strcat(info[1], "a");
				}
				else if (options[2 * i] == '5') {
					strcat(info[1], "r");
				}
				else {
					printf("옵션을 형식에 맞춰 입력해주세요.");
					info[0] = "-1";
				}
			}
		}

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
		info[0] = "-1";
		//이상하면 -1반환
	}

}
