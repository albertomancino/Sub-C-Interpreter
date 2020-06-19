int global;

int print_array(int array[], int dimension){

  printf("[ %d ", array[0]);
  int i = 1;
  while (i < dimension) {
    printf("| %d ", array[i]);
    i++;
  }
  printf("]\n");

  return 0;
}

int bubble_sort_iteration(int array[], int dimension){

  int i = 0;
  int swaps = 0;

  while ( i < dimension - 1){

    int support = array[i];

    if (array[i] > array[i+1]) {
      array[i] = array[i+1];
      array[i+1] = support;
      swaps ++;
    }
    i++;
  }

  return swaps;
}

int bubble_sort(int array[], int dimension){

  int sorted = 0;

  while (sorted != 1) {

    int swaps = bubble_sort_iteration(array, dimension);
    printf("Swaps: %d\n", swaps);
    if (swaps == 0) sorted = 1;
  }

  return 0;
}

int main(){

  int dimension;

  printf("Insert array dimension\n");
  scanf("%d", &dimension);

  int i = 0;
  int array[dimension];

  if (dimension < 1) {
    printf("Invalid array dimension.\n");
    return 0;
  }

  while (i < dimension) {
    printf("Insert array elements: \n");
    scanf("%d", &array[i]);
    i++;
  }

  bubble_sort(array, dimension);

  printf("\n\n\nSorted array:\t");
  print_array(array, dimension);

  return 0;
}
