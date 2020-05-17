int a;

int fun1(){

  int b;
  return 0;
}

int fun2(){

  return 0;
}

int main(){

  //b = 4; // b is declared inside another function

  {
    int c;
  }

  c = 5;  // c is declared in a scope that has been removed from the stack

  return 0;
}
