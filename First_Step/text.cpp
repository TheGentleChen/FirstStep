#include <iostream>

const int limit = 5;
template <typename T>
T max5(T ar[]);

int main()
{
using namespace std;
int ari[limit] = {1,2,3,5,4};
double ard[limit] = {1.1,2.2,3.3,5.5,4.4};
int maxi = max5(ari);
double maxd = max5(ard);
cout << "maxi = " << maxi << endl;
cout << "maxd = " << maxd << endl;
return 0;
}
template <typename T>
T max5(T ar[])
{
	T max = ar[0];
	for (int i = 1;i < limit;i++)
		{
		    if (max < ar[i])
		max = ar[i];
		}
	return max;
}
