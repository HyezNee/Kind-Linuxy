#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command() {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭
	char commandInput[10];
	char options[10];
	char arguments[150];
	char commandstr[200]="";
	char partition[2] = "#";

	printf("��ɾ� �Է� >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "����")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
		strcat(commandstr, partition);
		printf("������ ����� ��ɾ �Է��ϼ���(������ x�Է�)\n���� �Է� >>");
		scanf("%130s", arguments);
		strcat(commandstr, arguments);
		printf("%s", commandstr);
	}
	else if (!strcmp(commandInput, "����̵�")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "���")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "��������")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "��������")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else if (!strcmp(commandInput, "��ɾ�")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, "#");
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
	}

	//return info;
}

void _parse(char *str, char *buf) {


}