int fun1(int a){

  return 0;
}

int fun2(char a){

  return 0;
}

int test(){

  int int_array[10];
  char char_array[10];

  fun1(int_array);   // int pointer to int conversion
  //fun1(char_array);  // char pointer to int conversion
  //fun2(int_array);   // int pointer to char conversion
  //fun2(char_array);  // char pointer to char conversion

  return 0;
}

int main(){


  return 0;
}
