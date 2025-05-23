#include <stdio.h> 
#include <string.h>
#include <stdbool.h>

int main() {
    char nombres[5][30];
    char asignaturas[3][30];
    float notas[5][3];
    float promedioE[5] = {0};
    float promedioM[3] = {0};
    float mayore[5], menore[5];
    float mayorm[3], menorm[3];
    int aprobados[3] = {0}, reprobados[3] = {0};
    int len;
    bool valido;

    printf("Ingrese los nombres de las 3 materias:\n");
    for (int i = 0; i < 3; i++) {
        do {
            valido = true;
            printf("Materia %d: ", i + 1);
            fflush(stdin);
            fgets(asignaturas[i], 30, stdin);

            len = strlen(asignaturas[i]);
            if (len > 0 && asignaturas[i][len - 1] == '\n') {
                asignaturas[i][len - 1] = '\0';
                len--;
            }

            if (len == 0) {
               
                valido = false;
            }

            for (int j = 0; j < len; j++) {
                if (asignaturas[i][j] >= '0' && asignaturas[i][j] <= '9') {
                    printf("La materia no puede tener números.\n");
                    valido = false;
                    break;
                }
            }
        } while (!valido);
    }

   
    for (int i = 0; i < 5; i++) {
    
        do {
            valido = true;
            printf("\nIngrese el nombre del estudiante %d: ", i + 1);
            fflush(stdin);
            fgets(nombres[i], 30, stdin);
            len = strlen(nombres[i]);
           
            if (len > 0 && nombres[i][len - 1] == '\n') {
                nombres[i][len - 1] = '\0';
                len--;
            }

            if (len == 0) {
                valido = false;
            }

            for (int j = 0; j < len; j++) {
                if (nombres[i][j] >= '0' && nombres[i][j] <= '9') {
                    printf("El nombre no puede tener números.\n");
                    valido = false;
                    break;
                }
            }
        } while (!valido);

       
        for (int j = 0; j < 3; j++) {
            int resultado;
            do {
                printf("Nota de %s en %s (0-10): ", nombres[i], asignaturas[j]);
                resultado = scanf("%f", &notas[i][j]);
                fflush(stdin);

                if (resultado != 1) {
                    printf(" La nota debe ser un número válido.\n");
                    notas[i][j] = -1;
                } else if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("La nota debe estar entre 0 y 10.\n");
                }
            } while (resultado != 1 || notas[i][j] < 0 || notas[i][j] > 10);

            promedioE[i] += notas[i][j];
            promedioM[j] += notas[i][j];

            if (notas[i][j] > mayore[i]) mayore[i] = notas[i][j];
            if (notas[i][j] < menore[i]) menore[i] = notas[i][j];

            if (i == 0) {
                mayorm[j] = menorm[j] = notas[i][j];
            } else {
                if (notas[i][j] > mayorm[j]) mayorm[j] = notas[i][j];
                if (notas[i][j] < menorm[j]) menorm[j] = notas[i][j];
            }

            if (notas[i][j] >= 6) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }

        promedioE[i] /= 3;
    }

    for (int j = 0; j < 3; j++) {
        promedioM[j] /= 5;
    }

   
    printf("\n-- RESULTADOS --\n");

    for (int i = 0; i < 5; i++) {
        printf("\nEstudiante: %s\n", nombres[i]);
        printf("Promedio: %.2f\n", promedioE[i]);
        printf("Nota más alta: %.2f\n", mayore[i]);
        printf("Nota más baja: %.2f\n", menore[i]);
    }

    for (int j = 0; j < 3; j++) {
        printf("\nMateria: %s\n", asignaturas[j]);
        printf("Promedio: %.2f\n", promedioM[j]);
        printf("Nota más alta: %.2f\n", mayorm[j]);
        printf("Nota más baja: %.2f\n", menorm[j]);
        printf("Aprobados: %d\n", aprobados[j]);
        printf("Reprobados: %d\n", reprobados[j]);
    }

    return 0;
}