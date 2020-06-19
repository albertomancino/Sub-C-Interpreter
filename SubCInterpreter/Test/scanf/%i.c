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
  scanf("%i", &a);

  printf("Char variable memory address:\n");
  scanf("%i", &c);

  printf("Int array memory address:\n");
  scanf("%i", &b);

  printf("Char array memory address:\n");
  scanf("%i", &d);

  printf("Int array element memory address:\n");
  scanf("%i", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%i", &d[3]);

  //printf("Int variable:\n");
  //scanf("%i", a);           // error

  //printf("Char variable:\n");
  //scanf("%i", c);             // error

  //printf("Int array element:\n");
  //scanf("%i", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%i", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%i", b);             // error

  //printf("Char array pointer\n");
  //scanf("%i", d);             // error

  //printf("String:\n");
  //scanf("%i", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%i", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%i", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%i", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%i", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%i", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%i", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%i", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%i", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%i", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%i", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%i", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%i", a--);           // error

  return 0;
}


int main(){

  test();

  return 0;
}
