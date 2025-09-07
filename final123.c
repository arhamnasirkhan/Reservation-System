#include <stdio.h>
#include <stdlib.h>//system("cls")
#include <string.h>//String
#include <ctype.h>//Upper or lower case
#include <windows.h>//colour and sleep
#include <time.h> //time
#include <conio.h> // Required for getch() on Windows

#define MAX_USERNAME 60
#define MAX_SEATS 30       //limiting and for global use
f#define MAX_ROOMS 100
#define FILE_ROUTE1 "route1.txt"
#define FILE_ROUTE2 "route2.txt"
#define FILE_ROUTE3 "route3.txt"
#define FILE_STANDARD_ROOM "Standard Room.txt"
#define FILE_DOUBLE_ROOM "Double Room.txt"
#define FILE_DELUXE_ROOM "Deluxe Room.txt"
// Global arrays to track reserved seats for each route
int reserved_seats_route1[MAX_SEATS] = {0};
int reserved_seats_route2[MAX_SEATS] = {0};
int reserved_seats_route3[MAX_SEATS] = {0};
int reserved_rooms_Standard_Room[MAX_ROOMS] = {0};
int reserved_rooms_Double_Room[MAX_ROOMS]   = {0};
int reserved_rooms_Deluxe_Room[MAX_ROOMS]   = {0};
// Global array to track reserved rooms
//int reserved_rooms[MAX_ROOMS] = {0};

// Bus structure
struct Bbooking {
    char user_name[MAX_USERNAME];
    int seat_number;
    int reserved_seats[MAX_SEATS];
    float price;
    char route_name[50];
}

// Hotel structure
struct Hbooking {
    char user_name[MAX_USERNAME];
    int room_number;
    int reserved_rooms[MAX_ROOMS];
    float price;
    char room_type[50];
};

// Set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function prototypes
void welcome();
void terms();
void login();
void showMenu();
void busSelection();
void hotelSelection();
void cancelBusBooking();
void cancelHotelBooking();
void display_seat_status(const int seats[]);
void display_room_status(const int rooms[]);
void finalize_booking(struct Bbooking *booking, int route);
void finalize_hotel_booking(struct Hbooking *booking, int room_type );
void display_bus_booking(struct Bbooking bus_booking);
void display_hotel_booking(struct Hbooking hotel_booking);
int isValidUsername(const char *username) 
{
	int hasUpper = 0, hasLower = 0;
	
	int i = 0;
    for (; username[i] != '\0'; i++) 
	{
        if (isupper(username[i])) hasUpper = 1;
        if (islower(username[i])) hasLower = 1;
        if (hasUpper && hasLower) 
		return 1; // Valid username
    }
    return 0; // Invalid username
}


int isValidPassword(const char *password) 
{
    int hasAlphabet = 0, hasNumber = 0;
	
	int i = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (isalpha(password[i])) hasAlphabet = 1;
        if (isdigit(password[i])) hasNumber = 1;
        if (hasAlphabet && hasNumber) return 1; // Valid password
    }
    return 0; // Invalid password
}

int main() {
    system("cls");
    welcome();
    printf("\n\n\nKindly Press Any Key To Proceed");
    getch();
    system("cls");

	terms();
    printf("\n\n\nKindly Press Any Key To Proceed");
    getch();
    system("cls");
	
    login();
    printf("\n\n\nKindly Press Any Key To Proceed");
    getch();
    system("cls");

    showMenu();
    return 0;
}

void welcome() {
   setColor(11); 
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t     WWW     WWW   EEEEEEE   LL         CCCCCC    OOOOO    MM      MM   EEEEEEE\n");
    sleep(50);
    printf("\t\t\t\t\t     WWW     WWW   EE        LL        CC        OO   OO   MMM    MMM   EE     \n");
    sleep(50);
    printf("\t\t\t\t\t     WWW  W  WWW   EEEEE     LL        CC        OO   OO   MM M  M MM   EEEEE  \n");
    sleep(50);
    printf("\t\t\t\t\t      WW WWW WW    EE        LL        CC        OO   OO   MM  MM  MM   EE     \n");
    sleep(50);
    printf("\t\t\t\t\t       WW   WW     EEEEEEE   LLLLLL     CCCCCC    OOOOO    MM      MM   EEEEEEE\n\n");
    sleep(50);
    setColor(15);
	printf("\t\t\t\t\t\t\t\t\033[1;36m  TO OUR RESERVATION SYSTEM\033[0m\n\n\n");
    sleep(50);
	printf("\n\t\t\t\t\t\033[1;36m==================================================================================\033[0m\n");
    sleep(50);
    printf("\t\t\t\t\t\033[1;36m=                                                                                =\033[0m\n");
    sleep(50);
    printf("\t\t\t\t\t\033[1;36m=                 Thank you for choosing our reservation system!                 =\033[0m\n");
    sleep(50);
    printf("\t\t\t\t\t\033[1;36m=                      Your journey starts with us. Enjoy!                       =\033[0m\n");
    sleep(50);
    printf("\t\t\t\t\t\033[1;36m=                                                                                =\033[0m\n");
    sleep(50);
    printf("\t\t\t\t\t\033[1;36m==================================================================================\033[0m\n");
    sleep(50);

}

void terms() {
	setColor(11);
    printf("\n\n\n\n\n\t\t\t\t\t\t=========================================");
    sleep(50);
    printf("\n\t\t\t\t\t\t=                                       =");
    sleep(50);
	printf("\n\t\t\t\t\t\t=                                       =");
    sleep(50);
    printf("\n\t\t\t\t\t\t=           TERMS AND CONDITIONS        =");
    sleep(50);
	printf("\n\t\t\t\t\t\t=                                       =");
    sleep(50);
	printf("\n\t\t\t\t\t\t=                                       =");
    sleep(50);
    printf("\n\t\t\t\t\t\t=========================================");
    sleep(50);
    setColor(15);
    printf("\n\n\n\tPlease Read Our Terms And Conditions Carefully\n");
    sleep(50);
    printf("\n\t1. Reservation can be made through various payment options.");
    sleep(50);
    printf("\n\t2. Reservation is considered confirmed only upon getting confirmation receipt.");
    sleep(50);
    printf("\n\t3. The information provided by the customer should be accurate.");
    sleep(50);
    printf("\n\t4. In case of no-show, no refund will be given.");
    sleep(50);
    printf("\n\t5. Additional charges will be applied in case of any damage to our property.");
    sleep(50);
    printf("\n\t6. For further information or queries, please visit our instagram.");
    sleep(50);
}

void login() {
    char username[50], password[20];
    int usernameAttempts = 3, passwordAttempts = 3;

	printf("\n\n\n\n\n\t\t\t\t\t\t\033[1;36m=========================================\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=                                       =\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=                                       =\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=             LOGIN SYSTEM              =\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=                                       =\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=                                       =\033[0m");
    sleep(50);
    printf("\n\t\t\t\t\t\t\033[1;36m=========================================\033[0m\n\n");
    sleep(50);
	printf("Press any key to proceed...");
    
    getch();
	
    while (usernameAttempts > 0) {
        sleep(50);
        printf("\n\tEnter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0; // Remove trailing newline

        if (isValidUsername(username)) {
            printf("\tValid username.\n");
            break;
        } else {
            usernameAttempts--;
            sleep(50);
            printf("\n\tInvalid username!");
            sleep(50);
			printf("\n\t- Username Must contain at least one uppercase and one lowercase letter!"); 
            sleep(50);
			printf("\n\tAttempts left: %d\n", usernameAttempts);
            sleep(50);
        }

        if (usernameAttempts == 0) {
            sleep(50);
            printf("\n\tToo many invalid username attempts!");
            sleep(50);
			printf("\n\tExiting program!!!\n");
            sleep(50);
            exit(0); // Exit program
        }
    }

    while (passwordAttempts > 0) {
        printf("\n\tEnter password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0; // Remove trailing newline

        if (isValidPassword(password)) {
            printf("\tValid password.\n");
            break;
        } else {
            passwordAttempts--;
			printf("\tInvalid Password! Please follow the instructions:\n");
            sleep(50);
			printf("\t- It must be include at least one alphabet (A-Z or a-z)\n");
            sleep(50);
			printf("\t- It must be include at least one number (0-9)\n"); 
            sleep(50);
			printf("\tAttempts left: %d\n", passwordAttempts);
        }

        if (passwordAttempts == 0) {
            printf("\n\tToo many invalid password attempts!");
            sleep(50);
			printf("\n\tExiting program!!!\n");
            exit(0); // Exit program
        }
    }

    printf("\n\n\tLogin successful... Welcome!\n");
}

void showMenu() {
    int choice;
    while (1) {
       setColor(11);
        printf("\n\n\n\n\n\t\t\t\t\t\t=========================================");
        sleep(50);
        printf("\n\t\t\t\t\t\t=                                       =");
        sleep(50);
		printf("\n\t\t\t\t\t\t=                                       =");
        sleep(50);
        printf("\n\t\t\t\t\t\t=               MAIN MENU               =");
        sleep(50);
		printf("\n\t\t\t\t\t\t=                                       =");
        sleep(50);
		printf("\n\t\t\t\t\t\t=                                       =");
        sleep(50);
        printf("\n\t\t\t\t\t\t=========================================\n\n");
        setColor(15);
        printf("\t1. Reservation For Bus\n");
		sleep(50);
        printf("\t2. Reservation For Hotel\n");
		sleep(50);
        printf("\t3. Cancel Bus Booking\n");
		sleep(50);
        printf("\t4. Cancel Hotel Booking\n");
		sleep(50);
        printf("\t5. Exit\n");
		sleep(50);
        printf("\tSelect (1 to 5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                busSelection();
                break;
            case 2:
                hotelSelection();
                break;
            case 3:
                cancelBusBooking();
                break;
            case 4:
                cancelHotelBooking();
                break;
            case 5:
                printf("\n\tExiting Program. Thank you for using our service.\n");
                exit(0);
            default:
                printf("\n\tInvalid choice. Please try again.\n");
        }
    }
}
// Function to load seat reservation data from file
void load_seat_status(int reserved_seats[], int route) {
    FILE *file;
    char filename[20];

    // Determine the file name based on the selected route
    if (route == 1) {
        strcpy(filename, "route1.txt");
    } else if (route == 2) {
        strcpy(filename, "route2.txt");
    } else if (route == 3) {
        strcpy(filename, "route3.txt");
    } else {
        printf("Invalid route number.\n");
        return;
    }

    file = fopen(filename, "r");
int i;
    if (file != NULL) {
        // Read the seat status from the file
        for ( i = 0; i < MAX_SEATS; i++) {
            fscanf(file, "%d", &reserved_seats[i]);
        }
        fclose(file);
    } else {
        // If the file doesn't exist, initialize all seats as unreserved (0)
        for ( i = 0; i < MAX_SEATS; i++) {
            reserved_seats[i] = 0;
        }
    }
    
}
void load_room_status(int reserved_rooms[],int room_type) {
    FILE *file;
    char filename[20];

    // Determine the file name based on the selected route
    if (room_type == 1) {
        strcpy(filename, "Standard Room.txt");
    } else if (room_type == 2) {
        strcpy(filename, "Double Room.txt");
    } else if (room_type == 3) {
        strcpy(filename, "Deluxe Room.txt");
    } else {
        printf("Invalid room number.\n");
        return;
    }

    file = fopen(filename, "r");
int i;
    if (file != NULL) {
        // Read the room status from the file
        for ( i = 0; i < MAX_ROOMS; i++) {
            fscanf(file, "%d", &reserved_rooms[i]);
        }
        fclose(file);
    } else {
        // If the file doesn't exist, initialize all room as unreserved (0)
        for ( i = 0; i < MAX_ROOMS; i++) {
            reserved_rooms[i] = 0;
        }
    }
}
// Function to save the updated seat status back to the file
void save_seat_status(int reserved_seats[], int route) {
    FILE *file;
    char filename[20];

    // Determine the file name based on the selected route
    if (route == 1) {
        strcpy(filename, "route1.txt");
    } else if (route == 2) {
        strcpy(filename, "route2.txt");
    } else if (route == 3) {
        strcpy(filename, "route3.txt");
    } else {
        printf("Invalid route number.\n");
        return;
    }

    file = fopen(filename, "w");
int i;
    if (file != NULL) {
        // Write the seat status to the file
        for ( i = 0; i < MAX_SEATS; i++) {
            fprintf(file, "%d\n", reserved_seats[i]);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
    
}
void save_room_status(int reserved_rooms[],int room_type) {
    FILE *file;
    char filename[20];

    // Determine the file name based on the selected room
    if (room_type== 1) {
        strcpy(filename, "Standard Room.txt");
    } else if (room_type == 2) {
        strcpy(filename, "Double Room.txt");
    } else if (room_type == 3) {
        strcpy(filename, "Deluxe Room.txt");
    } else {
        printf("Invalid room number.\n");
        return;
    }

    file = fopen(filename, "w");
int i;
    if (file != NULL) {
        // Write the room status to the file
        for ( i = 0; i < MAX_ROOMS; i++) {
            fprintf(file, "%d\n", reserved_rooms[i]);
          
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}
void busSelection() {
	system("cls");
    struct Bbooking bus_booking = {0};
    int route = 0;
    int seat_choice, seats_to_book;

    while (1) {
        Sleep(100);
        printf("\n\t\t\n\t\t\t\t\033[1;36m ========================================== \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =          Select Your Route             = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
        Sleep(50);
        Sleep(50);
        printf("  1) Karachi   ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Lahore     \033[30;47m[8,000 PKR](Include Breakfast,Lunch,HiTea & Dinner)\033[0m\n");
        Sleep(50);
        printf("\t ______________________________\n");
        Sleep(50);
        printf("\t|   \033[1;33mDeparture Time: 07:00 AM \033[0m  |\n");
        Sleep(50);
        printf("\t|      \033[1;33m====15hr:26m====\033[0m        |\n");
        Sleep(50);
        printf("\t|    \033[1;33mArrival Time: 10:26 PM\033[0m    |\n");
        Sleep(50);
        printf("\t ______________________________\n\n");
        Sleep(50);
        printf("  2) Islamabad ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Multan     \033[30;47m[5,500 PKR](Include Breakfast & Dinner)\033[0m\n\n");
        Sleep(50);
        printf("\t ______________________________\n");
        Sleep(50);
        printf("\t|   \033[1;33mDeparture Time: 09:00 AM \033[0m  |\n");
        Sleep(50);
        printf("\t|      \033[1;33m====06hr:30m====\033[0m        |\n");
        Sleep(50);
        printf("\t|    \033[1;33mArrival Time: 03:30 PM\033[0m    |\n");
        Sleep(50);
        printf("\t ______________________________\n\n");
        Sleep(50);
        printf("  3) Peshawar  ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Quetta     \033[30;47m[7,500 PKR](Include Breakfast, Lunch & HiTea)\033[0m\n\n");
        Sleep(50);
        printf("\t ______________________________\n");
        Sleep(50);
        printf("\t|   \033[1;33mDeparture Time: 06:00 AM \033[0m  |\n");
        Sleep(50);
        printf("\t|      \033[1;33m====13hr:50m====\033[0m        |\n");
        Sleep(50);
        printf("\t|    \033[1;33mArrival Time: 07:30 PM\033[0m    |\n");
        Sleep(50);
        printf("\t ______________________________\n\n");
        Sleep(50);
        printf("  4) \033[4;34mBack\033[0m \n\n");
        Sleep(50);
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &route);

        if (route == 4) return;

        if (route >= 1 && route <= 3) {
            if (route == 1) {
                strcpy(bus_booking.route_name, "Karachi to Lahore");
                bus_booking.price = 8000;
      
            } else if (route == 2) {
                strcpy(bus_booking.route_name, "Islamabad to Multan");
                bus_booking.price = 5500;
            
            } else {
                strcpy(bus_booking.route_name, "Peshawar to Quetta");
                bus_booking.price = 7500;
                        }
// Load the current seat reservation status from the file
            load_seat_status(bus_booking.reserved_seats, route);
            printf("\n\t\t\tRoute: %s\n\t\t\tPrice per seat: %.2f PKR\n", bus_booking.route_name, bus_booking.price);
            display_seat_status(bus_booking.reserved_seats);
            printf("\n\t\t\tEnter your name: ");
            sleep(50);
            getchar(); // Clear newline from input buffer
            fgets(bus_booking.user_name, sizeof(bus_booking.user_name), stdin);
            bus_booking.user_name[strcspn(bus_booking.user_name, "\n")] = 0;
            printf("\n\t\t\tEnter the number of seats to book (1-%d): ", MAX_SEATS);
            scanf("%d", &seats_to_book);

            if (seats_to_book <= 0 || seats_to_book > MAX_SEATS) {
                printf("\t\t\tInvalid number of seats.\n");
                continue;
            }
int i = 0;
            for (; i < seats_to_book; i++) {
                printf("\t\t\tEnter seat number (1-%d): ", MAX_SEATS);
                scanf("%d", &seat_choice);

                if (seat_choice < 1 || seat_choice > MAX_SEATS) {
                    printf("\t\t\tInvalid seat number. Try again.\n");
                    i--;
                    continue;
                }

                if (bus_booking.reserved_seats[seat_choice - 1] == 1) {
                    printf("\t\t\tSeat %d is already reserved. Choose another seat.\n", seat_choice);
                    i--;
                } else {
                    bus_booking.reserved_seats[seat_choice - 1] = 1;
                }
            }

            bus_booking.seat_number = seats_to_book;
            finalize_booking(&bus_booking, route);
            // Save the updated seat reservation status back to the file
            save_seat_status(bus_booking.reserved_seats, route);
            break;
        } else {
            printf("\t\t\tInvalid choice. Try again.\n");
        }
    }
}


void hotelSelection() {
	system("cls");
    struct Hbooking hotel_booking = {0};
    int room_type = 0;
    int room_choice, rooms_to_book;
    int room = 0;
    while (1) {
        Sleep(200);
        printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =           Select Your Room             = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
        sleep(50);
		printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
        Sleep(200);
        printf("  1) Standard Room    \033[30;47m[20,000 PKR Per Night](Include BreakFast)\033[0m\n\n");
        Sleep(100);
        printf("  2) Double Room      \033[30;47m[35,000 PKR Per Night](Include BreakFast & Spa Service)\033[0m\n\n");
        Sleep(100);
        printf("  3) Deluxe Room      \033[30;47m[40,000 PKR Per Night](Use All Facalities)\033[0m\n\n");
        Sleep(100);
        printf("  4) \033[4;34mBack\033[0m \n\n");
        Sleep(100);
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &room_type);

        if (room_type == 4) return;

        if (room_type >= 1 && room_type <= 3) {
            if (room_type == 1) {
                strcpy(hotel_booking.room_type, "Standard Room");
                hotel_booking.price = 20000;
            } else if (room_type == 2) {
                strcpy(hotel_booking.room_type, "Double Room");
                hotel_booking.price = 35000;
            } else {
                strcpy(hotel_booking.room_type, "Deluxe Room");
                hotel_booking.price = 40000;
            }
// Load the current room reservation status from the file
            load_room_status(hotel_booking.reserved_rooms,room_type);
            printf("\n\t\t\tRoom Type: %s\n\t\t\tPrice per night: %.2f PKR\n", hotel_booking.room_type, hotel_booking.price);
            display_room_status(hotel_booking.reserved_rooms);
            printf("\n\t\t\tEnter your name: ");
            getchar(); // Clear newline from input buffer
            fgets(hotel_booking.user_name, sizeof(hotel_booking.user_name), stdin);
            hotel_booking.user_name[strcspn(hotel_booking.user_name, "\n")] = 0;
            sleep(50);
            printf("\n\t\t\tEnter the number of rooms to book (1-%d): ", MAX_ROOMS);
            scanf("%d", &rooms_to_book);

            if (rooms_to_book <= 0 || rooms_to_book > MAX_ROOMS) {
                printf("\t\t\tInvalid number of rooms.\n");
                continue;
            }
int i = 0;
            for (; i < rooms_to_book; i++) {
                printf("\t\t\tEnter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &room_choice);

                if (room_choice < 1 || room_choice > MAX_ROOMS) {
                    printf("\t\t\tInvalid room number. Try again.\n");
                    i--;
                    continue;
                }

                if (hotel_booking.reserved_rooms[room_choice - 1] == 1)  {
                    printf("\t\t\tRoom %d is already reserved. Choose another room.\n", room_choice);
                    i--;
                } else {
                   hotel_booking.reserved_rooms[room_choice - 1] = 1;
                }
            }

            hotel_booking.room_number = rooms_to_book;
            finalize_hotel_booking(&hotel_booking, room_type);
            // Save the updated room reservation status back to the file
            save_room_status(hotel_booking.reserved_rooms,room_type);
            break;
        } else {
            printf("\t\t\tInvalid choice. Try again.\n");
        }
    }
}


void finalize_booking(struct Bbooking *booking, int route) {
	
    printf("\n\t\t\tFinalizing your booking...\n");
    char filename[20];
    if (route == 1) {
    	 strcpy(filename, "route1.txt");
       
    } else if (route == 2) {
    	 strcpy(filename, "route2.txt");
      
    } else if (route == 3) {
    	strcpy(filename, "route3.txt");
     
    }
    else {
        printf("\t\t\tInvalid route.\n");
        return;
    }
    // Open the file to update the seat reservation status
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\t\t\tError opening file for writing.\n");
        return;
    }
int i;
    // Write the updated seat reservation status to the file
    for ( i = 0; i < MAX_SEATS; i++) {
        fprintf(file, "%d\n", booking->reserved_seats[i]);
    }
    fclose(file); // Close the file after writing

    display_bus_booking(*booking);
}

void finalize_hotel_booking(struct Hbooking *booking, int room_type) {
    printf("\n\t\t\tFinalizing your booking...\n");
    char filename[20];
    if (room_type == 1) {
    	 strcpy(filename, "Standard Room.txt");
    } else if (room_type == 2) {
    	 strcpy(filename, "Double Room.txt");
    } else if (room_type == 3) {
    	strcpy(filename, "Deluxe Room.txt");
    }
    else {
        printf("\t\t\tInvalid room.\n");
        return;
    }
 .   // Open the file to update the room reservation status
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("\t\t\tError opening file for writing.\n");
        return;
    }
int i;
    // Write the updated room reservation status to the file
    for ( i = 0; i < MAX_ROOMS; i++) {
        fprintf(file, "%d\n", booking->reserved_rooms[i]);
    }

    fclose(file); // Close the file after writing

    display_hotel_booking(*booking);
}

void display_bus_booking(struct Bbooking bus_booking) {
	system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =       Your Bus Booking Details         = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
			
    printf("\t\t\tName: %s\n", bus_booking.user_name);
	sleep(50);
    printf("\t\t\tRoute: %s\n", bus_booking.route_name);
	sleep(50);
    printf("\t\t\tSeats Reserved: %d\n", bus_booking.seat_number);
	sleep(50);
    printf("\t\t\tReserved Seats Number: ");
	sleep(50);
	
	int i = 0;
    for (; i < MAX_SEATS; i++) {
        if (bus_booking.reserved_seats[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n\t\t\tTotal Price: %.2f PKR\n", bus_booking.seat_number * bus_booking.price);
	sleep(50);
    printf("\t\t\tDate: %04d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	sleep(50);
    printf("\t\t\tTime: %02d:%02d\n", tm.tm_hour, tm.tm_min);
	sleep(50);
	
	printf("\n\n\nEnter any key to return to main menu");
	getch();
	showMenu();
}

void display_hotel_booking(struct Hbooking hotel_booking) {
	system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =       Your Hotel Booking Details       = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
			
    printf("\t\t\tName: %s\n", hotel_booking.user_name);
	sleep(50);
    printf("\t\t\tRoom Type: %s\n", hotel_booking.room_type);
	sleep(50);
    printf("\t\t\tRooms Reserved: %d\n", hotel_booking.room_number);
	sleep(50);
    printf("\t\t\tReserved rooms Number: ");
	sleep(50);
	
	int i = 0;
    for (; i < MAX_ROOMS; i++) {
        if (hotel_booking.reserved_rooms[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n\t\t\tTotal Price: %.2f PKR\n", hotel_booking.room_number * hotel_booking.price);
	sleep(50);
    printf("\t\t\tDate: %04d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	sleep(50);
    printf("\t\t\tTime: %02d:%02d\n", tm.tm_hour, tm.tm_min);
	sleep(50);
	
	printf("\n\n\nEnter any key to return to main menu");
	getch();
	showMenu();
}
void cancelBusBooking() {
	system("cls");
    int route, seat_number;
    
	Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =              Cancellation              = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
			
    printf("\t\t\tSelect Route:\n\n\n");
	sleep(50);
     printf(" \t\t\t 1) Karachi   ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Lahore \n\n");
       
        printf(" \t\t\t 2) Islamabad ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Multan  \n\n");
       
        printf(" \t\t\t 3) Peshawar  ");
        Sleep(50);
        printf("  \033[1;36m---->\033[0m");
        Sleep(50);
        printf(" Quetta \n\n");
	sleep(50);
    printf("\t\t\tEnter your choice: ");
	sleep(50);
    scanf("%d", &route);

    if (route < 1 || route > 3) {
        printf("\t\t\tInvalid route. Returning to main menu.\n");
		sleep(50);
        return;
    }

    printf("\t\t\tEnter seat number to cancel (1-%d): ", MAX_SEATS);
	sleep(50);
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > MAX_SEATS) {
        printf("\t\t\tInvalid seat number.\n");
		sleep(50);
        return;
    }

    FILE *file;
    int reserved_seats[MAX_SEATS];
    char filename[20];

    if (route == 1) {
        strcpy(filename, FILE_ROUTE1);
    } else if (route == 2) {
        strcpy(filename, FILE_ROUTE2);
    } else {
        strcpy(filename, FILE_ROUTE3);
    }

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tError opening file for reading.\n");
        sleep(1);
        return;
    }
int i;
    // Read the reserved seat status into the array
    for ( i = 0; i < MAX_SEATS; i++) {
        fscanf(file, "%d", &reserved_seats[i]);
    }
    fclose(file);

    if (reserved_seats[seat_number - 1] == 1) {
        reserved_seats[seat_number - 1] = 0;
        printf("\t\t\tSeat %d successfully canceled.\n", seat_number);
        sleep(1);

        // Open the file for writing (overwrite the seat status)
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("\t\t\tError opening file for writing.\n");
            sleep(1);
            return;
        }
int i;
        // Write the updated reserved seat status into the file
        for ( i = 0; i < MAX_SEATS; i++) {
            fprintf(file, "%d\n", reserved_seats[i]);
        }
        fclose(file);
    } else {
        printf("\t\t\tSeat %d is not currently reserved.\n", seat_number);
        sleep(1);
    }

    printf("\n\n\nEnter any key to return to main menu");
    getch();  // Wait for a key press
    showMenu();  // If you have a function to show the menu
}

void cancelHotelBooking() {
	system("cls");
    int room_number;
    int room_type;
	Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =              Cancellation              = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
	
    printf("\t\t\tEnter room number to cancel (1-%d): ", MAX_ROOMS);
	sleep(50);
    scanf("%d", &room_number);
     
    if (room_number < 1 || room_number > MAX_ROOMS) {
        printf("\t\t\tInvalid room number.\n");
		sleep(50);
        return;
    }
 printf("\t\t\tEnter room type (1 for Standard, 2 for Double, 3 for Deluxe): ");
    scanf("%d", &room_type);

    // Declare filename based on room type
    char filename[20];

    if (room_type == 1) {
        strcpy(filename, FILE_STANDARD_ROOM);
    } else if (room_type == 2) {
        strcpy(filename, FILE_DOUBLE_ROOM);
    } else {
        strcpy(filename, FILE_DELUXE_ROOM);
    }
    FILE *file;
    int reserved_rooms[MAX_ROOMS];
    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\t\t\tError opening file for reading.\n");
        sleep(1);
        return;
    }
int i;
    // Read the reserved room status into the array
    for ( i = 0; i < MAX_ROOMS; i++) {
        fscanf(file, "%d", &reserved_rooms[i]);
    }
    fclose(file); 
    
    if (reserved_rooms[room_number - 1] == 1) {
        reserved_rooms[room_number - 1] = 0;
        printf("\t\t\tRoom %d successfully canceled.\n", room_number);
		sleep(50);
    
	 // Open the file for writing (overwrite the seat status)
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("\t\t\tError opening file for writing.\n");
            sleep(1);
            return;
        }

        // Write the updated reserved seat status into the file
        for ( i = 0; i < MAX_ROOMS; i++) {
            fprintf(file, "%d\n", reserved_rooms[i]);
        }
        fclose(file);
	
	}else {
        printf("\t\t\tRoom %d is not currently reserved.\n",room_number);
		sleep(50);
    }
    printf("\n\n\nEnter any key to return to main menu");
    getch();  // Wait for a key press
    showMenu();  // If you have a function to show the menu
}

void display_seat_status(const int seats[]) {
    system("cls");
			Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =               SEAT STATUS              = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
	
	int i = 0;
    for (; i < MAX_SEATS; i++) {
        if (i % 10 == 0) printf("\n\t\t\t"); 
        if (seats[i] == 0) { // Available seat
            printf("\n\t %2d.\033[1;33m[A]\033[0m ", i + 1);
        } else { // Reserved seat
            printf("\n\t %2d.\033[1;32m[R]\033[0m", i + 1);
        }
        sleep(50); 
    }
    printf("\n\t\t\t\033[1;33m[A]\033[0m = Available, \033[1;32m[R]\033[0m = Reserved\n");
    sleep(50);
}

void display_room_status(const int rooms[]) {
    system("cls");
			Sleep(200);
			printf("\n\n\n\t\t\t\t\033[1;36m ========================================== \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =               ROOM STATUS              = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m =                                        = \033[0m");
            sleep(50);
			printf("\n\t\t\t\t\033[1;36m ========================================== \033[0m\n\n");
	
	int i = 0;
    for (; i < MAX_ROOMS; i++) {
        sleep(50);
        if (i % 10 == 0) printf("\n\t\t\t");
        if (rooms[i] == 0)
            printf("%2d.\033[1;33m[A]\033[0m ", i + 1); // Available rooms
        else
            printf("%2d.\033[1;32m[R]\033[0m ", i + 1); // Reserved rooms
    }
    printf("\n\n\t\t\t\033[1;33m[A]\033[0m = Available,\033[1;32m[R]\033[0m = Reserved\n");
	
}
