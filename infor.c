#include"head.h"


Student* createStudent(const char* name, const char* id) {
	//������Ч�Լ��
	if (name == NULL || id == NULL) {
		printf("������Ϣ����Ϊ��\n");
		return NULL;
	}

	//����û�������
	if (strlen(name) >= NAME_LEN) {
		printf("�����û�����������󳤶�Ϊ%d\n", NAME_LEN - 1);
		return NULL;
	}

	//���ѧ�ų���
	if (strlen(id) >= ID_LEN) {
		printf("����:ѧ�Ź�������󳤶�Ϊ%d\n", ID_LEN - 1);
		return NULL;
	}


	//�����ڴ�
	Student* new_student = (Student*)malloc(sizeof(Student));
	if (new_student == NULL) {
		printf("�����ڴ����ʧ��\n");
		return NULL;
	}

	//��ʼ���û���Ϣ
	strcpy(new_student->name, name);
	strcpy(new_student->id, id);


	return new_student;
}


//����û�������
void addStudent(Student** head, Student* new_student) {
	//������Ч�Լ��
	if (head == NULL || new_student == NULL) {
		printf("������Ч�Ĳ���\n");
		return;
	}

	//�������Ϊ�գ����û���Ϊͷ���
	if (*head == NULL) {
		*head = new_student;
		new_student->next = NULL;
		printf("ѧ��%s�ѳɹ���ӵ�ϵͳ\n", new_student->name);
		return;
	}

	//������Ϊ�գ���鲻������ͬѧ������ӵ�����,����������ͬ
	Student* current = *head;
	while (current != NULL) {
		if (strcmp(current->id, new_student->id) == 0) {
			printf("����ѧ��%s�Ѵ���", new_student->id);
			free(new_student);		//�ͷ��ڴ�����ڴ�й©
			return;
		}

		current = current->next;
	}

	//����ѧ����Ϣ��ӵ���ͷ
	new_student->next = *head;
	*head = new_student;
	printf("ѧ��%s�ѳɹ���ӵ�ϵͳ\n", new_student->name);
}

//ɾ��ѧ����Ϣ
void deleteStudent(Student** head, const char* id) {
	//������Ч�Լ��
	if (head == NULL || *head == NULL || id == NULL) {
		printf("������Ч�Ĳ���\n");
		return;
	}

	Student* current = *head;
	Student* prec = NULL;
	if (strcmp(current->id, id) == 0) {
		*head = current->next;
		printf("%s�Ѵ�ϵͳ��ɾ��\n", current->id);
		free(current);
		return;
	}
}


//�޸�ѧ����Ϣ
void modifyStudent(Student* head, const char* id) {
	Student* current = head;
	while (current != NULL) {
		if(strcmp(current->))
	}
}


