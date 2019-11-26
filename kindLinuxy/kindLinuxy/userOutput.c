#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int _work(char **info) {//execl,wait,exit
	int stat = 0;

	if (!strcmp(info[0], "경로이동")) {

	}
	else if (!strcmp(info[0], "목록")) {
		info[0] = "ls";
		pid_t childpid;
		childpid = fork();

		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			return 1;
		}

		if (childpid == 0) {	// Child code
			execv("/bin/ls", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {	// parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			return 1;
		}
	}
	return stat;	// 정상적 종료 (stat == 0)
}

void _fileopen() {//open,read,lseek

}

/*int main(void) {	// 테스트용 메인 함수
	char* info[2];
	info[0] = "목록";
	info[1] = "-l";
	info[2] = (char*)0;
	_work(info);
}*/