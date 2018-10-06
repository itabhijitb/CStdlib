#include "CString.h"
#include <algorithm>
#include<stdlib.h> 
bool CString::isalnum(const char * st) { return false; }
bool CString::isalpha(const char * st) { return false; }
char *CString::strcat(char * dest, const char * src) {
	const size_t szDest = strlen(dest);
	const size_t szSrc = strlen(src);
	char *newdest = nullptr;
	if (szDest + szSrc != 0) {
		newdest = new char[(szDest + szSrc) * sizeof(char)];
		strcpy(newdest, dest);
		strcpy(newdest + szSrc, src);
	}
	else {
		newdest = nullptr;
	}
	return dest = newdest;

}
char *CString::strncat(char * dest, const char * src, size_t num) {
	const size_t szDest = strlen(dest);
	const size_t szSrc = std::min(strlen(src), num);
	char *newdest = nullptr;
	if (szDest + szSrc != 0) {
		newdest = new char[(szDest + szSrc) * sizeof(char)];
		strcpy(newdest, dest);
		strncpy(newdest + szSrc, src, num);
	}
	else {
		newdest = nullptr;
	}
	return dest = newdest;

}
const char *CString::strchr(const char * hay, const char c) {
	for (; hay && *hay != c; hay++);
	return hay;
}
int CString::strcmp(const char * lhs, const char *rhs) {
	for (; *lhs && *rhs && *(lhs++) == *(rhs++););
	return *lhs - *rhs;
}
const char *CString::strpbrk(const char *str1, const char *str2) {
	bool arr[2 << (sizeof(char) * 8)]{ false };
	for (; *str2; arr[*str2] = true, str2++);
	for (; *str2 && arr[*str2] == false; str2++);
	return str2;
}
char *CString::strcpy(char *dest, const char *src) {
	for (char *it = dest; *(it++) = *(src++););
	return dest;
}
char *CString::strncpy(char *dest, const char *src, size_t n) {
	char *it = dest;
	for (size_t i = 0; i < n && (*(it++) = *(src++));i++);
	return dest;
}

size_t CString::strcspn(const char *str1, const char *str2) {
	bool arr[2 << (sizeof(char) * 8)]{ false };
	size_t size = 0;
	for (; *str2; arr[*str2] == false, str2++);
	for (; *str2 && arr[*str2]; str2++, size++);
	return size;
}
size_t CString::strlen(const char *str) {
	size_t len = 0;
	for (; str[len] != NULL; len++);
	return len;
}
const char *CString::strrchr(const char *str, int c) {
	const char *it = str;
	for (;++str;) {
		if (*str == c) {
			it = str;
		}
	}
	return it;
}
size_t CString::strspn(const char *str1, const char *str2) {
	bool arr[2 << (sizeof(char) * 8)]{ false};
	size_t size = 0;
	for (; *str2; arr[*str2], str2++);
	for (; *str2 && arr[*str2]; str2++, size++);
	return size;
}
char *CString::strstr(const char *hay, const char *needle) {
	return nullptr;
}