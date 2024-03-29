/*
典型问题分析 3 也补充了
#ifndef  STATICLINKLIST_H
#define  STATICLINKLIST_H

#include "LinkList.h"

namespace SimLib
{

	template<typename T, int N>
	class StaticLinkList : public LinkList<T>
	{
	protected:
		typedef typename LinkList<T>::Node Node;

		struct SNode: public Node
		{
			void* operator new (unsigned int size, void* loc)
			{
				(void)size;
				return loc;
			}
		};
		unsigned char m_space[sizeof(SNode) * N];
		int m_used[N];

		Node* create()
		{
			SNode* ret = nullptr;
			for (int i = 0; i < N; i++)
			{
				if (!m_used[i])
				{
					ret = reinterpret_cast<SNode*>(m_space) + i;
					ret = new(ret) SNode();
					m_used[i] = 1;
					break;
				}
			}

			return nullptr;
		}

		void destroy(Node* pn)
		{
			SNode* space = reinterpret_cast<SNode*>(m_space);
			SNode* psn = dynamic_cast<SNode*>(pn);

			for (int i = 0; i < N; i++)
			{
				if (pn == (space + i))
				{
					m_used[i] = 0;
					psn->~SNode();

				}
			}
		}

	public:

		StaticLinkList()
		{
			for (int i = 0; i < N; i++)
			{
				m_used[i] = 0;
			}
		}

		int capacity()
		{
			return N;
		}
	};


	
}


#endif // ! STATICLINKLIST_H

*/

