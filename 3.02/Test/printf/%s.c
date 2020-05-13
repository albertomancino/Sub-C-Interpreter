int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 6581362;
  int b[] = {1819043144,1867980911,6581362,0,0,0,0,0,0,0};
  char c = 'a';
  char d[] = {'H','e','l','l','o'};


  //printf("Costant positive integer: %s\n", 1);  // error
  //printf("Costant negative integer: %s\n", -1); // error
  //printf("Int variable: %s\n", a);              // error
  //printf("Char variable: %s\n", c);             // error
  //printf("Int array element: %s\n", b[1]);      // error
  //printf("Char array element: %s\n", d[1]);     // error
  printf("Int array pointer: %s\n", b);
  printf("Char array pointer: %s\n", d);
  printf("String: %s\n", "Hello world");
  //printf("Int function call: %s\n", infFun());  // error
  //printf("Char function call: %s\n", charFun());// error
  //printf("Costant sum: %s\n", 1+1);             // error
  //printf("Costant diffrence: %s\n", 1-1);       // error
  //printf("Costant multiplication: %s\n", 1*1);  // error
  //printf("Costant division: %s\n", 1/1);        // error
  //printf("Costant modulo: %s\n", 1%1);          // error
  //printf("Costant operation inside parenthesis: %s\n", (1%1));  // error
  //printf("Int variable pre-increment: %s\n",  ++a);             // error
  //printf("Int variable pre-decrement: %s\n", --a);              // error
  //printf("Int variable post-increment: %s\n", a++);             // error
  //printf("Int variable post-decrement: %s\n", a--);             // error
  printf("Int variable memory address: %s\n", &a);              // warning
  printf("Char variable memory address: %s\n", &c);             // warning
  printf("Int array memory address: %s\n", &b);                 // warning
  printf("Char array memory address: %s\n", &d);                // warning
  printf("Int array element memory address: %s\n", &b[3]);      // warning
  printf("Char array element memory address: %s\n", &d[3]);     // warning

  return 0;
}


int main(){

  test();

  return 0;
}
