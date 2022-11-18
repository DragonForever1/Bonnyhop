#include "include.h"
using namespace offsets;

BOOL WINAPI Bunnyhop(HMODULE createModule)
{
	DWORD gameModule = (DWORD)GetModuleHandle("client.dll");
	while (!GetAsyncKeyState(VK_END))
	{
		DWORD localPlayer = *(DWORD*)(gameModule + dwLocalPlayer);
		if (localPlayer == NULL) continue;

		int flag = *(int*)(localPlayer + m_fFlags);

		if (GetAsyncKeyState(VK_SPACE) && flag & (1 << 0))
		{
			*(DWORD*)(gameModule + dwForceJump) = 6;
		}
	}


	FreeLibraryAndExitThread(createModule, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Bunnyhop, 0, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
