//Keyboard.cpp
#include <Windows.h>
#include "Keyboard.h"

//==== グロバール変数 ====
BYTE g_keyTable[256];  //キー情報を保存しておくための配列
BYTE g_oldKeyTable[256];  //ひとつ前のキー情報を保存しておくための配列 

void UpdateKeyboard()
{
	memcpy(g_oldKeyTable, g_keyTable, sizeof(g_oldKeyTable));  //ひとつ前の情報をコピー
	GetKeyboardState(g_keyTable);                              //キー情報をテーブルに格納
}

bool IsKeyPress(int nVirtKey)
{
	return g_keyTable[nVirtKey] & 0x80;
}

bool IsKeyTrigger(int nVirtKey)
{
	return (g_keyTable[nVirtKey] ^ g_oldKeyTable[nVirtKey]) & g_keyTable[nVirtKey] & 0x80;
}

bool IsKeyRelease(int nVirtKey)
{
	return (g_keyTable[nVirtKey] ^ g_oldKeyTable[nVirtKey]) & g_oldKeyTable[nVirtKey] & 0x80;
}