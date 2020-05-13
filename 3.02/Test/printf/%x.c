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

  printf("Costant positive integer: %x\n", 1);
  printf("Costant negative integer: %x\n", -1);
  printf("Int variable: %x\n", a);
  printf("Char variable: %x\n", c);
  printf("Int array element: %x\n", b[1]);
  printf("Char array element: %x\n", d[1]);
  printf("Int array pointer: %x\n", b);  // warning
  printf("Char array pointer: %x\n", d);    // warning
  printf("String: %x\n", "Hello world");    //warning
  printf("Int function call: %x\n", infFun());
  printf("Char function call: %x\n", charFun());
  printf("Costant sum: %x\n", 1+1);
  printf("Costant diffrence: %x\n", 1-1);
  printf("Costant multiplication: %x\n", 1*1);
  printf("Costant division: %x\n", 1/1);
  printf("Costant modulo: %x\n", 1%1);
  printf("Costant operation inside parenthesis: %x\n", (1%1));
  printf("Int variable pre-increment: %x\n",  ++a);
  printf("Int variable pre-decrement: %x\n", --a);
  printf("Int variable post-increment: %x\n", a++);
  printf("Int variable post-decrement: %x\n", a--);
  printf("Int variable memory address: %x\n", &a);          // warning
  printf("Char variable memory address: %x\n", &c);         // warning
  printf("Int array memory address: %x\n", &b);             // warning
  printf("Char array memory address: %x\n", &d);            // warning
  printf("Int array element memory address: %x\n", &b[3]);  // warning
  printf("Char array element memory address: %x\n", &d[3]); // warning




  return 0;
}


int main(){

  test();

  return 0;
}
