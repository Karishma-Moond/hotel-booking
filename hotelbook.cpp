#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
public:
    int roomNumber;
    string roomType;
    double price;
    bool isOccupied;

    Room(int number, string type, double p) : roomNumber(number), roomType(type), price(p), isOccupied(false) {}
};

class Hotel {
public:
    string name;
    vector<Room> rooms;

    Hotel(string hotelName) : name(hotelName) {}

    void addRoom(int number, string type, double price) {
        rooms.push_back(Room(number, type, price));
    }

    void displayAvailableRooms() {
        cout << "Available Rooms in " << name << ":" << endl;
        for (const Room& room : rooms) {
            if (!room.isOccupied) {
                cout << "Room " << room.roomNumber << " - Type: " << room.roomType << " - Price: $" << room.price << "/night" << endl;
            }
        }
    }
};

class Booking {
public:
    string customerName;
    int roomNumber;
    int numberOfNights;

    Booking(string name, int room, int nights) : customerName(name), roomNumber(room), numberOfNights(nights) {}
};

int main() {
    Hotel hotel("Sample Hotel");
    hotel.addRoom(101, "Single", 100.0);
    hotel.addRoom(102, "Double", 150.0);
    hotel.addRoom(103, "Suite", 250.0);

    vector<Booking> bookings;

    while (true) {
        cout << "Hotel Booking System" << endl;
        cout << "1. Display Available Rooms" << endl;
        cout << "2. Make a Booking" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2: {
                string name;
                int room;
                int nights;

                cout << "Enter your name: ";
                cin >> name;

                cout << "Enter the room number you want to book: ";
                cin >> room;

                bool roomExists = false;

                for (Room& r : hotel.rooms) {
                    if (r.roomNumber == room) {
                        roomExists = true;

                        if (r.isOccupied) {
                            cout << "Room is already occupied." << endl;
                        } else {
                            cout << "Enter the number of nights: ";
                            cin >> nights;

                            r.isOccupied = true;
                            bookings.push_back(Booking(name, room, nights));
                            cout << "Booking successful!" << endl;
                        }
                    }
                }

                if (!roomExists) {
                    cout << "Invalid room number." << endl;
                }
                break;
            }
            case 3:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
