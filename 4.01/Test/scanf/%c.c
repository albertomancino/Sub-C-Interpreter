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
  scanf("%c", &a);

  printf("Char variable memory address:\n");
  scanf("%c", &c);

  printf("Int array memory address:\n");
  scanf("%c", &b);

  printf("Char array memory address:\n");
  scanf("%c", &d);

  printf("Int array element memory address:\n");
  scanf("%c", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%c", &d[3]);

  //printf("Int variable:\n");
  //scanf("%c", a);           // error

  //printf("Char variable:\n");
  //scanf("%c", c);             // error

  //printf("Int array element:\n");
  //scanf("%c", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%c", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%c", b);             // error

  //printf("Char array pointer\n");
  //scanf("%c", d);             // error

  //printf("String:\n");
  //scanf("%c", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%c", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%c", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%c", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%c", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%c", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%c", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%c", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%c", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%c", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%c", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%c", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%c", a--);           // error

  return 0;
}


int main(){

  test();

  return 0;
}
