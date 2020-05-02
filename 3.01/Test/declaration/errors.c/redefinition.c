int a;

int fun(){

  int a;  // this is not a redefinition

  return 0;
}
 int main(){

   int a;  // this is not a redefinition

   int b;
   {
     char b;  // this is not a redefinition
   }

   int c;

   char c;  // this is a redefinition


   return 0;
 }
