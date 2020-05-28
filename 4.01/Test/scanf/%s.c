int infFun(){

  return 0;
}

char charFun(){

  return 'a';
}

int test(){

  int a = 6581362;
  int b[] = {1819043144,1867980911,6581362,0,0,0,0,0,0,0};
  char c = 'a';
  char d[] = {'H','e','l','l','o'};

  printf("\n");

  printf("Int variable memory address:\n");
  scanf("%s", &a);

  printf("Char variable memory address:\n");
  scanf("%s", &c);

  printf("Int array memory address:\n");
  scanf("%s", &b);

  printf("Char array memory address:\n");
  scanf("%s", &d);

  printf("Int array element memory address:\n");
  scanf("%s", &b[3]);

  printf("Char array element memory address:\n");
  scanf("%s", &d[3]);


  //printf("Int variable:\n");
  //scanf("%s", a);           // error

  //printf("Char variable:\n");
  //scanf("%s", c);             // error

  //printf("Int array element:\n");
  //scanf("%s", b[1]);          // error

  //printf("Char array element:\n");
  //scanf("%s", d[1]);         // error

  //printf("Int array pointer:\n");
  //scanf("%s", b);             // error

  //printf("Char array pointer\n");
  //scanf("%s", d);             // error

  //printf("String:\n");
  //scanf("%s", "Hello world"); // error

  //printf("Int function call:\n");
  //scanf("%s", infFun());      // error

  //printf("Char function call:\n");
  //scanf("%s", charFun());     // error

  //printf("Costant sum:\n");
  //scanf("%s", 1+1);           // error

  //printf("Costant diffrence:\n");
  //scanf("%s", 1-1);           // error

  //printf("Costant multiplication:\n");
  //scanf("%s", 1*1);           // error

  //printf("Costant division:\n");
  //scanf("%s", 1/1);           // error

  //printf("Costant modulo:\n");
  //scanf("%s", 1%1);           // error

  //printf("Costant operation inside parenthesis:\n");
  //scanf("%s", (1%1));         // error

  //printf("Int variable pre-increment:\n");
  //scanf("%s", ++a);           // error

  //printf("Int variable pre-decrement:\n");
  //scanf("%s", --a);           // error

  //printf("Int variable post-increment:\n");
  //scanf("%s", a++);           // error

  //printf("Int variable post-decrement:\n");
  //scanf("%s", a--);           // error

  return 0;
}


int main(){

  test();

  return 0;
}
