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

//按照学号查找
Student* findStudentById(Student* head, char* id) {
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
		printf("学号：%s,姓名：%s,平均分：%.2lf,总分：%.2lf\n", found_student->id, 
			found_student->name, found_student->average,found_student->total);
		printf("科目成绩:");
		for (int i = 0; i < MAX_SUBJECTS; i++) {
			printf("%.2lf ", found_student->score[i]);
		}
		printf("\n");
	}
}




//列出所有学生信息

//交换节点数据函数
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

//排序
Student* (const Student* head，order) {
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


