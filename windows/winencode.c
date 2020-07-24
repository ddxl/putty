#include "winencode.h"
 
 
wchar_t* ansi_2_utf16(const char* srcStr, int *destLen)
{
	int len = MultiByteToWideChar(CP_ACP, 0, srcStr, -1, 0, 0);
	len += (len == 0);
	wchar_t* rst = (wchar_t*)malloc(len * 2);
	len = MultiByteToWideChar(CP_ACP, 0, srcStr, -1, rst, len);
	len += (len == 0);
	rst[len - 1] = '\0';
	if (destLen)
		*destLen = len - 1;
	return rst;
 
}
 
char* utf16_2_ansi(const wchar_t* srcStr, int *destLen)
{
	int len = WideCharToMultiByte(CP_ACP, 0, srcStr, -1, 0, 0, NULL, NULL);
	len += (len == 0);
	char* rst = (char*)malloc(len);
	len = WideCharToMultiByte(CP_ACP, 0, srcStr, -1, rst, len, NULL, NULL);
	len += (len == 0);
	rst[len - 1] = '\0';
	if (destLen)
		*destLen = len - 1;
	return rst;
 
}
 
wchar_t* utf8_2_utf16(const char* srcStr, int *destLen)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, srcStr, -1, 0, 0);
	len += (len == 0);
	wchar_t* rst = (wchar_t*)malloc(len * 2);
	len = MultiByteToWideChar(CP_UTF8, 0, srcStr, -1, rst, len);
	len += (len == 0);
	rst[len - 1] = '\0';
	if (destLen)
		*destLen = len - 1;
	return rst;
}
 
char* utf16_2_utf8(const wchar_t* srcStr, int *destLen)
{
	int len = WideCharToMultiByte(CP_UTF8, 0, srcStr, -1, 0, 0, NULL, NULL);
	len += (len == 0);
	char* rst = (char*)malloc(len);
	len = WideCharToMultiByte(CP_UTF8, 0, srcStr, -1, rst, len, NULL, NULL);
	len += (len == 0);
	rst[len - 1] = '\0';
	if (destLen)
		*destLen = len - 1;
	return rst;
}
 
char* ansi_2_utf8(const char* srcStr, int *destLen)
{
	wchar_t* utf16Str = ansi_2_utf16(srcStr, 0);
	char* utf8Str = utf16_2_utf8(utf16Str, destLen);
	free(utf16Str);
	return utf8Str;
}
 
char* utf8_2_ansi(const char* srcStr, int *destLen)
{
	wchar_t* utf16Str = utf8_2_utf16(srcStr, 0);
	char* ansiStr = utf16_2_ansi(utf16Str, destLen);
	free(utf16Str);
	return ansiStr;
}