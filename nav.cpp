#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define NoEdge 99999999
using namespace std;
void DoNavigation();
void NavBar();
int map[100][100], flag[100], flag1[100], dis[100], mendmap[100][100];
int fix1 = 0, fix2 = 0;

struct A		//����ṹ��洢������Ϣ 
{
	char name[100];
	char introduce[800];
	int JamDegree;
	int x;
	int y;
}placeInfo[100];

void Background()
{
	IMAGE background;//����һ��ͼƬ��.
	loadimage(&background, "C:\\Users\\52954\\Desktop\\test.png", 1000, 900, 1);//��ͼƬ�ļ���ȡͼ��
	putimage(0, 0, &background);//����ͼ����Ļ��ͼƬ���Ͻ�����Ϊ(0,0)
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 5);
	line(placeInfo[4].x, placeInfo[4].y, placeInfo[14].x, placeInfo[14].y);//1
	line(placeInfo[4].x, placeInfo[4].y, placeInfo[5].x, placeInfo[5].y);//2
	line(placeInfo[14].x, placeInfo[14].y, placeInfo[8].x, placeInfo[8].y);//3
	line(placeInfo[14].x, placeInfo[14].y, placeInfo[11].x, placeInfo[11].y);//4
	line(placeInfo[8].x, placeInfo[8].y, placeInfo[16].x, placeInfo[16].y);//5
	line(placeInfo[6].x, placeInfo[6].y, placeInfo[11].x, placeInfo[11].y);//6
	line(placeInfo[11].x, placeInfo[11].y, placeInfo[7].x, placeInfo[7].y);//7
	line(placeInfo[13].x, placeInfo[13].y, placeInfo[6].x, placeInfo[6].y);//8
	line(placeInfo[7].x, placeInfo[7].y, placeInfo[13].x, placeInfo[13].y);//9
	line(placeInfo[7].x, placeInfo[7].y, placeInfo[16].x, placeInfo[16].y);//10
	line(placeInfo[6].x, placeInfo[6].y, placeInfo[9].x, placeInfo[9].y);//11
	line(placeInfo[13].x, placeInfo[13].y, placeInfo[2].x, placeInfo[2].y);//12
	line(placeInfo[15].x, placeInfo[15].y, placeInfo[16].x, placeInfo[16].y);//13
	line(placeInfo[9].x, placeInfo[9].y, placeInfo[10].x, placeInfo[10].y);//14
	line(placeInfo[16].x, placeInfo[16].y, placeInfo[3].x, placeInfo[3].y);//15
	line(placeInfo[2].x, placeInfo[2].y, placeInfo[9].x, placeInfo[9].y);//16
	line(placeInfo[2].x, placeInfo[2].y, placeInfo[12].x, placeInfo[12].y);//17
	line(placeInfo[6].x, placeInfo[6].y, placeInfo[5].x, placeInfo[5].y);//18
	line(placeInfo[12].x, placeInfo[12].y, placeInfo[15].x, placeInfo[15].y);//19
	line(placeInfo[1].x, placeInfo[1].y, placeInfo[12].x, placeInfo[12].y);//20edge
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	fillcircle(placeInfo[1].x, placeInfo[1].y, 6); outtextxy(placeInfo[1].x, placeInfo[1].y, "1.�л�����԰");
	fillcircle(placeInfo[2].x, placeInfo[2].y, 6); outtextxy(placeInfo[2].x, placeInfo[2].y, "2.���ϻ����");
	fillcircle(placeInfo[3].x, placeInfo[3].y, 6); outtextxy(placeInfo[3].x, placeInfo[3].y, "3.�Ӻ���ѧ");
	fillcircle(placeInfo[4].x, placeInfo[4].y, 6); outtextxy(placeInfo[4].x, placeInfo[4].y, "4.��Ŀ��");
	fillcircle(placeInfo[5].x, placeInfo[5].y, 6); outtextxy(placeInfo[5].x, placeInfo[5].y - 20, "5.������");
	fillcircle(placeInfo[6].x, placeInfo[6].y, 6); outtextxy(placeInfo[6].x, placeInfo[6].y, "6.�ͳ�Ұ������԰");
	fillcircle(placeInfo[7].x, placeInfo[7].y, 6); outtextxy(placeInfo[7].x, placeInfo[7].y, "7.�л�Т��԰");
	fillcircle(placeInfo[8].x, placeInfo[8].y, 6); outtextxy(placeInfo[8].x, placeInfo[8].y, "8.��÷��԰");
	fillcircle(placeInfo[9].x, placeInfo[9].y, 6); outtextxy(placeInfo[9].x, placeInfo[9].y, "9.���ݲ����");
	fillcircle(placeInfo[10].x, placeInfo[10].y, 6); outtextxy(placeInfo[10].x, placeInfo[10].y, "10.�����κ���");
	fillcircle(placeInfo[11].x, placeInfo[11].y, 6); outtextxy(placeInfo[11].x, placeInfo[11].y, "11.���Ƕ�����Ϸ��");
	fillcircle(placeInfo[12].x, placeInfo[12].y, 6); outtextxy(placeInfo[12].x, placeInfo[12].y, "12.����������");
	fillcircle(placeInfo[13].x, placeInfo[13].y, 6); outtextxy(placeInfo[13].x, placeInfo[13].y, "13.�����й滮��");
	fillcircle(placeInfo[14].x, placeInfo[14].y, 6); outtextxy(placeInfo[14].x, placeInfo[14].y, "14.��ɽ��");
	fillcircle(placeInfo[15].x, placeInfo[15].y, 6); outtextxy(placeInfo[15].x, placeInfo[15].y - 20, "15.�����");
	fillcircle(placeInfo[16].x, placeInfo[16].y, 6); outtextxy(placeInfo[16].x, placeInfo[16].y, "16.���¹�԰");
}
void showMap()
{
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	Background();
	_getch();
	closegraph();
}
void Map()
{
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	Background();
	_getch();
	closegraph();
	DoNavigation();
}
void restoreMap()
{
	int i, j;
	for (i = 1; i <= 28; i++)
		for (j = 1; j <= 28; j++)
		{
			mendmap[i][j] = map[i][j];
		}
}
void CreateUDN()		//�洢������Ϣ��ͬʱ��ͼ��������Ϣ 
{
	int i, j;
	strcpy(placeInfo[1].name, "�л�����԰"); strcpy(placeInfo[1].introduce, "�л�����԰�ǻ�������ǵĺ��ľ��㣬��һ�������ա����֡����ա�ס�ޡ�������һ���һվʽ���ζȼ������С�����٪�޼͡�֮�ơ�");
	strcpy(placeInfo[2].name, "���ϻ����"); strcpy(placeInfo[2].introduce, "���ϻ������һ������������԰����������ȫ�淢չ�������ۺ���,�Ǻ����˳�ס���ι��������ȫ��ҵ����");
	strcpy(placeInfo[3].name, "�Ӻ���ѧ"); strcpy(placeInfo[3].introduce, "�Ӻ���ѧ����ˮ��Ϊ��ɫ������Ϊ������ѧ��Э����չ�Ľ�����ֱ������������ˮ���������Һ�����뽭��ʡ��������������ȫ���ص��ѧ��");
	strcpy(placeInfo[4].name, "��Ŀ��"); strcpy(placeInfo[4].introduce, "��Ŀ��Ϊһ����խ���ϱ�������ˮ��������Ϊ���������顱������ɫ�ɾ���������Χ�ִ������ʷ�Ļ���ַ������ḻ��");
	strcpy(placeInfo[5].name, "������"); strcpy(placeInfo[5].introduce, "������ʼ�����������䣬�Ƿ���������µķ�Դ��֮һ������ȫ���ص�����Ժ֮һ������ʡ���ﱣ����λ���ж��ϵ�һ����֮�ơ�");
	strcpy(placeInfo[6].name, "�ͳ�Ұ������԰"); strcpy(placeInfo[6].introduce, "�����ͳ�Ұ����������λ�ڳ�����������ĳ������ೣ������8���");
	strcpy(placeInfo[7].name, "�л�Т��԰"); strcpy(placeInfo[7].introduce, "�л�Т��԰������ȫ��ʮ��������Ƭ֮һ�ĳ��������̫�������ζȼ������ǽ���һ���ġ�������Դ����");
	strcpy(placeInfo[8].name, "��÷��԰"); strcpy(placeInfo[8].introduce, "��÷��԰λ�ڳ��������Ķ��࣬��԰�ڵ������Ž���-��÷����������ǳ��������Ĺ����ص㹫԰��");
	strcpy(placeInfo[9].name, "���ݲ����"); strcpy(placeInfo[9].introduce, "���ݲ���ݣ�������1958��10�£��Ǽ��ղء��о�������չ����һ��ĵط��ۺ��Բ���ݡ�");
	strcpy(placeInfo[10].name, "�����κ���"); strcpy(placeInfo[10].introduce, "�����κ���λ���л�������ɽ����̳éɽ�������������οعɼ���Ͷ�ʿ�������ģ����Ҽ�ɽˮ�������ζȼ�����");
	strcpy(placeInfo[11].name, "��������Ϸ��"); strcpy(placeInfo[11].introduce, "��������Ϸ����԰��λ�ڳ��������̫�������ζȼ����ڣ���һ�����ʶ�����Ϸ���鲩��԰��");
	strcpy(placeInfo[12].name, "����������"); strcpy(placeInfo[12].introduce, "���������������ǳ���������������ִ�л��أ��ǽ���ʡ�����еĹ����������أ��Գ�������������Ḻ�𲢱��湤����");
	strcpy(placeInfo[13].name, "�����й滮��"); strcpy(placeInfo[13].introduce, "�����й滮��չʾ�˳����ƾõĳ�����ʷ��չ���˸ĸ￪���������ݳ��н���ĻԻͳɾͣ�չ���˳���δ����չ�ĺ�ΰ��ͼ��");
	strcpy(placeInfo[14].name, "��ɽ��"); strcpy(placeInfo[14].introduce, "��Ŀ����ɽ�񺣾����ش����ա�������ʡ����֮���Ľ��������������Ļ������Ļ�Ϊ���⣬�ǹ���5A��������");
	strcpy(placeInfo[15].name, "�����"); strcpy(placeInfo[15].introduce, "�����������������塢���ʱ�ڵĽ���Ϊ�����ֲ�����լ�ʾӡ��������ŷ���ʯ�ȣ��ǳ��ݹ�����ʷ�Ļ����ǵġ��ʯ����");
	strcpy(placeInfo[16].name, "���¹�԰"); strcpy(placeInfo[16].introduce, "���¹�԰�ǹ���4A�����ξ�����λ�ڳ��ݵ�һ԰�֡�����÷��԰���ϲ࣬���˺Ӷ�ȥ���ʺ�Ҫ�ء�");
	//////////////////////////////////////////////////////////////////////////////////////////
	for (i = 1; i <= 16; i++)
		placeInfo[i].JamDegree = 0;
	//////////////////////////////////////////////////////////////////////////////////////////
	for (i = 1; i <= 28; i++)// �����䲻��ͨ
		for (j = 1; j <= 28; j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = NoEdge;
		}

	map[4][14] = 170; map[14][4] = 170; map[4][5] = 180; map[5][4] = 180;
	map[14][8] = 450; map[8][14] = 450; map[14][11] = 140; map[11][14] = 140;
	map[8][16] = 420; map[16][8] = 420;
	map[5][6] = 160; map[6][5] = 160;
	map[11][6] = 220; map[6][11] = 220; map[11][7] = 180; map[7][11] = 180;
	map[6][13] = 100; map[13][6] = 100; map[6][9] = 220; map[9][6] = 220;
	map[7][13] = 200; map[13][7] = 200; map[7][16] = 110; map[16][7] = 110;
	map[13][2] = 280; map[2][13] = 280;
	map[16][15] = 70; map[15][16] = 70; map[16][3] = 80; map[3][16] = 80;
	map[9][10] = 200; map[10][9] = 200; map[9][2] = 190; map[2][9] = 190;
	//map[11][]
	map[2][12] = 100; map[12][2] = 100;
	map[12][15] = 100; map[15][12] = 100; map[12][1] = 220; map[1][12] = 220;

	for (i = 1; i <= 16; i++)
		for (j = 1; j <= 16; j++)
			map[j][i] = map[i][j];

	//�����ʼ�����
	placeInfo[1].x = 690, placeInfo[1].y = 80;
	placeInfo[2].x = 350, placeInfo[2].y = 90;
	placeInfo[3].x = 720, placeInfo[3].y = 240;
	placeInfo[4].x = 80, placeInfo[4].y = 560;
	placeInfo[5].x = 120, placeInfo[5].y = 360;
	placeInfo[6].x = 320, placeInfo[6].y = 400;//
	placeInfo[7].x = 560, placeInfo[7].y = 480;//
	placeInfo[8].x = 640, placeInfo[8].y = 750;
	placeInfo[9].x = 200, placeInfo[9].y = 200;
	placeInfo[10].x = 50, placeInfo[10].y = 60;
	placeInfo[11].x = 400, placeInfo[11].y = 640;
	placeInfo[12].x = 500, placeInfo[12].y = 160; 
	placeInfo[13].x = 400, placeInfo[13].y = 360;
	placeInfo[14].x = 240, placeInfo[14].y = 660;
	placeInfo[15].x = 560, placeInfo[15].y = 320;
	placeInfo[16].x = 660, placeInfo[16].y = 360;
}

void Visual()			//�����б� 
{
	system("cls");			//���� 
	printf("\n\n\n");
	printf("\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t * *                              *�����б�*                                     * *\n");
	printf("\t\t\t * ******************************************************************************* *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <1>�л�����԰     <2>���ϻ����        <3>�Ӻ���ѧ         <4>��Ŀ��       * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <5>������         <6>�ͳ�Ұ������԰    <7>�л�Т��԰       <8>��÷��԰     * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <9>���ݲ����     <10>�����κ���       <11>��������Ϸ��  <12>����������  * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <13>�����й滮��  <14>��ɽ��         <15>�����          <16>���¹�԰    * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * ******************************************************************************* *\n");
	printf("\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
}

int IdentifyID(char s[])//��ѯ������ 
{
	int f = 0, i;
	for (i = 1; i <= 16; i++)
	{
		if (strcmp(placeInfo[i].name, s) == 0) //ƥ�侰������ţ�������ת���ɱ��
			return i;
	}
	return -1;
}

void Dijkstra(int v0, int s)		//�Ͻ�˹���������·���������·�� 
{
	int NumString[20] = { 0 };// ·����������
	int min, i, j, u, v, f;
	int lastV, nextV;
	//int x1, y1, x2, y2;
	int p[100], l[100];
	memset(p, -1, sizeof(p)); // �洢ǰ���
	memset(l, 0, sizeof(l)); // ��¼���յ�ǰ���
	memset(flag, 0, sizeof(flag)); // �������
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//ÿ���ҳ�����v0����� 
		{
			if (flag[j] == 0 && dis[j] < min) // δ����� ��dis��С
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			// ��Ǹõ� �����
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//ͨ���������������� 
			{
				p[v] = u;					//�洢���µıߣ���Ϊ·�� 
				dis[v] = dis[u] + map[u][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//��·�ߴ���ջ�У�������� 
	{
		l[i++] = p[v]; // l ��¼ ���յ�ǰ��� �� line244 ������ҵ�;������
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("·��Ϊ��\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // ��¼·���Ͼ�����������
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	printf("���·������Ϊ��%d ��λ����\n", dis[s]);

	int head = IdentifyID(placeInfo[s].name); // Ŀ�ĵ� �� NumString �� 1 ����
	int tail = IdentifyID(placeInfo[v0].name); // ������
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	int once_cnt = 0; // ����Ÿ�ѭ��������䣬�� Map ���ɵĴ����۵�����
	Background(); // ���ƿ�ͨ·��
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 6);
	if(f>0){
		//printf("%d\n", NumString[1]);
		//printf("place_s=%s  place_v0=%s  head:%d  X:%d   Y:%d   \n", placeInfo[s].name, placeInfo[v0].name,head, placeInfo[head].x, placeInfo[head].y);
		/*x1 = ;
		placeInfo[14].x = 560, placeInfo[14].y = 320;
		placeInfo[16].x = 690, placeInfo[16].y = 80;
		y2 = ;*/
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[NumString[1]].x, placeInfo[NumString[1]].y);
		line(placeInfo[tail].x, placeInfo[tail].y, placeInfo[NumString[f]].x, placeInfo[NumString[f]].y);
		for (int i = 1; i < f; i++)
		{
			//line(5, 5, 244, 237);
			lastV = NumString[i];
			nextV = NumString[i + 1];
			//printf("x1:%d  y1:%d  x2:%d  y2:%d ", placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
			line(placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
			//line(placeInfo[1].x, placeInfo[1].y, placeInfo[5].x, placeInfo[5].y);
		}

	}
	else {
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[tail].x, placeInfo[tail].y);

	}
	settextcolor(RED);
	settextstyle(20, 0, "����");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "������");
	outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "�յ�");
	_getch();
	closegraph();
}

void Dijkstra_l(int v0, int s, int maxdis)		//�Ͻ�˹���������·���������·�� 
{
	int NumString[20] = { 0 };// ·����������
	int min, i, j, u, v, f;
	int lastV, nextV;
	int p[100], l[100];
	memset(p, -1, sizeof(p));
	memset(l, 0, sizeof(l));
	memset(flag, 0, sizeof(flag));
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//ÿ���ҳ�����v0����� 
		{
			if (flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			//��Ǹõ� 
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//ͨ���������������� 
			{
				p[v] = u;					//�洢���µıߣ���Ϊ·�� 
				dis[v] = dis[u] + map[u][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//��·�ߴ���ջ�У�������� 
	{
		l[i++] = p[v];
		v = p[v];
	}

	u = i - 1;
	f = u;
	if (dis[s] < maxdis)
	{
		printf("\n");
		printf("·��Ϊ��\n");
		printf("%s--->", placeInfo[v0].name);
		for (i = u; i >= 1; i--)
		{
			NumString[i] = IdentifyID(placeInfo[l[i]].name); // ��¼·���Ͼ�����������
			printf("%s--->", placeInfo[l[i]].name);
		}
		printf("%s\n", placeInfo[s].name);
		printf("���·������Ϊ��%d ��λ����\n", dis[s]);

		int head = IdentifyID(placeInfo[s].name); // Ŀ�ĵ� �� NumString �� 1 ����
		int tail = IdentifyID(placeInfo[v0].name); // ������
		initgraph(1000, 900, SHOWCONSOLE);
		setbkcolor(WHITE);
		cleardevice();		
		int once_cnt = 0; // ����Ÿ�ѭ��������䣬�� Map ���ɵĴ����۵�����
		Background();
		setlinecolor(BLUE);
		setlinestyle(PS_SOLID, 6);
		if (f > 0) {
			line(placeInfo[head].x, placeInfo[head].y, placeInfo[NumString[1]].x, placeInfo[NumString[1]].y);
			line(placeInfo[tail].x, placeInfo[tail].y, placeInfo[NumString[f]].x, placeInfo[NumString[f]].y);
			for (int i = 1; i < f; i++)
			{
				//line(5, 5, 244, 237);
				lastV = NumString[i];
				nextV = NumString[i + 1];
				//printf("x1:%d  y1:%d  x2:%d  y2:%d ", placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
				line(placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
				//line(placeInfo[1].x, placeInfo[1].y, placeInfo[5].x, placeInfo[5].y);
			}
		}
		else {
			line(placeInfo[head].x, placeInfo[head].y, placeInfo[tail].x, placeInfo[tail].y);

		}	
		settextcolor(RED);
		settextstyle(20, 0, "����");
		outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "������");
		outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "�յ�");
		_getch();
		closegraph();
	}
}

void WayMustPass(int v0, int must1,int must2 , int s)		//ȥ����·�ıߣ��Ͻ�˹���������·���������·�� 
{
	int NumString[20] = { 0 };// ·����������
	int NumString1[20] = { 0 };
	int min, i, j, u, v, f, g, w;
	int lastV, nextV;
	//int x1, y1, x2, y2;
	int p[100], l[100], p1[100], l1[100];
	memset(p, -1, sizeof(p)); // �洢ǰ���
	memset(l, 0, sizeof(l)); // ��¼���յ�ǰ���
	memset(flag, 0, sizeof(flag)); // �������
	memset(p1, -1, sizeof(p1)); // �洢ǰ���
	memset(l1, 0, sizeof(l1)); // ��¼���յ�ǰ���
	memset(flag1, 0, sizeof(flag1)); // �������
	for (i = 1; i <= 16; i++)
	{
		dis[i] = mendmap[v0][i];
		if (dis[i] < NoEdge)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//ÿ���ҳ�����v0����� 
		{
			if (flag[j] == 0 && dis[j] < min) // δ����� ��dis��С
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			// ��Ǹõ� �����
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + mendmap[u][v])			//ͨ���������������� 
			{
				p[v] = u;					//�洢���µıߣ���Ϊ·�� 
				dis[v] = dis[u] + mendmap[u][v];
			}
		}
	}
	v = must1;
	i = 1;
	while (p[v] != v0)			//��·�ߴ���ջ�У�������� 
	{
		l[i++] = p[v]; // l ��¼ ���յ�ǰ��� �� line565 ������ҵ�;������
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("·��Ϊ��\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // ��¼·���Ͼ�����������
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s--->", placeInfo[must1].name);

	for (i = 1; i <= 16; i++)
	{
		dis[i] = mendmap[must2][i];
		if (dis[i] < NoEdge)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p1[i] = must2;
	}

	flag1[must2] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//ÿ���ҳ�����v0����� 
		{
			if (flag1[j] == 0 && dis[j] < min) // δ����� ��dis��С
			{
				min = dis[j];
				w = j;
			}
		}
		flag1[w] = 1;			// ��Ǹõ� �����
		for (v = 1; v <= 16; v++)
		{
			if (flag1[v] == 0 && dis[v] > dis[w] + mendmap[w][v])			//ͨ���������������� 
			{
				p1[v] = w;					//�洢���µıߣ���Ϊ·�� 
				dis[v] = dis[w] + mendmap[w][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p1[v] != must2)			//��·�ߴ���ջ�У�������� 
	{
		l1[i++] = p1[v]; // l1 ��¼ ���յ�ǰ��� �� line565 ������ҵ�;������
		v = p1[v];
	}
	w = i - 1;
	g = w;
	printf("%s--->", placeInfo[must2].name);
	for (i = w; i >= 1; i--)
	{
		NumString1[i] = IdentifyID(placeInfo[l1[i]].name); // ��¼·���Ͼ�����������
		printf("%s--->", placeInfo[l1[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	printf("���·������Ϊ��%d ��λ����\n", dis[s] + dis[must1]);

	int head = IdentifyID(placeInfo[must1].name); // Ŀ�ĵ� �� NumString �� 1 ����
	int tail = IdentifyID(placeInfo[v0].name); // ������

	int head1 = IdentifyID(placeInfo[s].name); // Ŀ�ĵ� �� NumString1 �� 1 ����
	int tail1 = IdentifyID(placeInfo[must2].name); // ������

	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	int once_cnt = 0; // ����Ÿ�ѭ��������䣬�� Map ���ɵĴ����۵�����
	Background();

	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 6);
	if (f > 0) {
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[NumString[1]].x, placeInfo[NumString[1]].y);
		line(placeInfo[tail].x, placeInfo[tail].y, placeInfo[NumString[f]].x, placeInfo[NumString[f]].y);
		for (int i = 1; i < f; i++)
		{
			lastV = NumString[i];
			nextV = NumString[i + 1];
			line(placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
		}
	}
	else {
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[tail].x, placeInfo[tail].y);

	}
	if (g > 0) {
		line(placeInfo[head1].x, placeInfo[head1].y, placeInfo[NumString1[1]].x, placeInfo[NumString1[1]].y);
		line(placeInfo[tail1].x, placeInfo[tail1].y, placeInfo[NumString1[g]].x, placeInfo[NumString1[g]].y);
		for (int i = 1; i < g; i++)
		{
			lastV = NumString1[i];
			nextV = NumString1[i + 1];
			line(placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
		}
	}
	else {
		line(placeInfo[head1].x, placeInfo[head1].y, placeInfo[tail1].x, placeInfo[tail1].y);

	}
	//��� �ο�ָ���ı��������·
	setlinecolor(GREEN);
	setlinestyle(PS_SOLID, 8);
	line(placeInfo[must1].x, placeInfo[must1].y, placeInfo[must2].x, placeInfo[must2].y);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 8);
	// ���Ƴ� ����ά���в�ͨ����·
	line(placeInfo[fix1].x, placeInfo[fix1].y, placeInfo[fix2].x, placeInfo[fix2].y);
	settextcolor(RED);
	settextstyle(20, 0, "����");
	outtextxy((placeInfo[fix1].x + placeInfo[fix2].x) / 2, (placeInfo[fix1].y + placeInfo[fix2].y) / 2, "��·��ͨ��");
	outtextxy(5, 5, "�������·��~�����������ˣ������������·����ͨ��Ŷ~");
	outtextxy((placeInfo[must1].x + placeInfo[must2].x) / 2, (placeInfo[must1].y + placeInfo[must2].y) / 2, "���·\n����̫�����ˣ�");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "������");
	outtextxy(placeInfo[head1].x + 20, placeInfo[head1].y + 20, "�յ�");
	_getch();
	closegraph();
}

void FastWay(int v0, int s)		
{
	int NumString[20] = { 0 };// ·����������
	int min, i, j, u, v, f;
	int lastV, nextV;
	int p[100], l[100];

	//�������·���������Ȩ�أ���ʾ�þ���ӵ��ϵ����������·������ʱ��
	for (int i = 0; i < 100; i++) 
		placeInfo[i].JamDegree = abs( rand() % 100 + 20 );   
	memset(p, -1, sizeof(p)); // �洢ǰ���
	memset(l, 0, sizeof(l)); // ��¼���յ�ǰ���
	memset(flag, 0, sizeof(flag)); // �������
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0��ֱ�ӵ������һվ��Ϊv0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//ÿ���ҳ�����v0����� 
		{
			if (flag[j] == 0 && dis[j] + placeInfo[j].JamDegree < min) // δ����� ��dis��С
			{
				min = dis[j]+placeInfo[j].JamDegree;
				u = j;
			}
		}
		flag[u] = 1;			// ��Ǹõ� �����
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//ͨ���������������� 
			{
				p[v] = u;					//�洢���µıߣ���Ϊ·�� 
				dis[v] = dis[u] + map[u][v]+ placeInfo[j].JamDegree;
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//��·�ߴ���ջ�У�������� 
	{
		l[i++] = p[v]; // l ��¼ ���յ�ǰ��� �� line565 ������ҵ�;������
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("·��Ϊ��\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // ��¼·���Ͼ�����������
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	//printf("Hey Here!!!%d", placeInfo[1].JamDegree);
	printf("���·������Ϊ��%d ��λ����\n", dis[s]);
	int head = IdentifyID(placeInfo[s].name); // Ŀ�ĵ� �� NumString �� 1 ����
	int tail = IdentifyID(placeInfo[v0].name); // ������
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	Background();
	settextcolor(RED);
	settextstyle(25, 0, "����");
	for (int fff = 1; fff <= 16; fff++) 
	{
		char num[20];
		int JamString = (char)placeInfo[fff].JamDegree;
		sprintf(num, "%d", JamString);
		outtextxy(placeInfo[fff].x - 10, placeInfo[fff].y + 20, num);
	}
	outtextxy(5, 5, "�����Ժ�ɫ���ִ���ӵ��ϵ������ʾ�����õ�������ʱ��");
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 6);
	if (f > 0) {
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[NumString[1]].x, placeInfo[NumString[1]].y);
		line(placeInfo[tail].x, placeInfo[tail].y, placeInfo[NumString[f]].x, placeInfo[NumString[f]].y);
		for (int i = 1; i < f; i++)
		{
			lastV = NumString[i];
			nextV = NumString[i + 1];
			//printf("x1:%d  y1:%d  x2:%d  y2:%d ", placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
			line(placeInfo[lastV].x, placeInfo[lastV].y, placeInfo[nextV].x, placeInfo[nextV].y);
		}

	}
	else {
		line(placeInfo[head].x, placeInfo[head].y, placeInfo[tail].x, placeInfo[tail].y);

	}
	settextcolor(RED);
	settextstyle(20, 0, "����");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "������");
	outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "�յ�");
	_getch();
	closegraph();
}

//��ѯ��ʽ 
int QueryPattern(int x)
{
	int i;
	system("cls");			//���� 
	printf("\n");
	printf("\t\t\t\t\t                    *�������ѯ��ʽ*\n\n");
	printf("\t\t\t\t\t                  1�����뾰���Ų�ѯ\n\n");
	printf("\t\t\t\t\t                  2�����뾰�����Ʋ�ѯ\n\n");
	printf("\t\t\t\t\t                  0��������һ����\n\n\n\n\n\n\n");
	scanf("%d", &i);
	return i;
}

//�������� 
void DoNavigation()
{
	int x, m, n, u, v, i, j, dis;
	int must1 = 0, must2 = 0;
	char c[100];
	system("cls");			//���� 
	printf("\n\n\n");
	printf("\t\t\t\t\t ����������������������������������������������\n");
	printf("\t\t\t\t\t ��                                          ��\n");
	printf("\t\t\t\t\t ��   �� ӭ ʹ �� �� �� �� �� �� �� ϵ ͳ    ��\n");
	printf("\t\t\t\t\t ��                                          ��\n");
	printf("\t\t\t\t\t ����������������������������������������������\n");
	printf("\n\n\n");
	printf("\t\t\t       1����ѯ��ĳ�ص����������о�������·��\n\n");
	printf("\t\t\t       2����ѯ���������������·��\n\n");
	printf("\t\t\t       3���������������ƣ���ѯ���п�����·�� ���ο�����û���˻���·�����ޣ�  \n\n ");
	printf("\t\t\t       4��ָ�����������ĳ��·����ѯ�����·�ߣ����������·��������ܸö�·�治��Ŷ��  \n\n");
	printf("\t\t\t       5��ʵʱ���ɾ���ӵ���������ѯ���·��������ĳ����ӵ�£������õ�·�߱�����   \n\n");
	printf("\t\t\t       6����ѯ���⾰����Ϣ \n\n");
	printf("\t\t\t       7������������ͼ   \n\n");
	printf("\t\t\t       8��������������  \n\n");

	printf("\n\n\n");
	
	restoreMap();// �ָ���·�ı�

	while (1)//���������������� 
	{
		scanf("%d", &x);
		if (x == 1) //�����Ӵ˳������������·��
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("�����뵱ǰ���ھ����ţ�\n");
					scanf("%d", &n);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							for (i = 1; i <= 16; i++)
							{
								if (i != n)
									Dijkstra(n, i);
							}
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰���ţ�\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("�����뵱ǰ���ھ������ƣ�\n");
					scanf("%s", c);
					n = IdentifyID(c);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							for (i = 1; i <= 16; i++)
							{
								if (i != n)
									Dijkstra(n, i);
							}
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰�����ƣ�\n");
							scanf("%s", c);
							n = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation(); // �����ϼ�����
					break;
				}
				else
				{
					printf("\n\n����������������룡\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 2) // ��ѯ�����������̾���
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("��������㾰���ţ�\n");
					scanf("%d", &n);
					printf("\n�������յ㾰���ţ�\n");
					scanf("%d", &m);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							Dijkstra(n, m);
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n���벻�Ϸ������������룡\n\n");
							printf("��������㾰���ţ�\n");
							scanf("%d", &n);
							printf("\n�������յ㾰���ţ�\n");
							scanf("%d", &m);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("��������㾰�����ƣ�\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("\n�������յ㾰�����ƣ�\n");
					scanf("%s", c);
					m = IdentifyID(c);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							Dijkstra(n, m);
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n���벻�Ϸ������������룡\n\n");
							printf("��������㾰�����ƣ�\n");
							scanf("%s", c);
							n = IdentifyID(c);
							printf("\n�������յ㾰�����ƣ�\n");
							scanf("%s", c);
							m = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation();
					break;
				}
				else
				{
					printf("\n\n����������������룡\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 3) //�о������Ƶ�·�� 
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("�����뵱ǰ���ھ����ţ�\n");
					scanf("%d", &n);
					printf("��������Զ�������Զ����: \n");
					scanf("%d", &dis);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							for (i = 1; i <= 16; i++)
							{
								if (i != n)
									Dijkstra_l(n, i, dis);
							}
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰���ţ�\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("�����뵱ǰ���ھ������ƣ�\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("��������Զ�������Զ����: \n");
					scanf("%d", &dis);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							for (i = 1; i <= 16; i++)
							{
								if (i != n)
									Dijkstra_l(n, i, dis);
							}
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰�����ƣ�\n");
							scanf("%s", c);
							n = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation(); // �����ϼ�����
					break;
				}
				else
				{
					printf("\n\n����������������룡\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 4) // �ο�֪��ĳ��·�ܺ��棬�οͱ��뾭�����·�ٵ��յ㣬��ѯ��·��
		{
			srand(time(NULL));
			do {
				fix1 = 1 + (rand() % 16);
			} while (fix1 == 1 || fix1 == 3 || fix1 == 10);
			do {
				fix2 = 1 + (rand() % 16);
			} while (fix1 == fix2 || map[fix1][fix2] == NoEdge || fix2 == 1 || fix2 == 3 || fix2 == 10);
			mendmap[fix1][fix2] = NoEdge; mendmap[fix2][fix1] = NoEdge;
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("������������ͨ����·�����ӵ��������������\n��һ:\n");
					scanf("%d", &must1);
					printf("\n���:\n");					
					scanf("%d", &must2);
					while (1)
					{
						if (map[must1][must2]!=NoEdge)
						{
							break;
						}
						else
						{
							printf("\n�����������ֱ��ͨ·�����������룡\n\n");
							printf("������������ͨ����·�����ӵ��������������\n\n��һ:\n\n");
							scanf("%d", &must1);
							printf("���:\n\n");
							scanf("%d", &must2);
						}
					}
					if ((must1 == fix1) && (must2 == fix2) || (must2 == fix1) && (must1 == fix2))
					{
						printf("��ѽ̫�����ˣ�����������·�պ����ޣ���һ���ؾ�֮·����?");
						break;
					}
					printf("��������㾰���ţ�\n");
					scanf("%d", &n);
					printf("\n�������յ㾰���ţ�\n");
					scanf("%d", &m);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{					
							//printf("%d\n", must1);
							WayMustPass(n,must1,must2, m);
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n���벻�Ϸ������������룡\n\n");
							printf("��������㾰���ţ�\n");
							scanf("%d", &n);
							printf("\n�������յ㾰���ţ�\n");
							scanf("%d", &m);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("������������ͨ����·�����ӵ��������������\n��һ:\n");
					scanf("%s", c);
					must1 = IdentifyID(c);
					printf("���:\n");
					scanf("%s", c);
					must2 = IdentifyID(c);
					while (1)
					{
						if (map[must1][must2] != NoEdge)
						{
							break;
						}
						else
						{
							printf("\n�����������ֱ��ͨ·�����������룡\n\n");
							printf("������������ͨ����·�����ӵ��������������\n��һ:\n");
							scanf("%s", c);
							must1 = IdentifyID(c);
							printf("���:\n");
							scanf("%s", c);
							must2 = IdentifyID(c);
						}
					}
					if ((must1 == fix1) && (must2 == fix2) || (must2 == fix1) && (must1 == fix2))
					{
						printf("��ѽ̫�����ˣ�����������·�պ����ޣ���һ���ؾ�֮·����?");
						break;
					}
					printf("��������㾰�����ƣ�\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("\n�������յ㾰�����ƣ�\n");
					scanf("%s", c);
					m = IdentifyID(c);

					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							WayMustPass(n, m,must1,must2);
							printf("\n\n���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n���벻�Ϸ������������룡\n\n");
							printf("��������㾰�����ƣ�\n");
							scanf("%s", c);
							n = IdentifyID(c);
							printf("\n�������յ㾰�����ƣ�\n");
							scanf("%s", c);
							m = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation();
					break;
				}
				else
				{
					printf("\n\n����������������룡\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 5) // ���ǵ��Ȩֵ������ĳ���ӵ���ӳ�ʱ�䣩��ѯ���·��
		{
		v = QueryPattern(x);
		while (1)
		{
			if (v == 1)
			{
				Visual();
				showMap();
				printf("��������㾰���ţ�\n");
				scanf("%d", &n);
				printf("\n�������յ㾰���ţ�\n");
				scanf("%d", &m);
				while (1)
				{
					if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
					{
						FastWay(n, m);
						printf("\n\n���س�������������ϵͳ����\n\n");
						getchar(); getchar();
						DoNavigation();
						break;
					}
					else
					{
						printf("\n���벻�Ϸ������������룡\n\n");
						printf("��������㾰���ţ�\n");
						scanf("%d", &n);
						printf("\n�������յ㾰���ţ�\n");
						scanf("%d", &m);
					}
				}
				break;
			}
			else if (v == 2)
			{
				Visual();
				showMap();
				printf("��������㾰�����ƣ�\n");
				scanf("%s", c);
				n = IdentifyID(c);
				printf("\n�������յ㾰�����ƣ�\n");
				scanf("%s", c);
				m = IdentifyID(c);
				while (1)
				{
					if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
					{
						FastWay(n, m);
						printf("\n\n���س�������������ϵͳ����\n\n");
						getchar(); getchar();
						DoNavigation();
						break;
					}
					else
					{
						printf("\n���벻�Ϸ������������룡\n\n");
						printf("��������㾰�����ƣ�\n");
						scanf("%s", c);
						n = IdentifyID(c);
						printf("\n�������յ㾰�����ƣ�\n");
						scanf("%s", c);
						m = IdentifyID(c);
					}
				}
				break;
			}
			else if (v == 0)
			{
				DoNavigation();
				break;
			}
			else
			{
				printf("\n\n����������������룡\n\n");
				scanf("%d", &v);
			}
		}
		break;
		}	
		else if (x == 6) // ��ѯ������Ϣ 
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("�����뾰���ţ�\n");
					scanf("%d", &n);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							printf("\n\n������%s\n\n%s\n\n��������Ϊ(%d,%d)\n\n", placeInfo[n].name, placeInfo[n].introduce,placeInfo[n].x,placeInfo[n].y);
							printf("���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰���ţ�\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					printf("�����뾰�����ƣ�\n");
					scanf("%s", c);
					n = IdentifyID(c);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							printf("\n\n������%s\n\n%s\n\n��������Ϊ(%d,%d)\n\n", placeInfo[n].name, placeInfo[n].introduce, placeInfo[n].x, placeInfo[n].y);
							printf("���س�������������ϵͳ����\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n�þ��㲻���ڣ����������뾰�����ƣ�\n");
							scanf("%s", c);
							n = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation();
					break;
				}
				else
				{
					printf("\n\n����������������룡\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 7) // չʾ������ͼ
		{
			Map();
			break;
		}
		else if (x == 8) // �������˵�
		{
			NavBar();
			break;
		}
		else
		{
			printf("\n\n����������������룡\n");
		}
	}

}

//������������ 
void NavBar()
{
	system("cls");		//���� 
	int m;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");	
	printf("\t\t\t\t\t    *--------------------�� �� ��------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------1���� �� �� �� ϵ ͳ----------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------2���� �� �� ��----------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------3���� �� ��-------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	scanf("%d", &m);
	while (1)
	{
		if (m == 1)
		{
			DoNavigation();
			break;
		}

		else if (m == 2)
		{
			system("cls");
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ��\n");
			printf("\t\t\t\t\t���                                                      ���\n");
			printf("\t\t\t\t\t���        ��      ӭ     ��     ��      ʹ      ��      ���\n");
			printf("\t\t\t\t\t���                                                      ���\n");
			printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ��ߡ�ߡ�ߡ�ߡ�ߡ��ߡ�ߡ�\n");
			printf("\n\n\n");
			break;
		}
		else if (m == 3)
		{
			system("cls");		//���� 
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t    ****************************************************\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *                    �� �� ��                      *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *               1961010516     �� ��               *\n");
			printf("\t\t\t\t\t    *               1962310203     ������              *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    ****************************************************\n");
			printf("\n\n\n\n\n");
			printf("���س�������������\n");
			getchar(); getchar();
			NavBar();
			break;
		}
		else
		{
			printf("\n\n\n\t\t����������������룡\n\n\n\n");
			scanf("%d", &m);
		}
	}

}

//��ӭ���� 
void MainInterface()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t   _______________________________________________________ \n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |-----------------***���ݽṹ����***-------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |----------------��ӭʹ�ó��ݵ���ϵͳ------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |--------------------���س�������----------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |______________________________________________________|\n");
	getchar();

	NavBar();
}

int main(void)
{
	system("color f0");		//�ı����д���ɫ
	system("mode con cols=150 lines=40");		//�ı����д��ڴ�С 
	CreateUDN();
	srand(time(NULL));
	srand(time(NULL));
	do {
		fix1 = 1 + (rand() % 16);
	} while (fix1 == 1 || fix1 == 3 || fix1 == 10);
	do {
		fix2 = 1 + (rand() % 16);
	} while (fix1 == fix2 || map[fix1][fix2] == NoEdge || fix2 == 1 || fix2 == 3 || fix2 == 10);
	mendmap[fix1][fix2] = NoEdge; mendmap[fix2][fix1] = NoEdge;
	MainInterface();
	return 0;
}
