#ifndef __CSTRING_H__
#define __CSTRING_H__
#include<memory>
class CString {
public:
	bool isalnum(const char * st);
	bool isalpha(const char * st);
	char * strcat(char * dest, const char * src);
	char * strncat(char * dest, const char * src, size_t num);
	const char * strchr(const char * hay, const char c);
	int strcmp(const char * lhs, const char *rhs);
	const char *strpbrk(const char *str1, const char *str2);
	char *strcpy(char *dest, const char *src);
	char *strncpy(char *dest, const char *src, size_t n);
	size_t strcspn(const char *str1, const char *str2);
	size_t strlen(const char *str);
	const char *strrchr(const char *str, int c);
	size_t strspn(const char *str1, const char *str2);
	char *strstr(const char *hay, const char *needle);
};
#endif
