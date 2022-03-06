#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

int novesForaStr(string b, int t){
  int n = 0;
  stringstream base;
  for(int i=0; i<t; i++){
    n += int(b[i])-48;
  }
  if(to_string(n).length()>1){
    n = novesForaStr(to_string(n), to_string(n).length());
  }
  return n;
}

int novesForaInt(int b){
  if(b%9==0){
    return 9;
  }else{
    return b%9;
  }
}

int calculaResposta(int valor, string b, int t){
  int n=1;
  for(int i=0; i<t;i++){
    n = novesForaInt(pow(n,10));
    n = novesForaInt(n*pow(valor, int(b[i])-48));
  }
  return n;
}

int main() {
    string b, e;
    cin >> b >> e;
    int base = novesForaStr(b, b.length());
    cout<<calculaResposta(base, e, e.length())<<endl;    
    return 0;
}
