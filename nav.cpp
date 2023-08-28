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

struct A		//定义结构体存储景点信息 
{
	char name[100];
	char introduce[800];
	int JamDegree;
	int x;
	int y;
}placeInfo[100];

void Background()
{
	IMAGE background;//定义一个图片名.
	loadimage(&background, "C:\\Users\\52954\\Desktop\\test.png", 1000, 900, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
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
	settextstyle(20, 0, "楷体");
	fillcircle(placeInfo[1].x, placeInfo[1].y, 6); outtextxy(placeInfo[1].x, placeInfo[1].y, "1.中华恐龙园");
	fillcircle(placeInfo[2].x, placeInfo[2].y, 6); outtextxy(placeInfo[2].x, placeInfo[2].y, "2.江南环球港");
	fillcircle(placeInfo[3].x, placeInfo[3].y, 6); outtextxy(placeInfo[3].x, placeInfo[3].y, "3.河海大学");
	fillcircle(placeInfo[4].x, placeInfo[4].y, 6); outtextxy(placeInfo[4].x, placeInfo[4].y, "4.天目湖");
	fillcircle(placeInfo[5].x, placeInfo[5].y, 6); outtextxy(placeInfo[5].x, placeInfo[5].y - 20, "5.天宁寺");
	fillcircle(placeInfo[6].x, placeInfo[6].y, 6); outtextxy(placeInfo[6].x, placeInfo[6].y, "6.淹城野生动物园");
	fillcircle(placeInfo[7].x, placeInfo[7].y, 6); outtextxy(placeInfo[7].x, placeInfo[7].y, "7.中华孝道园");
	fillcircle(placeInfo[8].x, placeInfo[8].y, 6); outtextxy(placeInfo[8].x, placeInfo[8].y, "8.红梅公园");
	fillcircle(placeInfo[9].x, placeInfo[9].y, 6); outtextxy(placeInfo[9].x, placeInfo[9].y, "9.常州博物馆");
	fillcircle(placeInfo[10].x, placeInfo[10].y, 6); outtextxy(placeInfo[10].x, placeInfo[10].y, "10.东方盐湖城");
	fillcircle(placeInfo[11].x, placeInfo[11].y, 6); outtextxy(placeInfo[11].x, placeInfo[11].y, "11.环城动漫嬉戏谷");
	fillcircle(placeInfo[12].x, placeInfo[12].y, 6); outtextxy(placeInfo[12].x, placeInfo[12].y, "12.常州市政府");
	fillcircle(placeInfo[13].x, placeInfo[13].y, 6); outtextxy(placeInfo[13].x, placeInfo[13].y, "13.常州市规划馆");
	fillcircle(placeInfo[14].x, placeInfo[14].y, 6); outtextxy(placeInfo[14].x, placeInfo[14].y, "14.南山竹海");
	fillcircle(placeInfo[15].x, placeInfo[15].y, 6); outtextxy(placeInfo[15].x, placeInfo[15].y - 20, "15.青果巷");
	fillcircle(placeInfo[16].x, placeInfo[16].y, 6); outtextxy(placeInfo[16].x, placeInfo[16].y, "16.东坡公园");
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
void CreateUDN()		//存储景点信息、同时存图，各边信息 
{
	int i, j;
	strcpy(placeInfo[1].name, "中华恐龙园"); strcpy(placeInfo[1].introduce, "中华恐龙园是环球恐龙城的核心景点，是一座集科普、游乐、演艺、住宿、购物于一体的一站式旅游度假区，有“东方侏罗纪”之称。");
	strcpy(placeInfo[2].name, "江南环球港"); strcpy(placeInfo[2].introduce, "江南环球港是一个大型休闲乐园，是文旅商全面发展的新型综合体,是涵盖了吃住行游购娱的旅游全产业链。");
	strcpy(placeInfo[3].name, "河海大学"); strcpy(placeInfo[3].introduce, "河海大学是以水利为特色，工科为主，多学科协调发展的教育部直属，教育部、水利部、国家海洋局与江苏省人民政府共建的全国重点大学。");
	strcpy(placeInfo[4].name, "天目湖"); strcpy(placeInfo[4].introduce, "天目湖为一东西窄、南北长的深水湖，被誉为“江南明珠”、“绿色仙境”。其周围现存许多历史文化遗址，物产丰富。");
	strcpy(placeInfo[5].name, "天宁寺"); strcpy(placeInfo[5].introduce, "天宁寺始建于唐贞观年间，是佛教音乐梵呗的发源地之一。它是全国重点佛教寺院之一，江苏省文物保护单位，有东南第一丛林之称。");
	strcpy(placeInfo[6].name, "淹城野生动物园"); strcpy(placeInfo[6].introduce, "江苏淹城野生动物世界位于常州市武进中心城区，距常州市区8公里。");
	strcpy(placeInfo[7].name, "中华孝道园"); strcpy(placeInfo[7].introduce, "中华孝道园坐落于全国十大旅游名片之一的常州市武进太湖湾旅游度假区，是江南一带的“世外桃源”。");
	strcpy(placeInfo[8].name, "红梅公园"); strcpy(placeInfo[8].introduce, "红梅公园位于常州市中心东侧，因园内的著名古建筑-红梅阁而得名，是常州市最大的国家重点公园。");
	strcpy(placeInfo[9].name, "常州博物馆"); strcpy(placeInfo[9].introduce, "常州博物馆，创建于1958年10月，是集收藏、研究、陈列展览于一体的地方综合性博物馆。");
	strcpy(placeInfo[10].name, "东方盐湖城"); strcpy(placeInfo[10].introduce, "东方盐湖城位于中华道教名山—金坛茅山，是由龙城旅游控股集团投资开发建设的，国家级山水养生旅游度假区。");
	strcpy(placeInfo[11].name, "环球动漫嬉戏谷"); strcpy(placeInfo[11].introduce, "环球动漫嬉戏谷乐园，位于常州市武进太湖湾旅游度假区内，是一座国际动漫游戏体验博览园。");
	strcpy(placeInfo[12].name, "常州市政府"); strcpy(placeInfo[12].introduce, "常州市人民政府是常州市人民代表大会的执行机关，是江苏省常州市的国家行政机关，对常州市人民代表大会负责并报告工作。");
	strcpy(placeInfo[13].name, "常州市规划馆"); strcpy(placeInfo[13].introduce, "常州市规划馆展示了常州悠久的城市历史，展现了改革开放以来常州城市建设的辉煌成就，展昭了常州未来发展的宏伟蓝图。");
	strcpy(placeInfo[14].name, "南山竹海"); strcpy(placeInfo[14].introduce, "天目湖南山竹海景区地处江苏、安徽两省交界之处的江苏溧阳，以竹文化和寿文化为主题，是国家5A级景区。");
	strcpy(placeInfo[15].name, "青果巷"); strcpy(placeInfo[15].introduce, "青果巷街区内以明、清、民国时期的建筑为主，分布有名宅故居、祠庙殿宇、桥坊碑石等，是常州国家历史文化名城的“活化石”。");
	strcpy(placeInfo[16].name, "东坡公园"); strcpy(placeInfo[16].introduce, "东坡公园是国家4A级旅游景区，位于常州第一园林——红梅公园东南侧，古运河东去的咽喉要地。");
	//////////////////////////////////////////////////////////////////////////////////////////
	for (i = 1; i <= 16; i++)
		placeInfo[i].JamDegree = 0;
	//////////////////////////////////////////////////////////////////////////////////////////
	for (i = 1; i <= 28; i++)// 相异点间不连通
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

	//定义初始坐标点
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

void Visual()			//景点列表 
{
	system("cls");			//清屏 
	printf("\n\n\n");
	printf("\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t * *                              *景点列表*                                     * *\n");
	printf("\t\t\t * ******************************************************************************* *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <1>中华恐龙园     <2>江南环球港        <3>河海大学         <4>天目湖       * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <5>天宁寺         <6>淹城野生动物园    <7>中华孝道园       <8>红梅公园     * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <9>常州博物馆     <10>东方盐湖城       <11>环球动漫嬉戏谷  <12>常州市政府  * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * *  <13>常州市规划馆  <14>南山竹海         <15>青果巷          <16>东坡公园    * *\n");
	printf("\t\t\t * *                                                                             * *\n");
	printf("\t\t\t * ******************************************************************************* *\n");
	printf("\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
}

int IdentifyID(char s[])//查询景点编号 
{
	int f = 0, i;
	for (i = 1; i <= 16; i++)
	{
		if (strcmp(placeInfo[i].name, s) == 0) //匹配景点和其编号，将名称转换成编号
			return i;
	}
	return -1;
}

void Dijkstra(int v0, int s)		//迪杰斯特拉求最短路径，并输出路线 
{
	int NumString[20] = { 0 };// 路径景点的序号
	int min, i, j, u, v, f;
	int lastV, nextV;
	//int x1, y1, x2, y2;
	int p[100], l[100];
	memset(p, -1, sizeof(p)); // 存储前面点
	memset(l, 0, sizeof(l)); // 记录最终的前面点
	memset(flag, 0, sizeof(flag)); // 标记数组
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0能直接到达，即上一站点为v0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//每次找出距离v0最近点 
		{
			if (flag[j] == 0 && dis[j] < min) // 未被标记 且dis最小
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			// 标记该点 最近点
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//通过最近点更新其他边 
			{
				p[v] = u;					//存储更新的边，即为路线 
				dis[v] = dis[u] + map[u][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//将路线存入栈中，正序输出 
	{
		l[i++] = p[v]; // l 记录 最终的前面点 在 line244 里帮助找到途径景点
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("路线为：\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // 记录路径上景点次序的数组
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	printf("最短路径长度为：%d 单位长度\n", dis[s]);

	int head = IdentifyID(placeInfo[s].name); // 目的地 和 NumString 第 1 连接
	int tail = IdentifyID(placeInfo[v0].name); // 出发地
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	int once_cnt = 0; // 这里放个循环控制语句，把 Map 生成的代码折叠起来
	Background(); // 绘制可通路线
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
	settextstyle(20, 0, "楷体");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "出发点");
	outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "终点");
	_getch();
	closegraph();
}

void Dijkstra_l(int v0, int s, int maxdis)		//迪杰斯特拉求最短路径，并输出路线 
{
	int NumString[20] = { 0 };// 路径景点的序号
	int min, i, j, u, v, f;
	int lastV, nextV;
	int p[100], l[100];
	memset(p, -1, sizeof(p));
	memset(l, 0, sizeof(l));
	memset(flag, 0, sizeof(flag));
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0能直接到达，即上一站点为v0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//每次找出距离v0最近点 
		{
			if (flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			//标记该点 
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//通过最近点更新其他边 
			{
				p[v] = u;					//存储更新的边，即为路线 
				dis[v] = dis[u] + map[u][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//将路线存入栈中，正序输出 
	{
		l[i++] = p[v];
		v = p[v];
	}

	u = i - 1;
	f = u;
	if (dis[s] < maxdis)
	{
		printf("\n");
		printf("路线为：\n");
		printf("%s--->", placeInfo[v0].name);
		for (i = u; i >= 1; i--)
		{
			NumString[i] = IdentifyID(placeInfo[l[i]].name); // 记录路径上景点次序的数组
			printf("%s--->", placeInfo[l[i]].name);
		}
		printf("%s\n", placeInfo[s].name);
		printf("最短路径长度为：%d 单位长度\n", dis[s]);

		int head = IdentifyID(placeInfo[s].name); // 目的地 和 NumString 第 1 连接
		int tail = IdentifyID(placeInfo[v0].name); // 出发地
		initgraph(1000, 900, SHOWCONSOLE);
		setbkcolor(WHITE);
		cleardevice();		
		int once_cnt = 0; // 这里放个循环控制语句，把 Map 生成的代码折叠起来
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
		settextstyle(20, 0, "楷体");
		outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "出发点");
		outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "终点");
		_getch();
		closegraph();
	}
}

void WayMustPass(int v0, int must1,int must2 , int s)		//去掉修路的边，迪杰斯特拉求最短路径，并输出路线 
{
	int NumString[20] = { 0 };// 路径景点的序号
	int NumString1[20] = { 0 };
	int min, i, j, u, v, f, g, w;
	int lastV, nextV;
	//int x1, y1, x2, y2;
	int p[100], l[100], p1[100], l1[100];
	memset(p, -1, sizeof(p)); // 存储前面点
	memset(l, 0, sizeof(l)); // 记录最终的前面点
	memset(flag, 0, sizeof(flag)); // 标记数组
	memset(p1, -1, sizeof(p1)); // 存储前面点
	memset(l1, 0, sizeof(l1)); // 记录最终的前面点
	memset(flag1, 0, sizeof(flag1)); // 标记数组
	for (i = 1; i <= 16; i++)
	{
		dis[i] = mendmap[v0][i];
		if (dis[i] < NoEdge)			//v0能直接到达，即上一站点为v0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//每次找出距离v0最近点 
		{
			if (flag[j] == 0 && dis[j] < min) // 未被标记 且dis最小
			{
				min = dis[j];
				u = j;
			}
		}
		flag[u] = 1;			// 标记该点 最近点
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + mendmap[u][v])			//通过最近点更新其他边 
			{
				p[v] = u;					//存储更新的边，即为路线 
				dis[v] = dis[u] + mendmap[u][v];
			}
		}
	}
	v = must1;
	i = 1;
	while (p[v] != v0)			//将路线存入栈中，正序输出 
	{
		l[i++] = p[v]; // l 记录 最终的前面点 在 line565 里帮助找到途径景点
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("路线为：\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // 记录路径上景点次序的数组
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s--->", placeInfo[must1].name);

	for (i = 1; i <= 16; i++)
	{
		dis[i] = mendmap[must2][i];
		if (dis[i] < NoEdge)			//v0能直接到达，即上一站点为v0 
			p1[i] = must2;
	}

	flag1[must2] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//每次找出距离v0最近点 
		{
			if (flag1[j] == 0 && dis[j] < min) // 未被标记 且dis最小
			{
				min = dis[j];
				w = j;
			}
		}
		flag1[w] = 1;			// 标记该点 最近点
		for (v = 1; v <= 16; v++)
		{
			if (flag1[v] == 0 && dis[v] > dis[w] + mendmap[w][v])			//通过最近点更新其他边 
			{
				p1[v] = w;					//存储更新的边，即为路线 
				dis[v] = dis[w] + mendmap[w][v];
			}
		}
	}
	v = s;
	i = 1;
	while (p1[v] != must2)			//将路线存入栈中，正序输出 
	{
		l1[i++] = p1[v]; // l1 记录 最终的前面点 在 line565 里帮助找到途径景点
		v = p1[v];
	}
	w = i - 1;
	g = w;
	printf("%s--->", placeInfo[must2].name);
	for (i = w; i >= 1; i--)
	{
		NumString1[i] = IdentifyID(placeInfo[l1[i]].name); // 记录路径上景点次序的数组
		printf("%s--->", placeInfo[l1[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	printf("最短路径长度为：%d 单位长度\n", dis[s] + dis[must1]);

	int head = IdentifyID(placeInfo[must1].name); // 目的地 和 NumString 第 1 连接
	int tail = IdentifyID(placeInfo[v0].name); // 出发地

	int head1 = IdentifyID(placeInfo[s].name); // 目的地 和 NumString1 第 1 连接
	int tail1 = IdentifyID(placeInfo[must2].name); // 出发地

	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	int once_cnt = 0; // 这里放个循环控制语句，把 Map 生成的代码折叠起来
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
	//标出 游客指定的必须游玩的路
	setlinecolor(GREEN);
	setlinestyle(PS_SOLID, 8);
	line(placeInfo[must1].x, placeInfo[must1].y, placeInfo[must2].x, placeInfo[must2].y);
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 8);
	// 绘制出 正在维修中不通畅的路
	line(placeInfo[fix1].x, placeInfo[fix1].y, placeInfo[fix2].x, placeInfo[fix2].y);
	settextcolor(RED);
	settextstyle(20, 0, "楷体");
	outtextxy((placeInfo[fix1].x + placeInfo[fix2].x) / 2, (placeInfo[fix1].y + placeInfo[fix2].y) / 2, "此路不通！");
	outtextxy(5, 5, "最近在修路呢~不过您真幸运！想游玩的那条路可以通行哦~");
	outtextxy((placeInfo[must1].x + placeInfo[must2].x) / 2, (placeInfo[must1].y + placeInfo[must2].y) / 2, "这段路\n真是太好玩了！");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "出发点");
	outtextxy(placeInfo[head1].x + 20, placeInfo[head1].y + 20, "终点");
	_getch();
	closegraph();
}

void FastWay(int v0, int s)		
{
	int NumString[20] = { 0 };// 路径景点的序号
	int min, i, j, u, v, f;
	int lastV, nextV;
	int p[100], l[100];

	//随机生成路况，赋予点权重，表示该景点拥堵系数，正比于路线消耗时间
	for (int i = 0; i < 100; i++) 
		placeInfo[i].JamDegree = abs( rand() % 100 + 20 );   
	memset(p, -1, sizeof(p)); // 存储前面点
	memset(l, 0, sizeof(l)); // 记录最终的前面点
	memset(flag, 0, sizeof(flag)); // 标记数组
	for (i = 1; i <= 16; i++)
	{
		dis[i] = map[v0][i];
		if (dis[i] < NoEdge)			//v0能直接到达，即上一站点为v0 
			p[i] = v0;
	}

	flag[v0] = 1;

	for (i = 1; i < 16; i++)
	{
		min = NoEdge;
		for (j = 1; j <= 16; j++)			//每次找出距离v0最近点 
		{
			if (flag[j] == 0 && dis[j] + placeInfo[j].JamDegree < min) // 未被标记 且dis最小
			{
				min = dis[j]+placeInfo[j].JamDegree;
				u = j;
			}
		}
		flag[u] = 1;			// 标记该点 最近点
		for (v = 1; v <= 16; v++)
		{
			if (flag[v] == 0 && dis[v] > dis[u] + map[u][v])			//通过最近点更新其他边 
			{
				p[v] = u;					//存储更新的边，即为路线 
				dis[v] = dis[u] + map[u][v]+ placeInfo[j].JamDegree;
			}
		}
	}
	v = s;
	i = 1;
	while (p[v] != v0)			//将路线存入栈中，正序输出 
	{
		l[i++] = p[v]; // l 记录 最终的前面点 在 line565 里帮助找到途径景点
		v = p[v];
	}
	printf("\n");
	u = i - 1;
	f = u;
	printf("路线为：\n");
	printf("%s--->", placeInfo[v0].name);
	for (i = u; i >= 1; i--)
	{
		NumString[i] = IdentifyID(placeInfo[l[i]].name); // 记录路径上景点次序的数组
		printf("%s--->", placeInfo[l[i]].name);
	}
	printf("%s\n", placeInfo[s].name);
	//printf("Hey Here!!!%d", placeInfo[1].JamDegree);
	printf("最短路径长度为：%d 单位长度\n", dis[s]);
	int head = IdentifyID(placeInfo[s].name); // 目的地 和 NumString 第 1 连接
	int tail = IdentifyID(placeInfo[v0].name); // 出发地
	initgraph(1000, 900, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	Background();
	settextcolor(RED);
	settextstyle(25, 0, "楷体");
	for (int fff = 1; fff <= 16; fff++) 
	{
		char num[20];
		int JamString = (char)placeInfo[fff].JamDegree;
		sprintf(num, "%d", JamString);
		outtextxy(placeInfo[fff].x - 10, placeInfo[fff].y + 20, num);
	}
	outtextxy(5, 5, "景点旁红色数字代表拥堵系数，表示经过该点会延误的时间");
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
	settextstyle(20, 0, "楷体");
	outtextxy(placeInfo[tail].x + 20, placeInfo[tail].y + 20, "出发点");
	outtextxy(placeInfo[head].x + 20, placeInfo[head].y + 20, "终点");
	_getch();
	closegraph();
}

//查询方式 
int QueryPattern(int x)
{
	int i;
	system("cls");			//清屏 
	printf("\n");
	printf("\t\t\t\t\t                    *请输入查询方式*\n\n");
	printf("\t\t\t\t\t                  1、输入景点编号查询\n\n");
	printf("\t\t\t\t\t                  2、输入景点名称查询\n\n");
	printf("\t\t\t\t\t                  0、返回上一界面\n\n\n\n\n\n\n");
	scanf("%d", &i);
	return i;
}

//导航界面 
void DoNavigation()
{
	int x, m, n, u, v, i, j, dis;
	int must1 = 0, must2 = 0;
	char c[100];
	system("cls");			//清屏 
	printf("\n\n\n");
	printf("\t\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t\t\t\t\t ■                                          ■\n");
	printf("\t\t\t\t\t ■   欢 迎 使 用 常 州 景 区 导 航 系 统    ■\n");
	printf("\t\t\t\t\t ■                                          ■\n");
	printf("\t\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n\n");
	printf("\t\t\t       1、查询由某地到达其他所有景点的最短路线\n\n");
	printf("\t\t\t       2、查询任意两景点间的最短路径\n\n");
	printf("\t\t\t       3、输入最大距离限制，查询所有可游玩路线 （游客汽车没油了或者路费有限）  \n\n ");
	printf("\t\t\t       4、指定必须游玩的某段路，查询游玩的路线（随机产生修路情况，可能该段路玩不了哦）  \n\n");
	printf("\t\t\t       5、实时生成景点拥堵情况，查询最快路径（考虑某景点拥堵，经过该点路线变慢）   \n\n");
	printf("\t\t\t       6、查询任意景点信息 \n\n");
	printf("\t\t\t       7、阅览整幅地图   \n\n");
	printf("\t\t\t       8、返回至主界面  \n\n");

	printf("\n\n\n");
	
	restoreMap();// 恢复修路的边

	while (1)//输入错误可重新输入 
	{
		scanf("%d", &x);
		if (x == 1) //遍历从此出发的所有最短路线
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("请输入当前所在景点编号：\n");
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
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点编号：\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("请输入当前所在景点名称：\n");
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
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点名称：\n");
							scanf("%s", c);
							n = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation(); // 返回上级界面
					break;
				}
				else
				{
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 2) // 查询两个景点间最短距离
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("请输入起点景点编号：\n");
					scanf("%d", &n);
					printf("\n请输入终点景点编号：\n");
					scanf("%d", &m);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							Dijkstra(n, m);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点景点编号：\n");
							scanf("%d", &n);
							printf("\n请输入终点景点编号：\n");
							scanf("%d", &m);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("请输入起点景点名称：\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("\n请输入终点景点名称：\n");
					scanf("%s", c);
					m = IdentifyID(c);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							Dijkstra(n, m);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点景点名称：\n");
							scanf("%s", c);
							n = IdentifyID(c);
							printf("\n请输入终点景点名称：\n");
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
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 3) //有距离限制的路线 
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("请输入当前所在景点编号：\n");
					scanf("%d", &n);
					printf("请输入最远能游玩多远距离: \n");
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
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点编号：\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("请输入当前所在景点名称：\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("请输入最远能游玩多远距离: \n");
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
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点名称：\n");
							scanf("%s", c);
							n = IdentifyID(c);
						}
					}
					break;
				}
				else if (v == 0)
				{
					DoNavigation(); // 返回上级界面
					break;
				}
				else
				{
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 4) // 游客知道某段路很好玩，游客必须经过这段路再到终点，查询该路径
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
					printf("请输入您必须通过的路段连接的两个景点的名称\n其一:\n");
					scanf("%d", &must1);
					printf("\n其二:\n");					
					scanf("%d", &must2);
					while (1)
					{
						if (map[must1][must2]!=NoEdge)
						{
							break;
						}
						else
						{
							printf("\n该两景点间无直接通路！请重新输入！\n\n");
							printf("请输入您必须通过的路段连接的两个景点的名称\n\n其一:\n\n");
							scanf("%d", &must1);
							printf("其二:\n\n");
							scanf("%d", &must2);
						}
					}
					if ((must1 == fix1) && (must2 == fix2) || (must2 == fix1) && (must1 == fix2))
					{
						printf("哎呀太不幸了！您想玩的这段路刚好在修，换一条必经之路试试?");
						break;
					}
					printf("请输入起点景点编号：\n");
					scanf("%d", &n);
					printf("\n请输入终点景点编号：\n");
					scanf("%d", &m);
					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{					
							//printf("%d\n", must1);
							WayMustPass(n,must1,must2, m);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点景点编号：\n");
							scanf("%d", &n);
							printf("\n请输入终点景点编号：\n");
							scanf("%d", &m);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					showMap();
					printf("请输入您必须通过的路段连接的两个景点的名称\n其一:\n");
					scanf("%s", c);
					must1 = IdentifyID(c);
					printf("其二:\n");
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
							printf("\n该两景点间无直接通路！请重新输入！\n\n");
							printf("请输入您必须通过的路段连接的两个景点的名称\n其一:\n");
							scanf("%s", c);
							must1 = IdentifyID(c);
							printf("其二:\n");
							scanf("%s", c);
							must2 = IdentifyID(c);
						}
					}
					if ((must1 == fix1) && (must2 == fix2) || (must2 == fix1) && (must1 == fix2))
					{
						printf("哎呀太不幸了！您想玩的这段路刚好在修，换一条必经之路试试?");
						break;
					}
					printf("请输入起点景点名称：\n");
					scanf("%s", c);
					n = IdentifyID(c);
					printf("\n请输入终点景点名称：\n");
					scanf("%s", c);
					m = IdentifyID(c);

					while (1)
					{
						if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
						{
							WayMustPass(n, m,must1,must2);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点景点名称：\n");
							scanf("%s", c);
							n = IdentifyID(c);
							printf("\n请输入终点景点名称：\n");
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
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 5) // 考虑点的权值（经过某点会拥堵延迟时间）查询最快路径
		{
		v = QueryPattern(x);
		while (1)
		{
			if (v == 1)
			{
				Visual();
				showMap();
				printf("请输入起点景点编号：\n");
				scanf("%d", &n);
				printf("\n请输入终点景点编号：\n");
				scanf("%d", &m);
				while (1)
				{
					if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
					{
						FastWay(n, m);
						printf("\n\n按回车键返回至导航系统界面\n\n");
						getchar(); getchar();
						DoNavigation();
						break;
					}
					else
					{
						printf("\n输入不合法！请重新输入！\n\n");
						printf("请输入起点景点编号：\n");
						scanf("%d", &n);
						printf("\n请输入终点景点编号：\n");
						scanf("%d", &m);
					}
				}
				break;
			}
			else if (v == 2)
			{
				Visual();
				showMap();
				printf("请输入起点景点名称：\n");
				scanf("%s", c);
				n = IdentifyID(c);
				printf("\n请输入终点景点名称：\n");
				scanf("%s", c);
				m = IdentifyID(c);
				while (1)
				{
					if (n >= 1 && n <= 16 && m >= 1 && m <= 16 && n != m)
					{
						FastWay(n, m);
						printf("\n\n按回车键返回至导航系统界面\n\n");
						getchar(); getchar();
						DoNavigation();
						break;
					}
					else
					{
						printf("\n输入不合法！请重新输入！\n\n");
						printf("请输入起点景点名称：\n");
						scanf("%s", c);
						n = IdentifyID(c);
						printf("\n请输入终点景点名称：\n");
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
				printf("\n\n输入错误请重新输入！\n\n");
				scanf("%d", &v);
			}
		}
		break;
		}	
		else if (x == 6) // 查询景点信息 
		{
			v = QueryPattern(x);
			while (1)
			{
				if (v == 1)
				{
					Visual();
					showMap();
					printf("请输入景点编号：\n");
					scanf("%d", &n);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							printf("\n\n这里是%s\n\n%s\n\n地理坐标为(%d,%d)\n\n", placeInfo[n].name, placeInfo[n].introduce,placeInfo[n].x,placeInfo[n].y);
							printf("按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点编号：\n");
							scanf("%d", &n);
						}
					}
					break;
				}
				else if (v == 2)
				{
					Visual();
					printf("请输入景点名称：\n");
					scanf("%s", c);
					n = IdentifyID(c);
					while (1)
					{
						if (n >= 1 && n <= 16)
						{
							printf("\n\n这里是%s\n\n%s\n\n地理坐标为(%d,%d)\n\n", placeInfo[n].name, placeInfo[n].introduce, placeInfo[n].x, placeInfo[n].y);
							printf("按回车键返回至导航系统界面\n\n");
							getchar(); getchar();
							DoNavigation();
							break;
						}
						else
						{
							printf("\n该景点不存在！请重新输入景点名称：\n");
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
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d", &v);
				}
			}
			break;
		}
		else if (x == 7) // 展示整幅地图
		{
			Map();
			break;
		}
		else if (x == 8) // 返回主菜单
		{
			NavBar();
			break;
		}
		else
		{
			printf("\n\n输入错误！请重新输入！\n");
		}
	}

}

//导航栏主界面 
void NavBar()
{
	system("cls");		//清屏 
	int m;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");	
	printf("\t\t\t\t\t    *--------------------主 界 面------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------1、进 入 导 航 系 统----------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------2、退 出 程 序----------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------3、制 作 人-------------------------*\n");
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
			printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴∵\n");
			printf("\t\t\t\t\t∴∵                                                      ∴∵\n");
			printf("\t\t\t\t\t∴∵        欢      迎     下     次      使      用      ∴∵\n");
			printf("\t\t\t\t\t∴∵                                                      ∴∵\n");
			printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴∴∵∴∵∴∵∴∵∴∵∴∴∵∴∵∵\n");
			printf("\n\n\n");
			break;
		}
		else if (m == 3)
		{
			system("cls");		//清屏 
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t    ****************************************************\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *                    制 作 人                      *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *               1961010516     秦 骁               *\n");
			printf("\t\t\t\t\t    *               1962310203     顾书宁              *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    *                                                  *\n");
			printf("\t\t\t\t\t    ****************************************************\n");
			printf("\n\n\n\n\n");
			printf("按回车键返回主界面\n");
			getchar(); getchar();
			NavBar();
			break;
		}
		else
		{
			printf("\n\n\n\t\t输入错误请重新输入！\n\n\n\n");
			scanf("%d", &m);
		}
	}

}

//欢迎进入 
void MainInterface()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t   _______________________________________________________ \n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |-----------------***数据结构课设***-------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |----------------欢迎使用常州导航系统------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |--------------------按回车键继续----------------------|\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |                                                      |\n");
	printf("\t\t\t\t\t   |______________________________________________________|\n");
	getchar();

	NavBar();
}

int main(void)
{
	system("color f0");		//改变运行窗底色
	system("mode con cols=150 lines=40");		//改变运行窗口大小 
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
