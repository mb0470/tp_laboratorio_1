/***********************************************************************************************************************************

* Programa: Trabajo Practico Nro. 1 - Calculadora.
*
* Objetivo:
    Se solicita el ingreso de dos numeros "a" y "b".
    Estos serviran como operandos para calcular cinco operaciones matematicas con ellos.
    Luego, se pide el calculo de esas operaciones.
    Despues puede pedirse la impresion de los resultados.
    Las funciones que permiten las operaciones matematicas se encuentran en una biblioteca aparte.
*
* Autor: Boris Maximiliano Burgos.
*
***********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../Operaciones/operaciones.h"

int main()
{
    float a;/*Variables de los operandos. Permite el ingreso de numeros racionales. Los decimales se redondean a dos numeros.*/
    float b;
    float suma;/*Variables de las operaciones que pueden realizarse.*/
    float resta;
    float producto;
    float cociente;
    int factA;
    int factB;
    int aInt;/*Para evitar complicaciones al resolver los factoriales de numeros decimales, se convierten los operandos a enteros.*/
    int bInt;
    int flagA;/*Variables que permiten realizar las opciones en un orden adecuado.*/
    int flagB;
    char opciones;/*Variables que permiten seleccionar las opciones a realizar.*/
    opciones = '0';
    flagA = 0;/*Permiten realizar las primeras dos opciones.*/
    flagB = 0;
    printf("***TP1: Calculadora.***\n\n");
    printf("Menu de opciones:\n\n");
    printf("1 - Ingresar 1er operando.\n");
    printf("2 - Ingresar 2do operando.\n");
    printf("3 - Calcular operaciones (suma, resta, multiplicacion, division, factorial).\n");
    printf("4 - Informar resultados.\n");
    printf("5 - Salir.\n\n");
    do {
        scanf("%c", &opciones);
        switch (opciones)
        {
            case '1':
                if (flagA == 0)
                {
                    printf("Introduzca el primer operando.\n");
                    scanf("%f", &a);
                    flagA = 1;/*Impide repetir esta opcion.*/
                }
                else
                {
                    printf("Ya realizo este paso.\n");
                }
                break;
            case '2':/*La 2da opcion puede realizarse antes de la 1ra. Esto no es incompatible con el funcionamiento del programa.*/
                if (flagB == 0)
                {
                    printf("Introduzca el segundo operando.\n");
                    scanf("%f", &b);
                    flagB = 1;/*Impide repetir esta opcion.*/
                }
                else
                {
                    printf("Ya realizo este paso.\n");
                }
                break;
            case '3':
                if (flagA == 1 && flagB == 1)/*Permite realizar esta opcion cuando los dos operandos esten cargados.*/
                {
                    suma = sumar (a, b);
                    resta = restar (a, b);
                    producto = multiplicar (a, b);
                    cociente = (float) dividir (a, b);
                    if (a >= 0)/*Impide buscar el factorial de numeros negativos.*/
                    {
                        factA = factorial (a);
                    }
                    if (b >= 0)/*Impide buscar el factorial de numeros negativos.*/
                    {
                        factB = factorial (b);
                    }
                    flagA = 2;
                    flagB = 2;
                }
                else if (flagA == 2 && flagB == 2)/*Impide repetir esta opcion.*/
                {
                    printf("Ya realizo este paso.\n");
                }
                else
                {
                    printf("Haga todos los pasos anteriores antes de utilizar esta funcion.\n");
                }
                break;
            case '4':
                if (flagA == 2 && flagB == 2)/*Permite realizar esta opcion cuando se hayan realizado las anteriores.*/
                {
                    printf("El resultado de %.2f + %.2f es: %.2f.\n", a, b, suma);
                    printf("El resultado de %.2f - %.2f es: %.2f.\n", a, b, resta);
                    printf("El resultado de %.2f * %.2f es: %.2f.\n", a, b, producto);
                    if (b != 0)/*Impide la division por cero.*/
                    {
                        printf("El resultado de %.2f / %.2f es: %.2f.\n", a, b, cociente);
                    }
                    else
                    {
                        printf("No es posible dividir por cero.\n");
                    }
                    if (a >= 0)
                    {
                        aInt = (int) a;/*Ver comentario de linea 28.*/
                        printf("El factorial de %d es: %d.\n", aInt, factA);
                    }
                    else
                    {
                        printf("No es posible calcular el factorial del 1er numero.\n");
                    }
                    if (b >= 0)
                    {
                        bInt = (int) b;/*Ver comentario de linea 28.*/
                        printf("El factorial de %d es: %d.\n", bInt, factB);
                    }
                    else
                    {
                        printf("No es posible calcular el factorial del 2do numero.\n");
                    }
                }
                else
                {
                    printf("Haga todos los pasos anteriores antes de utilizar esta funcion.\n");
                }
                break;
            case '5':
                break;
        }
    } while (opciones != '5');
    system(("pause"));
    return 0;
}
