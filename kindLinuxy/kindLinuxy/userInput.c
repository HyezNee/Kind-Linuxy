#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command(char** info) {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭 --> ���ڷ� ������ ��� �� ��
	char commandInput[10];
	char options[11];
	char arguments[150];
	
	// main�� info �ʱ�ȭ �۾�
	info = (char**)malloc(sizeof(char*) * 4);
	info[3] = NULL;

	printf("��ɾ� �Է� >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "����")) {
		info[0] = commandInput;
		info[1] = "\0";
		printf("������ ����� ��ɾ �Է��ϼ���(������ x�Է�)\n���� �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;
		
	}
	else if (!strcmp(commandInput, "����̵�")) {
		info[0] = commandInput;
		info[1] = "\0";
		printf("�̵��� ��θ� �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "���")) {
		info[0] = commandInput;
		printf("���ϴ� �ɼ��� ���� ����(0.�ɼǾ���|1.��� ���|2.�����ð���|3.ũ���|4.����������|5.����)");
		info[2] = "\0";
	}
	else if (!strcmp(commandInput, "��������")) {
		info[0] = commandInput;
		printf("���� ������ �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "��������")) {
		info[0] = commandInput;
		printf("������ �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "��ɾ�")) {
		info[0] = commandInput;
		info[1] = "\0";
		info[2] = "\0";
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
	}

}

