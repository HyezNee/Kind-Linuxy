#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command(char** info) {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭 --> ���ڷ� ������ ��� �� ��
	char commandInput[10];
	char options[10];
	char arguments[150];
	
	// main�� info �ʱ�ȭ �۾�
	info = (char**)malloc(sizeof(char*) * 4);

	printf("��ɾ� �Է� >>");
	scanf("%8s", commandInput);
	if (!strcmp(commandInput, "����")) {
		info[0] = commandInput;
		printf("%s", info[0]);
		printf("������ ����� ��ɾ �Է��ϼ���(������ x�Է�)\n���� �Է� >>");
		scanf("%130s", arguments);
		
	}
	else if (!strcmp(commandInput, "����̵�")) {
		
	}
	else if (!strcmp(commandInput, "���")) {
		
	}
	else if (!strcmp(commandInput, "��������")) {
		
	}
	else if (!strcmp(commandInput, "��������")) {
		
	}
	else if (!strcmp(commandInput, "��ɾ�")) {
		
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
	}

}

