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
  printf("Costant positive integer: %d\n", 1);
  printf("Costant negative integer: %d\n", -1);
  printf("Int variable: %d\n", a);
  printf("Char variable: %d\n", c);
  printf("Int array element: %d\n", b[1]);
  printf("Char array element: %d\n", d[1]);
  printf("Int array pointer: %d\n", b);  // warning
  printf("Char array pointer: %d\n", d);    // warning
  printf("String: %d\n", "Hello world");    //warning
  printf("Int function call: %d\n", infFun());
  printf("Char function call: %d\n", charFun());
  printf("Costant sum: %d\n", 1+1);
  printf("Costant diffrence: %d\n", 1-1);
  printf("Costant multiplication: %d\n", 1*1);
  printf("Costant division: %d\n", 1/1);
  printf("Costant modulo: %d\n", 1%1);
  printf("Costant operation inside parenthesis: %d\n", (1%1));
  printf("Int variable pre-increment: %d\n",  ++a);
  printf("Int variable pre-decrement: %d\n", --a);
  printf("Int variable post-increment: %d\n", a++);
  printf("Int variable post-decrement: %d\n", a--);
  printf("Int variable memory address: %d\n", &a);          // warning
  printf("Char variable memory address: %d\n", &c);         // warning
  printf("Int array memory address: %d\n", &b);             // warning
  printf("Char array memory address: %d\n", &d);            // warning
  printf("Int array element memory address: %d\n", &b[3]);  // warning
  printf("Char array element memory address: %d\n", &d[3]); // warning
  //printf("%d\n", a=1);


  return 0;
}


int main(){

  test();

  return 0;
}
