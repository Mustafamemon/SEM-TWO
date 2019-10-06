#include <iostream>
using namespace std;
int GCD(int n , int m)
{
	if(m<=n && n%m==0)
		return m;
	else if(n<m)
		return GCD(m,n);
	else 
		return GCD(m,n%m);
}
int main()
{
	cout<<GCD(3,9);
}
/*int binomial(int n, int k)
{
	if (n<k)
	return 0;
    if (k == 0 || k == n)
	    return 1;
	else
     	return (binomial(n-1,k-1) + binomial(n-1,k));     
}
int main()
{
	cout << "binomial(2, 4) is " << binomial(10, 3) << endl;
	return 0;
}*/
