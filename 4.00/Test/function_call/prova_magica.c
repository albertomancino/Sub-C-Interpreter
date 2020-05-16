int main(){


  int var = 10;

  int condition = 10;

  if (condition == 2){
    var = 1;
  }
  else {
    if (condition == 4){
      var = 2;
    }
    else {
      if (condition == 10){
        var = 3;
      }
    }
  }

  --ST

  condition = 3;

  if(1) condition = 1;

  return 1;
  --ST
}
--SD
--PT
