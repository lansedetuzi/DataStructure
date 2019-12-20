#pragma once

char* StringCopy(char *dest, const char *source, int len);

char* StringCat(char *dest, const char *source, int len);

int StringCmp(const char *str1, const char *str2);

int StringToLower(char *dest, const char *source);

/*
@brief: 字符串拆分
@param: 
*/
int StringSplit(const char *source, const char split, char p[][20]);

unsigned int StringLen(const char *str);

char* StringChr(const char *source, const char c);
char* StringRChr(const char *source, const char c);

/*
@brief: 申请空间来存储str, 需要自己手动去释放
*/
char* StringDup(const char *str);

/*
@brief: 翻转字符串
*/
char* StringRev(char *str);

char* StringStr(const char *str1, const char *str2);
