int decimal_division (int value, int divider){

  int div = value % divider;
  return div*10 / divider;
}

int range (int hv, int vv){

  int range = ((2*hv*vv)/10);
  int decimal = decimal_division(2*hv*vv,10);

  printf("RANGE: %d.%d meters\n", range, decimal);

  return 0;
}

int max_altitude (int vv){

  int altitude = ((vv*vv)/(10*2));
  int decimal = decimal_division(vv*vv,10*2);

  printf("MAX ALTITUDE: %d.%d meters\n", altitude, decimal);

  return 0;
}

int main(){

  printf("This program computes the range and the max altitude of a classic ballistic problem.\n\n");

  int h_vel = -1;
  while (h_vel < 0) {
    printf("Insert horizontal velocity (m/s)\n");
    printf("-> ");
    scanf("%d", &h_vel);
    if (h_vel < 0) printf("Velocity must be positive\n");
  }

  int v_vel = -1;
  while (v_vel < 0) {
    printf("Insert vertical velocity (m/s)\n");
    printf("-> ");
    scanf("%d", &v_vel);
    if (v_vel < 0) printf("Velocity must be positive\n");
  }

  range(h_vel, v_vel);
  max_altitude(v_vel);

  return 0;
}
