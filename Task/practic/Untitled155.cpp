#include<iostream>
#include<cstdlib>
using namespace std;
int main ()
{
	int numberofelements,numberofqueries,ithindex,jthindex,kelement,count,i,j,k,l;
	cin>>numberofelements;
	int array[numberofelements];
	for (i=0;i<numberofelements;i++)
	{
		cin>>array[i];
	}
	cin>>numberofqueries;
	int countarray[numberofqueries];
	for(int j=0;j<numberofqueries;j++)
	{
		cin>>ithindex>>jthindex>>kelement;
		for (int k=ithindex;k<=jthindex;k++)
		{
			
			if (array[k] > kelement)
			{
				count++;
			}
		}
		cout<<count;
		countarray[j] = count;
		count =0;
		cout<<endl;
	}
	for(int l=0;l<numberofqueries;l++)
	{
		cout<<countarray[l]<<endl;
	}
	
}
