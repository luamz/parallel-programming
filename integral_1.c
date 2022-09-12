#include <stdio.h>
#include <mpi.h>

float f(float x)
{
    // esta é a função a integrar
    // exemplo: função quadrática

    float fx; // valor de retorno

    fx = x * x;

    return fx;
}

float calcula(float local_a, float local_b, int local_n, float h)
{
    float integral;
    float x, i;
    float f(float x); // função a integrar
    integral = (f(local_a) + f(local_b)) / 2.0;

    x = local_a;
    for (i = 1; i <= local_n; i++)
    {
        x += h;
        integral += f(x);
    }

    integral *= h;
    return integral;
}

int main(int argc, char **argv)
{

    int my_rank;
    float a = 0.0, b = 1.0; // intervalo a calcular
    
    int p;                  // número de processos
    int n = 1024;           // número de trapezóides
    
    float h;                // base do trapezóide
    float local_a, local_b; // intervalo local
    int local_n;            // número de trapezóides local
    float integral;         // integral no meu intervalo
    float total;            // integral total
    int source;             // remetente da integral
    int dest = 0;           // destino das integrais (nó 0)
    int tag = 200;          // tipo de mensagem (único)
    MPI_Status status;

    float calcula(float local_a, float local_b, int local_n, float h);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    h = (b - a) / n;
    local_n = n / p;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    
    if (my_rank == p-1) {
        local_n = (n / p) + n%p;
        local_b = b;
    }

    integral = calcula(local_a, local_b, local_n, h);
    
    MPI_Reduce(&integral, &total, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0){
        printf("Resultado: %f\n", total);
    }
    MPI_Finalize();
}
