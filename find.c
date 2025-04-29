#include"head.h"

//按照姓名精确查找
void findStudentByName_pre(Student* head, char* name) {
	//参数有效性检查
	if (name == NULL || head == NULL) {
		printf("参数无效\n");
	}

	//遍历链表查找
	int found = 0;
	Student* current = head;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			display(current);
			found = 1;
		}
		current = current->next;
	}

	//未找到目标
	if (!found) {
		printf("未找到目标\n");
	}
}

//按照姓名模糊查找
void findStudentByName_obs(Student* head, char* name) {
	//参数有效性检查
	if (head == NULL || name == NULL) {
		printf("参数无效\n");
	}

	//遍历链表查找
	int found = 0;
	Student* current = head;
	while (current != NULL) {
		if (strstr(current->name, name) != NULL) {
			display(current);
			found = 1;
		}
		current = current->next;
	}

	//未找到目标
	if (!found) {
		printf("未找到目标\n");
	}
}

Student* findStudentByName(Student* head, char* id) {
	//参数有效性检查
	if (head == NULL || id == NULL) {
		printf("参数无效\n");
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
			printf("未找到目标\n");
		}
		return NULL;
	}
}


//显示学生信息
void display(Student* found_student) {
	if (found_student != NULL) {
		printf("学号：%s,姓名：%s,平均分：%.2lf\n", found_student->id, 
			found_student->name, found_student->average);
		printf("科目成绩:");
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			printf("%.2lf ", found_student->score[i]);
		}
		printf("\n");
	}
}




//列出所有学生信息

//升序
void upList(const Student* head) {
	for()
}


