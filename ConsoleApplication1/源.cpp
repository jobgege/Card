#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")
#include<mmstream.h>
#include<ctype.h>
#include <stdlib.h>

FILE* fp1;
FILE* fp2;
typedef struct User_basicinfo
{
	char id[11];
	char key[9];
}Users;

typedef struct node1 {
	char user_name[11];
	int k;
	struct node1* next;
}nname;
nname* head11 = NULL;
nname* new_node11;
nname* node1;

typedef struct node2 {
	char user_key[9];
	struct node2* next;
	int k;
}nkey;
nkey* head22 = NULL;
nkey* new_node22;
nkey* node2;


//����ͼƬ��Ϣ

struct azur_line_high_star {
	char name1[100];
	int k1;
	struct azur_line_high_star* next;
};
struct azur_line_high_star* head1 = NULL;
struct azur_line_high_star* new_node1;

struct azur_line_middle_star {
	char name2[100];
	int k2;
	struct azur_line_middle_star* next;
};
struct azur_line_middle_star* head2 = NULL;
struct azur_line_middle_star* new_node2;

struct azur_line_low_star {
	char name3[100];
	int k3;
	struct azur_line_low_star* next;
};
struct azur_line_low_star* head3 = NULL;
struct azur_line_low_star* new_node3;
/////////////////////////////////
/////////////////////////////////
//����������ͼƬ����
struct Genshin_Card_Number
{	
	int danstar3=22;
	int danstar4=8;
	int danstar5=4;
	int star5 = 4;
	int star4 = 8;
	int star3 = 22;
}genshin_num;

struct Bilan_Card_Number
{
	int gold = 7;
	int purple = 13;
	int blue = 30;
}bilan_num;
/////////////////////////////////
struct Minimum_Guarantee
{
	float goldpercentage = 0.5;
	float purplepercentage = 10;

}probability;


struct button
{
	int x;
	int y;
	int width;
	int height;
	COLORREF color;
	char* pText;
};
// ��ʼ����ť������
struct button* createbutton(int x, int y, int width, int height, COLORREF color, const char* pText)
{
	struct button* pB = (struct  button*)malloc(sizeof(struct button));
	pB->x = x;
	pB->y = y;
	pB->width = width;
	pB->height = height;
	pB->color = color;
	pB->pText = (char*)malloc(strlen(pText) + 1);
	strcpy(pB->pText, pText);
	return pB;
}
// ����ť������
void drawButton1(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "����");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 50, pB->y + 15, pB->pText);
}
void drawButton2(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "����");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 35, pB->y + 15, pB->pText);
}
void drawButton3(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(12, 0, "����");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 20, pB->y + 15, pB->pText);
}
void drawButton4(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "����");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 15, pB->y + 15, pB->pText);
}
// �ж�����Ƿ��ڰ�ť��
int mouseInButton(struct button* pB, MOUSEMSG m)
{
	if (pB->x <= m.x && m.x <= pB->x + pB->width && pB->y < m.y && m.y <= pB->height + pB->y)
	{
		pB->color = RED;
		return 1;
	}
	pB->color = YELLOW;
	return 0;
}
// �����ť
int clickButton(struct button* pB, MOUSEMSG m)
{
	if (mouseInButton(pB, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}

int getRandomdan()
{
	int a, seed;
	seed = time(NULL);
	srand(seed * seed);
	a = rand() % 100;
	return a;
}

int getImagenum(int a,int b)
{
	
	int ra;
	b = time(NULL);
	srand(b * b);
	ra = rand() % a;
	return ra;
}

int* bubble_sort(int* nums) {
	int i, j, temp;

	//ð�������㷨������ n-1 �ֱȽ�
	for (i = 0; i < 10 - 1; i++) {
		//ÿһ�ֱȽ�ǰ n-1-i ����Ҳ����˵���Ѿ�����õ���� i �����ñȽ�
		for (j = 0; j < 10 - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}

	return nums;
}


void Zhuce()
{
	int i = 0;
	Users a = {}, b = {};
	FILE* pf = NULL;
	FILE* pff = NULL;
	pf = fopen("users.txt", "r");
	pff = fopen("users1.txt", "a");
	InputBox(a.id, 11, "�������û���(���ܴ���ʮ���ַ���");
	fread(&b.id, 11, 1, pf);
	while (1)
	{

		if (strcmp(a.id, b.id) != 0) {
			if (feof(pf) == 0)
				fread(&b.id, 11, 1, pf);
			else
				break;
		}
		else
		{
			i = 1;
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "���û����Ѿ�ע�����", "��ʾ", MB_OK);
			break;
		}

	}
	if (i != 1)
	{
		InputBox(a.key, 9, "���������루���볤��С��8λ��");
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "ע��ɹ�", "��ʾ", MB_OK);
		pf = NULL;
		pf = fopen("users.txt", "a");
		fwrite(&a.id, 11, 1, pf);
		fwrite(&a.key, 9, 1, pff);
		fclose(pf);
		fclose(pff);
	}

}



int glydenglu(char* a, char* b)
{
	int flag1, flag2;
	char glyname[4] = { "222" };
	char glykey[4] = { "222" };
	flag1 = strcmp(glyname, a);
	flag2 = strcmp(glykey, b);
	if (flag1 == 0 && flag2 == 0) {
		return 0;
	}
	if (flag1 != 0 || flag2 != 0) {
		return 1;
	}
}

int glylogin(int a) {
	int i;

	while (a == 0) {
		initgraph(800, 600);
		char s[11];
		char ss[9];
		InputBox(s, 11, "�������û���");
		InputBox(ss, 9, "����������");
		i = glydenglu(s, ss);
		if (i == 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "��½�ɹ�", "��ʾ", MB_OK);
			return 0;
		}
		if (i != 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "�˺Ż��������", "��ʾ", MB_OK);
			return 1;
		}

	}

}

int comdenglu()
{
	Users a = {}, b = {};
	FILE* pf = fopen("users.txt", "r");
	FILE* pff = fopen("users1.txt", "r");
	if (pf == NULL)
	{
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "��δע���κ��˺�", "��ʾ", MB_OK);
		return -1;
	}
	InputBox(a.id, 11, "�������û���");
	fread(&b.id, 11, 1, pf);
	fread(&b.key, 9, 1, pff);
	while (1)
	{
		if (strcmp(a.id, b.id) != 0)
		{
			if (feof(pf) == 0)//δ���ļ�β 
			{
				fread(&b.id, 11, 1, pf);
				fread(&b.key, 9, 1, pff);
			}
			else
			{
				HWND hndtipsD = GetHWnd();
				int isok = MessageBox(hndtipsD, "��δע��,����ע��", "��ʾ", MB_OK);
				fclose(pf);
				pf = NULL;
				return -1;
			}
		}
		else//�˺�ע���->������������ 
		{
			break; //�˳�����ѭ���������������� 
		}

	}
	;
	do {
		InputBox(a.key, 9, "����������");
		if (strcmp(a.key, b.key) != 0)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "�����������������", "��ʾ", MB_OK);
		}
		if (strcmp(a.key, b.key) == 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "��½�ɹ�", "��ʾ", MB_OK);
			return 0;
		}

	} while (1);
	fclose(pf);
	fclose(pff);
}


//�鿨����
int judgeYuanShen(int a, float purple, float gold)
{
	if (a < (100 - gold - purple)) {
		return 0;
	}
	if (a >= (100 - gold - purple) && a < (100 - gold)) {
		return 1;
	}
	if (a >= (100 - gold))
	{
		return 2;
	}
}

//�鿨����
int judgeBiLan(int a)
{
	if (a < 70) {
		return 0;
	}
	if (a >= 70 && a < 95) {
		return 1;
	}
	if (a >= 95)
	{
		return 2;
	}
}


int az_high_star()

{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;
	char* b;

	fp = fopen("bilangold.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head1 = (struct azur_line_high_star*)malloc(sizeof(struct azur_line_high_star));
	head1->next = NULL;
	new_node1 = head1;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{


		strcpy(new_node1->name1, c);

		(*new_node1).k1 = i++;
		new_node1->next = (struct azur_line_high_star*)malloc(sizeof(struct azur_line_high_star));
		new_node1 = new_node1->next;
		new_node1->next = NULL;
	} // ���ļ������ݶ���������
	struct azur_line_high_star* p1 = head1;
	while (p1->next != NULL)
	{
		printf("SSR      ");
		printf("%s", p1->name1);


		p1 = p1->next;
	}
	printf("\n");
	fclose(fp);
}

struct ys_high_star {
	char name4[100];
	int k4;
	struct ys_high_star* next;
};
struct ys_high_star* head4 = NULL;
struct ys_high_star* new_node4;

struct ys_middle_star {
	char name5[100];
	int k5;
	struct ys_middle_star* next;
};
struct ys_middle_star* head5 = NULL;
struct ys_middle_star* new_node5;

struct ys_low_star {
	char name6[100];
	int k6;
	struct ys_low_star* next;
};
struct ys_low_star* head6 = NULL;
struct ys_low_star* new_node6;

int yuans_high_star()

{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;

	fp = fopen("yuans5.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head4 = (struct ys_high_star*)malloc(sizeof(struct ys_high_star));
	head4->next = NULL;
	new_node4 = head4;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node4->name4, a);
		(*new_node4).k4 = i++;
		new_node4->next = (struct ys_high_star*)malloc(sizeof(struct ys_high_star));
		new_node4 = new_node4->next;
		new_node4->next = NULL;

	} // ���ļ������ݶ���������
	struct ys_high_star* p4 = head4;
	while (p4->next != NULL)
	{
		printf("��   ");
		printf("%s", p4->name4);
		p4 = p4->next;
	}
	printf("\n");
	fclose(fp);
}//i����������ﶫ���ĸ��������ڶ��β����������Χ 

int yuans_middle_star()
{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;
	fp = fopen("yuans4.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head5 = (struct ys_middle_star*)malloc(sizeof(struct ys_middle_star));
	head5->next = NULL;
	new_node5 = head5;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node5->name5, a);
		(*new_node5).k5 = i++;
		new_node5->next = (struct ys_middle_star*)malloc(sizeof(struct ys_middle_star));
		new_node5 = new_node5->next;
		new_node5->next = NULL;
	} // ���ļ������ݶ���������
	struct ys_middle_star* p5 = head5;
	while (p5->next != NULL)
	{
		printf("��   ");
		printf("%s", p5->name5);
		p5 = p5->next;
	}
	printf("\n");
	fclose(fp);
}

int yuans_low_star()
{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;
	fp = fopen("yuans3.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head6 = (struct ys_low_star*)malloc(sizeof(struct ys_low_star));
	head6->next = NULL;
	new_node6 = head6;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node6->name6, a);
		(*new_node6).k6 = i++;
		new_node6->next = (struct ys_low_star*)malloc(sizeof(struct ys_low_star));
		new_node6 = new_node6->next;
		new_node6->next = NULL;
	} // ���ļ������ݶ���������
	struct ys_low_star* p6 = head6;
	while (p6->next != NULL)
	{
		printf("��   ");
		printf("%s", p6->name6);
		p6 = p6->next;
	}
	printf("\n");
	fclose(fp);
}


int az_middle_star()
{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;
	char* b;
	fp = fopen("bilanpurple.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head2 = (struct azur_line_middle_star*)malloc(sizeof(struct azur_line_middle_star));
	head2->next = NULL;
	new_node2 = head2;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{
		strcpy(new_node2->name2, c);
		(*new_node2).k2 = i++;
		new_node2->next = (struct azur_line_middle_star*)malloc(sizeof(struct azur_line_middle_star));
		new_node2 = new_node2->next;
		new_node2->next = NULL;
	} // ���ļ������ݶ���������

	struct azur_line_middle_star* p2 = head2;
	while (p2->next != NULL)
	{
		printf("SR       ");
		printf("%s", p2->name2);

		p2 = p2->next;
	}
	printf("\n");
	fclose(fp);
}

int az_low_star()
{
	FILE* fp;
	char c[100];
	int i = 0;
	char FileName[30];
	char* a;
	char* b;
	fp = fopen("bilanblue.txt", "r");
	if (fp == NULL)
	{
		printf("Can not open file successfully!\n");
		return 0;
	} //���û�гɹ����ļ����˳����� 

	head3 = (struct azur_line_low_star*)malloc(sizeof(struct azur_line_low_star));
	head3->next = NULL;
	new_node3 = head3;  //����ĳ�ʼ�� 
	while (fgets(c, 100, fp) != NULL)
	{
		strcpy(new_node3->name3, c);
		(*new_node3).k3 = i++;
		new_node3->next = (struct azur_line_low_star*)malloc(sizeof(struct azur_line_low_star));
		new_node3 = new_node3->next;
		new_node3->next = NULL;
	} // ���ļ������ݶ���������
	struct azur_line_low_star* p3 = head3;
	while (p3->next != NULL)
	{
		printf("R        ");
		printf("%s", p3->name3);

		p3 = p3->next;
	}
	fclose(fp);
}

int introduce() {
	
	printf("\t\t\t\t*********************************************************\n");
	printf("\t\t\t\t|     ������Ŀ��Ϊģ����Ϸ�еĳ鿨����������ŷ��      |\n");
	Sleep(400);
	printf("\t\t\t\t|   �û���ע��ſɽ���ϵͳ��ÿ�ε�¼ӵ��100�γ鿨����   |\n");
	Sleep(400);
	printf("\t\t\t\t|  ��ԭ��ģ��ϵͳ�У�������ʻ����ų鿨���������Ӷ����� |\n");
	Sleep(400);
	printf("\t\t\t\t|    ���鿨�����ﵽ80�λ�δ���������81�α��׳���     |\n");
	Sleep(400);
	printf("\t\t\t\t|                   ϣ�����кõ�����                    |\n");
	Sleep(400);
	printf("\t\t\t\t|       ����Ϸ�����Ŷӣ�����    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       �½���    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       ������    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       ͯ���    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       ����    \t\t\t\t|\n");
	Sleep(200);  
	printf("\t\t\t\t|                       ����    \t\t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t*********************************************************\n");
	Sleep(10000);
	system("cls");
	return 0;
}

int main()
{
	initgraph(800, 600);
	//���ø�����Ƴ鿨���������Ƿ񱣵�
	int chounum = 0;
	int flag = 0;

	int iNum = 1;
	int ju = 0;
	int juju = 0;
	int jujuju = 0;
	int i = 0;
	int remainTimes = 100;
	char cNum = 'A';
	int seed = time(NULL);
	IMAGE mm, nn, nnn;
	loadimage(&mm, "background.jpg", 800, 600);
	int save;
	//save��������鵽�����û���returnֵ
	int save_[10];
	//*save_��������ʮ�������ĺû�
	int imasave;
	//imasave�������������ͼƬ·��
	int imasave_[10];
	int imasave_1[10];
	//*imasave_������ʮ���������ͼƬ·��
	int imaamount;
	//imaamount������ͼƬ����
	int imaamount_[10];
	//imaamount_������ʮ���������ͼƬ����
	char path_[10][60] = {};//��ʽ��֮���·��	
	struct button* dan = createbutton(200, 400, 180, 60, YELLOW, "����");
	struct button* shi = createbutton(400, 400, 180, 60, YELLOW, "ʮ����");
	struct button* quit = createbutton(500, 520, 100, 40, YELLOW, "�˳��鿨ϵͳ");
	struct button* bilian = createbutton(200, 300, 180, 60, YELLOW, "��������");
	struct button* yuanshen = createbutton(400, 300, 180, 60, YELLOW, "ԭ��");
	struct button* denglu = createbutton(200, 300, 180, 60, YELLOW, "��¼");
	struct button* yhdenglu = createbutton(150, 300, 200, 60, YELLOW, "�û���¼");
	struct button* zhuce = createbutton(300, 400, 200, 60, YELLOW, "�û�ע��");
	struct button* glydenglu = createbutton(400, 300, 250, 60, YELLOW, "����Ա��¼");
	struct button* glysystem1 = createbutton(100, 200, 250, 60, YELLOW, "���ӽ�ɫ(ԭ��");
	struct button* glysystem3 = createbutton(100, 400, 250, 60, YELLOW, "���ĸ���(ԭ��");
	struct button* re1 = createbutton(400, 400, 250, 60, YELLOW, "���س�ʼ����");
	struct button* glysystem4 = createbutton(400, 200, 250, 60, YELLOW, "���ӽ�ɫ(������");
	struct button* re = createbutton(500, 520, 100, 40, YELLOW, "����");
	struct button* kachi = createbutton(400, 520, 100, 40, YELLOW, "�鿴����");
	struct button* introducee = createbutton(400, 300, 180, 60, YELLOW, "�������");
//	struct button* records = createbutton(300, 520, 100, 40, YELLOW, "��ʷ��¼");
loop1:while (ju == 0)
{
	BeginBatchDraw();
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);
	drawButton1(denglu);
	drawButton2(introducee);
	if (clickButton(denglu, m))
	{
		ju = 3;
	}
	if (clickButton(introducee, m))
	{
		introduce();
	}
	EndBatchDraw();
}
loop2:while (ju == 3) {
BeginBatchDraw();
MOUSEMSG m = GetMouseMsg();
putimage(0, 0, &mm);
drawButton2(yhdenglu);
drawButton2(glydenglu);
drawButton2(zhuce);
if (clickButton(yhdenglu, m))
{
	int flag_com;

	flag_com = comdenglu();
	if (flag_com == 0) {
		ju = 1;
	}
	if (flag_com != 0) {

	}
}
if (clickButton(glydenglu, m))
{
	int flag_gly;
	flag_gly = glylogin(jujuju);
	if (flag_gly == 0) {
		ju = 4;
	}
	if (flag_gly != 0) {

	}
}
if (clickButton(zhuce, m))
{
	Zhuce();
}
EndBatchDraw();
}
loop3:while (ju == 1)
{
	BeginBatchDraw();
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);
	drawButton4(bilian);
	drawButton1(yuanshen);
	if (clickButton(bilian, m))
	{
		ju = 2;
		juju = 1;
	}
	if (clickButton(yuanshen, m))
	{
		ju = 2;
		juju = 2;
	}
	EndBatchDraw();
}
loop4:while (ju == 2)
{
	BeginBatchDraw();
	mciSendString("open 1.mp3", 0, 0, 0);
	mciSendString("play 1.mp3", 0, 0, 0);
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);
	drawButton1(dan);
	drawButton2(shi);
	drawButton3(quit);
	drawButton3(kachi);
	//drawButton3(records);
	if (clickButton(dan, m))
	{
		int danchou;
		danchou = getRandomdan();
		remainTimes = remainTimes - 1;
		
		if (remainTimes < 0)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "�鿨��������", "��ʾ", MB_OK);
		}
		

		else {
			if (juju == 1) {
				save = judgeBiLan(danchou);
				int seed = time(NULL);
				srand(seed * seed);
				switch (save) {
					
				case 0:imasave = rand() % bilan_num.blue;
					break;
				case 1:imasave = rand() % bilan_num.purple;
					break;
				case 2:imasave = rand() % bilan_num.gold;
					break;
				}
			}
				//��ʱ��õ�һ��С��ͼƬ����������

			
			if (juju == 2) {
				save = judgeYuanShen(danchou, probability.purplepercentage, probability.goldpercentage);
				probability.purplepercentage += 0.05;
				probability.goldpercentage += 0.05;
				chounum++;
				if (save == 2 && flag == 0) {
					flag = 1;
				}
				if (save_[i] == 2 && flag == 1)
					probability.goldpercentage -= 0.5;
				//�鵽��󽵵ͳ鿨����
				if (chounum > 80 && flag == 0) {
					save = 2;
					flag = 1;
				}
				switch (save) {

				case 0:imasave = rand() % genshin_num.danstar3;
					break;
				case 1:imasave = rand() % genshin_num.danstar4;
					break;
				case 2:imasave = rand() % genshin_num.danstar5;
					break;
				}
			}

			//��ʱ��õ�һ��С��ͼƬ����������
			///////////////////////////////////////////////////////////////////////////////����û�ģ�������///////////////////
			ju = 5;
		}
	}
	int seed = time(NULL);
	if (clickButton(shi, m))
	{

		remainTimes = remainTimes - 10;
		if (remainTimes < 0)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "�鿨��������", "��ʾ", MB_OK);

		}
		else
		{
		
			int seed1 = time(NULL);
			for (i = 0; i < 10; i++) {
				srand(seed1 * seed1);
				save_[i] = rand() % 100;
				seed1 = seed1 * 2 + 10;
			}
			if (juju == 1) {//����
				srand(seed* seed);
				for (i = 0; i < 10; i++)
				{
					
					save_[i] = judgeBiLan(save_[i]);
					switch (save_[i]){
						
					case 0:imaamount_[i] = rand() % bilan_num.blue;
						break;
					case 1:imaamount_[i] = rand() % bilan_num.purple;
						break;
					case 2:imaamount_[i] = rand() % bilan_num.gold;
						break;
					}
					
					

				}//������10����Ʒ�ĺû�012

			}
			if (juju == 2) {//ԭ��
				srand(seed * seed);
				for (i = 0; i < 10; i++)
				{	//���Ӹ���
					probability.purplepercentage += 0.05;
					probability.goldpercentage += 0.05;
					save_[i] = judgeYuanShen(save_[i], probability.purplepercentage, probability.goldpercentage);
					chounum++;

					if (save_[i] == 2 && flag == 0)
						flag = 1;//�鵽���ȡ������
					if (save_[i] == 2 && flag == 1)
						probability.goldpercentage -= 0.5;
					//�鵽��󽵵ͳ鿨����
					if (chounum > 80 && flag == 0) {
						save_[i] = 2;
						flag = 1;
					}
					///////////////////////////////////////////////////��save_[i]����/////////////////////////////////////////////////////////////
					int* p = save_;
					p = bubble_sort(save_);

					switch (save_[i]) {

					case 0:imaamount_[i] = rand() % genshin_num.star3;
						break;
					case 1:imaamount_[i] = rand() % genshin_num.star4;
						break;
					case 2:imaamount_[i] = rand() % genshin_num.star5;
						break;

					}
				}//������10����Ʒ�ĺû�012
			}

			
			ju = 6;
		}
	}
	if (clickButton(kachi, m)&&juju ==1)
	{
		az_high_star();
		az_middle_star();
		az_low_star();
	}
	if (clickButton(kachi, m)&& juju ==2)
	{
		yuans_high_star();
		yuans_middle_star();
		yuans_low_star();
	}
	if (clickButton(quit, m))
	{
		exit(-1);
	}
	
	//if (clickButton(records, m))
	//{
    //printrecord_ar();
	//}
	EndBatchDraw();
}
loop5:while (ju == 4)
{
	BeginBatchDraw();
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);
	drawButton4(glysystem1);
	drawButton4(re1);
	drawButton4(glysystem3);
	drawButton4(glysystem4);
	if (clickButton(glysystem1, m))
	{
		char str11[10], str21[2];
		int starss1;
		FILE* fp;
		InputBox(str11, 10, "��������ӽ�ɫ������");
		InputBox(str21, 2, "�������ɫ���Ǽ�");
		starss1 = strcmp(str21, "4");
		if (starss1 > 0)
		{
			fp = fopen("yuans5.txt", "a");
			fprintf(fp, "\n%s", str11);

		}
		if (starss1 == 0)
		{
			fp = fopen("yuans4.txt", "a");
			fprintf(fp, "\n%s", str11);
		}
		if (starss1 < 0)
		{
			fp = fopen("yuans3.txt", "a");
			fprintf(fp, "\n%s", str11);
		}
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "��ӳɹ�", "��ʾ", MB_OK);
	}
	//�ĸ���
	if (clickButton(glysystem3,m))
	{
		char percentyuan[3]; float percent;
		InputBox(percentyuan, 3, "�������޸ĺ�������(1~10)(��λΪ%)");
		percent = atoi(percentyuan);
		if (percent <= 10)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "���ĳɹ�", "��ʾ", MB_OK);
			probability.goldpercentage = percent;
		}
		else {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "�������", "��ʾ", MB_OK);
		}
			
	}
	if (clickButton(glysystem4,m))
	{
		char str12[10], str22[8]; 
		FILE* fp;
		InputBox(str12, 10, "��������ӽ�ɫ������");
		InputBox(str22, 8, "�������ɫ��Ʒ�ʣ���ɫ��");
		if (strcmp(str22, "blue") == 0)
		{
			fp = fopen("bilan1.txt", "a");
			fprintf(fp, "\n%s", str12);
			bilan_num.blue++;
		}
		if (strcmp(str22, "purple") == 0)
		{
			fp = fopen("bilan2.txt", "a");
			fprintf(fp, "\n%s", str12);
			bilan_num.purple++;
		}
		if (strcmp(str22, "gold") == 0)
		{
			fp = fopen("bilan3.txt", "a");
			fprintf(fp, "\n%s", str12);
			bilan_num.gold++;
		}
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "��ӳɹ�", "��ʾ", MB_OK);
	}
	/////////////////////////////////////////////////////////fanhuianniu////////////
	drawButton4(re1);
	if (clickButton(re1, m))
	{
		putimage(0, 0, &mm);
		ju = 0;
		goto loop1;
	}
	////////////////////////////////////////////////////////////////////////////////////
	EndBatchDraw();
}
while (ju == 5)
{
	BeginBatchDraw();
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);

	if (juju == 1) {
		if (save == 0) {
			char path[50] = { 0 };//��ʽ��֮���·��
			sprintf_s(path, "bilanblue/bilian%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
		if (save == 1) {
			char path[50] = { 0 };//��ʽ��֮���·��
			sprintf_s(path, "bilanpurple/bilan%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
		if (save == 2) {
			char path[50] = { 0 };//��ʽ��֮���·��
			sprintf_s(path, "bilangold/bilan%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
	}

		if (juju == 2) {
			if (save == 0) {
				char path[50] = { 0 };//��ʽ��֮���·��
				sprintf_s(path, "genshindan/genshin3star/genshin%d.jpg", imasave);
				loadimage(&nn, path, 800, 600);
				putimage(0, 0, &nn);
			}
			if (save == 1) {
				char path[50] = { 0 };//��ʽ��֮���·��
				sprintf_s(path, "genshindan/genshin4star/genshin%d.png", imasave);
				loadimage(&nn, path, 800, 600);
				putimage(0, 0, &nn);
			}
			if (save == 2) {
				char path[50] = { 0 };//��ʽ��֮���·��
				sprintf_s(path, "genshindan/genshin5star/genshin%d.jpg", imasave);
				loadimage(&nn, path, 800, 600);
				putimage(0, 0, &nn);
			}
		}

		drawButton3(re);
		if (clickButton(re, m))
		{
			putimage(0, 0, &mm);
			ju = 2;
			goto loop4;
		}
		EndBatchDraw();

	}
while (ju == 6)
{
	BeginBatchDraw();
	MOUSEMSG m = GetMouseMsg();
	putimage(0, 0, &mm);

	if (juju == 1) {
		for (i = 0; i < 10; i++)
		{
			for (i = 0; i < 10; i++)
			{


				if (save_[i] == 0) {
					sprintf_s(path_[i], "bilanblue/bilian%d.png", imaamount_[i]);
				}
				else if (save_[i] == 1) {
					sprintf_s(path_[i], "bilanpurple/bilan%d.png", imaamount_[i]);
				}
				else if (save_[i] == 2) {
					sprintf_s(path_[i], "bilangold/bilan%d.png", imaamount_[i]);
				}
			}
			for (i = 0; i < 10; i++) {
				loadimage(&nnn, path_[i], 160, 300);
				if (i < 5)
					putimage(160 * i, 0, &nnn);
				else
					putimage(160 * (i - 5), 300, &nnn);
			}

		}
	}
	if (juju == 2) {

		for (i = 0; i < 10; i++)
		{
			if (save_[i] == 0) {
				sprintf_s(path_[i], "genshin10lian/genshin3star/genshin%d.png", imaamount_[i]);
			}
			else if (save_[i] == 1) {
				sprintf_s(path_[i], "genshin10lian/genshin4star/genshin%d.png", imaamount_[i]);
			}
			else if (save_[i] == 2) {
				sprintf_s(path_[i], "genshin10lian/genshin5star/genshin%d.png", imaamount_[i]);
			}
			//else
				//sprintf_s(path_[i], "genshin10lian/genshin3star/genshin5.png");
		}
		for (i = 0; i < 10; i++) {
			loadimage(&nnn, path_[i], 80, 600);
			putimage(80 * i, 0, &nnn);
		}

	}

	drawButton4(re);
	if (clickButton(re, m))
	{
		putimage(0, 0, &mm);
		ju = 2;
		goto loop4;
	}
		//�ǵøĵ�ַ

		//10��ͼƬ������ʾ
			//sprintf_s(path_[1], "genshin10lian/genshin3star/genshin%d.png",1);
			//sprintf_s(path_[2], "genshin10lian/genshin3star/genshin%d.png",2);

		EndBatchDraw();
	
}
	closegraph();
	return 0;
}

