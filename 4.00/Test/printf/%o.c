int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 10;
  int b[] = {1,2,3,4,5,6,7,8,9,0};
  char c = 'a';
  char d[] = {'H','e','l','l','o'};

  printf("\n");
  printf("Costant positive integer: %o\n", 1);
  printf("Costant negative integer: %o\n", -1);
  printf("Int variable: %o\n", a);
  printf("Char variable: %o\n", c);
  printf("Int array element: %o\n", b[1]);
  printf("Char array element: %o\n", d[1]);
  printf("Int array pointer: %o\n", b);  // warning
  printf("Char array pointer: %o\n", d);    // warning
  printf("String: %o\n", "Hello world");    //warning
  printf("Int function call: %o\n", infFun());
  printf("Char function call: %o\n", charFun());
  printf("Costant sum: %o\n", 1+1);
  printf("Costant diffrence: %o\n", 1-1);
  printf("Costant multiplication: %o\n", 1*1);
  printf("Costant division: %o\n", 1/1);
  printf("Costant modulo: %o\n", 1%1);
  printf("Costant operation inside parenthesis: %o\n", (1%1));
  printf("Int variable pre-increment: %o\n",  ++a);
  printf("Int variable pre-decrement: %o\n", --a);
  printf("Int variable post-increment: %o\n", a++);
  printf("Int variable post-decrement: %o\n", a--);
  printf("Int variable memory address: %o\n", &a);          // warning
  printf("Char variable memory address: %o\n", &c);         // warning
  printf("Int array memory address: %o\n", &b);             // warning
  printf("Char array memory address: %o\n", &d);            // warning
  printf("Int array element memory address: %o\n", &b[3]);  // warning
  printf("Char array element memory address: %o\n", &d[3]); // warning

  return 0;
}


int main(){

  test();

  return 0;
}
