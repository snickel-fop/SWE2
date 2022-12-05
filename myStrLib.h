#ifndef MY_STR_LIB_H
#define MY_STR_LIB_H

int StrLength(char* Str);
int StrCompare(char* str1, char* str2);
void StrCopy(char* src, char* dst);
void StrCat(char* str1, char* str2, char* dst);
int StrCheckPalindrome(char* str);
void StrNCat(char* str1, char* str2, char* dst, int length);
int StrStr(char* haystack, char* needle);

#endif