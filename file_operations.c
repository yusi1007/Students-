#include"head.h"

//���ļ��м���ѧ����Ϣ
Student* loadStudents() {
	Student* head = NULL;
	FILE* file = fopen("data/students.txt", "r");
	if (file == NULL) {
		printf("�޷����ļ�students.txt\n");
		return head;
	}
	char name[NAME_LEN];
	char id[ID_LEN];
	double score[MAX_SUBJECTS];
	double average;
	while (fscanf(file, "%s %s", name, id) != EOF) {
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			if (fscanf(file, "%lf", &score[i]) != 1) {
				printf("��ȡ�ɼ�ʱ����\n");
			}
		}

	}


}

//������Ϣ���ļ�
void saveStudents(const Student* head) {
	FILE* file=fopen("data/students.txt","w");
	if (file == NULL) {
		printf("�޷����ļ�students.txt\n");
		return;
	}
	const Student* current = head;
	while (current != NULL) {
		//���������ѧ��
		fprintf(file, "%s %s",current->name,current->id);
		for (int i = 0; i < MAX_SUBJECTS;i++) {
			//������Ƴɼ�
			fprintf(file, "%.2lf", current->score[i]);
		}
		//���ƽ���ֲ�����
		fprintf(file, "%.2lf\n", current->average);
		current = current->next;
	}
	if (ferror(file)) {
		printf("д���ļ�ʱ����\n");
	}
	fclose(file);

}


//�ͷ�����
void freeStudentList(Student* head) {
	Student* current = head;
	Student* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}