#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command() {//readline
	//char **info; //��ɾ� ������ �迭
	char commandInput[10];

	printf("��ɾ� �Է� >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "����")) {
		printf("�����ν�\n");
	}
	else if (!strcmp(commandInput, "����̵�")) {
		printf("����̵��ν�\n");
	}
	else if (!strcmp(commandInput, "���")) {
		printf("����ν�\n");
	}
	else if (!strcmp(commandInput, "��������")) {
		printf("���������ν�\n");
	}
	else if (!strcmp(commandInput, "��������")) {
		printf("���������ν�\n");
	}
	else if (!strcmp(commandInput, "��ɾ�")) {
		printf("��ɾ��ν�\n");
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
	}

	//return info;
}

void _parse(char *str, char *buf) {


}