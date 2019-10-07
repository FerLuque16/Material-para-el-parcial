#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>
#include <ctype.h>
#include "input.h"

int main()
{
    int opc;
    int auxIdSector;
    int i,j;

    eEmployee emp[]={{1,"Juan","Lopez",'M',20000,2,7,1999,0,2},
                    {2,"Jose","Fernandez",'M',35000,1,8,1989,0,3},
                    {3,"Julia","Ramirez",'F',25000,18,11,1990,0,1},
                    {4,"Martina","Rodriguez",'F',40000,20,3,2001,0,1},
                    {5,"Emilia","Martinez",'F',32000,14,2,2000,0,2},
                    {6,"Hernan","Alvarado",'M',38000,10,3,2005,0,3,}};

    eMenu menu[]={{1,"Pollo con papas",250},
                 {2,"Hamburguesa con queso",200},
                 {3,"Hamburguesa completa",250},
                 {4,"Milanesa con pure de papas",300},
                 {5,"Milanesa con papas fritas",300},
                 {6,"Milanesa a caballo",350},
                 {7,"Salmon con pure de papas",450},
                 {8,"Pizza",400},
                 {9,"Carne con papas"},
                 {10,"Nioquis",350},
                 {11,"Ravioles",300},
                 {12,"Canelones",300},
                 {13,"Sorrentinos",325},
                 {14,"Guiso de arroz",250},
                 {15,"Guiso de fideos",250},
                 {16,"Omelette",200},
                 {17,"Pastel de papas",250},
                 {18,"Pancho",100},
                 {19,"Tortilla de papas",150},
                 {20,"Vitel tone",400}};



    eSector sec[]={{1,"Mantenimiento"},
                  {2,"Soporte tecnico"},
                  {3,"Recursos humanos"}};



    do
    {
        system("cls");
        printf("\n1) ALTAS\n2) MODIFICAR\n3) BAJAS\n4) LISTAR\n5) ALMUERZOS\n6) Salir\n");
        scanf("%d" ,&opc);

        switch(opc)
        {
            case 1:
                break;

            case 2:
                modifyEmployee(emp,6,sec,3);
                break;

            case 3:
                removeEmployee(emp,6,sec,3);
                break;

            case 4:
                printf("\nIngrese el ID de sector a listar:  ");
                scanf("%d" ,&auxIdSector);

                for(i=0;i<3;i++)
                    {
                        if(auxIdSector==sec[i].id)
                            {
                                for(j=0;j<6;j++)
                                    {
                                        if(emp[j].sector==auxIdSector && emp[j].isEmpty==0)
                                            {
                                                printf("%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\n", emp[j].id, emp[j].nombre, emp[j].apellido, emp[j].sexo, emp[j].isEmpty, emp[j].fechaIng.dia, emp[j].fechaIng.mes, emp[j].fechaIng.anio);

                                            }
                                    }
                            }
                    }
                    system("pause");
                    break;
                /*mostrarSector(emp,6,sec,4);
                system("pause");*/

                //mostrar(emp,3);
                break;

            case 5:
                break;

            case 6:
                opc=6;
                break;

            default:
                printf("\nOpcion no valida");
                break;
        }




    }while(opc!=6);
    return 0;
}
