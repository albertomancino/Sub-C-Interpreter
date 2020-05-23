int test(){

  int x;
  x = 0;

  while(0) {
    return 10;
  }
  printf("DOPO WHILE\n");

  return 100;

  if(0){
    printf("IF\n");
    return 12;
  }
  else{
    printf("ELSE\n");
    return 23;
  }

  printf("DOPO IF\n");
}

int main(){

  int x = test();
  printf("Valore ritornato:\n %d\n", x);

  int index = 10;
  while (index --){
    x = 10;
  }

  if (1){
    printf("MAIN IF\n");
    return 10;
  }

}
