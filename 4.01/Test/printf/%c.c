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
  printf("Costant positive integer: %c\n", 1);
  printf("Costant negative integer: %c\n", -1);
  printf("Int variable: %c\n", a);
  printf("Char variable: %c\n", c);
  printf("Int array element: %c\n", b[1]);
  printf("Char array element: %c\n", d[1]);
  printf("Int array pointer: %c\n", b);     // warning
  printf("Char array pointer: %c\n", d);    // warning
  printf("String: %c\n", "Hello world");    //warning
  printf("Int function call: %c\n", infFun());
  printf("Char function call: %c\n", charFun());
  printf("Costant sum: %c\n", 1+1);
  printf("Costant diffrence: %c\n", 1-1);
  printf("Costant multiplication: %c\n", 1*1);
  printf("Costant division: %c\n", 1/1);
  printf("Costant modulo: %c\n", 1%1);
  printf("Costant operation inside parenthesis: %c\n", (1%1));
  printf("Int variable pre-increment: %c\n",  ++a);
  printf("Int variable pre-decrement: %c\n", --a);
  printf("Int variable post-increment: %c\n", a++);
  printf("Int variable post-decrement: %c\n", a--);
  printf("Int variable memory address: %c\n", &a);          // warning
  printf("Char variable memory address: %c\n", &c);         // warning
  printf("Int array memory address: %c\n", &b);             // warning
  printf("Char array memory address: %c\n", &d);            // warning
  printf("Int array element memory address: %c\n", &b[3]);  // warning
  printf("Char array element memory address: %c\n", &d[3]); // warning

  return 0;
}


int main(){

  test();

  return 0;
}
