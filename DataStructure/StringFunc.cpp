#include "stdafx.h"
#include "StringFunc.h"

#include "String.h"

int LastWordLenOfString(const char *str)
{
    if (str == NULL)
        return 0;

    const char *tmp = str + StringLen(str) - 1;
    int nLastWordLen = 0;
    bool bStart = false;
    while (*tmp != ' ')
    {
        if (tmp == str)
        {
            nLastWordLen++;
            break;
        }
        if (!bStart)
        {
            if ((*tmp >= 'a' && *tmp <= 'z')
                || (*tmp >= 'A' && *tmp <= 'Z'))
            {
                bStart = true;
                nLastWordLen++;
            }
            tmp--;
            continue;
        }
        else
        {
            tmp--;
            nLastWordLen++;
        }
    }
    return nLastWordLen;
}

int LetterCountOfString(const char *str, const char c)
{
    int nCount = 0;
    const char *tmp = str;
    while (*tmp != '\0')
    {
        if (*tmp == c)
            nCount++;
        else
        {
            if (c >= 'a' && c <= 'z')
            {
                if (*tmp == c - 32)
                    nCount++;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                if (*tmp == c + 32)
                    nCount++;
            }
        }
        tmp++;
    }
    return nCount;
}
