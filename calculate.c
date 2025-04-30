#include"head.h"

//成绩统计函数
void calculateSubjectStats(const Student* head) {
	if (head == NULL) {
		printf("没有学生信息\n");
		return;
	}
	int index;
	double maxscore=-1;
	double minscore =101;
	double totalscore= 0;
	int student_count = 0;

	do {
		printf("请输入你想要统计的科目（0-%d对应科目0-科目%d）", MAX_SUBJECTS - 1, MAX_SUBJECTS - 1);
		scanf("%d", &index);
		if (index < 0 || index >= MAX_SUBJECTS) {
			printf("输入无效，请输入0-%d之间的数字。\n", MAX_SUBJECTS - 1);
		}
			

	} while (index < 0 || index >= MAX_SUBJECTS);
	const Student* current = head;
	while (current != NULL) {
		double score = current->score[index];
		if (score > maxscore) {
			maxscore = score;
		}
		if (score < minscore) {
			minscore = score;
		}

		//若学生数量为0
		if (student_count == 0) {
			printf("没有有效的学生成绩可供统计。\n");
			return;
		}
		totalscore += score;
		student_count++;
		current = current->next;
	}
	double averagescore = totalscore / student_count;
	printf("科目%d的最高分：%.2lf\n",index,maxscore);
	printf("科目%d的最低分：%.2lf\n", index, minscore);
	printf("科目%d的平均分：%.2lf\n", index, averagescore);

}