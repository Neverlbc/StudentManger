#define _CRT_SECURE_NO_WARNINGS//解决scanf报错
#include<stdio.h>
#include<stdlib.h>
#include"sudentsystem.h"

void menu() //菜单
{
	printf("               学生信息管理系统\n");
	printf("*****************************************\n");
	printf("\t\t0.录入信息	   ******\n");
	printf("\t\t1.浏览信息	   ******\n");
	printf("\t\t2.查找信息	   ******\n");
	printf("\t\t3.删除信息	   ******\n");
	printf("\t\t4.修改信息	   ******\n");
	printf("\t\t5.退出系统	   ******\n");
	printf("*****************************************\n");
	printf("请输入你的选择：");


}
struct Node* list = createList();
void KeyDown()
{
	int chioce;
	struct student data;
	scanf("%d", &chioce);
	switch (chioce)
	{
	case 0:
		printf("---------录入信息---------\n");
		printf("请输入学生学号,姓名,性别,年龄,出生日期，电话,地址,邮件\n");
		fflush(stdin);
		scanf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s", data.studentnumber,data.name,data.sex ,& data.age, data.birthday,data.phonenumber, data.address, data.E_mail);
		insertNodeByHead(list, data);

		break;
	case 1:
		printf("---------浏览信息---------\n");
		printList(list);//打印数据
		break;
	case 2:
		printf("---------查找信息---------\n");
		int way;
		printf("查找方式 1.按姓名查找\n\t2.按学号查找");
		scanf("%d", &way);
		if (way == 1) {
			printf("请输入要查找的学生姓名：");
			scanf("%s", data.name);
			if (serchInfoByDaya(list, data.name) == NULL)
			{
				printf("未找到要查找的学生信息\n");
			}
			else {
				printf("学号\t\t姓名\t性别\t年龄\t出生日期\t电话\t\t地址\t\t\t邮件\n");
				printf("%s\t%s\t%s", serchInfoByDaya(list, data.name)->data.studentnumber, serchInfoByDaya(list, data.name)->data.name, serchInfoByDaya(list, data.name)->data.sex);
				printf("\t%d\t%s\t%s\t%s\t\t%s\n", serchInfoByDaya(list, data.name)->data.age, serchInfoByDaya(list, data.name)->data.birthday, serchInfoByDaya(list, data.name)->data.phonenumber, serchInfoByDaya(list, data.name)->data.address, serchInfoByDaya(list, data.name)->data.E_mail);
			}
			break;
		}else {
			printf("请输入要查找的学生学号：\n");
			scanf("%s", data.studentnumber);
			if (studentnumberserchInfoByDaya(list, data.studentnumber) == NULL)
			{
				printf("未找到要查找的学生信息\n");
			}
			else {
				printf("学号\t\t姓名\t性别\t年龄\t出生日期\t电话\t\t地址\t\t\t邮件\n");
				printf("%s\t%s\t%s", studentnumberserchInfoByDaya(list, data.studentnumber)->data.studentnumber, studentnumberserchInfoByDaya(list, data.studentnumber)->data.name, studentnumberserchInfoByDaya(list, data.studentnumber)->data.sex);
				printf("\t%d\t%s\t%s\t%s\t\t%s\n", studentnumberserchInfoByDaya(list, data.studentnumber)->data.age, studentnumberserchInfoByDaya(list, data.studentnumber)->data.birthday,
					studentnumberserchInfoByDaya(list, data.studentnumber)->data.phonenumber, studentnumberserchInfoByDaya(list, data.studentnumber)->data.address, studentnumberserchInfoByDaya(list, data.studentnumber)->data.E_mail);
			}
			break;
		}
			
		
	case 3:
		printf("---------删除信息---------\n");
		printf("请输入删除的学生姓名：");
		scanf("%s", data.name);
		deleteAppointNode(list,data.name);
		printf("删除成功");
		
		break;
	case 4:

		printf("---------修改信息---------\n");
		printf("请输入要修改的学生姓名：");
		scanf("%s", data.name); 
		if (serchInfoByDaya(list, data.name) == NULL)
		{
			printf("未找到要修改的学生信息,请检查后重新输入\n");
		}
		else {
			printf("%s\t%s\t%s", serchInfoByDaya(list, data.name)->data.studentnumber, serchInfoByDaya(list, data.name)->data.name, serchInfoByDaya(list, data.name)->data.sex);
			printf("\t%d\t%s\t%s\t%s\t\t%s\n", serchInfoByDaya(list, data.name)->data.age, serchInfoByDaya(list, data.name)->data.birthday,serchInfoByDaya(list, data.name)->data.phonenumber, serchInfoByDaya(list, data.name)->data.address, serchInfoByDaya(list, data.name)->data.E_mail);
			deleteAppointNode(list, data.name);
			printf("请重新输入修改后的学生信息");
			scanf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s", data.studentnumber, data.name, data.sex, &data.age, data.birthday,data.phonenumber, data.address, data.E_mail);
			insertNodeByHead(list, data);
			printf("修改成功！\n");
		}
		

		break;
	case 5:
		printf("退出系统");
		exit(0);
		break;
	default:
		printf("选择错误，重新输入\n");
		
		break;
		system("pause");
	}
	writeIntofile(list, "1,txt");
}
int main()
{
	int ciper = 1314520;//设置系统密码
	printf("请输入系统密码:");
	scanf("%d", &ciper);
	if (ciper == 1314520) {
		system("cls");
		readInFormFile(list, "1.txt");
		for (;;)
		{
			menu();
			KeyDown();
			system("pause");
			system("cls");
		}
		getchar();
		system("pause");
		return 0;
	}
	printf("密码错误，退出系统\n");
	system("pause");
	return 0;
	
}