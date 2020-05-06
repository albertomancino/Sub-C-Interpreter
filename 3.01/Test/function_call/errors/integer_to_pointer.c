int fun1(int a[10]){

  return 0;
}

int fun2(char a[10]){

  return 0;
}

int test(){

  int int_var;
  char char_var;

  fun1(int_var);   // int pointer to int conversion
  //fun1(char_var);  // char pointer to int conversion
  //fun2(int_var);   // int pointer to char conversion
  //fun2(char_var);  // char pointer to char conversion

  return 0;
}

int main(){


  return 0;
}
