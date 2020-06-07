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
  
  printf("Int variable memory address:\n");
  scanf("%o", &a);

  printf("Char variable memory address:\n");
  scanf("%o", &c);

  printf("Int array memory address:\n");
  scanf("%o", &b);

  printf("Char array memory address:\n");
  scanf("%o", &d);

  printf("Int array element memory address:\n");
  scanf("%o", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%o", &d[3]);

  //printf("Int variable:\n");
  //scanf("%o", a);           // error

  //printf("Char variable:\n");
  //scanf("%o", c);             // error

  //printf("Int array element:\n");
  //scanf("%o", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%o", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%o", b);             // error

  //printf("Char array pointer\n");
  //scanf("%o", d);             // error

  //printf("String:\n");
  //scanf("%o", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%o", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%o", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%o", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%o", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%o", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%o", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%o", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%o", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%o", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%o", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%o", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%o", a--);           // error

  return 0;
}


int main(){

  test();

  return 0;
}
