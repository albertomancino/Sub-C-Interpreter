int fun(int a){

  return 0;
}

int intFun (){

  return 0;
}

char charFun (){

  return 0;
}

int main(){

  int a;
  char b;
  int c[10];
  char d[10];
  int e;
  char f;

  fun(30);
  fun(300);
  fun(a);
  fun(b);
  //fun(c); // errore perchè non posso passare un puntatore
  //fun(d); // errore perchè non posso passare un puntatore
  fun(c[5]);
  fun(d[5]);
  //fun("ciao");
  fun('a');
  fun(intFun());
  fun(charFun());
  fun(100+100);
  fun(100+10);
  fun((10+30-10*1/1%1));
  fun(1&&1);
  fun(e++);
  fun(--f);
  fun(++c[4]);
  fun(d[9]--);
  fun((e=10));
  fun((f=10));
  fun((c[4]=10));
  fun((d[9]= 10));


  return 0;
}
