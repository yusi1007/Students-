#include"head.h"


int main() {


	//初始化
	Student* student_head = loadStudents();



	displayMenu();




	//保存数据至文件，释放链表
	saveStudents(student_head);
	freeStudentList(student_head);


	return 0;
}