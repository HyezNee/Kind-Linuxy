#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int _work(char **info) {//execl,wait,exit
	int stat = 0;

	if (!strcmp(info[0], "����̵�")) {

	}
	else if (!strcmp(info[0], "���")) {
		info[0] = "ls";
		pid_t childpid;
		childpid = fork();

		if (childpid == -1) {
			perror("��� ���� ���� : ��ũ ����(�ڵ�1)");
			return 1;
		}

		if (childpid == 0) {	// Child code
			execv("/bin/ls", info);
			perror("��� ���� ���� : ��� �ҷ����� ����(�ڵ�2)");
			return 1;
		}
		else if (childpid != wait(NULL)) {	// parent code
			perror("��� ���� ���� : �θ� ��ٸ��� ����(�ڵ�3)");
			return 1;
		}
	}
	return stat;	// ������ ���� (stat == 0)
}

void _fileopen() {//open,read,lseek

}

/*int main(void) {	// �׽�Ʈ�� ���� �Լ�
	char* info[2];
	info[0] = "���";
	info[1] = "-l";
	info[2] = (char*)0;
	_work(info);
}*/