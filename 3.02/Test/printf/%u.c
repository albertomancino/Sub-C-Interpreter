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

  printf("\n");
  printf("Costant positive integer: %u\n", 1);
  printf("Costant negative integer: %u\n", -1);
  printf("Int variable: %u\n", a);
  printf("Char variable: %u\n", c);
  printf("Int array element: %u\n", b[1]);
  printf("Char array element: %u\n", d[1]);
  printf("Int array pointer: %u\n", b);  // warning
  printf("Char array pointer: %u\n", d);    // warning
  printf("String: %u\n", "Hello world");    //warning
  printf("Int function call: %u\n", infFun());
  printf("Char function call: %u\n", charFun());
  printf("Costant sum: %u\n", 1+1);
  printf("Costant diffrence: %u\n", 1-1);
  printf("Costant multiplication: %u\n", 1*1);
  printf("Costant division: %u\n", 1/1);
  printf("Costant modulo: %u\n", 1%1);
  printf("Costant operation inside parenthesis: %u\n", (1%1));
  printf("Int variable pre-increment: %u\n",  ++a);
  printf("Int variable pre-decrement: %u\n", --a);
  printf("Int variable post-increment: %u\n", a++);
  printf("Int variable post-decrement: %u\n", a--);
  printf("Int variable memory address: %u\n", &a);          // warning
  printf("Char variable memory address: %u\n", &c);         // warning
  printf("Int array memory address: %u\n", &b);             // warning
  printf("Char array memory address: %u\n", &d);            // warning
  printf("Int array element memory address: %u\n", &b[3]);  // warning
  printf("Char array element memory address: %u\n", &d[3]); // warning


  return 0;
}


int main(){

  test();

  return 0;
}
