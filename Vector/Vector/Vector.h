#pragma once

template <typename T>
class Vector
{
private:
	int m_size;
	int m_capacity;
	T* m_elements;

public:
	Vector() : m_capacity(1), m_size(0)
	{
		m_elements = new T[m_capacity];
	}

	Vector(const Vector& other)
	{
		m_size = other.size();
		m_capacity = other.capacity();
		m_elements = new int[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			m_elements[i] = other[i];
		}
	}

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] m_elements;
			m_size = other.size();
			m_capacity = other.capacity();
			m_elements = new int[m_capacity];

			for (int i = 0; i < m_size; i++)
			{
				m_elements[i] = other[i];
			}
		}

		return *this;
	}

	~Vector()
	{
		delete[] m_elements;
	}

	void push_back(const T& element)
	{
		if (m_size == m_capacity)
		{
			resize(m_capacity * 2);
		}

		m_elements[m_size] = element;
		m_size++;
	}

	void pop_back()
	{
		erase(m_size - 1);
	}

	void resize(int newSize)
	{
		T* buffer = m_elements;
		int oldCapacity = m_capacity;
		m_capacity = newSize;
		m_elements = new T[newSize];

		if (m_capacity >= oldCapacity)
		{
			m_size = oldCapacity;
		}
		else
		{
			m_size = m_capacity;
		}

		for (int i = 0; i < m_size; i++)
		{
			m_elements[i] = buffer[i];
		}

		delete[] buffer;
	}

	T& back()
	{
		return m_elements[m_size - 1];
	}

	T& front()
	{
		return m_elements[0];
	}

	void insert(int index, T element)
	{
		if (m_capacity == m_size)
		{
			resize(m_capacity * 2);
		}
		m_size++;

		for (int i = m_size - 1; i > index; i--)
		{
			m_elements[i] = m_elements[i - 1];
		}
		m_elements[index] = element;
	}

	void erase(int index)
	{
		if (index > m_size - 1 || index < 0)
		{
			throw std::out_of_range("Index is out of range.");
		}
		for (int j = 1 + index; j < m_size; j++)
		{
			m_elements[j - 1] = m_elements[j];
		}
		--m_size;
	}

	T& operator[](int index) const
	{
		if (index > m_size - 1 || index < 0)
		{
			throw std::out_of_range("Index is out of range.");
		}

		return m_elements[index];
	}

	int size() const
	{
		return m_size;
	}

	int capacity() const
	{
		return m_capacity;
	}

	bool empty()
	{
		if (m_size > 0)
		{
			return false;
		}
		return true;
	}

	void clear()
	{
		m_capacity = 1;
		m_size = 0;
		delete[] m_elements;
		m_elements = new int[m_capacity];
	}
};