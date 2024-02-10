#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyBinaryTree;

template<class T>
ostream& operator << (ostream &os, const MyBinaryTree<T> &tree)
{
   tree.print(tree.first);
   return os << endl;
}

template <class T>
class MyBinaryTree
{
private:
   class Root
   {
   public:
      Root* left;
      Root* right;
      T val;
      Root(Root *l, Root *r, T v)
      {
         left = l;
         right = r;
         val = v;
      }
      ~Root()
      {
         delete left;
         delete right;
      }
   };
public:
   Root* first = NULL;
   Root* sup = NULL;
   void push(T par)
   {
      if (first == NULL)
      {
         first =  new Root(NULL, NULL, par);
      }

      else
      {
         sup = first;
         while (true)
         {
            if (sup->val > par)
            {
               if (sup->left == NULL)
               {
                  sup->left =  new Root(NULL, NULL, par);
                  break;
               }
               else
               {
                  sup = sup->left;
                  continue;
               }
            }
            else
            {
               if (sup->right == NULL)
               {
                  sup->right = new Root(NULL, NULL, par);
                  break;
               }
               else
               {
                  sup = sup->right;
                  continue;
               }
            }

         }
      }
   }
   void print(const Root* first) const 
   {
      if (first->left != NULL)
         print(first->left);
      cout << first->val << " ";
      if (first->right != NULL)
         print(first->right);
   }
   ~MyBinaryTree()
   {
      delete first;
   }
   friend ostream& operator << <T>(std::ostream& os, const MyBinaryTree <T>& tree);
};


int main()
{
    MyBinaryTree <char> A;
    A.push('d');
    A.push('a');
    A.push('b');
    A.push('g');
    A.push('a');
    cout << A;
    return 0;
}
