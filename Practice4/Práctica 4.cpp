//Encuentra el �nico elememto de un arreglo
#include <stdio.h> 
  
int getSingle(int arr[], int n) 
{ 
    int ones = 0, twos = 0; 
  
    int common_bit_mask; 
  
    //Se usur� el ejemplo de {3,3,2,3} para explicar el programa.
    for (int i = 0; i < n; i++) { 
        /*La expresi�n "one & arr[i]" da los bits que se encuentra
    	en ambas variables, es decir, en "ones" y "arr[i]".
    	
    	Se suman estos bits a "twos" usando el operador OR.
    	
       	El valor de "twos" ser� establecido como 00, 11, 11 y 01 
		en las iteraciones correspondientes.*/
		 
        twos = twos | (ones & arr[i]); 
        
  		/*Se aplica XOR a los nuevos bits con los "ones" anteriores
  		para obtener los bits que aparecen un n�mero impar de veces.
  		
  		El valor de "ones" ser� 11, 00, 10 y 11 despu�s de las
  		iteraciones correspondientes*/
        ones = ones ^ arr[i]; 
        printf("Iteracion: %d \n", i);
        printf ("ones: %d twos: %d iniciales \n", ones, twos); 
        
  		/* Los bits comunes son aquellos que aparecen una tercera vez.
  		Por lo que estos bits no deber�n estar en ambas variables "ones" y "twos".
		La variable "common_bit_mask" contiene todos los bits como 0, de modo
		que los bits puedan ser removidos de "ones" y "twos".
		
		El valor de "common_bit_mask" ser� 11, 11, 01 y 10 despu�s de 
		las iteraciones correspondientes*/
        
        common_bit_mask = ~(ones & twos); 
  		/* Se remueven los bits en com�n (aquellos bits que aparecen por tercera
  		vez) en "ones".
  		
  		El valor de "ones" ser� 11, 00, 00 y 10 despu�s de las iteraciones
  		correspondientes. */
        
        ones &= common_bit_mask; 
  		/* Se remueven los bits en com�n (los bits que aparecen por tercera
  		vez en "twos". 
  		
  		El valor de "twos" ser� 00, 11, 01 y 00 despu�s de las iteraciones
  		correspondientes. */
        
        twos &= common_bit_mask; 
  
        printf ("ones: %d twos: %d finales \n", ones, twos); 
    } 
  
    return ones; 
} 
  
int main() 
{ 
    int arr[] = { 3, 3, 2, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("El elemento con multiplicidad unitaria es: %d ", 
           getSingle(arr, n)); 
    return 0; 
} 
