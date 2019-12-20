#include "stdafx.h"
#include "String.h"

#include <assert.h>

char* StringCopy(char *dest, const char *source, int len)
{
    assert(dest != NULL && source != NULL);

    char *tmp = dest;

    // 内存重叠，从后往前赋值
    if (tmp >= source && tmp <= source + len - 1)
    {
        tmp += len - 1;
        source += len - 1;
        while (len--)
            *tmp-- = *source--;
    }
    else
    {
        while (len--)
            *tmp++ = *source++;
    }

    return dest;
}

char* StringCat(char *dest, const char *source, int len)
{
    assert(dest != NULL && source != NULL);

    char *tmp = dest;

    while (*tmp != '\0')
        tmp++;

    while ((*tmp++ = *source++) != '\0');

    return dest;
}

int StringCmp(const char *str1, const char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }

    int nDiff = *str1 - *str2;
    if (nDiff > 0)
        return 1;
    else
        return -1;
}

int StringToLower(char *dest, const char *source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        if (source[i] >= 'A' && source[i] <= 'Z')
        {
            dest[i] = source[i] + 32;
        }
        else
        {
            dest[i] = source[i];
        }
        i++;
        dest[i] = '\0';
    }
    return 0;
}

int StringSplit(const char *source, const char split, char p[][20])
{
    int i = 0;
    int nRow = 0;
    int nCol = 0;
    char *tmp = const_cast<char*>(source);
    while (tmp[i] != '\0')
    {
        if (tmp[i] != split)
        {
            p[nRow][nCol] = tmp[i];
            i++;
            nCol++;
        }
        else
        {
            p[nRow][nCol] = '\0';
            i++;
            nRow++;
            nCol = 0;
        }
    }
    return nRow + 1;
}

unsigned int StringLen(const char *str)
{
    unsigned int nLen = 0;
    while (*str++ != '\0')
        nLen++;
    return nLen;
}

char* StringChr(const char *source, const char c)
{
    char *tmp = const_cast<char *>(source);
    while (*tmp != '\0' && *tmp != c)
        tmp++;

    return (*tmp != c ? NULL : tmp);
}

char* StringRChr(const char *source, const char c)
{
    char *tmp = const_cast<char*>(source) + strlen(source);

    while (tmp != source && *tmp != c)
        tmp--;

    if (tmp == source && *tmp != c)
        return NULL;
    else
        return tmp;
}

char* StringDup(const char *str)
{
    char *tmp = NULL;
    if (str && (tmp = (char *)malloc(strlen(str) + 1)))
        strcpy_s(tmp, strlen(str) + 1, str);

    return tmp;
}

char* StringRev(char *str)
{
    if (str == NULL)
        return NULL;

    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;
    while (start <= end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

char* StringStr(const char *str1, const char *str2)
{
    int nLength1 = strlen(str1);
    int nLength2 = strlen(str2);
    while (nLength1 >= nLength2)
    {
        nLength1--;
        if (0 == strncmp(str1, str2, nLength2))
            return const_cast<char*>(str1);
        str1++;
    }

    return NULL;
}
