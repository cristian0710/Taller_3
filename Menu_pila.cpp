#include <stdlib.h>
#include <stdio.h>

struct nodo
{
    int numero;
    nodo *siguiente;
};

nodo *pila=NULL;

void menu();
void estado(nodo *&);
void insertar(nodo *&);
void quitar(nodo *&);

int main()
{
    menu();
}

void menu()
{
    int opc;
    printf("        ****  MENU  ****\n");
    printf("1. Verificar estado de la pila\n");
    printf("2. Insertar elementos a la pila\n");
    printf("3. Quitar elementos de la pila\n");
    printf("0. Salir\n");
    printf("Digite opcion: ");
    scanf("%d",&opc);

    switch(opc)
    {
    case 1:
        {
            estado(pila);
        }break;
    case 2:
        {
            insertar(pila);
        }break;
    case 3:
        {
            quitar(pila);
        }break;
    case 0:
        {
            printf("salir");
        }break;
    default:
        {
            printf("Opcion incorrecta\n");
            system("pause");
            system("cls");
            menu();
        }
    }
}

void estado(nodo *&pila)
{
    if(pila==NULL)
    {
        printf("La pila esta vacia\n");
    }
    else
    {
        printf("La pila esta llena\n");
    }
    system("pause");
    system("cls");
    menu();
}

void insertar(nodo *&pila)
{
    int n, c=1, x;

    do
    {
        printf("\nIngrese elemento %d a la pila: ",c);
        scanf("%d",&n);
        nodo *nuevo_nodo=(nodo*)malloc(sizeof(nodo));
        nuevo_nodo->numero=n;
        nuevo_nodo->siguiente=pila;
        pila=nuevo_nodo;
        c++;
        printf("Desea ingresar mas elementos a la pila  1.SI o  2.NO: ");
        scanf("%d",&x);
    }while(x==1);
    system("pause");
    system("cls");
    menu();
}

void quitar(nodo *&pila)
{
    int z;
    while(pila!=NULL)
    {
        nodo *aux=pila;
        z=aux->numero;
        pila=aux->siguiente;
        free(aux);
        if(pila!=NULL)
        {
            printf("%d -> ",z);
        }
        else
        {
            printf("%d -> FIN\n",z);
        }
    }

    system("pause");
    system("cls");
    menu();
}


