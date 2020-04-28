int main(){
int value;
printf("char x;\n");

for(int i = 0; i < 256; i++){

  int value0 = i%8;
  int value1 = (i/8)%8;
  int value2 = (i/64)%8;
  value = value0 + value1*10 + value2*100;
  printf("x = ");
  printf("\'\\%d\';\n", value);
}


}
