#include <iostream>
#include <Windows.h>
using namespace std;

void Space()
{
	INPUT input;
	WORD vKey = VK_SPACE;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	input.ki.wVk = vKey;
	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT)); 
}

bool bhop = false;

void Bunnyhop()
{
	if (GetAsyncKeyState(VK_SPACE)); // нажми Пробел и станешь прыгать автоматически
	{
		Sleep(300);
		bhop = true;
	}
	if (GetAsyncKeyState(VK_CONTROL)) // Контрол чтобы остановиться
	{
		Sleep(150);
		bhop = false; 
	}
	if (bhop) Space();
}

int main()
{
	while (true) // бесконечный цикл
	{
		Bunnyhop();
	}
}
