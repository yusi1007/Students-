#ifndef HEAD_H
#define HEAD_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//常量定义
#define NAME_LEN 30
#define ID_LEN   5


//科目枚举
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


//学生信息结构体
typedef struct Student {
	char id[ID_LEN];				//学号
	char name[NAME_LEN];			//姓名
	double score[MAX_SUBJECTS];		//科目分数
	double average;					//平均分
	double total;					//总分
	struct Student* next;
} Student;


//函数声明

//数据结构操作
Student* loadstudents();
void saveStudents(const Student* head);

//内存管理函数
void freeStudentList(Student* head);


//界面模块
void displayMenu();
void findMenu(const Student* student_head);

//信息管理
Student* createStudent(const char* name, const char* id);	//创建新学生信息
void addStudent(Student** head, Student* new_student);		//添加学生信息
void inputStudent(Student** head);							//插入学生信息
void deleteStudent(Student** head,const char* id);			//删除学生信息
void modifyStudent(Student* head, const char* id);			//修改学生信息




//排序显示学生信息
void sortStudent(Student* head);			//学号排序
void upList(const Student* head);			//学号升序
void downList(const Student* head);			//学号降序

void scoreList(const Student* head);		//成绩排序


//排序与成绩统计
void sortBySingleSubject(Student* head, int number);		//单科成绩排序
void sortByTotal(Student* head);							//总成绩排序
void calculateSubjectStats(Student* head);
//查询学生信息函数
void findStudentByName_pre(Student* head, char* name);		//精确查找
void findStudentByName_obs(Student* head, char* name);		//模糊查找
Student* findStudengById(Student* head, char* id);				//学号查找
void display(Student* found_student);

#endif