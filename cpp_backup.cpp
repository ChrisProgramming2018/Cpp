LIB "linalg.lib";

proc rang(matrix A)
"USAGE: rang(A); A matrix
RETURN: matrix, A 
NOTE:
Platz für wichtige Anmerkungen,
auch über mehrere Zeilen gestreckt
EXAMPLE: example permcol; shows an example"

{
  int r=0;
  matrix m = gauss_nf(A);
  for (int i=1; i<= ncols(m); i++) {
    int allZeros = 1;  // if 0 its false
    for (int j=1;j<= nrows(m);j++) {
      if (m[i,j] != 0) {
        allZeros = 0;
        break;
      }
    }
    if (allZeros == 0) {
      r++;
    }
  }
  return (r)
}
example
{
"EXAMPLE:";
ring r=0,(x),lp;
matrix A[3][3]=1,2,3,4,5,6,7,8,9;
print(A);
print(rang(A));
}

ring r=0,(x),lp;
matrix A[3][3]=1,2,3,4,5,6,7,8,9;
print(A);

print(rang(A));
print(gauss_nf(A));


proc zeilenvielfaches (matrix A, int k, poly p) {
    print("k");
    print(k);
    for (int i=1;i<=ncols(A);i++) {
        A[k,i]=p*A[k,i];
        print(A[k,i]);
    }
    return(A);
   
}

proc elementarezeilenoperation (matrix A, int k, poly p, int l) {
    for (int i=1;i<=ncols(A);i++) {
        A[l,i]=A[l,i]+p*A[k,i];
    }
    return(A);
}

print("-------------------");

// Aufgabe 

proc rZSF(matrix A)
"USAGE: rang(A); A matrix
RETURN: matrix, A 
NOTE:
Platz für wichtige Anmerkungen,
auch über mehrere Zeilen gestreckt
EXAMPLE: example permcol; shows an example"
{
  matrix m = gauss_nf(A);
  for(int r = nrows(m); r > 0; r--){
    int c =1;
    while (m[r,c]== 0 && c < ncols(m)) {
        c++;
    }
    if (m[r,c] != 0) {
        //  print(m);
        m = zeilenvielfaches(m, r, 1/m[r,c]);
        // ~;
        for(int k =1; k <= r -1 ; k++){
            // addiere -akj von der r zeile auf die k zeile
            m =  elementarezeilenoperation(m, r,-m[k,c], k);
        }
    }
  }
  return (m);
}

matrix A[4][4] = 2,0,2,2,0,1,1,5,0,0,-1,1,0,0,0,0;
print(A);
print("------rZFS-------");
print(rZSF(A));
print("-------gauss--------");
print(gauss_nf(A));







exit;
