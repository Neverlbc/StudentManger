#define _CRT_SECURE_NO_WARNINGS//���scanf����
#include<stdio.h>
#include<stdlib.h>
#include"sudentsystem.h"

void menu() //�˵�
{
	printf("               ѧ����Ϣ����ϵͳ\n");
	printf("*****************************************\n");
	printf("\t\t0.¼����Ϣ	   ******\n");
	printf("\t\t1.�����Ϣ	   ******\n");
	printf("\t\t2.������Ϣ	   ******\n");
	printf("\t\t3.ɾ����Ϣ	   ******\n");
	printf("\t\t4.�޸���Ϣ	   ******\n");
	printf("\t\t5.�˳�ϵͳ	   ******\n");
	printf("*****************************************\n");
	printf("���������ѡ��");


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
		printf("---------¼����Ϣ---------\n");
		printf("������ѧ��ѧ��,����,�Ա�,����,�������ڣ��绰,��ַ,�ʼ�\n");
		fflush(stdin);
		scanf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s", data.studentnumber,data.name,data.sex ,& data.age, data.birthday,data.phonenumber, data.address, data.E_mail);
		insertNodeByHead(list, data);

		break;
	case 1:
		printf("---------�����Ϣ---------\n");
		printList(list);//��ӡ����
		break;
	case 2:
		printf("---------������Ϣ---------\n");
		int way;
		printf("���ҷ�ʽ 1.����������\n\t2.��ѧ�Ų���");
		scanf("%d", &way);
		if (way == 1) {
			printf("������Ҫ���ҵ�ѧ��������");
			scanf("%s", data.name);
			if (serchInfoByDaya(list, data.name) == NULL)
			{
				printf("δ�ҵ�Ҫ���ҵ�ѧ����Ϣ\n");
			}
			else {
				printf("ѧ��\t\t����\t�Ա�\t����\t��������\t�绰\t\t��ַ\t\t\t�ʼ�\n");
				printf("%s\t%s\t%s", serchInfoByDaya(list, data.name)->data.studentnumber, serchInfoByDaya(list, data.name)->data.name, serchInfoByDaya(list, data.name)->data.sex);
				printf("\t%d\t%s\t%s\t%s\t\t%s\n", serchInfoByDaya(list, data.name)->data.age, serchInfoByDaya(list, data.name)->data.birthday, serchInfoByDaya(list, data.name)->data.phonenumber, serchInfoByDaya(list, data.name)->data.address, serchInfoByDaya(list, data.name)->data.E_mail);
			}
			break;
		}else {
			printf("������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
			scanf("%s", data.studentnumber);
			if (studentnumberserchInfoByDaya(list, data.studentnumber) == NULL)
			{
				printf("δ�ҵ�Ҫ���ҵ�ѧ����Ϣ\n");
			}
			else {
				printf("ѧ��\t\t����\t�Ա�\t����\t��������\t�绰\t\t��ַ\t\t\t�ʼ�\n");
				printf("%s\t%s\t%s", studentnumberserchInfoByDaya(list, data.studentnumber)->data.studentnumber, studentnumberserchInfoByDaya(list, data.studentnumber)->data.name, studentnumberserchInfoByDaya(list, data.studentnumber)->data.sex);
				printf("\t%d\t%s\t%s\t%s\t\t%s\n", studentnumberserchInfoByDaya(list, data.studentnumber)->data.age, studentnumberserchInfoByDaya(list, data.studentnumber)->data.birthday,
					studentnumberserchInfoByDaya(list, data.studentnumber)->data.phonenumber, studentnumberserchInfoByDaya(list, data.studentnumber)->data.address, studentnumberserchInfoByDaya(list, data.studentnumber)->data.E_mail);
			}
			break;
		}
			
		
	case 3:
		printf("---------ɾ����Ϣ---------\n");
		printf("������ɾ����ѧ��������");
		scanf("%s", data.name);
		deleteAppointNode(list,data.name);
		printf("ɾ���ɹ�");
		
		break;
	case 4:

		printf("---------�޸���Ϣ---------\n");
		printf("������Ҫ�޸ĵ�ѧ��������");
		scanf("%s", data.name); 
		if (serchInfoByDaya(list, data.name) == NULL)
		{
			printf("δ�ҵ�Ҫ�޸ĵ�ѧ����Ϣ,�������������\n");
		}
		else {
			printf("%s\t%s\t%s", serchInfoByDaya(list, data.name)->data.studentnumber, serchInfoByDaya(list, data.name)->data.name, serchInfoByDaya(list, data.name)->data.sex);
			printf("\t%d\t%s\t%s\t%s\t\t%s\n", serchInfoByDaya(list, data.name)->data.age, serchInfoByDaya(list, data.name)->data.birthday,serchInfoByDaya(list, data.name)->data.phonenumber, serchInfoByDaya(list, data.name)->data.address, serchInfoByDaya(list, data.name)->data.E_mail);
			deleteAppointNode(list, data.name);
			printf("�����������޸ĺ��ѧ����Ϣ");
			scanf("%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s", data.studentnumber, data.name, data.sex, &data.age, data.birthday,data.phonenumber, data.address, data.E_mail);
			insertNodeByHead(list, data);
			printf("�޸ĳɹ���\n");
		}
		

		break;
	case 5:
		printf("�˳�ϵͳ");
		exit(0);
		break;
	default:
		printf("ѡ�������������\n");
		
		break;
		system("pause");
	}
	writeIntofile(list, "1,txt");
}
int main()
{
	int ciper = 1314520;//����ϵͳ����
	printf("������ϵͳ����:");
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
	printf("��������˳�ϵͳ\n");
	system("pause");
	return 0;
	
}