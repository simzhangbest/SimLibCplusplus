#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;
namespace SimLib
{
	void* Object::operator new (unsigned int size) throw() // throw 是异常抛出说明
	{
		cout << "SimLib Object::operator new and size : " << size << endl;
		return malloc(size);
	}
	void  Object::operator delete (void* p)
	{
		free(p);
	}
	void* Object::operator new[](unsigned int size) throw()
	{
		return malloc(size);
	}
	void  Object::operator delete[](void* p)
	{
		free(p);
	}

	Object::~Object()
	{

	}

	bool Object::operator== (const Object& proj)
	{
		return (this == &proj);
	}

	bool Object::operator!= (const Object& proj)
	{
		return (this != &proj);
	}
}


