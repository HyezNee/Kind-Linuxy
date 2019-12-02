#include <stdio.h>
#include <unistd.h>//read함수



else if (!strcmp(info[0], "설명")) {
if (info[2] != NULL) {
	_fileopen();
}
}

else if (!strcmp(info[0], "명령어")) {
_fileopen();
}


char buf[100];
ssize_t bytesread;

void _fileopen() {
	int myfd;
	if ((myfd = open("commanddescription.txt", O_RDONLY)) == -1) {
		perror("Failed to open file");
	}

	else {
		if (!strcmp(info[0], "명령어") {
			//char buf[2000];
			//ssize_t bytesread;
			//bytesread=read(myfd,buf,1999);
			for (int i = 0; i < 22; i++) {
				bytesread = readline(fd, buf, sizeof(buf));
					lseek(fd, (off_t)bytesread, SEEK_CUR);
					printf("%s", buf);
			}
		}
		else {
else if (!strcmp(info[2], "경로이동") {
lseek(fd, (off_t)CD - SEEK_CUR, SEEK_CUR);
for (int i = 0; i < 3; i++) {
	bytesread = readline(fd, buf, sizeof(buf));
		lseek(fd, (off_t)bytesread, SEEK_CUR);
		printf("%s", buf);
}
		 }
else if (!strcmp(info[2], "목록") {
lseek(fd, (off_t)LS - SEEK_CUR, SEEK_CUR);
for (int i = 0; i < 4; i++) {
	bytesread = readline(fd, buf, sizeof(buf));
		lseek(fd, (off_t)bytesread, SEEK_CUR);
		printf("%s", buf);
}
		 }
else if (!strcmp(info[2], "폴더생성") {
lseek(fd, (off_t)MKDIR - SEEK_CUR, SEEK_CUR);
		 }
else if (!strcmp(info[2], "폴더삭제") {
lseek(fd, (off_t)RMDIR - SEEK_CUR, SEEK_CUR);
		 }
else if (!strcmp(info[2], "명령어") {
lseek(fd, (off_t)INSTRUCTION - SEEK_CUR, SEEK_CUR);
		 }
else if (!strcmp(info[2], "설명") {
lseek(fd, (off_t)MAN - SEEK_CUR, SEEK_CUR);
		 }

		}

	}

	close(fd);
}