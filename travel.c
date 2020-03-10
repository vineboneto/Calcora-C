
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
void convertToMinutes(Time* time);
int hourToMinutes(int);
int calculeTime(Time*);


int main() {
    Time* time;
    int control = 0;
    time = loadTime();
    if(time == NULL) {
        printf("Unallocated time");
    }
    while(control != -1) {
        
        Departure(time);

        Arrival(time);

        convertToMinutes(time);

        int totalTime = calculeTime(time);

        convertToHour(totalTime);

        system("pause");
        system("cls");
    }


    return 0;
}

Time* loadTime() {
    Time* time = NULL;

    time = (Time*) malloc(sizeof(Time));

    return time;
}

void Departure(Time* time) {
    printf("\nDeparture\n");
    printf("Hour: ");
    scanf("%i", &time->hourDeparture);
    printf("Minutes: ");
    scanf("%i", &time->minuteDeparture);
}

void Arrival(Time* time) {
    printf("\nArrival\n");
    printf("Hour: ");
    scanf("%i", &time->hourArrival);
    printf("Minutes: ");
    scanf("%i", &time->minuteArrival);
}

void convertToMinutes(Time* time) {
    time->hourArrival = hourToMinutes(time->hourArrival);
    time->hourDeparture = hourToMinutes(time->hourDeparture);
    time->timeArrival = time->hourArrival + time->minuteArrival;
    time->timeDeparture = time->hourDeparture + time->minuteDeparture;
}

int hourToMinutes(int hour) {
    return hour * 60;
}

int calculeTime(Time* time) {
    if(time->hourDeparture > time->hourArrival) {
        int aux = 1440 - time->timeDeparture;
        return aux + time->timeArrival;
    } else {
       return time->timeArrival - time->timeDeparture;
    }
}

void convertToHour(int totalTime) {
    if(totalTime > 60) {
        int minutes = totalTime % 60;
        int hour = totalTime / 60;
        printf("\n%i : %i\n", hour, minutes);
    } else {
        printf("Minutes: %i\n", totalTime);
    }
}


