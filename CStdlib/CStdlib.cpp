#include <cctype>
#include <cmath>
#include "CStdlib.h"
#include "cstring"
#include <iostream>
#if defined(_WIN32) || defined(_WIN64) 
	#define snprintf _snprintf 
	#define vsnprintf _vsnprintf 
	#define strcasecmp _stricmp 
	#define strncasecmp _strnicmp 
#endif
double CStdlib::atof(const char *str) {
	return strtod(str, nullptr);
}

int CStdlib::atoi(const char *str) {
	
	return strtol(str, nullptr, 10);
}

long int CStdlib::atol(const char *str) {
	return strtol(str, nullptr, 10);
}

double CStdlib::strtod(const char *str, char **endptr) {
	double value[2]{};
	for (int i = 0; i < 2; i++) {
		auto isdigit = ::isdigit;
		int base = 10;
		char exponent_symbol = 'E';
		double whole = 0;
		int sign = 1;
		double fractional = 0;
		for (; isspace(*str); str++); /*Skip Whitespaces*/
		if (*str == '-') {  /*Check Sign*/
			sign = -1;
			str++;
		}
		else if (*str == '+') {
			str++;
		}
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {  /*Is Hexadecimal?*/
			isdigit = isxdigit;
			exponent_symbol = 'P';
			base = 16;
			str += 2;
		}
		if (strcasecmp(str, "infinity") == 0 || strcasecmp(str, "inf") == 0) {
			return std::numeric_limits<double>::infinity();
		}
		if (strcasecmp(str, "nan") == 0) {
			return std::numeric_limits<double>::quiet_NaN();
		}
		for (; *str && isdigit(*str); str++) {
			whole = whole * base + (*str - '0');
		}
		if (*str == '.') {
			str++;
			for (double p = 1./base; *str && isdigit(*str); str++, p/=base) {
				std::cout << "p = " << p << std::endl;
				fractional += p * (*str - '0');
			}

		}
		value[i] = sign * (whole + fractional);
		if (toupper(*str) != exponent_symbol) {
			break;
		}
		else {
			str++;
		}
	}
	if (endptr) {
		*endptr = const_cast<char *>(str);
	}
	return pow(10, value[1]) * value[0];
}

long int CStdlib::strtol(const char *str, char **endptr, int base) {
	long value = 0;
	int sign = 1;
	for (; isspace(*str); str++); /*Skip Whitespaces*/
	if (*str == '-') {
		sign = -1;
		str++;
	}
	else if (*str == '+') {
		str++;
	}
	for (; *str && isdigit(*str); str++) {
		value = value * base + (*str - '0');
	}
	if (endptr) {
		*endptr = const_cast<char *>(str);
	}
	return sign * value;
}

unsigned long int CStdlib::strtoul(const char *str, char **endptr, int base) {
	unsigned long value = 0;
	int sign = 1;
	for (; isspace(*str); str++); /*Skip Whitespaces*/
	for (; *str && isdigit(*str); str++) {
		value = value * base + (*str - '0');
	}
	if (endptr) {
		*endptr = const_cast<char *>(str);
	}
	return value;
}

void *CStdlib::calloc(size_t nitems, size_t size) { return nullptr; }

void CStdlib::free(void *ptr){}

void *CStdlib::malloc(size_t size) { return nullptr; }

void *CStdlib::realloc(void *ptr, size_t size) { return nullptr; }

void CStdlib::abort(void) {}

int CStdlib::atexit(void(*func)(void)) { return int(); }

void CStdlib::exit(int status) {}

char *CStdlib::getenv(const char *name) { return nullptr; }

int CStdlib::system(const char *string) { return int(); }

void *CStdlib::bsearch(const void *key, const void *base, size_t nitems, size_t size, int(*compar)(const void *, const void *)) { 
	const char * pivot{};
	int result{};
	for (; size;) {
		pivot = static_cast<const char *>(base) + (nitems / 2) * size;
		result = compar(pivot, key);
		if (result > 0) {
			base = pivot + size;
		}
		else {
			return static_cast<void *>(const_cast<char *>(pivot));
		}
		nitems /= 2;
	}
	return nullptr;
}

void CStdlib::qsort(void *base, size_t nitems, size_t size, int(*compar)(const void *, const void*)) {


}

int CStdlib::abs(int x) {
	return x < 0 ? -x : x;
}

div_t CStdlib::div(int numer, int denom) { 
	div_t result{};
	result.quot = numer / denom;
	result.rem = numer - result.quot * denom;
	return result;
}

long int CStdlib::labs(long int x) { 
	return x < 0 ? -x : x;
}

ldiv_t CStdlib::ldiv(long int numer, long int denom) { 
	ldiv_t result{};
	result.quot = numer / denom;
	result.rem = numer - result.quot * denom;
	return result;
}

int CStdlib::rand(void) { return int{}; }

void CStdlib::srand(unsigned int seed) {}

int CStdlib::mblen(const char *str, size_t n) { return int{}; }

size_t CStdlib::mbstowcs(wchar_t *pwcs, const char *str, size_t n) { return size_t{}; }

int CStdlib::mbtowc(wchar_t *pwc, const char *str, size_t n) { return int{}; }

size_t CStdlib::wcstombs(char *str, const wchar_t *pwcs, size_t n) { return size_t{}; }

int CStdlib::wctomb(char *str, wchar_t wchar) { return int{}; }