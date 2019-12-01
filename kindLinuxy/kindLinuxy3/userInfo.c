#include "header.h"

void _printInfo() {//execl,getuid
	printf("=====================================================\n");
	printf("<친절한 리눅씨>\n");
	printf("현재 경로 : ");
	char cwd[100];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	char  *name = getlogin();
	printf("사용자 : %s\n",name);
	printf("-----------------------------------------------------\n");


}
