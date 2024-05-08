#include <bits/stdc++.h>
#include <graphics.h>
#include <windows.h>
#include <conio.h>
#define key_down(key_name) ((GetAsyncKeyState(key_name))?1:0)
using namespace std;

int br = 3;
POINT ptbef, ptnow;
int bas = 0, xbas = 0, ybas = 0;
void drawbg(int wv, int cc) {   //For backgroud
	cleardevice();
	setlinewidth(0);
	int b = cc;
	for (int k = 0 + wv; k <= 360 + wv; k++) {
		setcolor(EGERGB(b, b, b));
		line(0, k, 1280, k);
		if (k % br == 0) {
			b--;
		}
	}
	for (int k = 0 + wv; k <= 360 + wv; k++) {
		setcolor(EGERGB(b, b, b));
		line(0, k + 360, 1280, k + 360);
		if (k % br == 0) {
			b++;
		}
	}
}

struct mappo{
	double x, y, z;
	int con, sss;
};
mappo p[2000000], sh[2000000], pp[2000000], pl;   //For video

bool mp[20000][20000];
int seeds, mapx, mapy;  //For building map

/*void buildmap(int a, int b) {
	int s = rand();
	s = s % 2;
	if (s) {
		mp[a][b] = !mp[a][b];
	}
	if (a < mapx - 1) {
		buildmap(a + 1, b);
	}
	if (b < mapy - 1) {
		buildmap(a, b + 1);
	}
	return;
}*///Do not use this function!!!
void buildr(int a, int b, int c) {
	Q:
	if (mp[a + 1][b + 1] == 1 && mp[a + 1][b - 1] == 1 && mp[a - 1][b + 1] == 1 && mp[a - 1][b - 1] == 1) {
		return;
	}
	int s = rand();
	s = s % 4;
	mp[a][b] = 1;
	if (s == 0) {
		if (a > 0) {
			if (c != 2) {
				buildr(a - 1, b, 0);
			} else {
				goto Q;
			}
		}
	} else if (s == 1) {
		if (b > 0) {
			if (c != 3) {
				buildr(a, b - 1, 1);
			} else {
				goto Q;
			}
		}
	} else if (s == 2) {
		if (a < mapx - 1) {
			if (c != 0) {
				buildr(a + 1, b, 2);
			} else {
				goto Q;
			}
		}
	} else if (s == 3) {
		if (b < mapy - 1) {
			if (c != 1) {
				buildr(a, b + 1, 3);
			} else {
				goto Q;
			}
		}
	}
}

int sum = 0, sum1, sum2 = 1; //For showing the map
double si, hei, vi;

bool cmp(mappo a, mappo b) {
	return a.y >= b.y;
}
double bbb = 1;
void sho() {
	/*for (int i = 0; i < sum; i++) {
		putpixel(p[i].x + 640, p[i].y + 360, BLACK);
	}*/
	setlinewidth(3);
	for (int i = 0; i < sum; i++) {
		//color_t color = EGERGB(0, 0, 0);
		sh[i].x = p[i].x / p[i].y * vi * sum2 + 640, sh[i].y = p[i].z / p[i].y * vi * sum2 + 360, sh[i].con = p[i].con;
		/*if (p[i].y >= 0) {
			if (p[p[i].con].y >= 0) {
				line(sh[i].x, sh[i].y, sh[sh[i].con].x, sh[sh[i].con].y);
			}
		}*/
		//cout << p[i].x << " " << p[i].y << endl;
		//putpixel(p[i].x + 640, p[i].y + 360, BLACK);
	}
	/*for (int i = 0; i < sum1; i++) {
		if (p[i].y >= 0) {
			if (p[i + sum1].y >= 0) {
				line(sh[i].x, sh[i].y, sh[i + sum1].x, sh[i + sum1].y);
			}
		}
	}*/
	/*for (int i = 0; i < sum; i++) {
		if (p[i].y >= 0 && p[p[i].con].y >= 0 && p[p[p[i].con].con].y >= 0 && p[p[p[p[i].con].con].con].y >= 0) {
			int f[8] = {sh[i].x, sh[i].y, sh[sh[i].con].x, sh[sh[i].con].y, sh[sh[sh[i].con].con].x, sh[sh[sh[i].con].con].y, sh[sh[sh[sh[i].con].con].con].x, sh[sh[sh[sh[i].con].con].con].y};
			fillpoly(4, f);
		}
	}*/
	//int ss = 0, xx = 0, yy = 0, zz = 0;
	setbkcolor(min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)));
	drawbg(0, min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)));
	if (min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)) >= 190) {
		PlaySound("bk.wav", NULL, SND_ASYNC|SND_NOSTOP);
	}
	if (min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)) <= 190 && min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)) >= 160) {
		if (rand() % 2500 == 987) {
			PlaySound("hh.wav", NULL, SND_ASYNC);//|SND_NOSTOP);
		}
	}
	if (min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)) <= 80) {
		if (rand() % 3500 == 531) {
			PlaySound("kd.wav", NULL, SND_ASYNC);//|SND_NOSTOP);
		}
	}
	if (min(255.0, max(0.0, pow(sqrt(pow(p[sum - 1].y, 2) + pow(p[sum - 1].x, 2)) / 1000, 2) + 80)) <= 100) {
		if (rand() % 2500 == 426) {
			PlaySound("zhong.wav", NULL, SND_ASYNC);//|SND_NOSTOP);
		}
	}
	int sa;
	double mmin = 0x3f3f3f3f;
	for (int i = 0; i < sum1; i++) {
		double sq = sqrt(pow(p[i].x, 2) + pow(p[i].y, 2));
		if (sq <= mmin) {
			sa = i;
			mmin = sq;
		}
	}
	for (int i = sum1 - 1; i >= sa; i--) {
		if (p[i].y >= 0 && p[i + sum1].y >= 0 && p[p[i].con].y >= 0 && p[p[i].con + sum1].y >= 0 && p[i].y <= 1000) {
			bbb = i / 4 * 0.08;
			/*if (ss != bbb) {
				xx = rand() % 225 + 1;
				yy = rand() % 225 + 1;
				zz = rand() % 225 + 1;
			}
			ss = bbb;*///HahA
			setcolor(EGERGB(255 - (int)bbb, 255 - (int)bbb, 255 - (int)bbb));
			setfillcolor(EGERGB(255 - (int)bbb, 255 - (int)bbb, 255 - (int)bbb));
			//setcolor(EGERGB(xx, yy, zz));
			//setfillcolor(EGERGB(xx, yy, zz));
			int f[8] = {sh[i].x, sh[i].y, sh[sh[i].con].x, sh[sh[i].con].y, sh[sh[i].con + sum1].x, sh[sh[i].con + sum1].y, sh[i + sum1].x, sh[i + sum1].y};
			fillpoly(4, f);
		}
	}
	for (int i = 0; i < sa; i++) {
		if (p[i].y >= 0 && p[i + sum1].y >= 0 && p[p[i].con].y >= 0 && p[p[i].con + sum1].y >= 0 && p[i].y <= 1000) {
			bbb = i / 4 * 0.08;
			/*if (ss != bbb) {
				xx = rand() % 225 + 1;
				yy = rand() % 225 + 1;
				zz = rand() % 225 + 1;
			}
			ss = bbb;*///HahA
			setcolor(EGERGB(255 - (int)bbb, 255 - (int)bbb, 255 - (int)bbb));
			setfillcolor(EGERGB(255 - (int)bbb, 255 - (int)bbb, 255 - (int)bbb));
			//setcolor(EGERGB(xx, yy, zz));
			//setfillcolor(EGERGB(xx, yy, zz));
			int f[8] = {sh[i].x, sh[i].y, sh[sh[i].con].x, sh[sh[i].con].y, sh[sh[i].con + sum1].x, sh[sh[i].con + sum1].y, sh[i + sum1].x, sh[i + sum1].y};
			fillpoly(4, f);
		}
	}
	/*setcolor(YELLOW);
	for (int i = 0; i < sum1; i++) {
		if (p[i].y >= 0) {
			if (p[i + sum1].y >= 0) {
				for (double k = 0; k < abs(sh[i].x - sh[sh[i].con].x); k++) {
					double kl = (sh[i].y - sh[sh[i].con].y) / (sh[i].x - sh[sh[i].con].x);
					double kl2 = (sh[i + sum1].y - sh[sh[i + sum1].con].y) / (sh[i + sum1].x - sh[sh[i + sum1].con].x);
					line(sh[i].x + k, sh[i].y + k * kl, sh[i + sum1].x + k, sh[i + sum1].y + k * kl2);
				}
			}
		}
	}
	delay_ms(0);*/
}

double r = 40.0;//Size of PlayerBox

bool torc(char s) {
	bool summ = 1;
	if (s == 'W') {
		for (int i = 0; i < sum; i++) {
			if (p[i].y >= 0 && (sqrt(p[i].x * p[i].x + p[i].y * p[i].y) <= r || (((p[i].x <= 0 && p[p[i].con].x >= 0) || (p[i].x >= 0 && p[p[i].con].x <= 0)) && abs(p[i]. y - p[i].x * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) / sqrt(1 + ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x)) * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) <= r))) {
				summ = !summ;
				break;
			}
		}
	}
	if (s == 'S') {
		for (int i = 0; i < sum; i++) {
			if (p[i].y <= 0 && (sqrt(p[i].x * p[i].x + p[i].y * p[i].y) <= r || (((p[i].x <= 0 && p[p[i].con].x >= 0) || (p[i].x >= 0 && p[p[i].con].x <= 0)) && abs(p[i]. y - p[i].x * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) / sqrt(1 + ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x)) * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) <= r))) {
				summ = !summ;
				break;
			}
		}
	}
	if (s == 'A') {
		for (int i = 0; i < sum; i++) {
			if (p[i].x <= 0 && (sqrt(p[i].x * p[i].x + p[i].y * p[i].y) <= r || (((p[i].y <= 0 && p[p[i].con].y >= 0) || (p[i].y >= 0 && p[p[i].con].y <= 0)) && abs(p[i]. y - p[i].x * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) / sqrt(1 + ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x)) * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) <= r))) {
				summ = !summ;
				break;
			}
		}
	}
	if (s == 'D') {
		for (int i = 0; i < sum; i++) {
			if (p[i].x >= 0 && (sqrt(p[i].x * p[i].x + p[i].y * p[i].y) <= r || (((p[i].y <= 0 && p[p[i].con].y >= 0) || (p[i].y >= 0 && p[p[i].con].y <= 0)) && abs(p[i]. y - p[i].x * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) / sqrt(1 + ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x)) * ((p[i].y - p[p[i].con].y) / (p[i].x - p[p[i].con].x))) <= r))) {
				summ = !summ;
				break;
			}
		}
	}
	return summ;
}

int main() {
	initgraph(1280, 720, INIT_RENDERMANUAL);
	//initgraph(1920, 1080, INIT_RENDERMANUAL);
	setcaption("Lost Land(Preview)");
	//setbkcolor(EGERGB(130, 130, 130));
	setbkcolor(WHITE);
	/*for (int i = 0; i < sum; i++) {
		cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
	}*/
	GetCursorPos(&ptbef);
	double sp = 1;
	PIMAGE tit = newimage(), bk = newimage(), bt1 = newimage(), bt2 = newimage(), bt3 = newimage(), bt11 = newimage(), bt22 = newimage(), bt33 = newimage();
	getimage(tit, "title.png");
	getimage(bk, "bk.png");
	getimage(bt1, "button2.png");
	getimage(bt2, "button2.png");
	getimage(bt3, "button2.png");
	getimage(bt11, "button.png");
	getimage(bt22, "button.png");
	getimage(bt33, "button.png");
	mouse_msg msg;
	while(1) {
		setbkmode(TRANSPARENT);	
		while(1) {
			msg = getmouse();
			cleardevice();
			putimage(0, 0, bk);
			putimage_withalpha(NULL, tit, 500, 50);
			if (msg.x >= 510 && msg.x <= 1180 && msg.y >= 290 && msg.y <= 370) { 
				setcolor(YELLOW);
				setfont(20, 0, "黑体", 0, 0, 1000, 0, 0 ,0);
				xyprintf(782, 320, "开      始");
				putimage_withalpha(NULL, bt11, 520, 300);
				if (msg.is_left() && msg.is_down()) {
					break;
				}
			} else {
				setcolor(WHITE);
				setfont(20, 0, "黑体", 0, 0, 0, 0, 0 ,0);
				xyprintf(785, 320, "开      始");
				putimage_withalpha(NULL, bt1, 520, 300);
			}
			if (msg.x >= 510 && msg.x <= 1180 && msg.y >= 380 && msg.y <= 460) {
				setcolor(YELLOW);
				setfont(20, 0, "黑体", 0, 0, 1000, 0, 0 ,0);
				xyprintf(782, 410, "设      置");
				putimage_withalpha(NULL, bt22, 520, 390);
			} else {
				setcolor(WHITE);
				setfont(20, 0, "黑体", 0, 0, 0, 0, 0 ,0);
				xyprintf(785, 410, "设      置");
				putimage_withalpha(NULL, bt2, 520, 390);
			}
			if (msg.x >= 510 && msg.x <= 1180 && msg.y >= 470 && msg.y <= 550) {
				setcolor(YELLOW);
				setfont(20, 0, "黑体", 0, 0, 1000, 0, 0 ,0);
				xyprintf(782, 500, "退      出");
				putimage_withalpha(NULL, bt33, 520, 480);
				if (msg.is_left() && msg.is_down()) {
					return 0;
				}
			} else {
				setcolor(WHITE);
				setfont(20, 0, "黑体", 0, 0, 0, 0, 0 ,0);
				xyprintf(785, 500, "退      出");
				putimage_withalpha(NULL, bt3, 520, 480);
			}
			//delay_ms(0);
		}
		
		//Game
		memset(p, 0, sizeof(p));
		memset(sh, 0, sizeof(sh));
		memset(pp, 0, sizeof(pp));
		pl.con = pl.sss = pl.x = pl.y = pl.z = 0;
		memset(mp, 0, sizeof(mp));
		sum = 0, sum1, sum2 = 1;
		br = 3;
		bas = 0, xbas = 0, ybas = 0;
		pl.x = 0, pl.y = 0, pl.z = 0;
		//scanf("%d %d %d", &seeds, &mapx, &mapy);
		//cin >> si >> hei >> vi;
		seeds = 1000, mapx = 100, mapy = 100, si = 100, hei = 100, vi = 550;
		printf("[log] Initialization...\n");
		srand(time(NULL));
		for (int i = 0; i < mapx; i++) {
			for (int k = 0; k < mapy; k++) {
				mp[i][k] = 0;
			}
		}
		printf("[log] Done\n");
		for (int i = 0; i < seeds; i++) {
			int ix = rand() % mapx + 1, iy = rand() % mapy + 1;
			buildr(ix, iy, rand() % 4);
		}
		printf("[log] Finsh building\n");
		printf("[log] Prepare for struct\n");
		for (int i = 0; i < mapx; i++) {
			for (int k = 0; k < mapy; k++) {
				if (mp[i][k] == 0) {
					p[sum].x = k * si, p[sum].y = i * si, p[sum].con = sum + 1, p[sum].sss = sum;
					sum++;
					p[sum].x = (k + 1) * si, p[sum].y = i * si, p[sum].con = sum + 1, p[sum].sss = sum;
					sum++;
					p[sum].x = (k + 1) * si, p[sum].y = (i + 1) * si, p[sum].con = sum + 1, p[sum].sss = sum;
					sum++;
					p[sum].x = k * si, p[sum].y = (i + 1) * si, p[sum].con = sum - 3, p[sum].sss = sum;
					sum++;
				}
			}
		}
		for (int i = 0; i < sum; i++) {
			p[i].z = hei;
		}
		sum1 = sum;
		for (int i = 0; i < sum1; i++) {
			p[sum1 + i].x = p[i].x, p[sum1 + i].y = p[i].y, p[sum1 + i].z = -p[i].z, p[sum1 + i].con = p[i].con + sum1, p[sum1 + i].sss = sum1 + i;
			sum++;
		}
		printf("[log] Done(Number of points = %d)\n", sum);
		double xd = (double)mapy * si, yd = (double)mapx * si;
		cout << xd << " " << yd << endl;
		for (int i = 0; i < sum; i++) {
			p[i].x -= xd / 2, p[i].y -= yd / 2;
		}
		for (int i = 0; i < sum; i++) {
			pp[i] = p[i];
		}
		while(1) {
			cleardevice();
			GetCursorPos(&ptnow);
			bas = bas + ptnow.y - ptbef.y;
			xbas = ptnow.x - ptbef.x;
			ybas = ptnow.y - ptbef.y;
			ptbef = ptnow;
			if (key_down(27)) {
				//linshi
				//set
				//Sleep(50);
				break;
			}
			if (key_down('A') && torc('A')) {
				PlaySound("jiaobu.wav", NULL, SND_ASYNC|SND_NOSTOP|SND_SYNC);
				for (int i = 0; i < sum; i++) {
					p[i].x += sp;
				}
				pl.x -= sp;
			}
			if (key_down('D') && torc('D')) {
				PlaySound("jiaobu.wav", NULL, SND_ASYNC|SND_NOSTOP|SND_SYNC);
				for (int i = 0; i < sum; i++) {
					p[i].x -= sp;
				}
				pl.x += sp;
			}
			if (key_down('W') && torc('W')) {
				PlaySound("jiaobu.wav", NULL, SND_ASYNC|SND_NOSTOP|SND_SYNC);
				for (int i = 0; i < sum; i++) {
					p[i].y -= sp;
				}
				pl.y += sp;
			}
			if (key_down('S') && torc('S')) {
				PlaySound("jiaobu.wav", NULL, SND_ASYNC|SND_NOSTOP|SND_SYNC);
				for (int i = 0; i < sum; i++) {
					p[i].y += sp;
				}
				pl.y -= sp;
			}
			if (key_down('J')) {
				for (int i = 0; i < sum; i++) {
					p[i].x += sp;
				}
				pl.x -= sp;
			}
			if (key_down('L')) {
				for (int i = 0; i < sum; i++) {
					p[i].x -= sp;
				}
				pl.x += sp;
			}
			if (key_down('I')) {
				for (int i = 0; i < sum; i++) {
					p[i].y -= sp;
				}
				pl.y += sp;
			}
			if (key_down('K')) {
				for (int i = 0; i < sum; i++) {
					p[i].y += sp;
				}
				pl.y -= sp;
			}
			//cout << pl.x << " " << pl.y << endl;
			double ro = 2.2;
			ro = ro * 3.1415 / 180;
			//if (ybas == 0) {
				if (xbas < 0) {
					for (int i = 0; i < sum; i++) {
						int px = p[i].x;
						p[i].x = p[i].x * cos(ro) + p[i].y * sin(ro);
						p[i].y = -px * sin(ro) + p[i].y * cos(ro);
						int pxx = pp[i].x;
						pp[i].x = pp[i].x * cos(ro) + pp[i].y * sin(ro);
						pp[i].y = -pxx * sin(ro) + pp[i].y * cos(ro);
					}
				} else if (xbas > 0) {
					for (int i = 0; i < sum; i++) {
						int px = p[i].x;
						p[i].x = p[i].x * cos(ro) - p[i].y * sin(ro);
						p[i].y = px * sin(ro) + p[i].y * cos(ro);
						int pxx = pp[i].x;
						pp[i].x = pp[i].x * cos(ro) - pp[i].y * sin(ro);
						pp[i].y = pxx * sin(ro) + pp[i].y * cos(ro);
					}
				}
			//}
			/*if (xbas == 0) {
				if (ybas < 0) {
					for (int i = 0; i < sum; i++) {
						int pz = p[i].z;
						p[i].z = p[i].z * cos(ro) + p[i].y * sin(ro);
						p[i].y = -pz * sin(ro) + p[i].y * cos(ro);
					}
				} else if (ybas > 0) {
					for (int i = 0; i < sum; i++) {
						int pz = p[i].z;
						p[i].z = p[i].z * cos(ro) - p[i].y * sin(ro);
						p[i].y = pz * sin(ro) + p[i].y * cos(ro);
					}
				}
			}*/   //Do not use this now!
			sho();
			delay_ms(0);
		}
		//getch();
		/*setbkcolor(EGERGB(130, 130, 130));
		color_t color = EGERGB(0, 0, 0);
		putpixel(color, 0, 0);
		GetCursorPos(&ptbef);
		while(1) {
			GetCursorPos(&ptnow);
			bas = bas + ptnow.y - ptbef.y;
			drawbg(-bas);
			delay_ms(0);
			ptbef = ptnow;
		}*/
	}
	return 0;
}
