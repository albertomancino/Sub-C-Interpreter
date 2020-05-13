int fun(){

    return 1;
}

int main(){


  int a = 10;
  int b[10] = {1,2,3,4,5,6,7,8,9,0};
  char c = 'a';
  char d[10] = {'H','e','l','l','o'};

  printf("\n");

  printf("Int variable memory address: %d\n", &a);
  printf("Char variable memory address: %d\n", &b);
  printf("Int array memory address: %d\n", &c);
  printf("Char array memory address: %d\n", &d);
  printf("Int array element memory address: %d\n", &b[0]);
  printf("Char array element memory address: %d\n", &d[5]);
  return 0;
}
