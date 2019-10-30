#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"
namespace SimLib
{
	template<typename T>
	class LinkList : public List<T>
	{

	protected:
		struct Node : public Object
		{
		
			T value;
			Node* next;
		};

		mutable struct : public Object {
			char reserved[sizeof(T)];
			Node* next;
		} m_header;

		int m_length;
		int m_step;
		Node* m_current;


		Node* position(int i) const
		{
			Node* ret = reinterpret_cast<Node*>(&m_header); // * ÀàÐÍ×ª»»

			for (int p = 0; p < i; p++)
			{
				ret = ret->next;
			}

			return ret;
		}

		virtual Node* create()
		{
			return new Node();
		}

		virtual void destroy(Node* pn)
		{
			delete pn;
		}
	public:
		LinkList()
		{
			m_header.next = nullptr;
			m_length = 0;
			m_step = 1;
			m_current = nullptr;
		}



		bool  insert(const T& e)
		{
			return  insert(m_length, e);
		}


		bool insert(int i, const T& e)
		{
			bool ret = ((0 <= i) && (i <= m_length));
			
			if (ret)
			{
				Node* node = create();

				if (node != nullptr)
				{
					Node* current = position(i);
					node->value = e;
					node->next = current->next;
					current->next = node;

					m_length++;
				}
				else
				{
					THROW_EXCEPTION(NoEnoughMemoryException, "No enough memory to insert ...");
				}
			}

			return ret;
		}
		bool remove(int i)
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				Node* current = position(i);

				Node* toDel = current->next;
				current->next = toDel->next;
				m_length--;

				destroy(toDel);
			}

			return ret;
		}
		bool set(int i, const T& e)
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				Node* current = position(i);
				current->next->value = e;
			}

			return ret;
		}

		T get(int i) const
		{
			T ret;
			if (get(i, ret))
			{
				return ret;
			}
			else
			{
				THROW_EXCEPTION(IndexOutOfBoundsException, "Invaild index i to get element ...");
			}
		}

		bool get(int i, T& e) const
		{
			bool ret = ((0 <= i) && (i < m_length));

			if (ret)
			{
				Node* current = position(i);
				e = current->next->value;
			}

			return ret;
		}
		int length() const
		{
			return m_length;
		}
		void clear()
		{
			while (m_header.next)
			{
				Node* toDel = m_header.next;

				m_header.next = toDel->next;
				
				m_length--;

				destroy(toDel);
			}

			
		}

		~LinkList()
		{
			clear();
		}

		int find(const T& e) const
		{
			int ret = -1;
			int i = 0;
			Node* node = m_header.next;

			while (node)
			{
				if (node->value == e)
				{
					ret = i;
					break;
				}
				else
				{
					node = node->next;
					i++;
				}
			}

			return ret;
		}


		bool move(int i, int step = 1)
		{
			bool ret = ((0 <= i) && (step > 0));

			if (ret)
			{
				m_current = position(i)->next;
				m_step = step;
			}

			return ret;
		}

		bool end()
		{
			return (m_current == nullptr);
		}

		T current()
		{
			if (!end())
			{
				return m_current->value;
			}
			else
			{
				THROW_EXCEPTION(InvalidOperationException, "no value at current position ...");
			}
		}

		bool next()
		{
			int i = 0;

			while ((i < m_step) && !end())
			{
				m_current = m_current->next;
				i++;
			}
			
			return (i == m_step);

		}
	};


}
#endif // !LINKLIST_H



