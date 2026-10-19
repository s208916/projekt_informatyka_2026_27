#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Pomiar {
    char czas[30];
    float temperatura;
    float wilgotnosc;
    float cisnienie;
};

struct Stacja {
    int id;
    char nazwa[40];
    char lokalizacja[60];
};

struct Rekord {
    struct Stacja stacja;
    struct Pomiar pomiar;
};

int main() {
    struct Stacja s1[2] = {{1, "Wrzeszcz", "Dmowskiego 1"},{2, "Brzezno", "Portowa 2"}};
    struct Rekord dane[50];
    time_t czas;
    srand(time(NULL));


    for(int i=0;i<10;i++){
        dane[i].pomiar.temperatura = rand()%70-35;
        dane[i].pomiar.wilgotnosc = 40+rand()%50;
        dane[i].pomiar.cisnienie = 1000 + rand()%30;
        time(&czas);
        strcpy(dane[i].pomiar.czas , ctime(&czas));
        int n = strlen(dane[i].pomiar.czas);
        dane[i].pomiar.czas[n-1] = 0;
        dane[i].stacja = s1[i%2];
    }


    for(int i=0;i<10;i++){
        printf("%d\t %s t:%f h:%f p:%f ", i, dane[i].pomiar.czas, dane[i].pomiar.temperatura,
               dane[i].pomiar.wilgotnosc, dane[i].pomiar.cisnienie);
        printf("%d %s %s\n", dane[i].stacja.id, dane[i].stacja.nazwa, dane[i].stacja.lokalizacja);
    }

    float tmin = dane[0].pomiar.temperatura;
    float tmax = dane[0].pomiar.temperatura;
    float sumaH = 0 , sumaP = 0;

    for(int i=0;i<10;i++) {
        if(dane[i].pomiar.temperatura < tmin)
            tmin = dane[i].pomiar.temperatura;
        if(dane[i].pomiar.temperatura > tmax)
            tmax = dane[i].pomiar.temperatura;
        sumaH += dane[i].pomiar.wilgotnosc;
        sumaP += dane[i].pomiar.cisnienie;
    }
    printf("\nPodsumowanie:\n");
    printf("T min: %.1f, T max: %.1f\n", tmin, tmax);
    printf("Srednia wilgotnosc: %.1f\n", sumaH / 10);
    printf("Srednie cisnienie: %.1f\n", sumaP / 10);

    return 0;

    }

