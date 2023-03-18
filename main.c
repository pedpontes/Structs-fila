#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int age;
    struct User *px;
} User;

void printList(User *p_user1)
{
    int i = 0;
    printf("%d", p_user1->age);
    for (i; p_user1->px != NULL; i++)
    {
        printf("\nNome = %s, Idade = %d", p_user1->name, p_user1->age);
        p_user1 = p_user1->px;
    }
    printf("\nTamanho da lista: %d", i);
}

User *addUser(User *p_user1)
{
    User *aux;
    while (p_user1->px != NULL)
        p_user1 = p_user1->px;
    int opc = 1;
    do
    {
        printf("\n\tNome: ");
        scanf(" %[^\n]", &p_user1->name);
        printf("\n\tIdade: ");
        scanf("%d", &p_user1->age);
        printf("\nValores a serem inseridos: Nome = %s, Idade = %d", p_user1->name, p_user1->age);
        printf("\nDigite 0 para confirmar, ou 1 para alterar o registro: ");
        scanf("%d", &opc);
        system("clear");
    } while (opc != 0);
    printf("\nValores atualizados: Nome = %s, Idade = %d", p_user1->name, p_user1->age);

    p_user1->px = (User *)malloc(sizeof(User));
    aux = p_user1->px;
    aux->px = NULL;
    return aux;
}

int main()
{
    int op = 1;
    User *p_user1, *aux;
    p_user1 = (User *)malloc(sizeof(User));
    do
    {
        system("clear");

        aux = p_user1;
        printf("\nEscolha uma opcao:");
        printf("\n\t1. Adciona elemento.");
        printf("\n\t2. Remove elemento.");
        printf("\n\t3. Imprime todos os elementos.");

        printf("\n\t0. Sair!");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nAdicionando valores...");
            addUser(aux);
            getchar();
            break;
        case 2:
            aux = p_user1->px;
            free(p_user1);
            p_user1 = aux;
            break;
        case 3:
            printf("Esses são os elementos da lista:");
            printList(p_user1);
            break;
        case 0:
            printf("\nBye!!!");
            break;
        default:
            printf("\nOpçao invalida!");
            break;
        }
    } while (op != 0);

    return 0;
}
