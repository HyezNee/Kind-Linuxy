#include "header.h"

int _work(char** info) {        //execl,wait,exit
	int stat = 0;

	if (!strcmp(info[0], "경로이동")) {
		int len = (int)(strlen(info[2])) + 3;
		char* directory = malloc(sizeof(char) * len);   // /경로 길이 만큼 메모리 할당
		strcpy(directory, "./");
		strcat(directory, info[2]);     // 문자열 붙이기
		//printf("%s", directory);
		if (chdir(directory) == -1) {
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
		}
		free(directory);
		char cwd[100];
		getcwd(cwd, sizeof(cwd));
		printf("%s", cwd);
	}
	else if (!strcmp(info[0], "목록")) {
		info[0] = "ls";
		pid_t childpid;
		printf("뭐징 %s %s", info[0], info[1]);
		childpid = fork();
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/ls", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			return 1;
		}
	}
	else if (!strcmp(info[0], "설명")) {
		if (info[2] != NULL) {	//kindLinuxy 내의 명령어들 설명->파일 참조

		}
		else {// 그냥 man 입력
			info[0] = "man";
			pid_t childpid;
			childpid = fork();
			info[1] = info[2];
			info[2] = "\0";	//어차피 다 null 이므로 상관없을듯
			if (childpid == -1) {
				perror("명령 실행 실패 : 포크 실패(코드1)");
				return 1;
			}
			if (childpid == 0) {    // Child code
				execv("/bin/ls", info);
				perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
				return 1;
			}
			else if (childpid != wait(NULL)) {      // parent code
				perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
				return 1;
			}
		}
	}
	else if (!strcmp(info[0], "폴더생성")) {
		info[0] = "mkdir";
		pid_t childpid;
		childpid = fork();
		info[1] = info[2];
		info[2] = "\0";
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/ls", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			return 1;
		}
	}
	else if (!strcmp(info[0], "폴더삭제")) {
		info[0] = "rmdir";
		pid_t childpid;
		childpid = fork();
		info[1] = info[2];
		info[2] = "\0";
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/ls", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			return 1;
		}
	}
	else if (!strcmp(info[0], "명령어")) {

	}
	return stat;    // 정상적 종료 (stat == 0)
}

void _fileopen() {//open,read,lseek

}

/*
int main(void) {	// 테스트용 메인 함수
	char* info[3];

	//info[0] = "목록";
	//info[1] = "-l";
	//info[2] = (char*)0;

	info[0] = "경로이동";
	info[1] = "NewDir";
	info[2] = (char*)0;
	_work(info);
	return 0;
}
*/