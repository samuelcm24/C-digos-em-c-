#include <stdio.h>
#include <stdlib.h>

void countingsort (int *v, int n, int R) 
{
   int r;
   int *fp, *aux;
   fp = malloc ((R+2) * sizeof (int));
   aux = malloc (n * sizeof (int));

   for (r = 0; r <= R+1; ++r) 
      fp[r] = 0;
   for (int i = 0; i < n; ++i) {
      r = v[i];
      fp[r+1] += 1; 
   }
   // agora fp[r+1] é a frequência de r
   for (r = 1; r <= R+1; ++r) 
      fp[r] += fp[r-1]; 
   // agora fp[r] é a freq dos predecessores
   // de r; logo, a carreira de elementos
   // iguais a r deve começar no índice fp[r]
   for (int i = n - 1; i >= 0; --i) {
      r = v[i];
      aux[fp[r]] = v[i];
      fp[r]++;
   }
   // aux[0..n-1] está em ordem crescente
   for (int i = 0; i < n; ++i) 
      v[i] = aux[i];

   free (fp);
   free (aux);
}


void printv(int *v, int n){
    for (int i = 0; i < n; i++)
        printf ("%d ", v[i]);
    printf ("\n");
}

int main(){
    int v[] = {5,3,0,2,4,1,3,2,4,0};
    int n = sizeof(v)/sizeof(v[0]);
    int R = 5; // range dos valores em v é 0..R
    
    countingsort (v, n, R);

    printv(v, n);

    return 0;
    
}