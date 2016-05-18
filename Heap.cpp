#include"Heap.h"
template<class T>
void test()
{
	int a[11]={10,16,18,12,11,13,15,17,14,19};
	size_t size=sizeof(a)/sizeof(a[0]);
	Heap(a,size);
	for(size_t i=0;i<size;i++)
	{
	  cout<<a[1]<<" ";
	}
	cout<<endl;
	push(20);

	pop();

}
template<class T>
int main()
{
test();
getchar();
return 0;
}



//#include <iostream>  
//#include <algorithm>  
//  
//using namespace std;  
//template<typename T>  
//class display  
//{  
//public:  
//    void operator()(const T &x)  
//    {  
//        cout<<x<<" ";   
//    }   
//};   
//   
//int main()  
//{  
//    int ia[]={1,2,3,4,5};  
//    for_each(ia,ia+5,display<int>());   
//    system("pause");
//    return 0;   
//}   