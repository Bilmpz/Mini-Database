#include <stdio.h>

int main() {
    printf("\n");
    printf("SUPER SIMPEL CSV LAESER\n");
    printf("======================\n");
    
    FILE *file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("FEJL: Kan ikke finde people.csv\n");
        return 1;
    }
    
    printf("Filen er aabnet!\n\n");
    
    char linje[1000];
    int person_nummer = 1;

    while (fgets(linje, 1000, file)) {
        
        int id, alder;
        char navn[100], fil_info[200], dato_info[200];
        
        if (sscanf(linje, "%d,%99[^,],%d,%199[^,],%199[^\n]", &id, navn, &alder, fil_info, dato_info) == 5) {
            printf("Bruger Nr.  %d\n", id);
            printf("Navn: %s\n", navn);
            printf("Alder: %d aar\n", alder);
            printf("Fil: %s\n", fil_info);
            printf("Dato: %s\n", dato_info);
        }

        printf("\n");
        person_nummer++;
    }
    
    fclose(file);
    printf("======================\n");
    printf("DONE!\n");
    
    return 0;
}
