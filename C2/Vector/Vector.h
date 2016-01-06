#ifndef VECTOR_H
#define VECTOR_H

template<typename Object>
class Vector
{
public:
    enum { initCapacity = 16 };
    explicit Vector(int initSize = 0)
        : m_size(initSize)
        , m_capacity(initSize + initCapacity)
    { m_objects = new Object[m_capacity];}

    explicit Vector(const Vector &vect)
        : m_objects(nullptr)
    {
        operator =(vect);
    }

    ~Vector()
    {
        delete []m_objects;
    }

    const Vector& operator=(const Vector &vect)
    {
        if (this != &vect)
        {
            delete []m_objects;
            m_size = vect.size();
            m_capacity = vect.capacity();
            m_objects = new Object[capacity()];
            for (int i = 0; i < size(); ++i)
            {
                m_objects[i] = vect[i];
            }
        }
        return *this;
    }

    void resize(const int newSize)
    {
        if (newSize > m_capacity)
        {
            reserve(newSize * 2 + 1);
        }

        m_size = newSize;
    }

    void reserve(const int newCapacity)
    {
        if (newCapacity <= m_capacity)
        {
            return;
        }

        Object *oldObjs = m_objects;
        m_objects = new Object[newCapacity];

        for (int i = 0; i < size(); ++i)
        {
            m_objects[i] = oldObjs[i];
        }

        m_capacity = newCapacity;

        delete []oldObjs;
    }

    Object& operator[](const int index)
    {
        return m_objects[index];
    }

    const Object& operator [](const int index) const
    {
        return m_objects[index];
    }

    bool empty() const
    { return m_size == 0; }

    int size() const
    { return m_size; }

    int capacity() const
    { return m_capacity; }

    void push_back(const Object &obj)
    {
        if (m_size == m_capacity)
        {
            reserve(2 * m_capacity + 1);
        }

        m_objects[m_size++] = obj;
    }

    void pop_back()
    {
        m_size--;
    }

    const Object& back() const
    {
        return m_objects[m_size - 1];
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
        return &m_objects[0];
    }

    const_iterator begin() const
    {
        return &m_objects[0];
    }

    iterator end()
    {
        return &m_objects[m_size];
    }

    const_iterator end() const
    {
        return &m_objects[m_size];
    }

private:
    int m_size;
    int m_capacity;
    Object *m_objects;
};

#endif // VECTOR_H
