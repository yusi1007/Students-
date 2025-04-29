#include"head.h"


Student* createStudent(const char* name, const char* id) {
	//参数有效性检查
	if (name == NULL || id == NULL) {
		printf("错误：信息不能为空\n");
		return NULL;
	}

	//检查用户名长度
	if (strlen(name) >= NAME_LEN) {
		printf("错误：用户名过长，最大长度为%d\n", NAME_LEN - 1);
		return NULL;
	}

	//检查学号长度
	if (strlen(id) >= ID_LEN) {
		printf("错误:学号过长，最大长度为%d\n", ID_LEN - 1);
		return NULL;
	}


	//分配内存
	Student* new_student = (Student*)malloc(sizeof(Student));
	if (new_student == NULL) {
		printf("错误：内存分配失败\n");
		return NULL;
	}

	//初始化用户信息
	strcpy(new_student->name, name);
	strcpy(new_student->id, id);


	return new_student;
}


//添加用户到链表
void addStudent(Student** head, Student* new_student) {
	//参数有效性检查
	if (head == NULL || new_student == NULL) {
		printf("错误：无效的参数\n");
		return;
	}

	//如果链表为空，新用户成为头结点
	if (*head == NULL) {
		*head = new_student;
		new_student->next = NULL;
		printf("学生%s已成功添加到系统\n", new_student->name);
		return;
	}

	//若链表不为空，检查不存在相同学号再添加到链表,姓名可以相同
	Student* current = *head;
	while (current != NULL) {
		if (strcmp(current->id, new_student->id) == 0) {
			printf("错误：学号%s已存在", new_student->id);
			free(new_student);		//释放内存避免内存泄漏
			return;
		}

		current = current->next;
	}

	//将新学生信息添加到表头
	new_student->next = *head;
	*head = new_student;
	printf("学生%s已成功添加到系统\n", new_student->name);
}

//删除学生信息
void deleteStudent(Student** head, const char* id) {
	//参数有效性检查
	if (head == NULL || *head == NULL || id == NULL) {
		printf("错误，无效的参数\n");
		return;
	}

	Student* current = *head;
	Student* prec = NULL;
	if (strcmp(current->id, id) == 0) {
		*head = current->next;
		printf("%s已从系统中删除\n", current->id);
		free(current);
		return;
	}
}


//修改学生信息
void modifyStudent(Student* head, const char* id) {
	Student* current = head;
	while (current != NULL) {
		if(strcmp(current->))
	}
}


