#include "header.h"

void _printInfo() {//execl,getuid	박소연 작성
	printf("=====================================================\n");
	printf("<친절한 리눅씨>\n");
	printf("현재 경로 : ");
	char cwd[100];
	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
	printf("사용자 : ");
	printf("%s",getlogin());
	printf("-----------------------------------------------------\n");
	

}