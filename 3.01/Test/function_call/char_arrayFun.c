char fun(char argument[4]){

  return 0;
}

int intFun (){

  return 0;
}

char charFun (){

  return 0;
}

int main(){

  int a;
  char b;
  int c[10] = {1000,11,12,13,14,5,6,7,8,9};
  char d[11] = {'H','e','l','l','o',' ','W','o','r','l','d'};
  int e;
  char f;


  //fun(30);    // incompatible conversion
  //fun(300);   // incompatible conversion
  //fun(a);     // incompatible conversion
  //fun(b);     // incompatible conversion
  //fun(c);
  //fun(d);     // incompatible pointer
  //fun(c[5]);  // incompatible conversion
  //fun(d[5]);  // incompatible conversion
  fun("Hello world");// incompatible conversion
  //fun('a');   // incompatible conversion
  //fun(intFun());  // incompatible conversion
  //fun(charFun()); // incompatible conversion
  //fun(100+100);   // incompatible conversion
  //fun(100+10);    // incompatible conversion
  //fun((10+30-10*1/1%1));  // incompatible conversion
  //fun(1&&1);    // incompatible conversion
  //fun(e++);     // incompatible conversion
  //fun(--f);     // incompatible conversion
  //fun(++c[4]);  // incompatible conversion
  //fun(d[9]--);  // incompatible conversion
  //fun((e=10));  // incompatible conversion
  //fun((f=10));  // incompatible conversion
  //fun((c[4]=10));   // incompatible conversion
  //fun((d[9]= 10));  // incompatible conversion

  //--ST
  return 0;
}
