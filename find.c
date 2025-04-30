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

//����ѧ�Ų���
Student* findStudentById(Student* head, char* id) {
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
		printf("ѧ�ţ�%s,������%s,ƽ���֣�%.2lf,�ܷ֣�%.2lf\n", found_student->id, 
			found_student->name, found_student->average,found_student->total);
		printf("��Ŀ�ɼ�:");
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			printf("%.2lf ", found_student->score[i]);
		}
		printf("\n");
	}
}




//�г�����ѧ����Ϣ

//�����ڵ����ݺ���
void swap(Student* a, Student* b) {
	Student temp = *a;
	strcpy(a->name, b->name);
	strcpy(a->id, b->id);
	for (int i = 0; i < MAX_SUBJECTS; i++) {
		a->score[i] = b->score[i];
	}
	a->average = b->average;
	a->total = b->total;

	strcpy(b->name, temp.name);
	strcpy(b->id, temp.id);
	for (int i = 0; i < MAX_SUBJECTS; i++) {
		b->score[i] = temp.score[i];
	}
	b->average = temp.average;
	b->total = temp.total;
}

//����
Student* (const Student* head��order) {
	int swapped;
	Student* p1;
	Student* p2 = NULL;
	
	if (head == NULL) {
		return head;
	}
	do {
		swapped = 0;
		p1 = head;
		while (p1->next != p2) {
			int cmp = strcmp(p1->id, p1->next->id);
			if ((order && cmp > 0) || (!order && cmp < 0)) {
				swap(p1, p1->next);
				swapped = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	} while (swapped);

	return head;
}


