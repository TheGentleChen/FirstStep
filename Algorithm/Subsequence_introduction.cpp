 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
 {
     double n, m;
     while (cin >> n >> m && n != 0 && m != 0)
     {
         double result = 0;
         for (double i = n;i <= m;i++)
         {
             result += (1.0 / (i * i));
         }
         cout << fixed << setprecision(5) << result << endl;
     }
     return 0;
 }
