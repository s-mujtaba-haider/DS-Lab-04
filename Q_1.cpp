#include<iostream>
using namespace std;
template <class T>
class CircularLinkedList {
public:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
    };
    class iterator {
    public:
        Node* n;
        iterator() {
            n = nullptr;
        }
        iterator(Node* N)
        {
            n = N;
        }
        iterator(const iterator& i)
        {
            this->n = i.n;
        }
        iterator& operator++ ()
        {
            n = n->next;
            return *this;
        }
        iterator& operator++ (int)
        {
            n = n->next;
            return *this;
        }
        iterator& operator-- ()
        {
            n = n->prev;
            return *this;
        }
        T operator* ()
        {
            return n->data;
        }
        T operator[] (int index)
        {
            for (int i = 0; i < index; i++)
                n = n->next;
            return n->data;
        }
        bool operator== (const iterator& i)
        {
            return this->n == i.n;
        }
        bool operator!= (const iterator& i)
        {
            return this->n != i.n;
        }
    };
public:
    Node* head;
    Node* tail;
    CircularLinkedList() {
        head = CreateNode(-1);
        tail = CreateNode(-1);
        head->next = tail;
        tail->next = head;
    }
    Node* CreateNode(T val) {
        Node* temp = new Node();
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }
    void Push(T val) {
        tail->data = val;
        tail->next = CreateNode(-1);
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = head;
    }
    T Pop(void) {
        if (head->next != tail) {
            Node* temp = head->next;
            T val = temp->data;
            head->next = temp->next;
            temp->next->prev = head;
            delete temp;
            return val;
        }
        return -1;
    }
    void DisplayList(void) {
        Node* ptr = head->next;
        while (ptr != tail) {
            cout << "Data : " << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }
    iterator Begin() {
        return iterator(head->next);
    }
    iterator RBegin() {
        return iterator(tail->prev);
    }
    iterator End() {
        return iterator(tail);
    }
    iterator REnd() {
        return iterator(head);
    }
};
int main() {
  int sum = 0, count = 0;
  CircularLinkedList<int> l;
  l.Push(5);
  l.Push(8);
  l.Push(2);
  l.Push(9);
  l.Push(1);
  l.Push(7);
  l.Push(6);
  CircularLinkedList<int>::iterator i;
  for (i = l.Begin(); i != l.End(); ++i)
  {
      count = count + 1;
  }
  for (int j = 0; j != count; j++)
  {
      cout << "Data";
      for (i = l.Begin(); i != l.End(); ++i)
      {
          cout << " -> " << *i;
          sum += *i;
      }
      cout << endl << "Sum = " << sum << endl << endl;
      if (sum % 2 == 0) {
          l.Pop();
          i++;
      }
      else if (sum % 2 != 0) {
          i++;
      }
      sum = 0;
  }
  cout << endl << endl;
  cout << endl;
  return 0;
}