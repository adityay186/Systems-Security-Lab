#include <iostream>

using namespace std;

int bToInt(int n) {
   int decimalNumber = 0;
   int base = 1;
   int temp = n;
   while (temp) {
      int lastDigit = temp % 10;
      temp = temp/10;
      decimalNumber += lastDigit*base;
      base = base*2;
   }

   return decimalNumber;
}

void dToBin(int n)
{
    for (int i = 5; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

int main(){
  int a;
  cout << "Enter PlainText : ";
  cin >> a;
  int b;
  cout << "Enter KeyWord   : ";
  cin >> b;

  int resa;
  int resb;
  resa = bToInt(a);
  resb = bToInt(b);

  int r = (resa ^ resb);
  cout << "Encrypted Text  : ";
  dToBin(r);
}
