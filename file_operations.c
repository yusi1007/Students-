#include"head.h"

//从文件中加载学生信息
Student* loadStudents() {
	Student* head = NULL;
	FILE* file = fopen("data/students.txt", "r");
	if (file == NULL) {
		printf("无法打开文件students.txt\n");
		return head;
	}
	char name[NAME_LEN];
	char id[ID_LEN];
	double score[MAX_SUBJECTS];
	double average;
	while (fscanf(file, "%s %s", name, id) != EOF) {
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			if (fscanf(file, "%lf", &score[i]) != 1) {
				printf("读取成绩时出错！\n");
			}
		}

	}


}

//保存信息至文件
void saveStudents(const Student* head) {
	FILE* file=fopen("data/students.txt","w");
	if (file == NULL) {
		printf("无法打开文件students.txt\n");
		return;
	}
	const Student* current = head;
	while (current != NULL) {
		//输出姓名和学号
		fprintf(file, "%s %s",current->name,current->id);
		for (int i = 0; i < MAX_SUBJECTS;i++) {
			//输出各科成绩
			fprintf(file, "%.2lf", current->score[i]);
		}
		//输出平均分并换行
		fprintf(file, "%.2lf\n", current->average);
		current = current->next;
	}
	if (ferror(file)) {
		printf("写入文件时出错！\n");
	}
	fclose(file);

}


//释放链表
void freeStudentList(Student* head) {
	Student* current = head;
	Student* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}