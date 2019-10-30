#include <iostream>
#include "LinkList.h"
using namespace std;
using namespace SimLib;

int main()
{

	LinkList<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.insert(0,i);
	}

	for (list.move(0,3); !list.end(); list.next())
	{
		cout << list.current() << endl;
	}

	return 0;

}