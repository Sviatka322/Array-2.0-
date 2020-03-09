#include <iostream>

class Array
{
private:
	int m_size;
	int* m_array;

public:
	Array(int size = 5) : m_size(size), m_array(new int[size]) {}

	Array(Array& copy)
	{
		m_array = copy.m_array;
		m_size = copy.m_size;
	}

	friend std::ostream& operator<<(std::ostream& os, Array& array);
	friend std::istream& operator>>(std::istream& is, Array& array);

	Array& operator+(Array& array)
	{
		if (this->m_size == array.m_size)
		{
			Array t_array;

			for (int i = 0; i < this->m_size; i++)
			{
				t_array.m_array[i] = this->m_array[i] + array.m_array[i];
			}

			for (int i = 0; i < this->m_size; i++)
			{
				this->m_array[i] = t_array.m_array[i];
			}

			return *this;
		}
		else
		{
			std::cout << "NaN" << '\n';
			exit(1);
		}

	}

	void operator-(int element)
	{
		int index = 0;

		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_array[i] == element)
			{
				index++;
			}
		}

		Array t_array(this->m_size);

		for (int i = 0; i < t_array.m_size; i++)
		{
			t_array.m_array[i] = this->m_array[i];
		}

		delete[] this->m_array;

		this->m_size = t_array.m_size - index;

		this->m_array = new int[this->m_size];
		int s_index = 0;

		for (int i = 0; i < t_array.m_size; i++)
		{
			if (t_array.m_array[i] != element)
			{
				this->m_array[s_index] = t_array.m_array[i];
				s_index++;
			}
		}
	}

	void operator+=(int value)
	{
		Array t_array(this->m_size);

		for (int i = 0; i < t_array.m_size; i++)
		{
			t_array.m_array[i] = this->m_array[i];
		}

		delete[] this->m_array;
		
		this->m_size += 1;
		this->m_array = new int[this->m_size];

		for (int i = 0; i < this->m_size; i++)
		{
			this->m_array[i] = t_array.m_array[i];
			
			this->m_array[this->m_size - 1] = value;
		}
	}

	void print()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_array[i] << ' ';
		}

		std::cout << '\n';
	}

	void push()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << "Enter " << i + 1 << " element: ";
			std::cin >> m_array[i];
		}
	}

	int search(int element)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_array[i] == element)
			{
				return i;
			}
		}

		return -1;
	}

	void sort()
	{
		int i, j, step;
		int tmp;
		for (step = m_size / 2; step > 0; step /= 2)
			for (i = step; i < m_size; i++)
			{
				tmp = m_array[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < m_array[j - step])
						m_array[j] = m_array[j - step];
					else
						break;
				}
				m_array[j] = tmp;
			}
	}


};

std::ostream& operator<<(std::ostream& os, Array& array)
{
	for (int i = 0; i < array.m_size; i++)
	{
		os << array.m_array[i] << " ";
	}

	return os;
}

std::istream& operator>>(std::istream& is, Array& array)
{
	for (int i = 0; i < array.m_size; i++)
	{
		std::cout << "Enter " << i + 1 << " element: ";
		is >> array.m_array[i];
	}

	return is;
}

int main()
{
	Array ar1;
	ar1.push();
	std::cout << ar1 << '\n';

	Array ar2;
	ar2.push();
	std::cout << ar2 << '\n';

	ar1 + ar2;

	ar2 - 3;
	std::cout << ar2 << '\n';

	ar1 += 6;
	std::cout << ar1 << '\n';

	return 0;
}