#include"head.h"


int main() {


	//��ʼ��
	Student* student_head = loadStudents();



	displayMenu();




	//�����������ļ����ͷ�����
	saveStudents(student_head);
	freeStudentList(student_head);


	return 0;
}