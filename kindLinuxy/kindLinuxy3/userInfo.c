#include "header.h"

void _printInfo() {//execl,getuid	
	char buf[256] = "";
	printf("=====================================================\n");
	printf("<친절한 리눅씨>\n");
	printf("현재 경로 : ");
	char cwd[100];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	cuserid(buf);
	printf("사용자 : %s\n",buf);
	printf("-----------------------------------------------------\n");


}
