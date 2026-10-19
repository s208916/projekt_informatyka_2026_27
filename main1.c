#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ProbaMocy {
    char czas[30];
    float moc_w;
};
int main() {
    struct ProbaMocy p[8];
    time_t currentTime;
    srand(time(NULL));
    int dt = 15;
    float Energia = 0;


    for(int i = 0; i < 8; i++) {
        p[i].moc_w = 100 + rand()%701;
        time (&currentTime);
        strcpy(p[i].czas, ctime(&currentTime));
        int n = strlen(p[i].czas);
        p[i].czas[n-1] = '\0';
    }

    for (int i = 0; i < 8; i++) {
        Energia = ((Energia + p[i].moc_w + p[i+1].moc_w)/2 * dt/60 )/1000;
    }

    float suma = 0;
    for (int i = 0; i < 8; i++) {
        suma = suma + p[i].moc_w;
    }
    float smp = suma / 8;
    float eop = smp * (7 * dt / 60 ) / 1000;

    printf("Nr\t Czas\t\t\t\t\t   Moc [W]\n");
    for(int i=0;i<8;i++){
        printf("%d\t %s   %.1f\n", i+1, p[i].czas, p[i].moc_w);
    }

    printf("\nPodsumowanie:\n");
    printf("Energia (metoda trapezow): %.4f kWh\n", Energia);
    printf("Energia ze sredniej mocy: %.4f kWh\n", eop);

    return 0;
}



