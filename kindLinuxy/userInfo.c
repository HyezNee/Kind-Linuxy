#include "header.h"

void _printInfo() {//execl,getuid
	char cwd[100];
	// char *name;
	uid_t userId;
	struct passwd *userPW;

	getcwd(cwd, sizeof(cwd));
	printf("=====================================================\n");
	printf("<친절한 리눅씨>\n");
	printf("현재 경로 : ");

	printf("%s\n", cwd);

	userId = getuid();
	userPW = getpwuid(userId);
	// name = getlogin();
	printf("사용자 : %s\n", userPW->pw_name);
	printf("-----------------------------------------------------\n");
}
