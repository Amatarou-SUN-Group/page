//Console Escape Sequence Functions Pack
//
//[Reference]
//-https://www-he.scphys.kyoto-u.ac.jp/member/n-kota/dokuwiki/doku.php?id=ja:cpp:wanttodo1
//-https://zenn.dev/memo/articles/20211004_ps1#%E7%92%B0%E5%A2%83%E5%A4%89%E6%95%B0ps1
//-https://dev.grapecity.co.jp/support/powernews/column/clang/047/page02.htm
//-https://qiita.com/PruneMazui/items/8a023347772620025ad6
//
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define CON_RED 1
#define CON_YELLOW 3
#define CON_GREEN 2
#define CON_CYAN 6
#define CON_BLUE 4
#define CON_MAGENTA 5
#define CON_WHITE 7
#define CON_BLACK 0
#define CON_DEFAULT 9

#define CON_NORMAL 0
#define CON_BOLD 1
#define CON_ITALIC 3
#define CON_UNDERLINE 4
#define CON_FLASH 5
#define CON_FAST_FRASH 6
#define CON_INVERSE_FOREC_BACKC 7
#define CON_HIDE_CURSOR 8
#define CON_UNDO 9

int nowfore = CON_DEFAULT;
int nowback = CON_DEFAULT;

bool extended_color_b = false;
bool extended_color_f = false;
bool bold = false;
bool italic = false;
bool underline = false;
bool st = false; //StrikeThrough

void applystyle()
{
	printf("\e[m");
	//Generate Escape sequence
	std::string stylees = "";
	char temp[128];

	//Setting Content
	stylees += "\e";
	stylees += "[";
	stylees += temp;
	if (!extended_color_b)
	{
		printf("\e[3%um", nowback);
	}
	if (!extended_color_f)
	{
		printf("\e[4%um", nowfore);
	}
	if (extended_color_b)
	{
		printf("\e[48;5;%um", nowback);
	}
	if (extended_color_f)
	{
		printf("\e[38;5;%um", nowfore);
	}
	if (bold)
	{
		printf("\e[1m");
	}
	if (italic)
	{
		printf("\e[3m");
	}
	if (underline)
	{
		printf("\e[4m");
	}
	if (st)
	{
		printf("\e[9m");
	}
}

// Set Console Foreground Color
void Set_Forecolor(int color)
{
	extended_color_f = false;
	nowfore = color;
	applystyle();
}

// Set Console Background Color
void Set_Backcolor(int color)
{
	extended_color_b = false;
	nowback = color;
	applystyle();
}

// Set Console Foreground Color (Extended Color - 256 Colors)
void Set_ForecolorEx(int color)
{
	extended_color_f = true;
	nowfore = color;
	applystyle();
}

// Set Console Background Color (Extended Color - 256 Colors)
void Set_BackcolorEx(int color)
{
	extended_color_b = true;
	nowback = color;
	applystyle();
}

// Set Style - Bold
void Set_Bold(bool arg_bold)
{
	bold = arg_bold;
	applystyle();
}

// Set Style - Italic
void Set_Italic(bool arg_italic)
{
	italic = arg_italic;
	applystyle();
}

// Set Style - Underline
void Set_Underline(bool arg_underline)
{
	underline = arg_underline;
	applystyle();
}

// Set Style - Strikethrough
void Set_Underline(bool arg_st)
{
	st = arg_st;
	applystyle();
}

// Set Styles
void Set_Styles(bool arg_bold, bool arg_italic, bool arg_underline, bool arg_st)
{
	bold = arg_bold;
	italic = arg_italic;
	underline = arg_underline;
	st = arg_st;
	applystyle();
}

// Reset Console Foreground Color
void Reset_Forecolor()
{
	extended_color_f = false;
	nowfore = CON_DEFAULT;
	applystyle();
}

// Reset Console Background Color
void Reset_Backcolor()
{
	extended_color_b = false;
	nowback = CON_DEFAULT;
	applystyle();
}

// Reset Console Background Color and Foreground Color
void Reset_Colors()
{
	Reset_Forecolor();
	Reset_Backcolor();
	applystyle();
}

// Reset Console Style
void Reset_Styles()
{
	bold = false;
	italic = false;
	underline = false;
	applystyle();
}

// Reset All Styles and colors
void Reset_All()
{
	Reset_Colors();
	Reset_Styles();
	applystyle();
	printf("\e[m");
}

// Set Cursor Position
void Set_CursorPos(int x, int y)
{
	printf("\e[%u;%uH", y, x);
	applystyle();
}

// Clear Console Screen
void Clear_Console()
{
	printf("\e[m");
	printf("\e[2J");
	Set_CursorPos(0, 0);
	applystyle();
}

// Output Style info and Color info to Console
void putstatus_to_console()
{
	printf("\e[mBackColor : %u (Extended : %d)\nForeColor : %u (Extended : %d)\nBold      : %d\nItalic    : %d\nUnderline : %d\nST        : %d", nowback, extended_color_b, nowfore, extended_color_f, bold, italic, underline, st);
	applystyle();
}