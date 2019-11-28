#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

int _work(char** info) {        //execl,wait,exit
	int stat = 0;

	if (!strcmp(info[0], "����̵�")) {
		int len = (int)(strlen(info[1])) + 3;
		char* directory = malloc(sizeof(char) * len);   // /��� ���� ��ŭ �޸� �Ҵ�
		strcpy(directory, "./");
		strcat(directory, info[1]);     // ���ڿ� ���̱�
		//printf("%s", directory);
		if (chdir(directory) == -1) {
			perror("��� ���� ���� : ��� �ҷ����� ����(�ڵ�2)");
		}
		free(directory);
		char cwd[100];
		getcwd(cwd, sizeof(cwd));
		printf("%s", cwd);
	}
	else if (!strcmp(info[0], "���")) {
		info[0] = "ls";
		pid_t childpid;
		printf("��¡ %s %s", info[0], info[1]);
		childpid = fork();
		if (childpid == -1) {
			perror("��� ���� ���� : ��ũ ����(�ڵ�1)");
			return 1;
		}
		if (childpid == 0) {    // Child code
			execv("/bin/ls", info);
			perror("��� ���� ���� : ��� �ҷ����� ����(�ڵ�2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {      // parent code
			perror("��� ���� ���� : �θ� ��ٸ��� ����(�ڵ�3)");
			return 1;
		}
	}
	else if (!strcmp(info[0], "����")) {

	}
	else if (!strcmp(info[0], "��������")) {
		info[0] = "mkdir";
		//���ϸ���ڿ�
	}
	else if (!strcmp(info[0], "��������")) {

	}
	else if (!strcmp(info[0], "��ɾ�")) {

	}
	return stat;    // ������ ���� (stat == 0)
}

void _fileopen() {//open,read,lseek

}

/*
int main(void) {	// �׽�Ʈ�� ���� �Լ�
	char* info[3];

	//info[0] = "���";
	//info[1] = "-l";
	//info[2] = (char*)0;

	info[0] = "����̵�";
	info[1] = "NewDir";
	info[2] = (char*)0;
	_work(info);
	return 0;
}
*/