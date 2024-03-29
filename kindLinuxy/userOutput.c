#include "header.h"

int readline(int fd, char* buf, int nbyte){
	int numread = 0;
	int returnval;

	while(numread < nbyte - 1) {
		returnval = read(fd, buf + numread, 1);
		

		numread++;

		if(buf[numread - 1] == '\n'){
			buf[numread] = '\0';
			return numread;
		}
	}
}

void _fileopen(char **buf) {	// 뒤에 놔두면 인식이 안되는 문제가 생길 수도 있어서 앞에 놔둠ㅎㅎ
	int fd;
	char buffer[200];
	 ssize_t bytesread;
	 for (int i = 0; i < 5; i++) {
		 strcpy(buf[i], "");
	}

     if((fd=open("commanddescription.txt",O_RDONLY))!=-1){
        lseek(fd,(off_t)0,SEEK_SET);
		for (int i = 0; i < 3; i++) {
			bytesread = readline(fd, buffer, sizeof(buffer));
			strcat(buf[0], buffer);
		}
		for (int i = 0; i < 4; i++) {
			bytesread = readline(fd, buffer, sizeof(buffer));
			strcat(buf[1], buffer);
		}
		for (int i = 0; i < 3; i++) {
			bytesread = readline(fd, buffer, sizeof(buffer));
			strcat(buf[2], buffer);
		}
		for (int i = 0; i < 5; i++) {
			bytesread = readline(fd, buffer, sizeof(buffer));
			strcat(buf[3], buffer);
		}
		for (int i = 0; i < 4; i++) {
			bytesread = readline(fd, buffer, sizeof(buffer));
			strcat(buf[4], buffer);
		}
     }
	 close(fd);
}



int _work(char** info,char** buf) {        //execl,wait,exit
	int stat = 0;
	

	if (!strcmp(info[0], "경로이동")) {
		int len = (int)(strlen(info[2])) + 3;
		char* directory = malloc(sizeof(char) * len);   // /경로 길이 만큼 메모리 할당
		strcpy(directory, "./");
		strcat(directory, info[2]);     // 문자열 붙이기
		// printf("%s", directory);
		if (chdir(directory) == -1) {
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
		}
		free(directory);
		free(info[2]);
		printf("\n");
	}
	else if (!strcmp(info[0], "목록")) {
		// printf("%s %s", info[0], info[1]);
		info[0] = "ls";
		pid_t childpid;
		// printf("뭐징 %s %s", info[0], info[1]);
		childpid = fork();
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			free(info[1]);
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/ls", info);
			free(info[1]);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			free(info[1]);
			return 1;
		}
	}
	else if (!strcmp(info[0], "설명")) {
		if (info[2] != NULL) {	//kindLinuxy 내의 명령어들 설명->파일 참조
			//_fileopen 가서 info[2] 내용에 따라 위에 define 에 해당하는 해당하는 줄부터 그 다음 define 해당하는 줄 전까지 파일 읽으면 됨.
			if (!strcmp(info[2], "경로이동"))
				printf("%s", buf[0]);
			else if (!strcmp(info[2], "목록"))
				printf("%s", buf[1]);
			else if (!strcmp(info[2], "폴더생성"))
				printf("%s", buf[2]);
			else if (!strcmp(info[2], "폴더삭제"))
				printf("%s", buf[3]);
			else if (!strcmp(info[2], "설명"))
				printf("%s", buf[4]);
			else {	// 친절한 리눅씨의 전체 설명 출력
				for (int i = 0; i < 5; i++) {
				printf("%s", buf[i]);
				}
			}
		}
	}
	else if (!strcmp(info[0], "폴더생성")) {
		info[0] = "mkdir";
		pid_t childpid;
		info[1] = info[2];
		info[2] = (char*)0;
		childpid = fork();
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			free(info[1]);
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/mkdir", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			free(info[1]);
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			free(info[1]);
			return 1;
		}
	}
	else if (!strcmp(info[0], "폴더삭제")) {
		info[0] = "rmdir";
		pid_t childpid;
		info[1] = info[2];
		info[2] = (char*)0;
		childpid = fork();
		if (childpid == -1) {
			perror("명령 실행 실패 : 포크 실패(코드1)");
			free(info[1]);
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/rmdir", info);
			perror("명령 실행 실패 : 명령 불러오기 실패(코드2)");
			free(info[1]);
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("명령 실행 실패 : 부모 기다리기 실패(코드3)");
			free(info[1]);
			return 1;
		}
	}
	return stat;    // 정상적 종료 (stat == 0)
}
