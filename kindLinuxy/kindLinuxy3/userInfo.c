#include "header.h"

void _printInfo() {//execl,getuid
	char cwd[100];
	getcwd(cwd, sizeof(cwd));
	pid_t childpid;
	childpid = fork();
	if (childpid == -1) {
		perror("명령 실행 실패 : 포크 실패(코드1)");
		return 1;
	}
	if (childpid == 0) {    // Child code
		execl(cwd, "clear",NULL);
		perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
		return 1;
	}
	else if (childpid != wait(NULL)) {      // parent code
		perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
		free(info[1]);
		return 1;
	}
	printf("=====================================================\n");
	printf("<친절한 리눅씨>\n");
	printf("현재 경로 : ");

	printf("%s\n", cwd);
	char  *name = getlogin();
	printf("사용자 : %s\n",name);
	printf("-----------------------------------------------------\n");


}
