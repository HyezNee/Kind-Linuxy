#include "header.h"
#pragma warning(disable:4996) //scanf ���� ��� ����


//��ɾ� 1ȸ �Է¹޾� ó���ϰ� �� ���·� return(char **��)
void _command(char** info) {//readline���� �ٲٱ� ���߿�
	//char **info; //��ɾ� ������ �迭 --> ���ڷ� ������ ��� �� ��
	char commandInput[10];
	char options[12];
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
		scanf("%11s", options);
		if (!strcmp(options, "0")) {
			options[1] = "\0";
		}
		int optionsize = sizeof(options) / sizeof(char);
		//�����ϰ� ����ó���� ������ ����ڰ� ���Ŀ� �°� �Է��ҰŶ�� �����Ͽ� ����.
		if (optionsize % 2 != 1) {
			printf("�ɼ��� ���Ŀ� ���� �Է����ּ���");
			info[0] = "-1";
		}
		else {
			info[1] = "#";	//option�� ������ #����...
			//�ϴ� �츮�� �Է��Ѱ� �Ľ̸� �ϰ� �ɼ� �浹������ os �͹̳ο��� ��� �༭ ���������� �״�� ����ڿ��� ����ϴ°ɷ� �ϴ°� �����
			for (int i = 0; i < (optionsize+1)/2; i++) {
				if (options[2 * i] == '1') {
					strcat(info[1], "l");
				}
				else if (options[2 * i] == '2') {
					strcat(info[1], "t");
				}
				else if (options[2 * i] == '3') {
					strcat(info[1], "S");
				}
				else if (options[2 * i] == '4') {
					strcat(info[1], "a");
				}
				else if (options[2 * i] == '5') {
					strcat(info[1], "r");
				}
				else {
					printf("�ɼ��� ���Ŀ� ���� �Է����ּ���.");
					info[0] = "-1";
				}
			}
		}

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
		info[0] = "-1";
		//�̻��ϸ� -1��ȯ
	}

}

