
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int hourDeparture;
    int minuteDeparture;
    int hourArrival; 
    int minuteArrival; 
    int timeDeparture;
    int timeArrival;
}Time;

Time* loadTime();
void Departure(Time*);
void Arrival(Time*);
int invalidHour(int);
int invalidMinutes(int);
int validHours();
int validMinutes();
int hourToMinutes(int);
int calculeTime(Time*);
void convertToHour(int);
void convertToMinutes(Time* time);

int main() {
    Time* time;
    time->hourDeparture = 0;
    int control = 0;
    time = loadTime();
    if(time == NULL) {
        printf("Unallocated time");
    }
    while(control != -1) {
        printf("\nObs:Nao funciona se ultrapassar 24h\n");
        printf("\n'Ctrl + c' para encerrar\n");   

        Departure(time);
        Arrival(time);

        convertToMinutes(time);

        int totalTime = calculeTime(time);

        convertToHour(totalTime);

        system("pause");
        system("cls");
    }

    free(time);

    return 0;
}

Time* loadTime() {
    Time* time = NULL;

    time = (Time*) malloc(sizeof(Time));

    return time;
}

void Departure(Time* time) {
    printf("\n..::Saida::..\n");

    time->hourDeparture = validHours();

    time->minuteDeparture = validMinutes();
}

void Arrival(Time* time) {
    printf("\n..::Chegada::..\n");

    time->hourArrival = validHours();

    time->minuteArrival = validMinutes();
}

int invalidHour(int hour) {
    if(hour > 24 || hour < 0) {
        return 1;
    }
    return 0;
}

int invalidMinutes(int minutes) {
    if(minutes < 0 || minutes > 60) {
        return 1;
    }
    return 0;
}

int validMinutes() {
    int minute = -1;
    while(invalidMinutes(minute) == 1) {
        printf("Minutos: ");
        scanf("%i", &minute);
        if(invalidMinutes(minute)) {
            printf("Minutos Invalidos\n\n");
        }
    }
    return minute;
}

int validHours() {
    int hour = -1;
    while(invalidHour(hour) == 1) {
        printf("Horas: ");
        scanf("%i", &hour);
        if(invalidHour(hour)) {
            printf("Hora Invalida!!\n\n");
        }
    }
    return hour;
}

int hourToMinutes(int hour) {
    return hour * 60;
}

int calculeTime(Time* time) {
    if(time->timeDeparture > time->timeArrival) {
        int aux = 1440 - time->timeDeparture;
        return aux + time->timeArrival;
    }
       return time->timeArrival - time->timeDeparture;
}

void convertToMinutes(Time* time) {
    time->hourArrival = hourToMinutes(time->hourArrival);
    time->hourDeparture = hourToMinutes(time->hourDeparture);
    time->timeArrival = time->hourArrival + time->minuteArrival;
    time->timeDeparture = time->hourDeparture + time->minuteDeparture;
}

void convertToHour(int totalTime) {
    if(totalTime > 60) {
        int minutes = totalTime % 60;
        int hour = totalTime / 60;
        printf("\n%i : %i\n", hour, minutes);
    } else {
        printf("Minutos: %i\n", totalTime);
    }
}


