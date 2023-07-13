#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	
	char studentnumber[100];
	char name[20];
	char sex[5];
	int age;
	char birthday[50];
	char address[100];
	char phonenumber[50];
	char E_mail[20];

	
	
};
//��������
struct Node//��ͷ
{
	//int data;
	struct student data;
	struct Node* next;
};
struct Node*createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//��̬����
	headNode->next = NULL;
	return headNode;
}
//�����ڵ�
	struct Node* createNode(struct student data)
	{
	struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
	//�����ͷ
	void insertNodeByHead(struct Node* headNode, struct student data)
	{
		struct Node* newNode = createNode(data);

		newNode->next = headNode->next;
		headNode->next = newNode;
	}
//ɾ������
	void deleteAppointNode(struct Node* headNode, char*name)
	{
		struct Node* posNode = headNode->next;
		struct Node* posFrontNode = headNode;
		if(posNode==NULL)
		{
			printf("����Ϊ�գ��޷�ɾ��");//���1
			return;
		}
		for(;strcmp(posNode->data.name,name);)
		{
			posFrontNode = posNode;
			posNode=posFrontNode->next;
			if(posNode==NULL)
			{
				printf("�Ҳ������ݣ��޷�ɾ��");//���2
				return;
			}
		}
		//���3
		posFrontNode->next = posNode->next;
		free(posNode);//�ͷ��ڴ�
		printf("\n");


	}
	
//��������
struct Node*serchInfoByDaya(struct Node*headNode,char*name)//���ֲ���
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
		return NULL;
	if (strcmp(pMove->data.name, name) != 0) {
		return NULL;
	}
	for (; strcmp(pMove->data.name, name);)
	{
		pMove = pMove->next;

	}
	return pMove;

}
struct Node* studentnumberserchInfoByDaya(struct Node* headNode, char* studentnumber)//ѧ�Ų���
{
	struct Node* pMove = headNode->next;
	if (pMove == NULL)
	return NULL;
	if (strcmp(pMove->data.studentnumber, studentnumber) != 0) {
	return NULL;
}
	for (; strcmp(pMove->data.studentnumber, studentnumber);)
	{
		pMove = pMove->next;

	}
	return pMove;

}
	

//��ӡ����
void printList(struct Node*headNode)
{
	struct Node* pMove = headNode->next;
	printf("ѧ��\t\t����\t�Ա�\t����\t��������\t�绰\t\t��ַ\t\t\t�ʼ�\n");
	for (;pMove;) 
	{
		printf("%s\t%s\t%s",pMove->data.studentnumber, pMove->data.name,pMove->data.sex);
		printf(" \t%d\t%s\t%s\t%s\t\t%s\n", pMove->data.age, pMove->data.birthday,pMove->data.phonenumber, pMove->data.address, pMove->data.E_mail);
		pMove = pMove->next;
	}
	printf("\n");
}
//���浽�ļ�
void writeIntofile(struct Node* headNode,const char*fileName)
{
	FILE* fp;
	fp = fopen(fileName, "w");
	struct Node* pMove = headNode->next;
	 while(pMove)
	 {
		 fprintf(fp,"%s\t%s\t%s", pMove->data.studentnumber, pMove->data.name, pMove->data.sex);
		 fprintf(fp, " \t%d\t%s\t%s\t\t%s\t%s\n", pMove->data.age, pMove->data.birthday, pMove->data.phonenumber, pMove->data.address, pMove->data.E_mail);
		 pMove = pMove->next;
		 
	}
	
	
}

//��ȡ�ļ�
void readInFormFile(struct Node* headNode,const char*fileName)
{
	FILE* fp;
	struct student data;
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		fp=fopen(fileName, "w+");
	}
	while (fscanf_s(fp, "%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\n", data.studentnumber, data.name, data.sex, &data.age,data.birthday, data.phonenumber, data.address, data.E_mail) != EOF)
	{
		insertNodeByHead(headNode, data);
	}
	fclose(fp);
}


