#include <stdio.h>
#include <stdbool.h>



/*	
	Herramientas de sintaxis I, declaracion de variables III Registros.
	Muchas veces los datos que queremos guardar tienen una relacion logica pero no de tipo
	por ejemplo una persona tiene:
		nombre,edad,peso,dni y altura 
	siendo:
		char[],int,float,dni y float
	
	si queremos guardar a varias personas nos surgira un problema, y es que tendremos que optar por usar n vectores de distinto tipo
	para guardar las personas por ejemplo si quiero guardar 10 personas:
		char nombres[10][25];
		int edades[10];
		float pesos[10];
		int dnis[10];
		float alturas[10];

	Esta solucion se torna engorroza y puede tornar en confuciones y algunas problematicas, para solucionar este tipo de situaciones
	se crearon los Registros que son "Objetos" que pueden almacenar distintos tipos de datos y guardarlos a traves de un nombre comun.
	se pueden crear con o sin alias, se prodecera a explicar como se hace con alias por ser esta la forma más facil y legible para el codigo.
	Para crear un Registro:
		struct Nombre_registro
		{
			tipo_dato nombre_dato;
			tipo_dato2 nombre_dato2;
			tipo_dato3 nombre_dato3;
			tipo_dato4 nombre_dato4;
		};

		struct Nombre_registro variable_registro;
	Con las personas seria:
		struct persona
		{
			char nombre[25];
			int edad;
			int dni;
			float peso;
			float altura;
		};
		struct persona personas[10];//Creo 10 personas.

		//accedo a traves del nombre_registro.campo_del_registro
		personas[0].dni=100000;
		personas[0].nombre="Guillermo";
		personas[0].altura=180.2;


		aclaracion, tambien se puede usar la palabra reservada typedef para asignarle un alias al registro
		tal que:
		typedef	struct Nombre_registro
		{
			tipo_dato nombre_dato;
			tipo_dato2 nombre_dato2;
			tipo_dato3 nombre_dato3;
			tipo_dato4 nombre_dato4;
		}nombre_alias_registro;

		nombre_alias_registro variable_registro;
*/



typedef struct cuenta
{
	char nombre[50];
	float monto;	
}Cuenta;




int main(void)
{
	 Cuenta cuenta1=
	 {
	 .nombre="Martin",
	 .monto=1000.20
	};

	 printf("%s tiene $%.2f dinero en la cuenta\n",cuenta1.nombre , cuenta1.monto);


	return 0;
}
