#include <iostream>
#include "SmartPointer.h"
using namespace std;
using namespace SimLib;

class Test : public Object
{
public:
	Test()
	{
		cout << "test()" << endl;
	}
	~Test()
	{
		cout << "~test()" << endl;
	}
};
int main()
{
	SmartPointer<Test> sp = new Test();

	SmartPointer<Test> spn;
	spn = sp;


}