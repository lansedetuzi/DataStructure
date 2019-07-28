#pragma once

#define MAXLEN 1024

struct SeqString
{
    char data[MAXLEN];
    int length;
};

enum StringSearchAlgorithm
{
    SSA_BF,
    SSA_KMP
};

void StringInitial(SeqString *s, const char *string = nullptr);

void StringAssign(SeqString *s, SeqString t);

int StringLength(SeqString s);

int StringCompare(SeqString s, SeqString t);

int StringInsert(SeqString *s, const int pos, SeqString t);

int StringDelete(SeqString *s, const int pos, const int len);

int SubString(SeqString s, const int pos, const int len, SeqString *t);

int StringSearch(SeqString s, const int pos, SeqString t, StringSearchAlgorithm algorithm);

int StringReplace(SeqString *s, const int pos, SeqString t, SeqString p);

