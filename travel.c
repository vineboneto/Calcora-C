
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int hourDeparture;
    int minuteDeparture;
    int hourArrival; 
    int minuteArrival; 

}Time;

Time* loadTime();
void Departure(Time*);
void Arrival(Time*);
int calculeTotalHours(Time*);
int calculeTotalMinutes(Time*);


int main() {
    Time* time;

    time = loadTime();
    if(time == NULL) {
        printf("Unallocated time");
    }

    Departure(time);

    Arrival(time);

    convertToHour(time);

    int totalHour = calculeTotalHours(time);
    int totalMinute = calculeTotalMinutes(time);

    printf("Total Hour: %i\n", totalHour);    
    printf("Total Minute: %i\n", totalMinute);    

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

int calculeTotalHours(Time* time) {
    if(time->hourDeparture > time->hourArrival) {
        int aux = 24 - time->hourDeparture;
        return aux + time->hourArrival;
    }
    return time->hourArrival - time->hourDeparture;
}

int calculeTotalMinutes(Time* time) {
    if(time->hourDeparture > time->hourArrival) {
        int aux = 1440
    }
    return time->minuteArrival - time->minuteDeparture;
}


