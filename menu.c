#include"head.h"

	void displayMenu() {
		int choice;
		char name[NAME_LEN];
		char id[ID_LEN];
		double score[MAX_SUBJECTS];
		printf("\n");
		printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
		printf("1.�������ѧ����Ϣ\n");
		printf("2.��ѯѧ����Ϣ\n");
		printf("3.���ѧ����Ϣ\n");
		printf("4.�޸�ѧ����Ϣ\n");
		printf("5.ɾ��ѧ����Ϣ\n");
		printf("6.���յ��Ƴɼ�����\n");
		printf("7.����ƽ��������\n");
		printf("8.ͳ�ƿ�Ŀ��߷֡���ͷֺ�ƽ����\n");
		printf("0.�˳�\n");
		printf("���������ѡ��0-8����");
		scanf("%d", &choice);

		
	}

	void findMenu(const Student* student_head) {
		int choice;
		char name[NAME_LEN];
		char id[ID_LEN];
		do {
			printf("\n��ѯ��ʽ��\n");
			printf("1.����������׼��ѯ\n");
			printf("2.��������ģ����ѯ\n");
			printf("3.����ѧ�Ų�ѯ\n");
			printf("0.������һ��\n");
			printf("���������ѡ��0-3��");

			Student* found_student = NULL;
			switch (choice) {
			case 1:		//����������׼��ѯ
				printf("������������");
				scanf("%s", name);
				findStudentByName_pre(student_head, name);
				break;
			case 2:
				printf("������������");
				scanf("%s", name);
				findStudentByName_obs(student_head, name);
				break;
			case 3:
				printf("������ѧ�ţ�");
				scanf("%s", id);
				findStudentById(student_head);
				break;
			case 0:
				printf("�����ϼ��˵�");
				break;
			default:
				printf("������Ч��������0-3֮�������");
			}

		} while (choice != 0);
	}

