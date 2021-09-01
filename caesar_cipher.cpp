#include <iostream>

using namespace std;

string encrypt(string inp, int sft){
  string res = "";

  for (int i = 0; i < inp.length(); i++){
    if (isupper(inp[i])){
      char t = char(int(inp[i]+sft-65)%26+65);
      res += t;
    }
    else if (inp[i] == ' '){
      res += ' ';
    }
    else{
      char t2 = char(int(inp[i]+sft-97)%26+97);
      res += t2;
    }
  }

  return res;
}

string decrypt(string inp, int sft){
  string res = "";

  for (int i = 0; i < inp.length(); i++){
    if (isupper(inp[i])){
      char t = char(int(inp[i])-sft-65)%26+65;
      res += t;
    }
    else if (inp[i] == ' '){
      res += ' ';
    }
    else{
      char t2 = char(int(inp[i])-sft-97)%26+97;
      res += t2;
    }
  }

  return res;
}


int main(){
  string inp;
  int sft;
  cout << "Enter Text     : ";
  getline(cin, inp);
  cout << "Enter Shift    : ";
  cin >> sft;
  string enc = encrypt(inp, sft);
  cout << endl;
  cout << "Encrypted Text : " << enc << endl;
  cout << endl;
  cout << "Decrypted Text : " << decrypt(enc, sft) << endl;
}
