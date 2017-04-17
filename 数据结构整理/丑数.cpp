#include <iostream>
#include <climits>
using namespace std;
//遍历法找丑数
int IsUgly(int num)//判断是否是
{
	while (num %2 == 0)
	{
		num /= 2;
	}
	while (num %3 == 0)
	{
		num /= 3;
	}
	while (num %5 == 0)
	{
		num /= 5;
	}
	if (num == 1)
		return 1;
	else
		return 0;//not an ugly number
}
void  GetUglyNumber(int index)
{//找到第index个丑数
	int i , time =0 ;
	if (index < 1)
	{
		cout << "error input " << endl;
//		exit(EXIT_FAILURE);
	}
	for (i=1 ; i< INT_MAX && time < index ; i++)
	{
		if ( IsUgly(i) )
		{
			time ++ ;
		//	cout << i << " " ;
		}
	}
	cout << i-1 << endl;
}
int main()
{
	int Number;
	cout << "Input a number : " ;
	cin >> Number ;
	GetUglyNumber(Number);
	return 0;
}
