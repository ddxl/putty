#ifndef PUTTY_ENCODE_H
#define PUTTY_ENCODE_H
 
#include <Windows.h>
 
#ifdef __cplusplus  
extern "C" {
#endif
	wchar_t* ansi_2_utf16(const char* srcStr, int *destLen);
	char* utf16_2_ansi(const wchar_t* srcStr, int *destLen);
	char* utf16_2_utf8(const wchar_t* srcStr, int *destLen);
	wchar_t* utf8_2_utf16(const char* srcStr, int *destLen);
	char* ansi_2_utf8(const char* srcStr, int *destLen);
	char* utf8_2_ansi(const char* srcStr, int *destLen);
#ifdef __cplusplus  
}
#endif
#endif
