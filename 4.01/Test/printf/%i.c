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
  printf("Costant positive integer: %i\n", 1);
  printf("Costant negative integer: %i\n", -1);
  printf("Int variable: %i\n", a);
  printf("Char variable: %i\n", c);
  printf("Int array element: %i\n", b[1]);
  printf("Char array element: %i\n", d[1]);
  printf("Int array pointer: %i\n", b);  // warning
  printf("Char array pointer: %i\n", d);    // warning
  printf("String: %i\n", "Hello world");    //warning
  printf("Int function call: %i\n", infFun());
  printf("Char function call: %i\n", charFun());
  printf("Costant sum: %i\n", 1+1);
  printf("Costant diffrence: %i\n", 1-1);
  printf("Costant multiplication: %i\n", 1*1);
  printf("Costant division: %i\n", 1/1);
  printf("Costant modulo: %i\n", 1%1);
  printf("Costant operation inside parenthesis: %i\n", (1%1));
  printf("Int variable pre-increment: %i\n",  ++a);
  printf("Int variable pre-decrement: %i\n", --a);
  printf("Int variable post-increment: %i\n", a++);
  printf("Int variable post-decrement: %i\n", a--);
  printf("Int variable memory address: %i\n", &a);          // warning
  printf("Char variable memory address: %i\n", &c);         // warning
  printf("Int array memory address: %i\n", &b);             // warning
  printf("Char array memory address: %i\n", &d);            // warning
  printf("Int array element memory address: %i\n", &b[3]);  // warning
  printf("Char array element memory address: %i\n", &d[3]); // warning

  return 0;
}


int main(){

  test();

  return 0;
}
