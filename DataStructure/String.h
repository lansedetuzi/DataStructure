#pragma once

char* StringCopy(char *dest, const char *source, int len);

char* StringCat(char *dest, const char *source, int len);

int StringCmp(const char *str1, const char *str2);

int StringToLower(char *dest, const char *source);

/*
@brief: �ַ������
@param: 
*/
int StringSplit(const char *source, const char split, char p[][20]);

unsigned int StringLen(const char *str);

char* StringChr(const char *source, const char c);
char* StringRChr(const char *source, const char c);

/*
@brief: ����ռ����洢str, ��Ҫ�Լ��ֶ�ȥ�ͷ�
*/
char* StringDup(const char *str);

/*
@brief: ��ת�ַ���
*/
char* StringRev(char *str);

char* StringStr(const char *str1, const char *str2);
