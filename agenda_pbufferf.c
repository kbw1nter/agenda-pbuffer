#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Aloca buffer inicial: 3 ints para controle + 100 bytes para dados temporários
    void* pBuffer = malloc(sizeof(int) * 3 + 50 + 50);
    
    if (!pBuffer) {
        printf("Error: Could not allocate memory for the contact list!\n");
        return 1;
    }
    
    // Inicializa contador de pessoas
    *((int*)pBuffer) = 0;
    
    do {
        printf("\n+==========================================+\n");
        printf("|             CONTACT LIST                 |\n");
        printf("+==========================================+\n");
        printf("|  1 - Add New Person                     |\n");
        printf("|  2 - Remove Existing Person             |\n");
        printf("|  3 - Search for Specific Person         |\n");
        printf("|  4 - View All People                    |\n");
        printf("|  5 - Exit Program                       |\n");
        printf("+==========================================+\n");
        printf("Your choice: ");
        
        scanf("%d", ((int*)pBuffer + 1));
        getchar();
        
        switch(*((int*)pBuffer + 1)) {
            
            case 1: // Adicionar nova pessoa
                printf("\n=== ADDING NEW PERSON ===\n");
                
                // Lê dados de entrada para áreas temporárias do buffer
                printf("Enter full name: ");
                fgets((char*)pBuffer + sizeof(int) * 3, 50, stdin);
                ((char*)pBuffer + sizeof(int) * 3)[strcspn((char*)pBuffer + sizeof(int) * 3, "\n")] = '\0';
                
                printf("Enter age: ");
                scanf("%d", ((int*)pBuffer + 2));
                getchar();
                
                printf("Enter email: ");
                fgets((char*)pBuffer + sizeof(int) * 3 + 50, 50, stdin);
                ((char*)pBuffer + sizeof(int) * 3 + 50)[strcspn((char*)pBuffer + sizeof(int) * 3 + 50, "\n")] = '\0';
                
                // Realoca buffer para acomodar nova pessoa (104 bytes por pessoa)
                pBuffer = realloc(pBuffer, sizeof(int) * 3 + 50 + 50 + ((*((int*)pBuffer) + 1) * (50 + sizeof(int) + 50)));
                
                if (!pBuffer) {
                    printf("Error: Insufficient memory to add person!\n");
                    return 1;
                }
                
                // Calcula localização na memória para nova pessoa
                char* newPerson = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer) * (50 + sizeof(int) + 50));
                
                // Copia dados do buffer temporário para armazenamento permanente
                strcpy(newPerson, (char*)pBuffer + sizeof(int) * 3);
                *((int*)(newPerson + 50)) = *((int*)pBuffer + 2);
                strcpy(newPerson + 50 + sizeof(int), (char*)pBuffer + sizeof(int) * 3 + 50);
                
                (*((int*)pBuffer))++;
                printf("Success! Person added. Total: %d person(s)\n", *((int*)pBuffer));
                break;
                
            case 2: // Remover pessoa
                if (*((int*)pBuffer) == 0) {
                    printf("Your contact list is empty! Nothing to remove.\n");
                    break;
                }
                
                printf("\n=== REMOVING PERSON ===\n");
                printf("Enter the name of the person to be removed: ");
                fgets((char*)pBuffer + sizeof(int) * 3, 50, stdin);
                ((char*)pBuffer + sizeof(int) * 3)[strcspn((char*)pBuffer + sizeof(int) * 3, "\n")] = '\0';
                
                // Procura pela pessoa para remover
                *((int*)pBuffer + 2) = -1; // Flag de não encontrado
                
                for (*((int*)pBuffer + 1) = 0; *((int*)pBuffer + 1) < *((int*)pBuffer); (*((int*)pBuffer + 1))++) {
                    char* currentPerson = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer + 1) * (50 + sizeof(int) + 50));
                    
                    if (strcmp(currentPerson, (char*)pBuffer + sizeof(int) * 3) == 0) {
                        *((int*)pBuffer + 2) = *((int*)pBuffer + 1); // Armazena índice encontrado
                        break;
                    }
                }
                
                if (*((int*)pBuffer + 2) == -1) {
                    printf("Person not found in contact list!\n");
                    break;
                }
                
                // Move pessoas restantes para preencher o espaço vazio
                for (*((int*)pBuffer + 1) = *((int*)pBuffer + 2); *((int*)pBuffer + 1) < *((int*)pBuffer) - 1; (*((int*)pBuffer + 1))++) {
                    char* destination = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer + 1) * (50 + sizeof(int) + 50));
                    char* source = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + ((*((int*)pBuffer + 1) + 1) * (50 + sizeof(int) + 50));
                    memcpy(destination, source, 50 + sizeof(int) + 50);
                }
                
                (*((int*)pBuffer))--;
                
                // Reduz buffer se ainda restam pessoas
                if (*((int*)pBuffer) > 0) {
                    pBuffer = realloc(pBuffer, sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer) * (50 + sizeof(int) + 50)));
                }
                
                printf("Success! Person removed. Current total: %d person(s)\n", *((int*)pBuffer));
                break;
                
            case 3: // Buscar pessoa
                if (*((int*)pBuffer) == 0) {
                    printf("Contact list is empty! Add some people first.\n");
                    break;
                }
                
                printf("\n=== SEARCHING FOR PERSON ===\n");
                printf("Enter the name of the person you're looking for: ");
                fgets((char*)pBuffer + sizeof(int) * 3, 50, stdin);
                ((char*)pBuffer + sizeof(int) * 3)[strcspn((char*)pBuffer + sizeof(int) * 3, "\n")] = '\0';
                
                *((int*)pBuffer + 2) = 0; // Flag de encontrado
                
                // Busca linear através do array de pessoas
                for (*((int*)pBuffer + 1) = 0; *((int*)pBuffer + 1) < *((int*)pBuffer); (*((int*)pBuffer + 1))++) {
                    char* currentPerson = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer + 1) * (50 + sizeof(int) + 50));
                    
                    if (strcmp(currentPerson, (char*)pBuffer + sizeof(int) * 3) == 0) {
                        printf("\n=== PERSON FOUND! ===\n");
                        printf("Name: %s\n", currentPerson);
                        printf("Age: %d years\n", *((int*)(currentPerson + 50)));
                        printf("Email: %s\n", currentPerson + 50 + sizeof(int));
                        *((int*)pBuffer + 2) = 1;
                        break;
                    }
                }
                
                if (!*((int*)pBuffer + 2)) {
                    printf("Person not found in contact list!\n");
                }
                break;
                
            case 4: // Listar todas as pessoas
                if (*((int*)pBuffer) == 0) {
                    printf("Your contact list is empty!\n");
                    printf("Tip: Use option 1 to add people.\n");
                    break;
                }
                
                printf("\n=== COMPLETE CONTACT LIST ===\n");
                printf("Total registered people: %d\n\n", *((int*)pBuffer));
                
                // Itera através de todas as pessoas armazenadas
                for (*((int*)pBuffer + 2) = 0; *((int*)pBuffer + 2) < *((int*)pBuffer); (*((int*)pBuffer + 2))++) {
                    char* currentPerson = (char*)pBuffer + sizeof(int) * 3 + 50 + 50 + (*((int*)pBuffer + 2) * (50 + sizeof(int) + 50));
                    
                    printf("+-------------------------------------------+\n");
                    printf("| Person #%d                               |\n", *((int*)pBuffer + 2) + 1);
                    printf("+-------------------------------------------+\n");
                    printf("| Name:  %-30s |\n", currentPerson);
                    printf("| Age:   %-30d |\n", *((int*)(currentPerson + 50)));
                    printf("| Email: %-30s |\n", currentPerson + 50 + sizeof(int));
                    printf("+-------------------------------------------+\n\n");
                }
                break;
                
            case 5: // Sair do programa
                printf("\n=== CLOSING PROGRAM ===\n");
                printf("Thank you for using the Personal Contact List!\n");
                printf("Registered people: %d\n", *((int*)pBuffer));
                printf("See you next time!\n");
                break;
                
            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
                printf("Tip: Type only the number of the desired option.\n");
        }
        
        // Espera entrada do usuário antes de continuar
        if(*((int*)pBuffer + 1) != 5 && *((int*)pBuffer + 1) >= 1 && *((int*)pBuffer + 1) <= 4) {
            printf("\nPress Enter to continue...");
            getchar();
        }
        
    } while(*((int*)pBuffer + 1) != 5);
    
    // Limpa a memória alocada
    printf("\nFreeing memory... ");
    free(pBuffer);
    printf("Done!\n");
    
    return 0;
}
