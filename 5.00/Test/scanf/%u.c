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

  printf("Int variable memory address:\n");
  scanf("%u", &a);

  printf("Char variable memory address:\n");
  scanf("%u", &c);

  printf("Int array memory address:\n");
  scanf("%u", &b);

  printf("Char array memory address:\n");
  scanf("%u", &d);

  printf("Int array element memory address:\n");
  scanf("%u", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%u", &d[3]);

  //printf("Int variable:\n");
  //scanf("%u", a);           // error

  //printf("Char variable:\n");
  //scanf("%u", c);             // error

  //printf("Int array element:\n");
  //scanf("%u", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%u", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%u", b);             // error

  //printf("Char array pointer\n");
  //scanf("%u", d);             // error

  //printf("String:\n");
  //scanf("%u", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%u", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%u", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%u", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%u", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%u", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%u", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%u", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%u", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%u", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%u", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%u", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%u", a--);           // error


  return 0;
}


int main(){

  test();

  return 0;
}
