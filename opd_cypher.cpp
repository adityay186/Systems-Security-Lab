#include <iostream>
#include <map>

using namespace std;

class OPDCypher{
public:
  string plain_text;
  string key_text;
  int length;
  string cypher_text;

  OPDCypher(string action, string pt, string kt){
    if (action == "decrypt"){
      cypher_text = pt;
      key_text = kt;
      length = pt.length();
    }
    else{
      plain_text = pt;
      key_text = kt;
      length = pt.length();
    }
  }

  int getIndex(char c){
    map<char, int> dict;

    dict['A'] = 0;
    dict['B'] = 1;
    dict['C'] = 2;
    dict['D'] = 3;
    dict['E'] = 4;
    dict['F'] = 5;
    dict['G'] = 6;
    dict['H'] = 7;
    dict['I'] = 8;
    dict['J'] = 9;
    dict['K'] = 10;
    dict['L'] = 11;
    dict['M'] = 12;
    dict['N'] = 13;
    dict['O'] = 14;
    dict['P'] = 15;
    dict['Q'] = 16;
    dict['R'] = 17;
    dict['S'] = 18;
    dict['T'] = 19;
    dict['U'] = 20;
    dict['V'] = 21;
    dict['W'] = 22;
    dict['X'] = 23;
    dict['Y'] = 24;
    dict['Z'] = 25;

    return dict[c];
  }

  char getChar(int c){
    map<int, char> dict;

    dict[0] = 'A';
    dict[1] = 'B';
    dict[2] = 'C';
    dict[3] = 'D';
    dict[4] = 'E';
    dict[5] = 'F';
    dict[6] = 'G';
    dict[7] = 'H';
    dict[8] = 'I';
    dict[9] = 'J';
    dict[10] = 'K';
    dict[11] = 'L';
    dict[12] = 'M';
    dict[13] = 'N';
    dict[14] = 'O';
    dict[15] = 'P';
    dict[16] = 'Q';
    dict[17] = 'R';
    dict[18] = 'S';
    dict[19] = 'T';
    dict[20] = 'U';
    dict[21] = 'V';
    dict[22] = 'W';
    dict[23] = 'X';
    dict[24] = 'Y';
    dict[25] = 'Z';

    return dict[c];
  }

  string encrypt(){
    int ptarr[length];
    int ktarr[length];
    char resarr[length];
    string res = "";

    for (int i = 0; i < length; i++){
      ptarr[i] = getIndex(plain_text[i]);
      ktarr[i] = getIndex(key_text[i]);
    }

    for (int i = 0; i < length; i++){
      int k = ptarr[i] + ktarr[i];
      if (k > 26){
        k = k - 26;
        resarr[i] = getChar(k);
      }
      else{
        resarr[i] = getChar(k);
      }
    }

    for (int i = 0; i < length; i++){
      res += resarr[i];
    }

    return res;
  }

  string decrypt(){
    char dres[length];
    string resu{""};
    for (int i = 0; i < length; i++){
      if (getIndex(cypher_text[i]) < getIndex(key_text[i])){
        int p = 26- (getIndex(key_text[i]) - getIndex(cypher_text[i]));
        dres[i] = getChar(p);
      }
      else{
        int p = getIndex(cypher_text[i]) - getIndex(key_text[i]);
        dres[i] = getChar(p);
      }
    }

    for (int j = 0; j < length; j++){
      resu += dres[j];
    }

    return resu;
  }
};

int main(){
  string choice;
  cout << "What do you want to do ? (Encrypt/Decrypt) : ";
  cin >> choice;
  if (choice == "encrypt" || choice == "E" || choice == "e"){
    string pt;
    string key;
    cout << "Enter PlainText : ";
    cin >> pt;
    cout << "Enter KeyWord   : ";
    cin >> key;
    OPDCypher opd = OPDCypher("encrypt", pt, key);
    cout << "Encrypted Text  : " << opd.encrypt() << endl;
  }
  else{
    if (choice == "decrypt" || choice == "D" || choice == "d"){
      string ct;
      string key;
      cout << "Enter CypherText : ";
      cin >> ct;
      cout << "Enter KeyWord    : ";
      cin >> key;
      OPDCypher opd = OPDCypher("decrypt", ct, key);
      cout << "Decrypted Text   : " << opd.decrypt() << endl;
    }
  }
}
