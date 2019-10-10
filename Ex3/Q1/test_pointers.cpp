// test_pointers.cpp
// COMPLETE include necessary headers
#include<iostream>

int main(void)
{
  //
  // 1. declare a variable d as a pointer to a double
  double* d;
  // 2. create a double variable named pi, and store the value 3.14159
  double pi = 3.14159;
  // 3. make d points to pi
  d = &pi;
  // 4. print out the content of the memory location pointed to by d
  std::cout << *d  << std::endl;
  //
  int a[5] = {1, 2, 3, 4, 5};
  // 5. declare a variable ip as a pointer to an int
  int *ip;
  // 6. make ip points to the beginning of the array a
  ip = a;
  // 7. print out what ip points to and the content of a[0] (verify they are the same)
  std::cout << "Ip points to: " << *ip << " Expected value a[0]: " << a[0] << std::endl;
  // 8. increase ip by 3 and check that what it points to corresponds to a[3]
  ip += 3;
  std::cout << "Ip points to: " << *ip << " Expected value a[3]: " << a[3] << std::endl;
  // 9. make ip points to the last element of the array by increasing it by 1
  ip ++;
  // and check that what it points to corresponds to a[4]
  std::cout << "Ip points to: " << *ip << " Expected value a[4]: " << a[4] << std::endl;

  // 
  int n = 10;
  // 10. declare a variable "f" as a pointer to float and
  float *f; 
  // make it point to an array of "n" element of type "float" created on the heap
  f = new float[n];
  // 11. store in each f[i] (for i=0 to n-1) the value float(i) / 5.0f;
  int i;
  for(i = 0; i < n; i ++) 
    f[i] = float(i) / 5.0f;
  // 12. print out each element of f
  for(i = 0; i < n; i ++)
    std::cout << f[i] << std::endl;
  // 13. delete the previously allocated memory
  delete[] f;

  //
  int m = 5;
  double** dd;
  // 14. allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n).  // Make dd points to this 2d array.
  dd = new double*[m];
  for(i = 0; i < m; i ++) {
    dd[i] = new double[n];
  }
  // 15. set the element dd[i][j] to be equal to i*j/2
  int j;
  for(i = 0; i < m; i ++) {
    for(j = 0; j < n; j ++) {
      dd[i][j] = i * j / 2;
    }
  }
  // 16. delete the memory allocated for the 2d array
  for(i = 0; i < m; i ++) 
    delete[] dd[i];
  delete[] dd; 

  return 0;
}