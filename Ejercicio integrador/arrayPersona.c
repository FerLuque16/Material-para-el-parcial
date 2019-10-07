#include <stdio.h>
#include <stdlib.h>
#include "arrayPersona.h"
#include <string.h>
#include <ctype.h>

void alta(eEmpleado emp[],int cantidad)
{   int i;

     for(i=0;i<cantidad;i++)
     {
         if(emp[i].isEmpty==1)
         {
            printf("Ingrese nombre: \n");
            setbuf(stdin,NULL);
            scanf("%s",emp[i].nombre);

            printf("Ingrese apellido: \n");
            setbuf(stdin,NULL);
            scanf("%s",emp[i].apellido);

            printf("Ingrese dia de ingreso: \n");
            setbuf(stdin,NULL);
            scanf("%d" ,&emp[i].fechaIng.dia);

            printf("Mes de ingreso: \n");
            setbuf(stdin,NULL);
            scanf("%d" ,&emp[i].fechaIng.mes);

            printf("Anio de ingreso: \n");
            setbuf(stdin,NULL);
            scanf("%d" ,&emp[i].fechaIng.anio);

            emp[i].isEmpty=0;
            //emp[i].legajo=generarId();
            break;
        }

     }

}

void mostrarUno(eEmpleado emp)
{
    printf("%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\n", emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.isEmpty, emp.fechaIng.dia, emp.fechaIng.mes, emp.fechaIng.anio);
}
/*void mostrarUno(eEmpleado emp)
{
    printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", emp.nombre, emp.apellido, emp.edad, emp.isEmpty, emp.fechaIng.dia, emp.fechaIng.mes, emp.fechaIng.anio);
}*/

void mostrarTodos(eEmpleado emp[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(emp[i].isEmpty==0)
        {
            mostrarUno(emp[i]);
        }


    }
}

/*void mostrar(eEmpleado emp[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(emp[i].isEmpty==0)
        {
        printf("%d\t-\t%s\t-\t%s\t-\t%c\t-\t%d\t-\t%d\t-\t%d\t-\t%d\t-\t%d\n" ,emp[i].legajo ,emp[i].nombre ,emp[i].apellido ,emp[i].sexo ,emp[i].isEmpty ,emp[i].fechaIng.dia ,emp[i].fechaIng.mes ,emp[i].fechaIng.anio);
        }
        printf("Nombre: %s\n" ,emp[i].nombre);

        printf("Apellido: %s\n" ,emp[i].apellido);

        printf("Edad: %d\n" ,emp[i].edad);
    }
}*/

void ordenar(eEmpleado emps[],int CANT)
{
    int i,j;
    eEmpleado auxemp;

     for(i=0;i< CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(strcmp(emps[i].nombre,emps[j].nombre)>0)
                {
                    auxemp=emps[i];
                    emps[i]=emps[j];
                    emps[j]=auxemp;
                }

            if(strcmp(emps[i].nombre,emps[j].nombre)==0)
                {
                    if(strcmp(emps[i].apellido,emps[j].apellido)>0)
                        {
                            auxemp=emps[i];
                            emps[i]=emps[j];
                            emps[j]=auxemp;
                        }
                }

            /*if(strcmp(emps[i].apellido,emps[j].apellido)==0)
            {
                 if(emps[i].edad>emps[j].edad)
                    {
                        auxemp=emps[i];
                        emps[i]=emps[j];
                        emps[j]=auxemp;
                    }
            }*/

        }
    }

}

void init(eEmpleado emps[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        emps[i].isEmpty=1;
    }
}

void baja(eEmpleado emps[],int cantidad)
{
    char rta;
    int auxId,i;

    printf("\nIngrese ID : ");
    scanf("%d" ,&auxId);

    for(i=0;i<cantidad;i++)
    {
            if(auxId==emps[i].legajo)
            {
               mostrarUno(emps[i]);
               system("pause");
               do
               {
                   system("cls");
                   printf("\n¿Desea dar de baja? Ingrese s o n");
                   setbuf(stdin,NULL);
                   scanf("%c" ,&rta);
                   rta=tolower(rta);

               }while(rta!='s' && rta !='n');

               if(rta=='s')
                {
                    emps[i].isEmpty=1;
                    break;
                }
               else
                {
                    printf("No se dio de baja");
                }
            }
    }
}

void modificar(eEmpleado emps[],int cantidad)
{
    char rta;
    int auxId,i;
    int opcMod;

    printf("\nIngrese legajo : ");
    scanf("%d" ,&auxId);

    for(i=0;i<cantidad;i++)
    {
            if(auxId==emps[i].legajo)
            {
               mostrarUno(emps[i]);
               system("pause");
               do
               {   system("cls");
                   printf("\n¿Desea modificar? Ingrese s o n");
                   scanf("%c" ,&rta);
                   rta=tolower(rta);

               }while(rta!='s' && rta!='n');

               if(rta=='s')
                {
                    do
                    {
                        system("cls");
                        printf("\n1. Modificar apellido y nombre");
                        printf("\n2. Modificar sexo");
                        printf("\n3. Modificar fecha de ingreso");
                        printf("\n4. Salir");

                        scanf("%d" ,&opcMod);

                        switch(opcMod)
                        {
                            case 1:
                                printf("Ingrese nombre: \n");
                                setbuf(stdin,NULL);
                                scanf("%s",emps[i].nombre);


                                printf("Ingrese apellido: \n");
                                setbuf(stdin,NULL);
                                scanf("%s",emps[i].apellido);
                                break;

                            case 2:
                                printf("Ingrese Sexo (M o F): \n");
                                setbuf(stdin,NULL);
                                scanf("%c",&emps[i].sexo);
                                break;

                            case 3:
                                printf("Ingrese dia de ingreso: \n");
                                setbuf(stdin,NULL);
                                scanf("%d" ,&emps[i].fechaIng.dia);

                                printf("Mes de ingreso: \n");
                                setbuf(stdin,NULL);
                                scanf("%d" ,&emps[i].fechaIng.mes);

                                printf("Año de ingreso: \n");
                                setbuf(stdin,NULL);
                                scanf("%d" ,&emps[i].fechaIng.anio);
                                break;

                            case 4:

                                opcMod=4;
                                break;

                            default:
                                printf("Opcion no valida\n");

                        }
                    }while(opcMod!=4);
                }
               else
                {
                    printf("No se modifico");
                    system("pause");
                }
            }
    }
}

/*static int generarId(void)
    {
        static int nuevoId =0;

        nuevoId++;

        return nuevoId;
    }
    */

void mostrarSector(eEmpleado emp[],int cantidadEmp,eSector sec[],int cantidadSec)
{
    int auxIdSector;
    int i,j;

    printf("\nIngrese el ID de sector a listar:  ");
    scanf("%d" ,&auxIdSector);
        for(i=0;i<cantidadSec;i++)
        {
            if(auxIdSector==sec[i].id)
            {   break;
                for(j=0;j<cantidadEmp;j++)
                {
                    if(emp[j].idSector==auxIdSector && emp[j].isEmpty==0)
                    {
                        printf("%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\n", emp[j].legajo, emp[j].nombre, emp[j].apellido, emp[j].sexo, emp[j].isEmpty, emp[j].fechaIng.dia, emp[j].fechaIng.mes, emp[j].fechaIng.anio ,emp[j].idSector);
                    }
                }
            }
        }
}

