int main(){

  int x;
  char y;
  int vec1[2];
  char vec2[2];

  // AND - OR costant operator
  x = 12 && 13;
  x = 12 || 13;
  x = 12 && (1+3);
  x = 12 || (1+3);

  // AND - OR costant operator
  x = 'a' && 'b';
  x = 'a' || 'b';
  x = 'a' * 'b' && 'b'%'\?';
  x = 'a' * 'b' || 'b'%'\?';

  // AND - OR array identifier
  x = vec1 && vec2;
  x = vec1 || vec2;

  // AND - OR string
  x = "hello" && "world";
  x = "hello" || "world";

  // > - < always true against char
  x = 128 > y;
  x = 128 > vec2[1];
  x = (118 + 10) > y;
  x = y < 128;
  x = vec2[1] < 128;
  x = -129 < y;
  x = -129 < vec2[1];
  x = (-119 - 10) < y;
  x = y > -129;
  x = vec2[1] > -129;

  // > - < always false against char
  x = 128 < y;
  x = 128 < vec2[1];
  x = (118 + 10) < y;
  x = y > 128;
  x = vec2[1] > 128;
  x = -129 > y;
  x = -129 > vec2[1];
  x = (-119 -10) > y;
  x = y < -129;
  x = vec2[1] < -129;

  // > - < always true against boolean
  x = 0 && 1 > -1;
  x = 0 && 1 < 2;
  x = -1 < 0 && 1;
  x = 2 > 0 && 1;
  x = 0 && 1 < 's';
  x = 's' > 0 && 1;

  // > - < always true against boolean
  x = 0 && 1 > 2;
  x = 0 && 1 < -1;
  x = -1 > 0 && 1;
  x = 2 < 0 && 1;
  x = 0 && 1 > 's';
  x = 's' < 0 && 1;

  // self-comparison always true
  x = x == x;

  // self-comparison always false
  x = x > x;
  x = x < x;
  x = x != x;

  // == - != always true against char
  x = 128 != y;
  x = 128 != vec2[1];
  x = (118 + 10) != y;
  x = y != 128;
  x = vec2[1] != 128;
  x = -129 != y;
  x = -129 != vec2[1];
  x = (-119 - 10) != y;
  x = y != -129;
  x = vec2[1] != -129;

  // == - != always false against char
  x = 128 == y;
  x = 128 == vec2[1];
  x = (118 + 10) == y;
  x = y == 128;
  x = vec2[1] == 128;
  x = -129 == y;
  x = -129 == vec2[1];
  x = (-119 - 10) == y;
  x = y == -129;
  x = vec2[1] == -129;

  // == - != always true against boolean
  x = 2 != x && x;
  x = 's' != x && x;
  x = (10*10) != x && x;

  // == - != always false against boolean
  x = 2 == x && x;
  x = 's' == x && x;
  x = (10*10) == x && x;


  return 0;
}
