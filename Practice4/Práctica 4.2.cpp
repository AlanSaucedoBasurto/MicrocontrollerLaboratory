//Calcule el cuadrado de un n�mero sin utilizar ning�n operador num�rico.
//Dado un entero N, calcule el cuadrado de un numero sin utilizar *, / o librer�as de potencias.
#include <stdio.h>

int main() {
	int temp, num;
	int cuadrado = 0;
	int cuenta = 0;
    printf("Ingresa el numero del que deseas saber su cuadrado: \n");
    scanf("%d", &num);   
	temp = num;                                                                //Se asigna a temp el valor ingresa a num
	while(temp > 0)                                                            //Se ejecuta mientras temp sea mayor a 0
	{
	    if(temp & 1)                                                           //Este ciclo se ejecuta mientras el valor de temp sea diferente de 0
	    {                                                                      //En la primera iteraci�n la cuenta vale 0 por lo que el corrimiento de "cuenta" bits no modifica el valor de "num" y solo se suma a "cuadrado" 
	        cuadrado += num << cuenta;
	        printf("El valor actual de cuadrado es: %d \n", cuadrado);
	    }
	    temp = temp >> 1;                                                    //Se le aplica un corrimiento de 1 bit a la derecha a temp de modo que se divide entre 2 y se actualiza su valor
	    printf("El valor actual de temp es: %d \n", temp);                   
	    cuenta++;                                                            //El valor de cuenta se incrementa en 1, esto nos servir� en la siguiente iteraci�n para a�adir a el doble de veces el valor de "num" a "cuadrado" 
	    printf("El valor actual de cuenta es: %d \n", cuenta);               // y esto se repetir� hasta que temp se vuelva 0
	}                                                                        // de modo que se habr�n sumado "num" veces "num" a "cuadrado" y de esta forma se obtiene el cuadrado del n�mero ingresado
	printf("El cuadrado de %d es: %d\n", num, cuadrado );
}
