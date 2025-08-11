/*write an openmp program that divides the iterations into chunks containing 2 iterations,respectively(OMP_SCHEDULE),
its input should be no.of iterations and its output should be which iterations of a parallelized for loop are executed by which
thread.for example, if there are 2 threads and 4 iterations, the output should be:
Thread 0: iterations 0 1
Thread 1: iterations 2 3
*/

#include<stdio.h>
#include<omp.h>

int main(){
    int n,i;
    int chunks;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Enter the number of chunks per thread: ");
    scanf("%d", &chunks);
    omp_set_num_threads(4);

    #pragma omp parallel for schedule(dynamic, chunks)
    for(i=0; i<n; i++){
        printf("Thread %d: iterations %d\n", omp_get_thread_num(), i);
    }

}