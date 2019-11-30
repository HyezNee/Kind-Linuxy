#include <signal.h>
#include <stdlib.h>
#include "header.h"

static volatile sig_atomic_t doneflag = 0;

static void handler(int sig) {
	doneflag = 1;
}

void _printExitMsg() {
	printf("친절한 리눅씨를 종료합니다.");
}

void _manage() {	//exit 말고 atexit 써야할듯?
	char* info[4];	// 일단 넉넉하게 이렇게...
	atexit(_printExitMsg);

	while(!doneflag){
		_printInfo();
		_command(info);
		_work(info);
	}
}


int main(void){
	// printf("이것은 한글이다.")
	_manage();
	return 0;
}
