#include <iostream>
#include <string>
using namespace std;

const int FLIGHT_COUNT = 4;
const int RESERVATION_COUNT = 100;

int flightNumbers[FLIGHT_COUNT] = {101, 102, 103, 104};
string destinations[FLIGHT_COUNT] = {"Karachi", "Lahore", "Multan", "Islamabad"};
int seatsAvailable[FLIGHT_COUNT] = {50, 40, 30, 20};

string passengerNames[RESERVATION_COUNT];
int passengerFlights[RESERVATION_COUNT];
int reservationCount = 0;

string feedbacks[RESERVATION_COUNT];
int ratings[RESERVATION_COUNT];
int feedbackCount = 0;

void displayFlights() {
    cout << "\nAvailable Flights:\n";
    cout << "Flight Number\tDestination\tSeats Available\n";
    for (int i = 0; i < FLIGHT_COUNT; i++) {
        cout << flightNumbers[i] << "\t\t" << destinations[i] << "\t\t" << seatsAvailable[i] << "\n";
    }
}

void bookFlight() {
    string name;
    int flightNumber;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);

    displayFlights();

    cout << "\nEnter the flight number you want to book: ";
    cin >> flightNumber;

    for (int i = 0; i < FLIGHT_COUNT; i++) {
        if (flightNumbers[i] == flightNumber) {
            if (seatsAvailable[i] > 0) {
                seatsAvailable[i]--;
                passengerNames[reservationCount] = name;
                passengerFlights[reservationCount] = flightNumber;
                reservationCount++;
                cout << "\nBooking successful!\n";
                return;
            } else {
                cout << "\nNo seats available on this flight.\n";
                return;
            }
        }
    }

    cout << "\nInvalid flight number. Please try again.\n";
}

void viewReservations() {
    if (reservationCount == 0) {
        cout << "\nNo reservations found.\n";
        return;
    }

    cout << "\nCurrent Reservations:\n";
    cout << "Passenger Name\tFlight Number\n";
    for (int i = 0; i < reservationCount; i++) {
        cout << passengerNames[i] << "\t\t" << passengerFlights[i] << "\n";
    }
}

void cancelBooking() {
    string name;
    int flightNumber;

    cout << "\nEnter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the flight number of your booking: ";
    cin >> flightNumber;

    for (int i = 0; i < reservationCount; i++) {
        if (passengerNames[i] == name && passengerFlights[i] == flightNumber) {
            // Shift reservations to "remove" the canceled one
            for (int j = i; j < reservationCount - 1; j++) {
                passengerNames[j] = passengerNames[j + 1];
                passengerFlights[j] = passengerFlights[j + 1];
            }
            reservationCount--;

            // Restore the seat in the corresponding flight
            for (int k = 0; k < FLIGHT_COUNT; k++) {
                if (flightNumbers[k] == flightNumber) {
                    seatsAvailable[k]++;
                    break;
                }
            }

            cout << "\nBooking canceled successfully.\n";
            return;
        }
    }

    cout << "\nNo matching booking found.\n";
}

void collectFeedback() {
    string feedback;
    int rating;

    cout << "\nWe value your feedback. Please let us know how your experience was:\n";
    cin.ignore();
    getline(cin, feedback);

    cout << "Please rate your experience (1 to 5): ";
    cin >> rating;

    if (rating < 1 || rating > 5) {
        cout << "\nInvalid rating. Please provide a rating between 1 and 5.\n";
        return;
    }

    feedbacks[feedbackCount] = feedback;
    ratings[feedbackCount] = rating;
    feedbackCount++;

    cout << "\nThank you for your feedback and rating!\n";
}

void viewFeedback() {
    if (feedbackCount == 0) {
        cout << "\nNo feedback available yet.\n";
        return;
    }

    cout << "\nFeedback Summary:\n";
    cout << "Feedback\t\tRating\n";
    for (int i = 0; i < feedbackCount; i++) {
        cout << feedbacks[i] << "\t\t" << ratings[i] << "\n";
    }
}

void menu() {
    while (true) {
        cout << "\n===========================================\n";
        cout << "            Flight Reservation System       \n";
        cout << "===========================================\n";
        cout << "1. Display Flights\n";
        cout << "2. Book Flight\n";
        cout << "3. View Reservations\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Provide Feedback\n";
        cout << "6. View Feedback\n";
        cout << "7. Exit\n";           
        cout << "===========================================\n";

        cout << "\n>> Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:
                bookFlight();
                break;
            case 3:
                viewReservations();
                break;
            case 4:
                cancelBooking();
                break;
            case 5:
                collectFeedback();
                break;
            case 6:
                viewFeedback();
                break;
            case 7:
                cout << "\nThank you for using the Flight Reservation System. Goodbye!\n";
                return;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

int main() {
    cout << "Welcome to the Flight Reservation System!\n";
    menu();
    return 0;
}
