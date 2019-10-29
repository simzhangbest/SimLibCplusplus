#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Exception.h"
#include "Array.h"
namespace SimLib
{
	template <typename T>
	class DynamicArray : public Array<T>
	{
	protected:
		int m_length;

		T* copy(T* array, int len, int newLen)
		{
			T* ret = new T[newLen];
			if (ret != NULL)
			{
				int size = (len < newLen) ? len : newLen;

				for (int i = 0; i < size; i++)
				{
					ret[i] = array[i];
				}
				
			}

			return ret;
		}


		void update(T* array, int length)
		{
			if (array != nullptr)
			{
				T* temp = this->m_array;
				
				this->m_array = array;
				this->m_length = length;

				delete[] temp;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to update Dynamic obj ...");
			}
		}

		void init(T* array, int length)
		{
			if (array != nullptr)
			{
				this->m_array = array;
				this->m_length = length;
			}
			else
			{
				THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create DynamicArray obj ...");
			}
		}
	public:
		DynamicArray(int length)
		{
			init(new T[length], length);
		}

		DynamicArray(const DynamicArray<T>& obj)
		{
			T* array = copy(obj.m_array, obj.m_length, obj.m_length);
			init(array, obj.m_length);
		}

		DynamicArray<T>& operator= (const DynamicArray<T>& obj)
		{
			if (this != nullptr)
			{
				update(copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);
			}

			return *this;
		}

		int length() const
		{
			return this->m_length;
		}

		//重置数组的长度
		void resize(int length)
		{
			if (length != m_length)
			{
				T* array = copy(this->m_length);
				update(array, length);
			}
		}

		~DynamicArray()
		{
			delete[] this->m_array;
		}
	};
}

#endif