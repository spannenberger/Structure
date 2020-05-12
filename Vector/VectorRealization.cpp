#include <bits/stdc++.h>
using namespace std;

template <typename T>
class vect
{
	T* values;
	int size;
public:
	vect() : size(0) { values = new T[0]; }
	~vect() { delete[] values; }

	void add_first(T value);
	void add_last(T value);
	void add_in_position(T value, int p);

	void remove_first();
	void remove_last();
	void remove_from_position(int p);

	T get_value_in_position(int position) const { return values[position]; }
	T get_first_value() const { if (size > 0) return values[0]; }
	T get_last_value() const { if (size > 0) return values[size - 1]; }

	int get_size() const { return size; }
	void print();
};

template <typename T>
void vect<T>::add_first(T value)
{
	T* temp = new T[size + 1];
	temp[0] = value;
	for (size_t i = 0; i < size; ++i)
		temp[i + 1] = values[i];
	values = temp;
	++size;
}

template <typename T>
void vect<T>::add_last(T value)
{
	++size;
	T* temp = new T[size];
	for (size_t i = 0; i < size - 1; ++i)
		temp[i] = values[i];
	temp[size - 1] = value;
	values = temp;
}

template <typename T>
void vect<T>::add_in_position(T value, int p)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < p; ++i)
		temp[i] = values[i];
	temp[p] = value;
	for (size_t i = p + 1; i < size + 1; ++i)
		temp[i] = values[i - 1];
	values = temp;
	++size;
}

template <typename T>
void vect<T>::remove_first()
{
	T* temp = new T[size - 1];
	for (size_t i = 0; i < size - 1; ++i)
		temp[i] = values[i + 1];
	values = temp;
	--size;
}

template <typename T>
void vect<T>::remove_from_position(int p)
{
	T* temp = new T[size - 1];
	for (size_t i = 0; i < p; ++i)
		temp[i] = values[i];
	for (size_t i = p; i < size - 1; ++i)
		temp[i] = values[i + 1];
	values = temp;
	--size;
}

template <typename T>
void vect<T>::remove_last()
{
	--size;
	T* temp = new T[size];
	for (size_t i = 0; i < size; ++i)
		temp[i] = values[i];
	values = temp;
}

template <typename T>
void vect<T>::print()
{
	if (size > 0)
	{
		T* temp = new T[size];
		for (size_t i = 0; i < size; ++i)
			temp[i] = values[i];

		for (size_t i = 0; i < size - 1; ++i)
		{
			for (size_t j = i + 1; j < size; ++j)
			{
				if (temp[i] > temp[j])
				{
					T a_temp = temp[i];
					temp[i] = temp[j];
					temp[j] = a_temp;
				}
			}
		}


		for (size_t i = 0; i < size; ++i)
			std::cout << temp[i] << " ";
		std::cout << std::endl;

		delete[] temp;
	}
}
int main (){
    cout << "Vector realization is okey!";
    return 0;
}
