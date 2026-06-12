#include <iostream>
#include <iomanip>
using namespace std;

// Returns the day of the week for the 1st of a given month/year
// 0 = Sunday, 1 = Monday, ..., 6 = Saturday
// Uses Zeller's formula
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int day = (1 + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
    // Zeller returns 0=Sat, 1=Sun, ..., 6=Fri; convert to 0=Sun
    return (day + 6) % 7;
}

// Returns the number of days in a given month/year
int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Check for leap year
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return leap ? 29 : 28;
    }
    return days[month - 1];
}

// Prints the full calendar for a given month and year
void printCalendar(int month, int year) {
    string monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << "\n";
    cout << "  ================================\n";
    cout << "      " << monthNames[month - 1] << " " << year << "\n";
    cout << "  ================================\n";
    cout << "   Su  Mo  Tu  We  Th  Fr  Sa\n";
    cout << "  --------------------------------\n";

    int startDay    = getStartDay(month, year);
    int totalDays   = getDaysInMonth(month, year);

    // Print leading spaces for the first week
    cout << "  ";
    for (int i = 0; i < startDay; i++) {
        cout << "    ";
    }

    // Print each day
    for (int day = 1; day <= totalDays; day++) {
        cout << setw(4) << day;
        // Move to the next line after Saturday (column 6)
        if ((day + startDay) % 7 == 0) {
            cout << "\n  ";
        }
    }

    cout << "\n  ================================\n\n";
}

int main() {
    int month, year;

    cout << "========================================\n";
    cout << "          Simple C++ Calendar           \n";
    cout << "========================================\n";

    cout << "Enter month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a value between 1 and 12.\n";
        return 1;
    }

    cout << "Enter year (e.g. 2025): ";
    cin >> year;

    if (year < 1) {
        cout << "Invalid year!\n";
        return 1;
    }

    printCalendar(month, year);

    return 0;
}