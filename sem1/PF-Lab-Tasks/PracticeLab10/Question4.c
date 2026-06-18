#include <stdio.h>
#include <string.h>
typedef struct Flight{
	int flightNumber;
	char departureCity[50];
	char arrivalCity[50];
	int departureTime;
	int arrivalTime;
	int availableSeats;
} Flight;
void bookSeat(Flight flight[], int *num, int number){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if(flight[i].flightNumber == number){
			if(flight[i].availableSeats != 0){
				found = 1;
				flight[i].availableSeats--;
				printf("Booked.\n");
			}
			else{
				printf("No Available Seats.\n");
			}
			break;
		}
	}
	if(!found){
		printf("Did Not Find %d\n", number);
	}
	printf("_________________________\n\n");
	return;
}
void displayFlights(Flight flight[], int *num){
	int i;
	if(*num == 0){
		printf("No Flights Available\n");
		printf("_________________________\n\n");
		return;
	}
	for(i = 0; i < *num; i++){
		printf("Flight %d Number: %d\n", i + 1, flight[i].flightNumber);
		printf("Departure City : %s\n", flight[i].departureCity);
		printf("Arrival City : %s\n", flight[i].arrivalCity);
		printf("Departure Time: %d \n", flight[i].departureTime);
		printf("Arrival Time: %d \n", flight[i].arrivalTime);
		printf("Seats Available: %d\n", flight[i].availableSeats);
		printf("\n");
	}
	printf("_________________________\n\n");
}
void search2Flights(Flight flight[], int *num, char arr1[], char arr2[]){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if( strcmp(flight[i].departureCity, arr1) == 0 && strcmp(flight[i].arrivalCity, arr2) == 0 ){
			printf("Flight %d Number: %d\n", i + 1, flight[i].flightNumber);
			printf("Departure City : %s\n", flight[i].departureCity);
			printf("Arrival City : %s\n", flight[i].arrivalCity);
			printf("Departure Time: %d \n", flight[i].departureTime);
			printf("Arrival Time: %d \n", flight[i].arrivalTime);
			printf("Seats Available: %d\n", flight[i].availableSeats);
			printf("\n");
			found = 1;
		}
	}
	if(!found){
		printf("Did Not Find a Flight b/w those Two Cities. \n");
	}
	printf("_________________________\n\n");
	return;
}
void changeSchedule(Flight flight[], int *num, int number){
	int found = 0, i;
	for(i = 0; i<*num ; i++){
		if(flight[i].flightNumber == number){
			printf("Enter the New Departure Time (24HR format => 0000) : ");
			scanf("%d", &flight[i].departureTime);
			printf("Enter the New Arrival Time : ");
			scanf("%d", &flight[i].arrivalTime);
			found = 1;
			break;
		}
	}
	if(!found){
		printf("Did Not Find %d\n", number);
	}
	printf("_________________________\n\n");
	return;
}
int main(){
	Flight flights[50] = {0};
	int num = 3, n;
	char arr[50], arr1[50], arr2[50];	
//	Assigning preset values
	flights[0].flightNumber = 1001;
    strcpy(flights[0].departureCity, "New York");
    strcpy(flights[0].arrivalCity, "Los Angeles");
    flights[0].departureTime = 930; // 9:30 AM
    flights[0].arrivalTime = 1230;  // 12:30 PM
    flights[0].availableSeats = 150;
//     Assign values to the second flight
    flights[1].flightNumber = 2002;
    strcpy(flights[1].departureCity, "Chicago");
    strcpy(flights[1].arrivalCity, "Miami");
    flights[1].departureTime = 1045; // 10:45 AM
    flights[1].arrivalTime = 1430;   // 2:30 PM
    flights[1].availableSeats = 120;
    // Assign values to the third flight
    flights[2].flightNumber = 3003;
    strcpy(flights[2].departureCity, "San Francisco");
    strcpy(flights[2].arrivalCity, "Seattle");
    flights[2].departureTime = 1500; // 3:00 PM
    flights[2].arrivalTime = 1700;   // 5:00 PM
    flights[2].availableSeats = 100;
	while(1){
		printf("Enter 1 to Book a Flight, 2 to Search for Flights b/w 2 cities, 3 to Change Schedules for a Flight or 0 to End : ");
		if (scanf("%d", &n) != 1) {
        	printf("Invalid input. Please enter a number.\n");
        	while (getchar() != '\n');
        	continue;
		}
		switch(n){
			case 1:
				displayFlights(flights, &num);
				printf("Enter the Flight Number you want to Book : ");
				scanf("%d", &n);
				bookSeat(flights, &num, n);
				break;
			case 2:
				displayFlights(flights, &num);
				printf("Enter Flight's Departure City : ");
				scanf(" %49[^\n]%*c", arr1);
				printf("Enter Flight's Arrival City : ");
				scanf(" %49[^\n]%*c", arr2);
				search2Flights(flights, &num, arr1, arr2);
				break;
			case 3:
				displayFlights(flights, &num);
				printf("Enter the Flight Number you want to Change Schedule For : ");
				scanf("%d", &n);
				changeSchedule(flights, &num, n);
				break;
			case 0:
				printf("Operation Ended.");
				return 0;
			default:
				printf("Invalid Input, Try again.");
				break;
		}
	}			
	return 0;
}
