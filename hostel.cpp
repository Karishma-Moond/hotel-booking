#include <iostream>
#include <vector>
#include <string>

class Hostel {
public:
    Hostel(const std::string& name, int capacity) : name(name), capacity(capacity), available(capacity) {}

    std::string getName() const {
        return name;
    }

    int getCapacity() const {
        return capacity;
    }

    int getAvailable() const {
        return available;
    }

    void bookRoom() {
        if (available > 0) {
            available--;
            std::cout << "Room booked successfully!" << std::endl;
        } else {
            std::cout << "No rooms available." << std::endl;
        }
    }

    void checkoutRoom() {
        if (available < capacity) {
            available++;
            std::cout << "Room checked out successfully!" << std::endl;
        } else {
            std::cout << "No rooms to check out." << std::endl;
        }
    }

private:
    std::string name;
    int capacity;
    int available;
};

class HostelBookingSystem {
public:
    void addHostel(const std::string& name, int capacity) {
        hostels.push_back(Hostel(name, capacity));
    }

    void listHostels() {
        std::cout << "Available Hostels:" << std::endl;
        for (const Hostel& hostel : hostels) {
            std::cout << "Name: " << hostel.getName() << ", Capacity: " << hostel.getCapacity()
                      << ", Available: " << hostel.getAvailable() << std::endl;
        }
    }

    void bookRoom(int hostelIndex) {
        if (hostelIndex >= 0 && hostelIndex < hostels.size()) {
            hostels[hostelIndex].bookRoom();
        } else {
            std::cout << "Invalid hostel index." << std::endl;
        }
    }

    void checkoutRoom(int hostelIndex) {
        if (hostelIndex >= 0 && hostelIndex < hostels.size()) {
            hostels[hostelIndex].checkoutRoom();
        } else {
            std::cout << "Invalid hostel index." << std::endl;
        }
    }

private:
    std::vector<Hostel> hostels;
};

int main() {
    HostelBookingSystem bookingSystem;

    bookingSystem.addHostel("Hostel A", 10);
    bookingSystem.addHostel("Hostel B", 15);

    int choice;
    do {
        std::cout << "Hostel Booking System" << std::endl;
        std::cout << "1. List Hostels" << std::endl;
        std::cout << "2. Book a Room" << std::endl;
        std::cout << "3. Check Out a Room" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.listHostels();
                break;
            case 2:
                int bookChoice;
                std::cout << "Enter the hostel index to book a room: ";
                std::cin >> bookChoice;
                bookingSystem.bookRoom(bookChoice);
                break;
            case 3:
                int checkoutChoice;
                std::cout << "Enter the hostel index to check out a room: ";
                std::cin >> checkoutChoice;
                bookingSystem.checkoutRoom(checkoutChoice);
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
