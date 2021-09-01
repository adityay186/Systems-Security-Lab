//Encryption using Monoalphabetic Cipher Substitution Technique
//Author : Aditya Kamlesh Yadav
//PRN    : 20190802060
//email  : 20190802060@dypiu.ac.in

//Subject : Systems Security LAB 01

#include <iostream> //input-output library

using namespace std;  //setting namespace to avoid name pollution

int getIndex(char c, char *ptr){  //function to get index of a particular character in the string
  int ind {0};
  if (*ptr == c){
    return ind; //if the character which we are searching comes out to be the first one in the string, then return 0 as the index
  }
  else{
    while (*ptr != c){  //else increment pointer ptr until we find the character
      ind++;  //increment index variable
      ptr++;  //increment pointer variable
    }
  }

  return ind; //finally return index of the character in the query
}

string encrypt(string inp){ //function to encrypt the string which we get through console input
  string main_text = "abcdefghijklmnopqrstuvwxyz "; //string used to find the index of relative characters in the input string
  string cypher_text =  "DKVQFIBJWPESCXHTMYAUOLRGZN ";  //string used to map the cypherise each character in the input string

  char *ptr = &(main_text[0]);  //pointer to be used in getIndex() function

  string res = "";  //initially empty string

  for (int i = 0; i < inp.length(); i++){ //iterating through whole string
    res += cypher_text[getIndex(tolower(inp[i]), ptr)]; //adding cypherised character to the string
  }

  return res; //return cypherised string
}

string decrypt(string inp){
  string main_text = "DKVQFIBJWPESCXHTMYAUOLRGZN "; //string used to find the index of relative characters in the input string
  string cypher_text =  "abcdefghijklmnopqrstuvwxyz ";  //string used to decypher each character in the cypherised string

  char *ptr = &(main_text[0]);  //pointer to be used in getIndex() function

  string res = "";  //initially empty string

  for (int i = 0; i < inp.length(); i++){ //iterating through whole string
    res += cypher_text[getIndex(toupper(inp[i]), ptr)]; //adding decypherised character to the string
  }

  return res; //return decypherised string
}

int main(){ //driver code
  string inp; //input text variable
  cout << "Enter Text     : ";
  getline(cin, inp);  //taking input from console-input to the input variable
  cout << endl;
  string encrypted_text = encrypt(inp);
  cout << "Encrypted Text : " << encrypted_text << endl;  //console-out the result(cypherised) text
  cout << endl;
  cout << "Decrypted Text : " << decrypt(encrypted_text) << endl;
}
