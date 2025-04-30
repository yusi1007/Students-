#include"head.h"

//�ɼ�ͳ�ƺ���
void calculateSubjectStats(const Student* head) {
	if (head == NULL) {
		printf("û��ѧ����Ϣ\n");
		return;
	}
	int index;
	double maxscore=-1;
	double minscore =101;
	double totalscore= 0;
	int student_count = 0;

	do {
		printf("����������Ҫͳ�ƵĿ�Ŀ��0-%d��Ӧ��Ŀ0-��Ŀ%d��", MAX_SUBJECTS - 1, MAX_SUBJECTS - 1);
		scanf("%d", &index);
		if (index < 0 || index >= MAX_SUBJECTS) {
			printf("������Ч��������0-%d֮������֡�\n", MAX_SUBJECTS - 1);
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

		//��ѧ������Ϊ0
		if (student_count == 0) {
			printf("û����Ч��ѧ���ɼ��ɹ�ͳ�ơ�\n");
			return;
		}
		totalscore += score;
		student_count++;
		current = current->next;
	}
	double averagescore = totalscore / student_count;
	printf("��Ŀ%d����߷֣�%.2lf\n",index,maxscore);
	printf("��Ŀ%d����ͷ֣�%.2lf\n", index, minscore);
	printf("��Ŀ%d��ƽ���֣�%.2lf\n", index, averagescore);

}