#include "CString.h"
#include <algorithm>
#include<stdlib.h> 
bool CString::isalnum(const char * st) { return false; }
bool CString::isalpha(const char * st) { return false; }
char *CString::strcat(char * dest, const char * src) {
	char *it = dest;
	for (; *it; it++);
	for (; *it = *(src++););
	return dest;

}
char *CString::strncat(char * dest, const char * src, size_t num) {
	char *it = dest;
	for (; *it; it++);
	for (; num-- && (*it = *(src++)); );
	return dest;

}
const char *CString::strchr(const char * hay, const char c) {
	for (; *hay && *hay != c; hay++);
	return *hay == c?hay:nullptr;
}
int CString::strcmp(const char * lhs, const char *rhs) {
	for (; *lhs && *rhs && *(lhs++) == *(rhs++););
	auto result = *lhs - *rhs;
	return result ? (result < 0 ? -1 : 1) : 0;
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
	for (; *str1 && arr[*str1]; str1++, size++);
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
	for (; *str2; arr[*str2]=true, str2++);
	for (; *str1 && arr[*str1]; str1++, size++);
	return size;
}
char *CString::strstr(const char *hay, const char *needle) {
	return nullptr;
}