#include <stdio.h>
#include <windows.h>

#pragma region 테트리스 블록

char blockModel[][4][4] =
{
	// 첫 번째 블록:bloclModel [0]~[3]
	{
		{0, 0, 0, 0},
		{1, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 0, 0, 0}  },
	{
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0}  },
	{
		{0, 0, 0, 0},
		{1, 1, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 0}  },
	{
		{0, 0, 0, 0},
		{1, 1, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 0}  },

    // 두 번째 블록:bloclModel [4]~[7]
    {
    	{0, 0, 0, 0},
    	{0, 0, 1, 0},
    	{1, 1, 1, 0},
    	{0, 0, 0, 0}  },
    {
    	{0, 0, 0, 0},
    	{0, 1, 1, 0},
    	{0, 0, 1, 0},
    	{0, 0, 1, 0}  },
    {
    	{0, 0, 0, 0},
    	{0, 1, 1, 1},
    	{0, 1, 0, 0},
    	{0, 0, 0, 0}  },
    {
    	{0, 1, 0, 0},
    	{0, 1, 0, 0},
    	{0, 1, 1, 0},
    	{0, 0, 0, 0}  },
    
    // 세 번째 블록:bloclModel [8]~[11]
    {
    	 {0, 0, 0, 0},
    	 {0, 1, 0, 0},
    	 {1, 1, 1, 0},
    	 {0, 0, 0, 0}  },
    {
    	 {0, 0, 0, 0},
    	 {0, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 1, 0, 0}  },
    {
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0},
    	 {1, 1, 1, 0},
    	 {0, 1, 0, 0}  },
    {
    	 {0, 0, 0, 0},
    	 {0, 1, 0, 0},
    	 {0, 1, 1, 0},
    	 {0, 1, 0, 0}  },
    
    	 // 네 번째 블록:bloclModel [12]~[15]
    {
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0}  },
    {
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0},
    	 {1, 1, 1, 1},
    	 {0, 0, 0, 0}  },
    {
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0},
    	 {0, 1, 0, 0}  },
    {
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0},
    	 {1, 1, 1, 1},
    	 {0, 0, 0, 0}  },
    
    	 // 다섯 번째 블록:bloclModel [16]~[19]
    {
    	 {1, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0}  },
    {
    	 {1, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0}  },
    {
    	 {1, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0}  },
    {
    	 {1, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0},
    	 {0, 0, 0, 0}  },
    
    	 // 여섯 번째 블록:bloclModel [20]~[23]
    {
    	 {0, 0, 0, 0},
    	 {0, 1, 1, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 1, 0, 0},
    	 {0, 1, 1, 0},
    	 {0, 0, 1, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 0, 0, 0},
    	 {0, 1, 1, 0},
    	 {1, 1, 0, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 1, 0, 0},
    	 {0, 1, 1, 0},
    	 {0, 0, 1, 0},
    	 {0, 0, 0, 0} },
    
    	 // 일곱 번째 블록:bloclModel [24]~[27]
    {
    	 {0, 0, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 1, 1, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {1, 0, 0, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 0, 0, 0},
    	 {1, 1, 0, 0},
    	 {0, 1, 1, 0},
    	 {0, 0, 0, 0} },
    {
    	 {0, 1, 0, 0},
    	 {1, 1, 0, 0},
    	 {1, 0, 0, 0},
    	 {0, 0, 0, 0} }

};
#pragma endregion

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemobeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}

void ShowBlock(char block[4][4])
{
	int y, x;
	COORD pos = GetCurrentCursorPos();
	for (y = 0; y < 4; y++)
	{
		for (x = 0; y < 4; x++)
		{
			SetCurrentCursorPos(pos.X + x * 2, pos.Y + y);
			if (block[y][x] == 1)
			{
				printf("■");
			}
		}
	}
	SetCurrentCursorPos(pos.X, pos.Y);
}

int main()
{
	RemobeCursor();
	int posX = 6, posY = 3;  //커서 위치 초기화
	for (int i = 0; i < 7; i++)
	{
		SetCurrentCursorPos(posX, posY);
		ShowBlock(blockModel[i * 4]);  // 블록 종류별로 출력
		posX += 10;  // 다음 위치로 이동
	}
	getchar();

	return 0;
}