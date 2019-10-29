#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
namespace SimLib
{
	template<typename T>
	class Array
	{

	protected:
		T* m_array;
	public:

		virtual bool set(int i, const T& e)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				m_array[i] = e;
			}
			return ret;
		}

		virtual bool get(int i, T& e)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				e = m_array[i];
			}

			return ret;
		}


		// 自定义的数组出现了越界，立马抛出异常，防止错误传递
		T& operator[] (int i)
		{
			bool ret = ((0 <= i) && (i < length()));
			if (ret)
			{
				return m_array[i];
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "Paramter i is invalid ...");
			}
		}

		T& operator[] (int i) const
		{
			return (const_cast<Array<T>&>(*this)[i]);
		}

		// 保证还是抽象类，用来作为基类 tips 这里如果忘了加 const 子类也别加 不然不是同一类函数，会导致子类无法实例化
		virtual int length() const = 0;

	};

}
#endif // !ARRAY_H


