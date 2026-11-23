/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
   int m = matSize;
   int n = matColSize[0];
    
    // if reshape dimension are invalid,keep original dimensions
    if (m*n!=r*c){
        r=m;
        c=n;
   }
  *returnSize = r;
  *returnColumnSizes = (int*)malloc(r*sizeof(int));
  int** result = (int**)malloc(r*sizeof(int*));

  for (int i =0;i<r;i++){
    (*returnColumnSizes)[i] = c;
    result[i] = (int*)malloc(c * sizeof(int));

  }

  for (int i = 0;i<m*n;i++) {
    result[i / c][i % c] = mat[i/n][i%n];

  }
   return result;
}