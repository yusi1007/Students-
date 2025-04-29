#include"head.h"

	void displayMenu() {
		int choice;
		char name[NAME_LEN];
		char id[ID_LEN];
		double score[MAX_SUBJECTS];
		printf("\n");
		printf("欢迎使用学生信息管理系统\n");
		printf("1.浏览所有学生信息\n");
		printf("2.查询学生信息\n");
		printf("3.添加学生信息\n");
		printf("4.修改学生信息\n");
		printf("5.删除学生信息\n");
		printf("6.按照单科成绩排序\n");
		printf("7.按照平均分排序\n");
		printf("8.统计科目最高分、最低分和平均分\n");
		printf("0.退出\n");
		printf("请输入你的选择（0-8）：");
		scanf("%d", &choice);

		
	}

	void findMenu(const Student* student_head) {
		int choice;
		char name[NAME_LEN];
		char id[ID_LEN];
		do {
			printf("\n查询方式：\n");
			printf("1.按照姓名精准查询\n");
			printf("2.按照姓名模糊查询\n");
			printf("3.按照学号查询\n");
			printf("0.返回上一级\n");
			printf("请输入你的选择（0-3）");

			Student* found_student = NULL;
			switch (choice) {
			case 1:		//按照姓名精准查询
				printf("请输入姓名：");
				scanf("%s", name);
				findStudentByName_pre(student_head, name);
				break;
			case 2:
				printf("请输入姓名：");
				scanf("%s", name);
				findStudentByName_obs(student_head, name);
				break;
			case 3:
				printf("请输入学号：");
				scanf("%s", id);
				findStudentById(student_head);
				break;
			case 0:
				printf("返回上级菜单");
				break;
			default:
				printf("输入无效，请输入0-3之间的数字");
			}

		} while (choice != 0);
	}

