#include "header.h"

// static volatile sig_atomic_t doneflag = 0;

void _printExitMsg() {
	printf("\n==============================\n");
	printf("친절한 리눅씨를 종료합니다.\n");
	printf("==============================\n");
}

void handler(int sig) {
	// doneflag = 1;
	exit(0);
}

void _manage() {	//exit 말고 atexit 써야할듯?
	char* info[4];	// 일단 넉넉하게 이렇게...
	char* buf[5];
	for (int i = 0; i < 5; i++) {
		buf[i] = (char*)malloc(sizeof(char) * 1000);
	}
	_fileopen(buf);
	atexit(_printExitMsg);
	if (signal(SIGINT, handler) == SIG_ERR){
		perror("에러 : 시그널 처리 오류");
	}

	while(1){
		_printInfo();
		_command(info);
		_work(info,buf);
	}
	for (int i = 0; i < 5; i++) {
		free(buf[i]);
	}
	free(buf);
}


