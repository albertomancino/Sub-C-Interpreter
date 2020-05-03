int fun1(char a, char s[], char vi[3], char v[2], char gian[]){

  printf("%d\n", a);
  printf("%s\n", s);
  printf("%s\n", v);

  for (int i = 0; i < 100; i++){

    printf(" %c -", vi[i]);
  }



  printf("%d %d %d %d\n", vi[0], vi[1], vi[2], vi[3]);


  return 0;
}

int main(){

  int x = 0;
  char vec[4] = {'a','b','c'};

  fun1(x = 100, "ciao", "hello", "bye", "sergio abascia");

  printf("------------------------------------------------------------------------\n");

  char nome_super_segreto[] = "Michele Corstese";

  char a[4] = "abcd";

  for (int i = 0; i < 100; i++){

    printf("%c", a[i]);
  }

  printf("\n");
  char nome_segreto[] = "Gianluca Azzolini";

  return 0;
}
