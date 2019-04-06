#include <stdio.h>
#include <stdlib.h>

float sumar(float a, float b)
{
    float suma;
    suma = a + b;
    return suma;
}

float restar(float a, float b)
{
    float resta;
    resta = a - b;
    return resta;
}

float multiplicar(float a, float b)
{
    float producto;
    producto = a * b;
    return producto;
}

float dividir(float a, float b)
{
    float cociente;
    cociente = a / b;
    return cociente;
}

int factorial(int n)
{
    int rta;
    if (n == 1 || n == 0)
    {
        return 1;
    }
    rta = n* factorial(n-1);
    return (rta);
}
