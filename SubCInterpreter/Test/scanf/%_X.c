int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 10;
  int b[10] = {1,2,3,4,5,6,7,8,9,0};
  char c = 'a';
  char d[10] = {'H','e','l','l','o'};

  printf("Costant positive integer: %X\n", 1);
  printf("Costant negative integer: %X\n", -1);
  printf("Int variable: %X\n", a);
  printf("Char variable: %X\n", c);
  printf("Int array element: %X\n", b[1]);
  printf("Char array element: %X\n", d[1]);
  printf("Int array pointer: %X\n", b);  // warning
  printf("Char array pointer: %X\n", d);    // warning
  printf("String: %X\n", "Hello world");    //warning
  printf("Int function call: %X\n", infFun());
  printf("Char function call: %X\n", charFun());
  printf("Costant sum: %X\n", 1+1);
  printf("Costant diffrence: %X\n", 1-1);
  printf("Costant multiplication: %X\n", 1*1);
  printf("Costant division: %X\n", 1/1);
  printf("Costant modulo: %X\n", 1%1);
  printf("Costant operation inside parenthesis: %X\n", (1%1));
  printf("Int variable pre-increment: %X\n",  ++a);
  printf("Int variable pre-decrement: %X\n", --a);
  printf("Int variable post-increment: %X\n", a++);
  printf("Int variable post-decrement: %X\n", a--);
  printf("Int variable memory address: %X\n", &a);          // warning
  printf("Char variable memory address: %X\n", &c);         // warning
  printf("Int array memory address: %X\n", &b);             // warning
  printf("Char array memory address: %X\n", &d);            // warning
  printf("Int array element memory address: %X\n", &b[3]);  // warning
  printf("Char array element memory address: %X\n", &d[3]); // warning


  return 0;
}


int main(){

  test();

  return 0;
}
