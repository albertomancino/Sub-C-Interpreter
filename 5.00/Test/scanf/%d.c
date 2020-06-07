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
  scanf("%d", &a);

  printf("Char variable memory address:\n");
  scanf("%d", &c);

  printf("Int array memory address:\n");
  scanf("%d", &b);

  printf("Char array memory address:\n");
  scanf("%d", &d);

  printf("Int array element memory address:\n");
  scanf("%d", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%d", &d[3]);

  //printf("Int variable:\n");
  //scanf("%d", a);           // error

  //printf("Char variable:\n");
  //scanf("%d", c);             // error

  //printf("Int array element:\n");
  //scanf("%d", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%d", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%d", b);             // error

  //printf("Char array pointer\n");
  //scanf("%d", d);             // error

  //printf("String:\n");
  //scanf("%d", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%d", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%d", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%d", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%d", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%d", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%d", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%d", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%d", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%d", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%d", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%d", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%d", a--);           // error

  return 0;
}


int main(){

  test();         // error

  return 0;
}
