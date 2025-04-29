#include"head.h"

//����������ȷ����
void findStudentByName_pre(Student* head, char* name) {
	//������Ч�Լ��
	if (name == NULL || head == NULL) {
		printf("������Ч\n");
	}

	//�����������
	int found = 0;
	Student* current = head;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			display(current);
			found = 1;
		}
		current = current->next;
	}

	//δ�ҵ�Ŀ��
	if (!found) {
		printf("δ�ҵ�Ŀ��\n");
	}
}

//��������ģ������
void findStudentByName_obs(Student* head, char* name) {
	//������Ч�Լ��
	if (head == NULL || name == NULL) {
		printf("������Ч\n");
	}

	//�����������
	int found = 0;
	Student* current = head;
	while (current != NULL) {
		if (strstr(current->name, name) != NULL) {
			display(current);
			found = 1;
		}
		current = current->next;
	}

	//δ�ҵ�Ŀ��
	if (!found) {
		printf("δ�ҵ�Ŀ��\n");
	}
}

Student* findStudentByName(Student* head, char* id) {
	//������Ч�Լ��
	if (head == NULL || id == NULL) {
		printf("������Ч\n");
	}

	int found = 0;
	Student* current = head;
	while (current != NULL) {
		if (strcmp(current->id, id) == 0) {
			display(current);
			found = 1;
			return current;
		}
		if (!found) {
			printf("δ�ҵ�Ŀ��\n");
		}
		return NULL;
	}
}


//��ʾѧ����Ϣ
void display(Student* found_student) {
	if (found_student != NULL) {
		printf("ѧ�ţ�%s,������%s,ƽ���֣�%.2lf\n", found_student->id, 
			found_student->name, found_student->average);
		printf("��Ŀ�ɼ�:");
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			printf("%.2lf ", found_student->score[i]);
		}
		printf("\n");
	}
}




//�г�����ѧ����Ϣ

//����
void upList(const Student* head) {
	for()
}


