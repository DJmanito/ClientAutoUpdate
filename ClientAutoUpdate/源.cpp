#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <graphics.h>
#include <direct.h>
#include <stdlib.h>
#include <Windows.h>
#include <wininet.h>
#include <UrlMon.h>
#include <conio.h>
#include <io.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "resource.h"
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment (lib, "urlmon.lib")

IMAGE start, VerMegAC_1, VerMegAC_2, VerMessage;
IMAGE update_background, update_warning, Update_info, Update_AC1, Update_AC2;
IMAGE temp_textbackground, button_1, button_2, button_3;

int time = 0;
int high = 300;
int work_text_long = 469;
int text_px = 51;
char launch[20] = "start HMCL-";
float localversion = 0.0;
float newestversion = 0.0;
float nextversion = 0.0;
bool flag = true;
bool flag_text = true;
bool flag_mouse = true;
bool flag_download = false;
char work_text[100] = "";
struct stat buf;
MOUSEMSG m;

//��ʼ��
void ��ʼ��()
{
	AddFontResource("STHUPO.TTF");
	system("ipconfig /flushdns");
	DeleteUrlCacheEntry("https://www.minecraft-ofmine.top/update.txt");
	loadimage(&start, _T("IMAGE"), MAKEINTRESOURCE(IDR_start), 800, 481);
	loadimage(&VerMegAC_1, _T("IMAGE"), MAKEINTRESOURCE(IDR_VerMegAC_1), 239, 115);
	loadimage(&VerMegAC_2, _T("IMAGE"), MAKEINTRESOURCE(IDR_VerMegAC_2), 239, 115);
	loadimage(&VerMessage, _T("IMAGE"), MAKEINTRESOURCE(IDR_VerMessage), 239, 115);
	loadimage(&update_background, _T("IMAGE"), MAKEINTRESOURCE(IDR_nowupdate), 800, 481);
	loadimage(&update_warning, _T("IMAGE"), MAKEINTRESOURCE(IDR_warning), 320, 70);
	loadimage(&Update_info, _T("IMAGE"), MAKEINTRESOURCE(IDR_update_info), 502, 208);
	loadimage(&Update_AC1, _T("IMAGE"), MAKEINTRESOURCE(IDR_Update_AC1), 502, 208);
	loadimage(&Update_AC2, _T("IMAGE"), MAKEINTRESOURCE(IDR_Update_AC2), 502, 208);
	loadimage(&button_1, _T("IMAGE"), MAKEINTRESOURCE(IDR_BUTTON_1), 380, 70);
	loadimage(&button_2, _T("IMAGE"), MAKEINTRESOURCE(IDR_BUTTON_2), 380, 70);
	loadimage(&button_3, _T("IMAGE"), MAKEINTRESOURCE(IDR_BUTTON_3), 380, 70);
	initgraph(800, 481);
	setbkmode(TRANSPARENT);
}

//������ʾ
void error(int a)
{
	int choice;
	char temp[1000] = "\0";
	remove("temp.dat");
	switch (a)
	{
	case 1:
		sprintf(temp, "��鱾�ذ汾ʧ��\nѡ <��> ǰ�������������������¿ͻ���,ѡ <��> �˳�����");
		choice = MessageBox(NULL, temp, TEXT("��鱾�ذ汾ʧ��"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://www.minecraft-ofmine.top/");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 2:
		sprintf(temp, "��ʱ�޷����ӵ�����������...\nǰ���ٶ������ֶ����ظ��µ�� <��> ,�Ժ����Ե�� <��>");
		choice = MessageBox(NULL, temp, TEXT("��������汾ʧ��,�Ƿ��ֶ�����"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://pan.baidu.com/s/1ciyLH1I726Uy6NWrLKnA8A");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 3:
		sprintf(temp, "�ļ�����ʧ��...\nǰ���ٶ����ֶ����ظ��µ�� <��> ,�Ժ����Ե�� <��>");
		choice = MessageBox(NULL, temp, TEXT("�ļ�����ʧ��"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://pan.baidu.com/s/1ciyLH1I726Uy6NWrLKnA8A");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 4:
		sprintf(temp, "���������ҸĿͻ���!\nѡ <��> ǰ�������������������¿ͻ���,ѡ <��> �˳�����");
		choice = MessageBox(NULL, temp, TEXT("�ͻ��˰汾�Աȳ���"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://www.minecraft-ofmine.top/");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 5:
		sprintf(temp, "ѡ <��> ǰ�������������������¿ͻ���,ѡ <��> �˳�����");
		choice = MessageBox(NULL, temp, TEXT("�޷������ͻ���������"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://www.minecraft-ofmine.top/");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 6:
		sprintf(temp, "��ȡ���¸��µİ汾����!\n��Ҳ��������ԭ��\nѡ <��> ǰ�������������������¿ͻ���,ѡ <��> �˳�����");
		choice = MessageBox(NULL, temp, TEXT("�쳣����"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://www.minecraft-ofmine.top/");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	case 7:
		sprintf(temp, "��ȡ��һ����Ҫ���µİ汾����!\n��Ҳ��������ԭ��\nѡ <��> ǰ�������������������¿ͻ���,ѡ <��> �˳�����");
		choice = MessageBox(NULL, temp, TEXT("�쳣����"), MB_YESNO);
		switch (choice)
		{
		case IDYES:
			system("start https://www.minecraft-ofmine.top/");
			break;
		case IDNO:
			break;
		}
		exit(a);
		break;
	}
}

//���̼�����
DWORD WINAPI loading(LPVOID pM)
{
	int R = 255, G = 0, B = 0;
	int i = 0;
	int status = 0;
	IMAGE temp;
	getimage(&temp, 0, 357, 800, 6);
	while (flag)
	{
		setlinecolor(RGB(R, G, B));
		line(i,357,i,362);
		i++;
		if (i >= 800) i = 0;
		switch (status)
		{
		case 0:
			B++;
			if (B >= 255) status = 1;
			break;
		case 1:
			R--;
			if (R <= 0) status = 2;
			break;
		case 2:
			G++;
			if (G >= 255) status = 3;
			break;
		case 3:
			B--;
			if (B <= 0) status = 4;
			break;
		case 4:
			R++;
			if (R >= 255) status = 5;
			break;
		case 5:
			G--;
			if (G <= 0) status = 0;
			break;
		}
		Sleep(3);
	}
	putimage(0, 357, &temp);
	flag = true;
	return 0;
}

//���ֶ���
DWORD WINAPI Worktext_AC(LPVOID pM)
{
	RECT text_desplay_area = { 0,high,work_text_long,high + 51 };
	RECT download_info_desplay_area = { 0,high,714,high + 51 };
	int i = 0;
	char temptext[103] = "";
	char del[4] = ".";
	char file_name[20] = "";
	sprintf(file_name, "V%.2f.zip", nextversion);
	while (flag_text)
	{
		putimage(0, high, &temp_textbackground);
		switch (i)
		{
		case 0:
			sprintf(del, "\0");
			i = 1;
			break;
		case 1:
			sprintf(del, ".\0");
			i = 2;
			break;
		case 2:
			sprintf(del, "..\0");
			i = 3;
			break;
		case 3:
			sprintf(del, "...\0");
			i = 0;
			break;
		}
		settextcolor(RGB(193, 228, 235));
		settextstyle(text_px, 0, _T("��������"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
		sprintf(temptext, "%s%s", work_text, del);
		drawtext(temptext, &text_desplay_area, DT_BOTTOM | DT_LEFT | DT_SINGLELINE);
		if (flag_download)
		{
			stat(file_name, &buf);
			settextcolor(RGB(193, 228, 235));
			settextstyle(18, 0, _T("��������"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
			sprintf(temptext, "������:  %d Mbit", buf.st_size/1048576);
			drawtext(temptext, &download_info_desplay_area, DT_BOTTOM | DT_RIGHT | DT_SINGLELINE);
		}
		Sleep(1000);
	}
	Sleep(10);
	putimage(0, high, &temp_textbackground);
	flag_text = true;
	return 0;
}

//��궯��-ʵ�ִ����������������ҳ
DWORD WINAPI Mouse_AC(LPVOID pM)
{
	int mouse_flag = 0;
	putimage(420, 411, &button_1);
	while (flag_mouse)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			switch (mouse_flag)
			{
			case 0:
				if (431 <= m.x&&m.x <= 653 && 418 <= m.y&&m.y <= 457)
				{
					mouse_flag = 1;
					putimage(420, 411, &button_2);
				}
				else if (658 <= m.x&&m.x <= 796 && 418 <= m.y&&m.y <= 457)
				{
					mouse_flag = 2;
					putimage(420, 411, &button_3);
				}
				break;
			case 1:
				if (431 > m.x || m.x > 653 || 418 > m.y || m.y > 457)
				{
					mouse_flag = 0;
					putimage(420, 411, &button_1);
				}
				break;
			case 2:
				if (658 > m.x || m.x > 796 || 418 > m.y || m.y > 457)
				{
					mouse_flag = 0;
					putimage(420, 411, &button_1);
				}
				break;
			}
			break;
		case WM_LBUTTONDOWN:
			switch (mouse_flag)
			{
			case 0:
				break;
			case 1:
				system("start https://www.minecraft-ofmine.top/");
				break;
			case 2:
				system("start https://pan.baidu.com/s/1ciyLH1I726Uy6NWrLKnA8A");
				break;
			}
			break;
		}
	}
	return 0;
}

//��ȡ���ذ汾��
int getlocalversion()
{
	int i = 0;
	char ch;
	FILE *fp = fopen(".minecraft\\versions\\update.txt", "r");
	if (fp == NULL) return 1;
	else
	{
		ch = getc(fp);
		while (1)
		{
			ch = getc(fp);
			if (ch == 10)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				return 1;
			}
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 'V')
				break;
			if (ch == EOF)
			{
				fclose(fp);
				return 1;
			}
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == '.')
				break;
			if (ch == EOF)
			{
				fclose(fp);
				return 1;
			}
			localversion = localversion * 10 + ch - 48;
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 9)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				return 1;
			}
			localversion = localversion + (ch - 48) * pow(10, -(++i));
		}
	}
	fclose(fp);
	return 0;
}

//��ȡ���°汾��
int getonlineversion()
{
	int i = 0;
	char ch;

	if (S_OK != URLDownloadToFile(NULL, "https://minecraft-ofmine.bid/update.txt", "temp.dat", 0, NULL)) error(2);

	FILE *fp = fopen("temp.dat", "r");
	if (fp == NULL) return 1;
	else
	{
		ch = getc(fp);
		while (1)
		{
			ch = getc(fp);
			if (ch == 10)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 'V')
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == '.')
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			newestversion = newestversion * 10 + ch - 48;
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 9)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			newestversion = newestversion + (ch - 48) * pow(10, -(++i));
		}
	}
	fclose(fp);
	return 0;
}

//�򿪰汾��Ϣ��->��ȡ�汾��Ϣ
void ��ȡ�汾��Ϣ()
{
	HANDLE handle, text_AC;
	handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);

	int messagebox_x = 472;
	int messagebox_y = 215;
	char temp[10] = "";

	RECT local_version_name_display_area = { messagebox_x + 30,messagebox_y + 14,messagebox_x + 111 ,messagebox_y + 58 };
	RECT online_version_name_display_area = { messagebox_x + 30,messagebox_y + 58,messagebox_x + 111 ,messagebox_y + 102 };
	RECT local_version_display_area = { messagebox_x + 111,messagebox_y + 14,messagebox_x + 224 ,messagebox_y + 58 };
	RECT online_version_display_area = { messagebox_x + 111,messagebox_y + 58,messagebox_x + 224 ,messagebox_y + 102 };

	Sleep(500);
	putimage(messagebox_x, messagebox_y, &VerMegAC_1);
	Sleep(100);
	putimage(messagebox_x, messagebox_y, &VerMegAC_2);
	Sleep(100);
	putimage(messagebox_x, messagebox_y, &VerMessage);
	Sleep(200);

	settextcolor(RGB(0, 0, 0));
	settextstyle(24, 0, _T("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
	drawtext("���ذ汾:", &local_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���°汾:", &online_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���ڻ�ȡ...", &local_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���ڻ�ȡ...", &online_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	sprintf(work_text, "      ���ڼ�����");
	work_text_long = 469;
	getimage(&temp_textbackground, 0, high, work_text_long, 51);
	text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);

	flag = false;
	WaitForSingleObject(handle, INFINITE);
	handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);

	if (getlocalversion())
		error(1);
	settextcolor(RGB(0, 0, 0));
	settextstyle(24, 0, _T("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
	putimage(messagebox_x, messagebox_y, &VerMessage);
	drawtext("���ذ汾:", &local_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���°汾:", &online_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	sprintf(temp, "V%.2f", localversion);
	drawtext(temp, &local_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���ڻ�ȡ...", &online_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	if (getonlineversion())
		error(2);
	settextcolor(RGB(0, 0, 0));
	settextstyle(24, 0, _T("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
	putimage(messagebox_x, messagebox_y, &VerMessage);
	drawtext("���ذ汾:", &local_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("���°汾:", &online_version_name_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	sprintf(temp, "V%.2f", localversion);
	drawtext(temp, &local_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	sprintf(temp, "V%.2f", newestversion);
	drawtext(temp, &online_version_display_area, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	flag = false;
	flag_text = false;
	WaitForSingleObject(handle, INFINITE);
	WaitForSingleObject(text_AC, INFINITE);
	putimage(0, high, &temp_textbackground);
}

//��ȡ��һ���汾���ºŸ���ʱ���Լ�����˵��
int ��ȡ��һ����Ҫ���µİ汾��()
{
	FILE *fp;
	int i = 0;
	time = 0;
	int temp_time = 0;
	float temp_ver = 0.0;
	char ch;
	char info[500] = "";
	char date[11] = "";
	char info_date[100] = "";
	if (S_OK != URLDownloadToFile(NULL, "https://minecraft-ofmine.bid/update.txt", "temp.dat", 0, NULL)) error(2);
	fp = fopen("temp.dat", "r");
	if (fp == NULL) return 1;
	else
	{
		ch = getc(fp);
		while (1)
		{
			if (ch == '\n')
			{
				ch = getc(fp);
				if (ch != 'V')
				{
					while (ch != '\n') ch = getc(fp);
					continue;
				}
				else
				{
					while (1)
					{
						ch = getc(fp);
						if (ch == '.')
							break;
						if (ch == EOF)
						{
							fclose(fp);
							error(6);
						}
						temp_ver = temp_ver * 10 + ch - 48;
					}
					while (1)
					{
						ch = getc(fp);
						if (ch == 9)
							break;
						if (ch == EOF)
						{
							fclose(fp);
							error(6);
						}
						temp_ver = temp_ver + (ch - 48) * pow(10, -(++i));
					}
					if (temp_ver == localversion)
						break;
					else
					{
						i = 0;
						time++;
						temp_ver = 0.0;
					}
				}
			}
			else
				while (ch != '\n') ch = getc(fp);
		}
	}
	fclose(fp);

	i = 0;
	fp = fopen("temp.dat", "r");
	if (fp == NULL) return 1;
	else
	{
		ch = getc(fp);
		while (1)
		{
			if (ch == '\n')
			{
				ch = getc(fp);
				if (ch != 'V')
				{
					while (ch != '\n') ch = getc(fp);
					continue;
				}
				else
				{
					temp_time++;
					if (temp_time == time)
						break;
				}
			}
			else
				while (ch != '\n') ch = getc(fp);
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == '.')
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			nextversion = nextversion * 10 + ch - 48;
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 9)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			nextversion = nextversion + (ch - 48) * pow(10, -(++i));
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == 9)
				break;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			sprintf(date, "%s%c", date, ch);
		}
		while (1)
		{
			ch = getc(fp);
			if (ch == '-')
				break;
			if (ch == '\t')
				continue;
			if (ch == EOF)
			{
				fclose(fp);
				error(6);
			}
			sprintf(info, "%s%c", info, ch);
		}
	}
	fclose(fp);

	RECT next_version_info = { 60,154,503,262 };
	RECT next_version_date = { 192,101,503,120 };

	sprintf(info_date, "�汾�ţ�V%.2f    ����ʱ�䣺%s  ", nextversion, date);
	settextcolor(RGB(0, 0, 0));
	settextstyle(20, 0, _T("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DRAFT_QUALITY, DEFAULT_PITCH);
	drawtext(info_date, &next_version_date, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
	drawtext(info, &next_version_info, NULL);
	return 0;
}

//���ذ汾������
void download()
{
	char url[80] = "";
	char path[20] = "";
	sprintf(url, "ftp://everyone@minecraft-ofmine.bid/ClientAutoUpdate/V%.2f.zip", nextversion);
	sprintf(path, "V%.2f.zip", nextversion);
	if (S_OK != URLDownloadToFile(NULL, url, path, 0, NULL))
		error(3);
}

//��ѹ������
void unzip()
{
	char command[256] = "";
	sprintf(command, ".minecraft\\libraries\\unzip.exe -o V%.2f.zip -d .", nextversion);
	system(command);
}

//��������
int update()
{
	int i = 0;
	char ch;
	char file[500] = "";
	char path[500] = "";
	char command[500] = "";
	sprintf(file, "V%.2f\\list.txt", nextversion);
	FILE *fp = fopen(file, "r");
	if (fp == NULL) return 1;
	else
	{
		while (1)
		{
			sprintf(file, "");
			sprintf(path, "");
			ch = getc(fp);
			if (ch == '-')
			{
				ch = getc(fp);
				while (1)
				{
					ch = getc(fp);
					if (ch == 10 || ch == EOF)
						break;
					sprintf(file, "%s%c", file, ch);
				}
				sprintf(command, "del /f /q %s", file);
				system(command);
			}
			if (ch == '/')
			{
				ch = getc(fp);
				while (1)
				{
					ch = getc(fp);
					if (ch == 10 || ch == EOF)
						break;
					sprintf(file, "%s%c", file, ch);
				}
				sprintf(command, "rmdir /s /q %s", file);
				system(command);
			}
			if (ch == '+')
			{
				ch = getc(fp);
				while (1)
				{
					ch = getc(fp);
					if (ch == 10 || ch == EOF)
						break;
					sprintf(path, "%s%c", path, ch);
				}
				for (i = 0; path[i + 1] != '\0'; i++);
				if (path[i] != '\\')
				{
					path[i + 1] = '\\';
					path[i + 2] = '\0';
				}
				sprintf(command, "md %s", path);
				system(command);
				while (1)
				{
					sprintf(file, "");
					ch = getc(fp);
					if (ch == '#' || ch == EOF)
						break;
					while (1)
					{
						ch = getc(fp);
						if (ch == 10 || ch == EOF)
							break;
						sprintf(file, "%s%c", file, ch);
					}
					sprintf(command, "copy /y V%.2f\\%s %s%s", nextversion, file, path, file);
					system(command);
				}
			}
			if (ch == 'x')
			{
				ch = getc(fp);
				while (1)
				{
					ch = getc(fp);
					if (ch == 10 || ch == EOF)
						break;
					sprintf(path, "%s%c", path, ch);
				}
				for (i = 0; path[i + 1] != '\0'; i++);
				if (path[i] != '\\')
				{
					path[i + 1] = '\\';
					path[i + 2] = '\0';
				}
				sprintf(command, "md %s", path);
				system(command);
				while (1)
				{
					sprintf(file, "");
					ch = getc(fp);
					if (ch == '#' || ch == EOF)
						break;
					while (1)
					{
						ch = getc(fp);
						if (ch == 10 || ch == EOF)
							break;
						sprintf(file, "%s%c", file, ch);
					}
					sprintf(command, "xcopy /y /e /h /k V%.2f\\%s %s%s\\", nextversion, file, path, file);
					system(command);
				}
			}
			if (ch == '*')
			{
				ch = getc(fp);
				while (1)
				{
					ch = getc(fp);
					if (ch == 10 || ch == EOF)
						break;
					sprintf(file, "%s%c", file, ch);
				}
				sprintf(command, "V%.2f\\%s", nextversion, file);
				system(command);
			}
			if (ch == EOF)
				break;
		}
	}
	sprintf(command, "copy /y V%.2f\\update.txt .minecraft\\versions\\", nextversion);
	system(command);
	fclose(fp);
	return 0;
}

//ɾ��������ʱ���ļ�
void deltemp()
{
	char temp[50] = "";
	//ɾ�����ظ��°�
	sprintf(temp, "del V%.2f.zip", nextversion);
	system(temp);
	//ɾ����ѹ��ĸ��°�
	sprintf(temp, "rmdir /s/q V%.2f", nextversion);
	system(temp);
	//ɾ������汾�Լ�Ѱ�ҿͻ�������������ʱ�ļ�
	remove("temp.dat");
}

//���пͻ���������(��������)
int end()
{
	char ch;
	system("dir /D /B /C > temp.dat");

	FILE *fp = fopen("temp.dat", "r");
	if (fp == NULL) return 1;
	else
	{
		while (1)
		{
			ch = getc(fp);
			if (ch == 'H')
			{
				ch = getc(fp);
				if (ch == 'M')
				{
					ch = getc(fp);
					if (ch == 'C')
					{
						ch = getc(fp);
						if (ch == 'L')
						{
							ch = getc(fp);
							if (ch == '-')
							{
								while (1)
								{
									ch = getc(fp);
									sprintf(launch, "%s%c", launch, ch);
									if (ch == 10 || ch == EOF)
									{
										fclose(fp);
										return 0;
									}
								}
							}
						}
					}
				}
			}
			while (1)
			{
				ch = getc(fp);
				if (ch == 10)
					break;
				if (ch == EOF)
				{
					fclose(fp);
					return 1;
				}
			}
		}
	}
}

void main()
{
	HANDLE text_AC, handle;
	system("title Mine Craft - Of Mine ��ӭ��");
	��ʼ��();
	
	putimage(0, 0, &start);
	��ȡ�汾��Ϣ();
	Sleep(100);
	//�汾Ϊ���µ�ʱ�������ͻ���
	if (localversion == newestversion)
	{
		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);

		sprintf(work_text, "    ��ǰ�汾Ϊ����,����Ϊ�������ͻ���");
		text_px = 24;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		end();
		deltemp();
		system(launch);

		Sleep(5000);

		flag = false;
		flag_text = false;
		WaitForSingleObject(handle, INFINITE);
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		exit(1);
	}
	//�汾�쳣��ʱ�򱨴�
	if (localversion > newestversion)
		error(4);
	//��Ҫ���µ�ʱ��
	if (localversion < newestversion)
	{
		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		putimage(0, 0, &update_background);
		Sleep(500);
		putimage(31, 79, &Update_AC1);
		Sleep(100);
		putimage(31, 79, &Update_AC2);
		Sleep(100);
		putimage(31, 79, &Update_info);

		HANDLE mouse = CreateThread(NULL, 0, Mouse_AC, NULL, 0, NULL);

		flag = false;
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		sprintf(work_text, "      ���ڻ�ȡ��һ���汾��");
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		��ȡ��һ����Ҫ���µİ汾��();
		flag = false;
		flag_text = false;
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		if (time > 1)
			putimage(0, 410, &update_warning);

		sprintf(work_text, "          ����������Դ��");
		flag_download = true;
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		download();
		flag = false;
		flag_text = false;
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		sprintf(work_text, "          ��ѹ��Դ��");
		flag_download = false;
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		unzip();
		flag = false;
		flag_text = false;
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		sprintf(work_text, "               ������");
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		update();
		flag = false;
		flag_text = false;
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		sprintf(work_text, "          �����ʱ�ļ�");
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);
		deltemp();
		flag = false;
		flag_text = false;
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		WaitForSingleObject(handle, INFINITE);

		handle = CreateThread(NULL, 0, loading, NULL, 0, NULL);
		sprintf(work_text, "  �������,�������¼��汾");
		text_px = 51;
		work_text_long = 800;
		getimage(&temp_textbackground, 0, high, work_text_long, 51);
		text_AC = CreateThread(NULL, 0, Worktext_AC, NULL, 0, NULL);

		deltemp();

		Sleep(2000);

		flag = false;
		flag_text = false;
		WaitForSingleObject(handle, INFINITE);
		WaitForSingleObject(text_AC, INFINITE);
		putimage(0, high, &temp_textbackground);
		
		ShellExecute(NULL, "open", "Mine Craft - Of Mine ��ӭ��.exe", NULL, NULL, SW_SHOW);
	}
	exit(0);
}