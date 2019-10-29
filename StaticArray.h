#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H
#include "Array.h"
namespace SimLib
{
	template <typename T, int N>
	class StaticArray : public Array<T>
	{
	protected:
		T m_sapce[N];
	public:
		StaticArray()
		{
			this->m_array = m_sapce;
		}

		StaticArray(const StaticArray<T, N>& obj)
		{
			this->m_array = obj.m_array;
			for (int i = 0; i < N; i++)
			{
				m_sapce[i] = obj.m_sapce[i];
			}
		}

		StaticArray<T, N>& operator= (const StaticArray<T, N>& obj)
		{
			if (this != obj)
			{
				for (int i = 0; i < N; i++)
				{
					m_sapce[i] = obj.m_sapce[i];
				}
			}

			return *this;
		}

		int length() const
		{
			return N;
		}
	};
}

#endif // !STATICARRAY_H

#include "Array.h"



