#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command(char** info) {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭 --> ���ڷ� ������ ��� �� ��
	char commandInput[10];
	char options[10];
	char arguments[150];
	char commandstr[200]="";
	char partition[2] = "#";
	
	// main�� info �ʱ�ȭ �۾�
	int i;
	for (i = 0; i < 10; i++)
		info[i] = NULL;

	printf("��ɾ� �Է� >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "����")) {
		strcat(commandstr, commandInput);
		// �̷��� �ϴ� �� �?
		// ���� cmd������ ��ɾ �� �ٷ� �� �޾Ƽ� �Ľ��� �ʿ�������, ���� �����غ��� �츮�� ����� shell��
		// ��ɾ�� �ɼ��� ���ε��� �޾Ƽ� �Ľ��� �ʿ��ұ� �;�..!
		// strcpy(info[0], commandInput);
		strcat(commandstr, partition);
		strcat(commandstr, partition);
		printf("������ ����� ��ɾ �Է��ϼ���(������ x�Է�)\n���� �Է� >>");
		scanf("%130s", arguments);
		strcat(commandstr, arguments);
		// strcpy(info[1], arguments);
		// info[2] = (char*)0;
		printf("%s ", commandstr);
	}
	else if (!strcmp(commandInput, "����̵�")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "���")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "��������")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "��������")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else if (!strcmp(commandInput, "��ɾ�")) {
		strcat(commandstr, commandInput);
		strcat(commandstr, partition);
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
	}

}

