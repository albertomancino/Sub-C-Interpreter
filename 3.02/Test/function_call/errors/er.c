/*int fun1(int a, int b, char c, char d, int e[], char f[], int g[10], char h[10]){

  return 0;
}


int fun2(){


    //fun1(1,2,3,400,5,6,7,8);

    int a,b,c,d,e,f,g,h;

    --ST
    a = b = c = d = e = f = g = 10;

    fun1(a,b,c,d,e,f,g,1);

  return 0;
}
*/

int intFun(int a){


  return a;
}

int charFun(char a){


  return a;
}

int intVFun(int a[10]){

  //for (int i = 0; i < 10; i++) printf("array element [%d]:%d\n", i, a[i]);
  return a;
}

int charVFun(char a[10]){


  return a;
}

int test(){

  int a;
  char b;
  int c[a];
  char d[5];

  intFun(a);
  intFun(b);
  intFun(c);  // warning int array -> int -- incompatible pointer to integer conversion passing 'int [10]' to parameter of type 'int'
  intFun(d);  // warning char array -> int -- incompatible pointer to integer conversion passing 'char [10]' to parameter of type 'int'

  charFun(a);
  charFun(b);
  charFun(c); // warning int array -> char -- incompatible pointer to integer conversion passing 'int [10]' to parameter of type 'char'
  charFun(d); // warning char array -> char -- incompatible pointer to integer conversion passing 'char [10]' to parameter of type 'char'

  intVFun(a); // warning int -> int array --  incompatible integer to pointer conversion passing 'int' to parameter of type 'int *'
  intVFun(b); // warning char -> int array --  incompatible integer to pointer conversion passing 'char' to parameter of type 'int *'
  intVFun(c);
  intVFun(d); // warning char array -> int array -- incompatible pointer types passing 'char [10]' to parameter of type 'int *'

  charVFun(a); // warning int -> char array --  incompatible integer to pointer conversion passing 'int' to parameter of type 'int *
  charVFun(b); // warning char -> char array --  incompatible integer to pointer conversion passing 'char' to parameter of type 'int *
  charVFun(c); // warning int array -> char array -- incompatible pointer types passing 'char [10]' to parameter of type 'int *'
  charVFun(d);

  return 0;

}



int main(){

  int array[13] = {1,2,3,4,5,6,7,8,9,10,11,12};
  intVFun(array);

  return 0;
}
