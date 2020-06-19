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

int merge (int input1[], int input2[], int dim1, int dim2, int output[], int dim_out){

   int index = -1;
   int out_index = 0;
   while (++index < dim1) {
     output[out_index++] = input1[index];
   }
   index = -1;
   while (++index < dim2) {
     output[out_index++] = input2[index];
   }

   return 1;
}

int quickSort(int array[], int dimension, int result[]){

  int pivot;
  if (dimension > 1){

    pivot = array[0];

    int index = 0;
    int bigger;
    int smaller;


    while (++index < dimension){

      if (array[index] > pivot) bigger ++;
      else smaller ++;
    }

    int bigger_array[bigger];
    int smaller_array[smaller];
    int index_1 = 0;
    int index_2 = 0;
    index = 0;

    while (++index < dimension){

      if (array[index] > pivot) bigger_array[index_1++] = array[index];
      else smaller_array[index_2++] = array[index];
    }

    index_1 = -1;
    index_2 = -1;

    int sorted1[bigger];
    int sorted2[smaller];

    quickSort(bigger_array, bigger, sorted1);
    quickSort(smaller_array, smaller, sorted2);

    int head[smaller+1];
    index = -1;
    while (++index < smaller) {
      head[index] = sorted2[index];
    }
    head[smaller] = pivot;

    merge(head, sorted1, smaller+1, bigger, result, dimension);

  }
  else{
    int index = -1;
    while (++index < dimension) {
      result[index] = array[index];
    }
  }
  return 1;
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

  int solution[dimension];
  quickSort(array, dimension, solution);

  int x[] = {1,2,3};
  int y[] = {3,4,5};
  int z[6];

  printf("\n\n\nSorted array:\t");
  print_array(solution, dimension);

  return 0;
}
