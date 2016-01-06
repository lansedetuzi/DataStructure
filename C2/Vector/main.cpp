#include <iostream>

#include "Vector.h"

using namespace std;

void testVector()
{
    Vector<int> *vector1 = new Vector<int>;

    for (int i = 0; i < 10; ++i)
    {
        vector1->push_back(i);
    }

    Vector<int>::iterator iter = vector1->begin();
    while (iter != vector1->end())
    {
        cout << *iter++ << endl;
    }

    cout << vector1->back() << endl;
    cout << vector1->size() << endl;
    cout << vector1->capacity() << endl;
    cout << vector1->empty() << endl;

    Vector<int> *vect2(vector1);
    Vector<int> *vect3;
    vect3 = vector1;

    cout << vect2->back() << endl;
    cout << vect3->back() << endl;
}

int main()
{
    testVector();
    return 0;
}

