// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
/*void printArray(int data[][8][3]) {
	//Drawing 8x8 grid 
	//system("cls");
	clearscreen();
	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(pen_device_context, pen);
	for (int i = 10; i <= 810; i = i + 100) {
		MoveToEx(pen_device_context, i + 400, 10, NULL);
		LineTo(pen_device_context, i + 400, 810);

		MoveToEx(pen_device_context, 10 + 400, i, NULL);
		LineTo(pen_device_context, 1210, i);
	}

	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);


	//Drawing gems
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			switch (data[x][y][0]) {
			case 1: gem1(x, y);
				break;
			case 2: gem2(x, y);
				break;
			case 3: gem3(x, y);
				break;
			case 4: gem4(x, y);
				break;
			case 5: gem5(x, y);
				break;
			case 6: cubegem(x, y);
				break;
			}
			if (data[x][y][2] == 1)
				drawDestroy(x, y);
			if (data[x][y][1] == 1 || data[x][y][1] == 2)
				flamingOverlay(x, y);
			if (data[x][y][1] == 3)
				destroyerOverlay(x, y);

		}
	}
	Sleep(50);
}
*/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "help.h"
#include <fstream>
using namespace std;


bool checkwinner(int board[][3], int & who)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
		{
			who = board[i][0];
			return true;
		}
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
		{
			who = board[0][i];
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
	{
		who = board[0][0];
		return true;
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
	{
		who = board[0][0];
		return true;
	}

	return false;
}
void findloc(int board[][3], int &row, int & col, int opp)
{
	int who;
	bool winner = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 0)
			{
				row = i;
				col = j;
				board[i][j] = opp;
				winner = checkwinner(board, who);
				board[i][j] = 0;
				if (winner == true)
				break;
			}
		}
		if (winner == true)
			break;
	}
if (winner == false)
{
	if (board[1][1] == 0)
	{
		row = 1;
		col = 1;
	}
}
}
void myLineblack(int x1, int y1, int x2, int y2) //Draws a black line
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void Tick(int i,int j){
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 4, RGB(255, 255,255));
	int x1 = i * 100 + 10;
	int y1 = j * 100+80  ;
	int x2 = x1 + 20;
	int y2 = y1 + 30 ;
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	x2 = i * 100 + 10 + 10 + 10;
	y2 = j * 100 +110;
	x1 = x2 + 80 ;
	y1 = y2 - 100;
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}
void Cross(int i,int j){
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	HPEN pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
	SelectObject(device_context, pen);
	int x1 = i * 100 + 10;
	int x2 = x1 + 100 ;
	int y1 = j * 100 +10;
	int y2 = y1 + 100 ;
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	x2 = i * 100 + 100 + 10;
	x1 = x2 - 100 ;
	y2 = j * 100+10;
	y1 = y2 + 100 ;
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
}
void printboard(int board[][3], int r)
{

	//Drawing 8x8 grid 
	system("cls");
	//clearscreen();
	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	SelectObject(pen_device_context, pen);
	for (int i = 10; i <= 310; i = i + 100) {
		MoveToEx(pen_device_context, i, 10, NULL);
		LineTo(pen_device_context, i, 310);

		MoveToEx(pen_device_context, 10, i, NULL);
		LineTo(pen_device_context, 310, i);
	}
	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 1)
				Tick(j, i);
			//cout << "O ";
			else if (board[i][j] == 2)
				Cross(j, i);
			//cout << "X ";
		}
		cout << endl;
	}
}
void removeCursor(int x, int y) { // 1 = white, 2 = green, 3 = blue
	
	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255,255, 255));
	SelectObject(pen_device_context, pen);
	x = (x * 100) + 10;
	y = (y * 100) + 10;
	MoveToEx(pen_device_context, x, y, NULL);
	LineTo(pen_device_context, x + 100, y);
	LineTo(pen_device_context, x + 100, y + 100);
	LineTo(pen_device_context, x, y + 100);
	LineTo(pen_device_context, x, y);


	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);
}
void printCursor(int x, int y, int color) { // 1 = white, 2 = green, 3 = blue
	int R = 255, G = 255, B = 255;
	if (color == 2) {
		R = 0;
		B = 0;
	}
	else if (color == 3) {
		R = 0;
		G = 0;
	}

	HWND console_handle = GetConsoleWindow();
	HDC pen_device_context = GetDC(console_handle);
	HPEN pen = CreatePen(PS_SOLID, 1, RGB(R, G, B));
	SelectObject(pen_device_context, pen);
	x = (x * 100) + 10;
	y = (y * 100) + 10;
	MoveToEx(pen_device_context, x, y, NULL);
	LineTo(pen_device_context, x + 100, y);
	LineTo(pen_device_context, x + 100, y + 100);
	LineTo(pen_device_context, x, y + 100);
	LineTo(pen_device_context, x, y);


	ReleaseDC(console_handle, pen_device_context);
	DeleteObject(pen);
}
int main()
{
	int board[3][3] = { 0 }, player = 1, row, col, who;
	bool winner = false;

	printboard(board, 3);
	cout << endl;

	int x = 0, y = 0;

	gotoxy(x, y);

	for (int i = 0; i < 9 && winner == false; i++)
	{
		char c = _getch();
		while (c != 13)
		{

			removeCursor(x, y);
			if (c == -32)
			{
				c = _getch();
				if (c == 'H')
				{
					if (y != 0)
						y = y - 1;
					printCursor(x, y, 3);
				}
				if (c == 'K')
				{
					if (x != 0)
						x = x - 1;
					printCursor(x, y, 3);
				}
				if (c == 'M')
				{
					if (x != 2)
						x = x + 1;
					
					printCursor(x, y, 3);
				}
				if (c == 'P')

				{
					if (y != 2)
						y = y + 1;
					printCursor(x, y, 3);

				}
			}

			else if (c == 'S')
			{
				ofstream fout("save.txt");
				fout << player << " " << i << " ";

				for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; i++)
					fout << board[i][j] << " ";

				fout.close();
			}
			else if (c == 'L')
			{
				ifstream fin("save.txt");
				fin >> player >> i;

				for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; i++)
					fin >> board[i][j];
				gotoxy(0, 0);
				printboard(board, 3);
			}
			c = _getch();
		}
		row = y;
		col = x; //cuz game is 2*2
		if (player == 1){
			//findloc(board, row, col, 2);
			board[row][col] = 1;

			player = 2;
		}
		else{
            //	cin >> row >> col;
			//	while (board[row][col] != 0)
			//		cin >> row >> col;
			board[row][col] = 2;
			player = 1;
		}
		gotoxy(0, 0);
		printboard(board, 3);
		
		winner = checkwinner(board, who);
	    gotoxy(x, y);
	}
	if (winner == true){
		gotoxy(0, 0);
		printboard(board, 3);
		gotoxy(10, 312);
		cout << endl << endl << endl << "The winner is " << who << endl;
	}
	else{
		gotoxy(0, 0);
		printboard(board, 3);
		gotoxy(10, 312);
		cout << endl << endl << endl << " its a draw";
	}
	_getch();

}


