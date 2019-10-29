#ifndef OBJECT_H
#define OBJECT_H

namespace SimLib
{
	class Object
	{
	public:
		void* operator new (unsigned int size) throw();
		void operator delete (void* p);
		void* operator new[](unsigned int size) throw();
		void operator delete[](void* p);
		virtual ~Object() = 0;
		bool operator== (const Object& proj);
		bool operator!= (const Object& proj);

	private:

	};
}
#endif // !OBJECT_H


