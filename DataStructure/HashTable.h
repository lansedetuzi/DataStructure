#pragma once

#include <stdlib.h>

typedef int DataType;

enum KindOfItem
{
	Empty,
	Active,
	Deleted
};

struct HashItem
{
	DataType data;
	KindOfItem info;
};

struct HashTable
{
	HashItem *ht;
	int tableSize;
	int curSize;
};

int Initial(HashTable *hash, int size)
{
	hash->tableSize = size;
	if (nullptr == (hash->ht = (HashItem *)malloc(size * sizeof(HashItem))))
	{
		return -1;
	}
	else
	{
		hash->curSize = 0;
		return 0;
	}
}

int Find(HashTable *hash, DataType x)
{
	int i = x % hash->tableSize;
	int j = i;
	while (hash->ht[j].info == Active && hash->ht[j].data != x)
	{
		// 说明存在冲突
		j = (j + 1) % hash->tableSize;
		if (j == i)
		{
			// 说明找遍整个哈希表仍未找到
			return -hash->tableSize;
		}
	}

	if (hash->ht[j].info == Active)
		return j;
	else
		return -j;
}

int Insert(HashTable *hash, DataType x)
{
	int i = Find(hash, x);
	if (i >= 0)
	{
		// x已存在
		return -1;
	}
	else if (i != -hash->tableSize)
	{
		hash->ht[-i].data = x;
		hash->ht[-i].info = Active;
		hash->curSize++;
		return 0;
	}
	else
	{
		return -1;
	}
}

int Delete(HashTable *hash, DataType x)
{
	int i = Find(hash, x);
	if (i >= 0)
	{
		hash->ht[i].info = Deleted;
		hash->curSize--;
		return 0;
	}
	else
		return -1;
}

void Destroy(HashTable *hash)
{
	free(hash);
}