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
		printf("\t请输入菜单编号(0-6):");
		scanf_s("%d", &oper);
		switch (oper)
		{
		case 0:
			printf("退出成功");
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
			printf("\n未知的命令,请重新输入\n");
			showTitle();
			break;
		}
	}
}
void _setStu(int index) {
	student stu;
	int a;
	char check;
	printf("请输入姓名:");
	scanf_s("%s", stu.name, sizeof(stu.name));
	printf("请输入学号:");
	scanf_s("%d", &stu.id);
	printf("请输入语文成绩:");
	scanf_s("%f", &stu.score_Ch);
	printf("请输入数学成绩:");
	scanf_s("%f", &stu.score_math);
	printf("请输入C语言成绩:");
	scanf_s("%f", &stu.score_C);
	stu.score_all = stu.score_Ch + stu.score_math + stu.score_C;
	stuTable[index] = stu;
	printf("设置成功\n\n");
}
void _showOneStu(int i) {
	printf("%s\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", stuTable[i].name, stuTable[i].id, stuTable[i].score_Ch, stuTable[i].score_math, stuTable[i].score_C, stuTable[i].score_all);
}
void showTitle() {
	printf("|-------学生成绩管理系统--------|\n");
	printf("|\t\t\t\t|\n");
	printf("|\t1.录入学生成绩\t\t|\n");
	printf("|\t2.删除学生成绩\t\t|\n");
	printf("|\t3.修改学生成绩\t\t|\n");
	printf("|\t4.搜索学生成绩\t\t|\n");
	printf("|\t5.插入学生成绩\t\t|\n");
	printf("|\t6.查看所有学生成绩\t|\n");
	printf("|\t0.退出系统\t\t|\n");
	printf("|\t\t\t\t|\n");
	printf("|-------------------------------|\n");
}
void addStudent() {
	printf("录入学生成绩操作\n");
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == 0) {
			_setStu(i);
			return;
		}
	}
	printf("该表格内容已满\n");
}
void deleteStudent() {
	printf("删除学生成绩操作\n");
	printf("请输入您所要删除学生对应的学号:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			student stu = {};
			stuTable[i] = stu;
			printf("删除成功\n\n");
			return;
		}
	}
	printf("没有找到您所输入的学号所对应的学生\n\n");
}
void changeStudent() {
	printf("修改学生成绩操作\n");
	printf("请输入您所要修改学生对应的学号:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			_setStu(i);
			printf("修改成功\n\n");
			return;
		}
	}
	printf("没有找到您所输入的学号所对应的学生\n\n");
}

void searchOneStu() {
	printf("搜索学生成绩操作\n");
	printf("请输入您所要查找学生对应的学号:");
	int id;
	scanf_s("%d", &id);
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id == id) {
			_showOneStu(i);
			printf("搜索成功\n\n");
			return;
		}
	}
	printf("没有找到您所输入的学号所对应的学生\n\n");
}
void insertStudent() {
	printf("插入学生成绩操作\n");
	printf("请输入您要插入的位置(第x行):");
	int pos;
	scanf_s("%d", &pos);
	if (0 >= pos || pos > MAX_COUNT) {
		printf("不存在该位置\n");
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
			printf("该表往后没有空位,无法进行插入\n");
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
	printf("查看所有学生成绩操作\n\n");
	printf("|---------------学生成绩信息---------------|\n");
	printf("姓名\t学号\t语文\t数学\tC语言\t总分\n");
	int sumStu = 0;
	for (int i = 0; i < MAX_COUNT; i++) {
		if (stuTable[i].id) {
			_showOneStu(i);
			sumStu++;
		}
	}
	printf("一共有%d个学生!\n\n", sumStu);
}