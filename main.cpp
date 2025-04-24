#include <stdio.h>
#include <string.h>
struct student
{
	char name[13] = "";
	int id = 0;
	float score_Ch = 0;
	float score_math = 0;
	float score_C = 0;
	float score_all = 0;
};
const int MAX_COUNT = 20;
student stuTable[20];
void _setStu(int index);
void _showOneStu(int i);
void showTitle();
void addStudent();
void deleteStudent();
void changeStudent();
void searchOneStu();
void insertStudent();
void getStuTable();
int main() {
	showTitle();
	while (true)
	{
		int oper;
		printf("\t������˵����(0-6):");
		scanf_s("%d", &oper);
		switch (oper)
		{
		case 0:
			printf("�˳��ɹ�");
			return 0;
		case 1:
			addStudent();
			break;
		case 2:
			deleteStudent();
			break;
		case 3:
			changeStudent();
			break;
		case 4:
			searchOneStu();
			break;
		case 5:
			insertStudent();
			break;
		case 6:
			getStuTable();
			break;
		default:
			printf("\nδ֪������,����������\n");
			showTitle();
			break;
		}
	}
}
void _setStu(int index) {
	student stu;
	int a;
	char check;
	printf("����������:");
	scanf_s("%s", stu.name, sizeof(stu.name));
	printf("������ѧ��:");
	scanf_s("%d", &stu.id);
	printf("���������ĳɼ�:");
	scanf_s("%f", &stu.score_Ch);
	printf("��������ѧ�ɼ�:");
	scanf_s("%f", &stu.score_math);
	printf("������C���Գɼ�:");
	scanf_s("%f", &stu.score_C);
	stu.score_all = stu.score_Ch + stu.score_math + stu.score_C;
	stuTable[index] = stu;
	printf("���óɹ�\n\n");
}
void _showOneStu(int i) {
	printf("%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", stuTable[i].name, stuTable[i].id, stuTable[i].score_Ch, stuTable[i].score_math, stuTable[i].score_C, stuTable[i].score_all);
}
void showTitle() {
	printf("|-------ѧ���ɼ�����ϵͳ--------|\n");
	printf("|\t\t\t\t|\n");
	printf("|\t1.¼��ѧ���ɼ�\t\t|\n");
	printf("|\t2.ɾ��ѧ���ɼ�\t\t|\n");
	printf("|\t3.�޸�ѧ���ɼ�\t\t|\n");
	printf("|\t4.����ѧ���ɼ�\t\t|\n");
	printf("|\t5.����ѧ���ɼ�\t\t|\n");
	printf("|\t6.�鿴����ѧ���ɼ�\t|\n");
	printf("|\t0.�˳�ϵͳ\t\t|\n");
	printf("|\t\t\t\t|\n");
	printf("|-------------------------------|\n");
}
void addStudent() {
	printf("¼��ѧ���ɼ�����\n");
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == 0) {
			_setStu(i);
			return;
		}
	}
	printf("�ñ����������\n");
}
void deleteStudent() {
	printf("ɾ��ѧ���ɼ�����\n");
	printf("����������Ҫɾ��ѧ����Ӧ��ѧ��:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			student stu = {};
			stuTable[i] = stu;
			printf("ɾ���ɹ�\n\n");
			return;
		}
	}
	printf("û���ҵ����������ѧ������Ӧ��ѧ��\n\n");
}
void changeStudent() {
	printf("�޸�ѧ���ɼ�����\n");
	printf("����������Ҫ�޸�ѧ����Ӧ��ѧ��:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			_setStu(i);
			printf("�޸ĳɹ�\n\n");
			return;
		}
	}
	printf("û���ҵ����������ѧ������Ӧ��ѧ��\n\n");
}

void searchOneStu() {
	printf("����ѧ���ɼ�����\n");
	printf("����������Ҫ����ѧ����Ӧ��ѧ��:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			_showOneStu(i);
			printf("�����ɹ�\n\n");
			return;
		}
	}
	printf("û���ҵ����������ѧ������Ӧ��ѧ��\n\n");
}
void insertStudent() {
	printf("����ѧ���ɼ�����\n");
	printf("��������Ҫ�����λ��(��x��):");
	int pos;
	scanf_s("%d", &pos);
	if (0 >= pos || pos > MAX_COUNT) {
		printf("�����ڸ�λ��\n");
		return;
	}
	if (stuTable[pos - 1].id != 0) {
		int emptyIndex = -1;
		for (int i = pos - 1; i < MAX_COUNT; i++) {
			if (stuTable[i].id == 0) {
				emptyIndex = i;
				break;
			}
		}
		if (emptyIndex == -1) {
			printf("�ñ�����û�п�λ,�޷����в���\n");
			return;
		}
		while (emptyIndex != pos - 1) {
			stuTable[emptyIndex] = stuTable[emptyIndex - 1];
			emptyIndex--;
		}
	}
	_setStu(pos - 1);
}
void getStuTable() {
	printf("�鿴����ѧ���ɼ�����\n\n");
	printf("|---------------ѧ���ɼ���Ϣ---------------|\n");
	printf("����\tѧ��\t����\t��ѧ\tC����\t�ܷ�\n");
	int sumStu = 0;
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id) {
			_showOneStu(i);
			sumStu++;
		}
	}
	printf("һ����%d��ѧ��!\n\n", sumStu);
}