#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command(char** info) {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭 --> ���ڷ� ������ ��� �� ��
	char commandInput[20];
	char options[13];
	char arguments[150];

	// main�� info �ʱ�ȭ �۾�
	// info = (char**)malloc(sizeof(char*) * 4);
	info[3] = NULL;

	printf("��ɾ� �Է� >>");
	scanf("%18s", commandInput);
	if (!strcmp(commandInput, "����")) {
		info[0] = commandInput;
		info[1] = NULL;
		printf("������ ����� ��ɾ �Է��ϼ���(������ x�Է�)\n���� �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;

	}
	else if (!strcmp(commandInput, "����̵�")) {
		info[0] = commandInput;
		info[1] = NULL;
		printf("�̵��� ��θ� �Է� >>");
		scanf("%130s", arguments);
		info[2] = arguments;
	}
	else if (!strcmp(commandInput, "���")) {
		info[0] = commandInput;
		printf("���ϴ� �ɼ��� ���� ����(0.�ɼǾ���|1.��� ���|2.�����ð���|3.ũ���|4.����������|5.����)");
		scanf("%11s", options);
		printf("%s", options);
		if (!strcmp(options, "0")) {
			info[1] = (char*)0;
		}
		// int optionsize = sizeof(options) / sizeof(char);
		//�����ϰ� ����ó���� ������ ����ڰ� ���Ŀ� �°� �Է��ҰŶ�� �����Ͽ� ����.
		/*
		if (optionsize % 2 != 1) {	// �ɼ��� ���̰� ¦���̸�
			printf("�ɼ��� ���Ŀ� ���� �Է����ּ���!");
			info[0] = "-1";
		}
		*/
		else {
			info[1] = (char*)malloc(sizeof(char) * 12);
			strcpy(info[1], "-");	//option�� ������ -��...
			//�ϴ� �츮�� �Է��Ѱ� �Ľ̸� �ϰ� �ɼ� �浹������ os �͹̳ο��� ��� �༭ ���������� �״�� ����ڿ��� ����ϴ°ɷ� �ϴ°� �����
			// for (int i = 0; i < (optionsize+1)/2; i++) {
			if (strchr(options, '1') != NULL) {
				strcat(info[1], "l");
			}
			else if (strchr(options, '2') != NULL) {
				strcat(info[1], "t");
			}
			else if (strchr(options, '3') != NULL) {
				strcat(info[1], "S");
			}
			else if (strchr(options, '4') != NULL) {
				strcat(info[1], "a");
			}
			else if (strchr(options, '5') != NULL) {
				strcat(info[1], "r");
			}
			else {
				printf("�ɼ��� ���Ŀ� ���� �Է����ּ���.");
				info[0] = "-1";
			}
			// }

			// p = strchr(options, '1');
			// printf("%s", p);
		}
		//
		info[2] = (char*)0;
		// printf("%s", options);
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
		info[1] = (char*)0;
		info[2] = (char*)0;
	}
	else {
		printf("�������� �ʴ� ��ɾ��Դϴ�. �ٽ� �Է����ּ���.\n");
		info[0] = "-1";
		//�̻��ϸ� -1��ȯ
	}

}

