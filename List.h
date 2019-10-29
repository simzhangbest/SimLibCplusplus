#ifndef LIST_H
#define LIST_H

#include "Object.h"
namespace SimLib
{
	template <typename T>
	class List : public Object
	{
	protected: 
		//禁用拷贝构造和赋值，防止重复释放堆空间
		List(const List&);
		List& operator= (const List&);
	public:
		List() {}
		virtual bool  insert(const T& e) = 0; //尾部插入
		virtual bool insert(int i, const T& e) = 0;
		virtual bool remove(int i) = 0;
		virtual bool set(int i, const T& e) = 0;
		virtual bool get(int i, T& e) const = 0;
		virtual int length() const = 0;
		virtual void clear() = 0;

	};

}
#endif // !LIST_H


