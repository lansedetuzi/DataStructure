#include "stdafx.h"
#include "SeqString.h"

#include <iostream>
using namespace std;

void StringInitial(SeqString *s, const char *string /*= nullptr*/)
{
    if (nullptr == string)
    {
        s->data[0] = '\0';
        s->length = 0;
    }
    else
    {
        int i = 0;
        for (; *(string + i) != '\0'; i++)
        {
            s->data[i] = *(string + i);
        }
        s->data[i] = '\0';
        s->length = i;
    }
}

void StringAssign(SeqString *s, SeqString t)
{
    for (int i = 0; i < t.length; i++)
    {
        s->data[i] = t.data[i];
    }

    s->data[t.length] = '\0';
    s->length = t.length;
}

int StringLength(SeqString s)
{
    return s.length;
}

int StringCompare(SeqString s, SeqString t)
{
    int nLenMin = s.length < t.length ? s.length : t.length;
    for (int i = 0; i < nLenMin; i++)
    {
        if (s.data[i] < t.data[i])
        {
            return -1;
        }
        else if (s.data[i] = t.data[i])
        {
            continue;
        }
        else
        {
            return 1;
        }
    }

    if (s.length < t.length)
        return -1;
    else if (s.length == t.length)
        return 0;
    else
        return 1;
}

int StringInsert(SeqString *s, const int pos, SeqString t)
{
    if (pos < 0 || pos > s->length)
    {
        cout << "invalid param..." << endl;
        return -1;
    }

    if (s->length + t.length > MAXLEN)
    {
        cout << "no enough space..." << endl;
        return - 1;
    }

    int nLenT = t.length;
    // 将s自pos位置到pos+t.length的位置让给t
    for (int i = s->length - 1; i >= pos; i--)
    {
        s->data[i + nLenT] = s->data[i];
    }

    for (int i = 0; i < t.length; i++)
    {
        s->data[pos + i] = t.data[i];
    }
    s->data[s->length + t.length] = '\0';
    s->length += t.length;

    return 0;
}

int StringDelete(SeqString *s, const int pos, const int len)
{
    if (s->length <= 0)
    {
        cout << "empty string" << endl;
        return -1;
    }

    if (pos < 0 || len < 0 || pos + len > s->length)
    {
        cout << "invalid param" << endl;
        return -1;
    }

    for (int i = pos + len; i < s->length; i++)
    {
        s->data[i - len] = s->data[i];
    }

    s->data[s->length - len] = '\0';
    s->length -= len;

    return 0;
}

int SubString(SeqString s, const int pos, const int len, SeqString *t)
{
    if (s.length <= 0)
    {
        cout << "empty string" << endl;
        return -1;
    }

    if (pos < 0 || len < 0 || pos + len > s.length)
    {
        cout << "invalid param" << endl;
        return -1;
    }

    for (int i = 0; i < len; i++)
    {
        t->data[i] = s.data[pos + i];
    }
    t->data[len] = '\0';
    t->length = len;

    return 0;
}

int StringSearch(SeqString s, const int pos, SeqString t, StringSearchAlgorithm algorithm)
{
    auto BruteForceMatch = [&](SeqString s, const int pos, SeqString t)
    {
        int i = pos, j = 0, nRel = 0;
        while (i < s.length && j < t.length)
        {
            if (s.data[i] == t.data[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }

        if (j == t.length)
            nRel = i - t.length;
        else
            nRel = -1;

        return nRel;
    };

    auto GetNext = [&](SeqString t, int next[])
    {
        int j = 1, k = 0;
        next[0] = -1;
        next[1] = 0;
        while (j < t.length)
        {
            if (t.data[j] == t.data[k])
            {
                next[j + 1] = k + 1;
                j++;
                k++;
            }
            else if (k == 0)
            {
                next[j + 1] = 0;
                j++;
            }
            else
            {
                k = next[k];
            }
        }
    };

    auto KMPMatch = [&](SeqString s, const int pos, SeqString t, int next[])
    {
        int nRel = 0, i = pos, j = 0;

        while (i < s.length && j < t.length)
        {
            if (s.data[i] == t.data[j])
            {
                i++;
                j++;
            }
            else if (j == 0)
            {
                i++;
            }
            else
            {
                j = next[j];
            }
        }

        if (j == t.length)
        {
            nRel = i - t.length;
        }
        else
        {
            nRel = -1;
        }

        return nRel;
    };

    if (SSA_BF == algorithm)
        return BruteForceMatch(s, pos, t);
    else
    {
        int next[] = {0};
        GetNext(t, next);
        return KMPMatch(s, pos, t, next);
    }
}

