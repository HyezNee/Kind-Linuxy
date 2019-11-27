#include <signal.h>
#include <stdlib.h>
#include "header.h"

static volatile sig_atomic_t doneflag = 0;

static void handler(int sig) {
	doneflag = 1;
}

void _printExitMsg() {
	printf("ģ���� �������� �����մϴ�.");
}

void _manage() {	//exit ���� atexit ����ҵ�?
	char** info[10];	// �ϴ� �˳��ϰ� �̷���...
	atexit(_printExitMsg);

	while(!doneflag){
		_printInfo();
		_command(info);
		work(info);
	}
}