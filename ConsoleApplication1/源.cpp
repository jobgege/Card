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


//保存图片信息

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
//声明卡池中图片数量
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
// 初始化按钮的属性
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
// 画按钮：矩形
void drawButton1(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "宋体");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 50, pB->y + 15, pB->pText);
}
void drawButton2(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "宋体");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 35, pB->y + 15, pB->pText);
}
void drawButton3(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(12, 0, "宋体");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 20, pB->y + 15, pB->pText);
}
void drawButton4(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "宋体");
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 15, pB->y + 15, pB->pText);
}
// 判断鼠标是否在按钮内
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
// 点击按钮
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

	//冒泡排序算法：进行 n-1 轮比较
	for (i = 0; i < 10 - 1; i++) {
		//每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
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
	InputBox(a.id, 11, "请输入用户名(不能大于十个字符）");
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
			int isok = MessageBox(hndtipsD, "该用户名已经注册过了", "提示", MB_OK);
			break;
		}

	}
	if (i != 1)
	{
		InputBox(a.key, 9, "请输入密码（密码长度小于8位）");
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "注册成功", "提示", MB_OK);
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
		InputBox(s, 11, "请输入用户名");
		InputBox(ss, 9, "请输入密码");
		i = glydenglu(s, ss);
		if (i == 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "登陆成功", "提示", MB_OK);
			return 0;
		}
		if (i != 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "账号或密码错误", "提示", MB_OK);
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
		int isok = MessageBox(hndtipsD, "尚未注册任何账号", "提示", MB_OK);
		return -1;
	}
	InputBox(a.id, 11, "请输入用户名");
	fread(&b.id, 11, 1, pf);
	fread(&b.key, 9, 1, pff);
	while (1)
	{
		if (strcmp(a.id, b.id) != 0)
		{
			if (feof(pf) == 0)//未到文件尾 
			{
				fread(&b.id, 11, 1, pf);
				fread(&b.key, 9, 1, pff);
			}
			else
			{
				HWND hndtipsD = GetHWnd();
				int isok = MessageBox(hndtipsD, "尚未注册,请先注册", "提示", MB_OK);
				fclose(pf);
				pf = NULL;
				return -1;
			}
		}
		else//账号注册过->跳到输入密码 
		{
			break; //退出无限循环，跳到输入密码 
		}

	}
	;
	do {
		InputBox(a.key, 9, "请输入密码");
		if (strcmp(a.key, b.key) != 0)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "密码错误，请重新输入", "提示", MB_OK);
		}
		if (strcmp(a.key, b.key) == 0) {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "登陆成功", "提示", MB_OK);
			return 0;
		}

	} while (1);
	fclose(pf);
	fclose(pff);
}


//抽卡概率
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

//抽卡概率
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
	} //如果没有成功打开文件则退出程序 

	head1 = (struct azur_line_high_star*)malloc(sizeof(struct azur_line_high_star));
	head1->next = NULL;
	new_node1 = head1;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{


		strcpy(new_node1->name1, c);

		(*new_node1).k1 = i++;
		new_node1->next = (struct azur_line_high_star*)malloc(sizeof(struct azur_line_high_star));
		new_node1 = new_node1->next;
		new_node1->next = NULL;
	} // 把文件的数据读入链表中
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
	} //如果没有成功打开文件则退出程序 

	head4 = (struct ys_high_star*)malloc(sizeof(struct ys_high_star));
	head4->next = NULL;
	new_node4 = head4;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node4->name4, a);
		(*new_node4).k4 = i++;
		new_node4->next = (struct ys_high_star*)malloc(sizeof(struct ys_high_star));
		new_node4 = new_node4->next;
		new_node4->next = NULL;

	} // 把文件的数据读入链表中
	struct ys_high_star* p4 = head4;
	while (p4->next != NULL)
	{
		printf("金   ");
		printf("%s", p4->name4);
		p4 = p4->next;
	}
	printf("\n");
	fclose(fp);
}//i是这个链表里东西的个数，即第二次产生随机数范围 

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
	} //如果没有成功打开文件则退出程序 

	head5 = (struct ys_middle_star*)malloc(sizeof(struct ys_middle_star));
	head5->next = NULL;
	new_node5 = head5;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node5->name5, a);
		(*new_node5).k5 = i++;
		new_node5->next = (struct ys_middle_star*)malloc(sizeof(struct ys_middle_star));
		new_node5 = new_node5->next;
		new_node5->next = NULL;
	} // 把文件的数据读入链表中
	struct ys_middle_star* p5 = head5;
	while (p5->next != NULL)
	{
		printf("紫   ");
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
	} //如果没有成功打开文件则退出程序 

	head6 = (struct ys_low_star*)malloc(sizeof(struct ys_low_star));
	head6->next = NULL;
	new_node6 = head6;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{
		a = c;
		strcpy(new_node6->name6, a);
		(*new_node6).k6 = i++;
		new_node6->next = (struct ys_low_star*)malloc(sizeof(struct ys_low_star));
		new_node6 = new_node6->next;
		new_node6->next = NULL;
	} // 把文件的数据读入链表中
	struct ys_low_star* p6 = head6;
	while (p6->next != NULL)
	{
		printf("蓝   ");
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
	} //如果没有成功打开文件则退出程序 

	head2 = (struct azur_line_middle_star*)malloc(sizeof(struct azur_line_middle_star));
	head2->next = NULL;
	new_node2 = head2;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{
		strcpy(new_node2->name2, c);
		(*new_node2).k2 = i++;
		new_node2->next = (struct azur_line_middle_star*)malloc(sizeof(struct azur_line_middle_star));
		new_node2 = new_node2->next;
		new_node2->next = NULL;
	} // 把文件的数据读入链表中

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
	} //如果没有成功打开文件则退出程序 

	head3 = (struct azur_line_low_star*)malloc(sizeof(struct azur_line_low_star));
	head3->next = NULL;
	new_node3 = head3;  //链表的初始化 
	while (fgets(c, 100, fp) != NULL)
	{
		strcpy(new_node3->name3, c);
		(*new_node3).k3 = i++;
		new_node3->next = (struct azur_line_low_star*)malloc(sizeof(struct azur_line_low_star));
		new_node3 = new_node3->next;
		new_node3->next = NULL;
	} // 把文件的数据读入链表中
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
	printf("\t\t\t\t|     本程序目的为模拟游戏中的抽卡，来检测你的欧气      |\n");
	Sleep(400);
	printf("\t\t\t\t|   用户需注册才可进入系统，每次登录拥有100次抽卡机会   |\n");
	Sleep(400);
	printf("\t\t\t\t|  在原神模拟系统中，出金概率会随着抽卡次数的增加而增加 |\n");
	Sleep(400);
	printf("\t\t\t\t|    当抽卡次数达到80次还未出金，则会在81次保底出金     |\n");
	Sleep(400);
	printf("\t\t\t\t|                   希望您有好的体验                    |\n");
	Sleep(400);
	printf("\t\t\t\t|       本游戏制作团队：丁润东    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       陈江涛    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       刘丰恺    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       童鸿睿    \t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t|                       加祥    \t\t\t\t|\n");
	Sleep(200);  
	printf("\t\t\t\t|                       江博    \t\t\t\t|\n");
	Sleep(200);
	printf("\t\t\t\t*********************************************************\n");
	Sleep(10000);
	system("cls");
	return 0;
}

int main()
{
	initgraph(800, 600);
	//重置概率与计抽卡数变量与是否保底
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
	//save用来保存抽到东西好坏的return值
	int save_[10];
	//*save_用来保存十连东西的好坏
	int imasave;
	//imasave用来存随机到的图片路径
	int imasave_[10];
	int imasave_1[10];
	//*imasave_用来存十连随机到的图片路径
	int imaamount;
	//imaamount用来存图片数量
	int imaamount_[10];
	//imaamount_用来存十连随机到的图片数量
	char path_[10][60] = {};//格式化之后的路径	
	struct button* dan = createbutton(200, 400, 180, 60, YELLOW, "单抽");
	struct button* shi = createbutton(400, 400, 180, 60, YELLOW, "十连抽");
	struct button* quit = createbutton(500, 520, 100, 40, YELLOW, "退出抽卡系统");
	struct button* bilian = createbutton(200, 300, 180, 60, YELLOW, "碧蓝航线");
	struct button* yuanshen = createbutton(400, 300, 180, 60, YELLOW, "原神");
	struct button* denglu = createbutton(200, 300, 180, 60, YELLOW, "登录");
	struct button* yhdenglu = createbutton(150, 300, 200, 60, YELLOW, "用户登录");
	struct button* zhuce = createbutton(300, 400, 200, 60, YELLOW, "用户注册");
	struct button* glydenglu = createbutton(400, 300, 250, 60, YELLOW, "管理员登录");
	struct button* glysystem1 = createbutton(100, 200, 250, 60, YELLOW, "增加角色(原神）");
	struct button* glysystem3 = createbutton(100, 400, 250, 60, YELLOW, "更改概率(原神）");
	struct button* re1 = createbutton(400, 400, 250, 60, YELLOW, "返回初始界面");
	struct button* glysystem4 = createbutton(400, 200, 250, 60, YELLOW, "增加角色(碧蓝）");
	struct button* re = createbutton(500, 520, 100, 40, YELLOW, "返回");
	struct button* kachi = createbutton(400, 520, 100, 40, YELLOW, "查看卡池");
	struct button* introducee = createbutton(400, 300, 180, 60, YELLOW, "程序介绍");
//	struct button* records = createbutton(300, 520, 100, 40, YELLOW, "历史记录");
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
			int isok = MessageBox(hndtipsD, "抽卡次数不足", "提示", MB_OK);
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
				//此时会得到一个小于图片数量的数字

			
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
				//抽到金后降低抽卡概率
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

			//此时会得到一个小于图片数量的数字
			///////////////////////////////////////////////////////////////////////////////池子没改！！！！///////////////////
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
			int isok = MessageBox(hndtipsD, "抽卡次数不足", "提示", MB_OK);

		}
		else
		{
		
			int seed1 = time(NULL);
			for (i = 0; i < 10; i++) {
				srand(seed1 * seed1);
				save_[i] = rand() % 100;
				seed1 = seed1 * 2 + 10;
			}
			if (juju == 1) {//碧蓝
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
					
					

				}//保存了10个物品的好坏012

			}
			if (juju == 2) {//原神
				srand(seed * seed);
				for (i = 0; i < 10; i++)
				{	//增加概率
					probability.purplepercentage += 0.05;
					probability.goldpercentage += 0.05;
					save_[i] = judgeYuanShen(save_[i], probability.purplepercentage, probability.goldpercentage);
					chounum++;

					if (save_[i] == 2 && flag == 0)
						flag = 1;//抽到金后取消保底
					if (save_[i] == 2 && flag == 1)
						probability.goldpercentage -= 0.5;
					//抽到金后降低抽卡概率
					if (chounum > 80 && flag == 0) {
						save_[i] = 2;
						flag = 1;
					}
					///////////////////////////////////////////////////给save_[i]排序/////////////////////////////////////////////////////////////
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
				}//保存了10个物品的好坏012
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
		InputBox(str11, 10, "请输入添加角色的名称");
		InputBox(str21, 2, "请输入角色的星级");
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
		int isok = MessageBox(hndtipsD, "添加成功", "提示", MB_OK);
	}
	//改概率
	if (clickButton(glysystem3,m))
	{
		char percentyuan[3]; float percent;
		InputBox(percentyuan, 3, "请输入修改后出金概率(1~10)(单位为%)");
		percent = atoi(percentyuan);
		if (percent <= 10)
		{
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "更改成功", "提示", MB_OK);
			probability.goldpercentage = percent;
		}
		else {
			HWND hndtipsD = GetHWnd();
			int isok = MessageBox(hndtipsD, "打灭打灭", "提示", MB_OK);
		}
			
	}
	if (clickButton(glysystem4,m))
	{
		char str12[10], str22[8]; 
		FILE* fp;
		InputBox(str12, 10, "请输入添加角色的名称");
		InputBox(str22, 8, "请输入角色的品质（颜色）");
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
		int isok = MessageBox(hndtipsD, "添加成功", "提示", MB_OK);
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
			char path[50] = { 0 };//格式化之后的路径
			sprintf_s(path, "bilanblue/bilian%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
		if (save == 1) {
			char path[50] = { 0 };//格式化之后的路径
			sprintf_s(path, "bilanpurple/bilan%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
		if (save == 2) {
			char path[50] = { 0 };//格式化之后的路径
			sprintf_s(path, "bilangold/bilan%d.png", imasave);
			loadimage(&nn, path, 400, 300);
			putimage(200, 100, &nn);
		}
	}

		if (juju == 2) {
			if (save == 0) {
				char path[50] = { 0 };//格式化之后的路径
				sprintf_s(path, "genshindan/genshin3star/genshin%d.jpg", imasave);
				loadimage(&nn, path, 800, 600);
				putimage(0, 0, &nn);
			}
			if (save == 1) {
				char path[50] = { 0 };//格式化之后的路径
				sprintf_s(path, "genshindan/genshin4star/genshin%d.png", imasave);
				loadimage(&nn, path, 800, 600);
				putimage(0, 0, &nn);
			}
			if (save == 2) {
				char path[50] = { 0 };//格式化之后的路径
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
		//记得改地址

		//10张图片依次显示
			//sprintf_s(path_[1], "genshin10lian/genshin3star/genshin%d.png",1);
			//sprintf_s(path_[2], "genshin10lian/genshin3star/genshin%d.png",2);

		EndBatchDraw();
	
}
	closegraph();
	return 0;
}

