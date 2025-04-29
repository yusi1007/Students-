#ifndef HEAD_H
#define HEAD_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//��������
#define NAME_LEN 30
#define ID_LEN   5


//��Ŀö��
typedef enum {
	SUB1,
	SUB2,
	SUB3,
	SUB4,
	SUB5,
	SUB6,
	SUB7,
	SUB8,
	SUB9,
	SUB10,
	MAX_SUBJECTS
}Subject;


//ѧ����Ϣ�ṹ��
typedef struct Student {
	char id[ID_LEN];				//ѧ��
	char name[NAME_LEN];			//����
	double score[MAX_SUBJECTS];		//��Ŀ����
	double average;					//ƽ����
	double total;					//�ܷ�
	struct Student* next;
} Student;


//��������

//���ݽṹ����
Student* loadstudents();
void saveStudents(const Student* head);

//�ڴ������
void freeStudentList(Student* head);


//����ģ��
void displayMenu();
void findMenu(const Student* student_head);

//��Ϣ����
Student* createStudent(const char* name, const char* id);	//������ѧ����Ϣ
void addStudent(Student** head, Student* new_student);		//���ѧ����Ϣ
void inputStudent(Student** head);							//����ѧ����Ϣ
void deleteStudent(Student** head,const char* id);			//ɾ��ѧ����Ϣ
void modifyStudent(Student* head, const char* id);			//�޸�ѧ����Ϣ




//������ʾѧ����Ϣ
void sortStudent(Student* head);			//ѧ������
void upList(const Student* head);			//ѧ������
void downList(const Student* head);			//ѧ�Ž���

void scoreList(const Student* head);		//�ɼ�����


//������ɼ�ͳ��
void sortBySingleSubject(Student* head, int number);		//���Ƴɼ�����
void sortByTotal(Student* head);							//�ܳɼ�����
void calculateSubjectStats(Student* head);
//��ѯѧ����Ϣ����
void findStudentByName_pre(Student* head, char* name);		//��ȷ����
void findStudentByName_obs(Student* head, char* name);		//ģ������
Student* findStudengById(Student* head, char* id);				//ѧ�Ų���
void display(Student* found_student);

#endif