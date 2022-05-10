#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*
Todos

1.
*/

void GenerateNumbers(int count, char* path)
{
    int* numbers = (int*)calloc(count, sizeof(int));
    int max = 99999;
    int min = 1;
    time_t t;

    printf("Zufallszahlen werden generiert\n");

    // Open file
    FILE* tempFile = fopen(path, "wb");

    if (tempFile == NULL) {
        // Create new file if not exist
        printf("Neue Datei wurde angelegt\n");
    }

    /* Intializes random number generator */
    srand((unsigned)time(&t));

    for (int i = 0; i < count; i++)
    {
        int temp = rand() % max + min;

        printf("[%d] %d\n",i, temp);

        if (numbers[i] == temp)
        {
            i--;
        }
        else
        {
            fprintf(tempFile, "%d", numbers[i]);
        }
    }

    fclose(tempFile);

    printf("Daten wurden erfolgreich in Datei <%s> geschrieben\n", path);
}

int main(int argc, char* argv[])
{
    // argc         Anzahl der Argummente
    // argv[0] =    Name der Anwendung
    // argv[1...n]  n Argumente

    // argv[1] --> Anzahl der zu generierenden Zahlen
    // argv[2] --> DateiName

    const* defaultPath = "DefaultNumbers.txt";
    int defaultNummbers = 10;

    const* path = malloc(255 * sizeof(char));
    int numbers;

    if (argc >= 3) // Anzahl und Dateiname wurde übergeben
    {
        numbers = argv[1];
        path = argv[2];
    }
    else if (argc == 2) // Nur Anzahl für Zahlen wurde angegeben --> verwende temp-pfad
    {
        path = defaultPath;
        numbers = argv[1];
    }
    else
    {
        path = defaultPath;
        numbers = defaultNummbers;
    }

    // &path --> Adresse wird übergeben
    GenerateNumbers(numbers, &path);

    exit(EXIT_SUCCESS);
}