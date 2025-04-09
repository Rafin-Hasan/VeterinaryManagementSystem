#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Pet {
private:
    std::string name;
    std::string breed;
    int age;
    bool vaccinated;
    std::vector<std::string> medicalHistory;

public:
    Pet(std::string n, std::string b, int a, bool v)
        : name(n), breed(b), age(a), vaccinated(v) {
    }

    void addMedicalRecord(std::string record) {
        medicalHistory.push_back(record);
    }

    void displayPetInfo() {
        std::cout << "Pet Name: " << name << std::endl;
        std::cout << "Breed: " << breed << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Vaccinated: " << (vaccinated ? "Yes" : "No") << std::endl;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Save pet data to file
    void saveToFile(std::ofstream& file) {
        file << name << "," << breed << "," << age << "," << vaccinated << std::endl;
    }
};

class Owner {
private:
    std::string name;
    std::string address;
    std::string phone;
    std::string email;

public:
    Owner(std::string n, std::string a, std::string p, std::string e)
        : name(n), address(a), phone(p), email(e) {
    }

    void displayOwnerInfo() {
        std::cout << "Owner Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Email: " << email << std::endl;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Save owner data to file
    void saveToFile(std::ofstream& file) {
        file << name << "," << address << "," << phone << "," << email << std::endl;
    }
};

class Appointment {
private:
    std::string date;
    std::string time;
    Pet* pet;
    Owner* owner;
    std::string status;

public:
    Appointment(std::string d, std::string t, Pet* p, Owner* o)
        : date(d), time(t), pet(p), owner(o), status("Scheduled") {
    }

    void displayAppointmentDetails() {
        std::cout << "Appointment Date: " << date << std::endl;
        std::cout << "Appointment Time: " << time << std::endl;
        std::cout << "Status: " << status << std::endl;
        pet->displayPetInfo();
        owner->displayOwnerInfo();
    }

    void cancelAppointment() {
        status = "Cancelled";
    }

    void completeAppointment() {
        status = "Completed";
    }

    // Save appointment details to file
    void saveToFile(std::ofstream& file) {
        file << date << "," << time << "," << pet->getName() << "," << owner->getName() << "," << status << std::endl;
    }
};

// Function to show the menu
void showMenu() {
    std::cout << "1. Add Pet\n";
    std::cout << "2. Add Owner\n";
    std::cout << "3. Schedule Appointment\n";
    std::cout << "4. View Appointments\n";
    std::cout << "5. Exit\n";
}

int main() {
    int choice;
    std::vector<Pet> pets;
    std::vector<Owner> owners;
    std::vector<Appointment> appointments;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string name, breed;
            int age;
            bool vaccinated;
            std::cout << "Enter pet details:\n";
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Breed: "; std::cin >> breed;
            std::cout << "Age: "; std::cin >> age;
            std::cout << "Vaccinated (1 for Yes, 0 for No): "; std::cin >> vaccinated;

            Pet newPet(name, breed, age, vaccinated);
            pets.push_back(newPet);
        }
        else if (choice == 2) {
            std::string name, address, phone, email;
            std::cout << "Enter owner details:\n";
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Address: "; std::cin >> address;
            std::cout << "Phone: "; std::cin >> phone;
            std::cout << "Email: "; std::cin >> email;

            Owner newOwner(name, address, phone, email);
            owners.push_back(newOwner);
        }
        else if (choice == 3) {
            // For simplicity, assume first pet and first owner are selected for appointment
            std::string date, time;
            std::cout << "Enter appointment date and time:\n";
            std::cout << "Date: "; std::cin >> date;
            std::cout << "Time: "; std::cin >> time;

            Appointment newAppointment(date, time, &pets[0], &owners[0]);
            appointments.push_back(newAppointment);
        }
        else if (choice == 4) {
            for (auto& app : appointments) {
                app.displayAppointmentDetails();
            }
        }
        else if (choice == 5) {
            break;
        }
    }

    // Save data to files at the end of program
    std::ofstream petFile("pets.txt");
    std::ofstream ownerFile("owners.txt");
    std::ofstream appointmentFile("appointments.txt");

    for (auto& pet : pets) pet.saveToFile(petFile);
    for (auto& owner : owners) owner.saveToFile(ownerFile);
    for (auto& appointment : appointments) appointment.saveToFile(appointmentFile);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Pet {
private:
    std::string name;
    std::string breed;
    int age;
    bool vaccinated;

public:
    Pet(std::string n, std::string b, int a, bool v)
        : name(n), breed(b), age(a), vaccinated(v) {
    }

    void displayPetInfo() {
        std::cout << "Pet Name: " << name << std::endl;
        std::cout << "Breed: " << breed << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Vaccinated: " << (vaccinated ? "Yes" : "No") << std::endl;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Save pet data to file
    void saveToFile(std::ofstream& file) {
        file << name << "," << breed << "," << age << "," << vaccinated << std::endl;
    }
};

class Owner {
private:
    std::string name;
    std::string address;
    std::string phone;
    std::string email;

public:
    Owner(std::string n, std::string a, std::string p, std::string e)
        : name(n), address(a), phone(p), email(e) {
    }

    void displayOwnerInfo() {
        std::cout << "Owner Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone: " << phone << std::endl;
        std::cout << "Email: " << email << std::endl;
    }

    // Getter for name
    std::string getName() {
        return name;
    }

    // Save owner data to file
    void saveToFile(std::ofstream& file) {
        file << name << "," << address << "," << phone << "," << email << std::endl;
    }
};

class Appointment {
private:
    std::string date;
    std::string time;
    Pet* pet;
    Owner* owner;
    std::string status;

public:
    Appointment(std::string d, std::string t, Pet* p, Owner* o)
        : date(d), time(t), pet(p), owner(o), status("Scheduled") {
    }

    void displayAppointmentDetails() {
        std::cout << "Appointment Date: " << date << std::endl;
        std::cout << "Appointment Time: " << time << std::endl;
        std::cout << "Status: " << status << std::endl;
        pet->displayPetInfo();
        owner->displayOwnerInfo();
    }

    void cancelAppointment() {
        status = "Cancelled";
    }

    void completeAppointment() {
        status = "Completed";
    }

    // Save appointment details to file
    void saveToFile(std::ofstream& file) {
        file << date << "," << time << "," << pet->getName() << "," << owner->getName() << "," << status << std::endl;
    }
};

// Function to show the menu
void showMenu() {
    std::cout << "1. Add Pet\n";
    std::cout << "2. Add Owner\n";
    std::cout << "3. Schedule Appointment\n";
    std::cout << "4. View Appointments\n";
    std::cout << "5. Exit\n";
}

int main() {
    int choice;
    std::vector<Pet> pets;
    std::vector<Owner> owners;
    std::vector<Appointment> appointments;

    // Read data from files when the program starts
    std::ifstream petFile("pets.txt");
    std::ifstream ownerFile("owners.txt");
    std::ifstream appointmentFile("appointments.txt");

    std::string name, breed, address, phone, email, date, time;
    int age;
    bool vaccinated;

    // Load pet data from file
    while (std::getline(petFile, name, ',') && std::getline(petFile, breed, ',') &&
        (petFile >> age >> vaccinated)) {
        Pet pet(name, breed, age, vaccinated);
        pets.push_back(pet);
        petFile.ignore();  // Ignore newline after reading a pet
    }

    // Load owner data from file
    while (std::getline(ownerFile, name, ',') && std::getline(ownerFile, address, ',') &&
        std::getline(ownerFile, phone, ',') && std::getline(ownerFile, email)) {
        Owner owner(name, address, phone, email);
        owners.push_back(owner);
    }

    // Load appointment data from file
    while (std::getline(appointmentFile, date, ',') && std::getline(appointmentFile, time, ',')) {
        // Here, we will assume the first pet and first owner are linked for simplicity
        Appointment appointment(date, time, &pets[0], &owners[0]);
        appointments.push_back(appointment);
    }

    petFile.close();  // Close the pet file
    ownerFile.close();  // Close the owner file
    appointmentFile.close();  // Close the appointment file

    // Menu loop
    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter pet details:\n";
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Breed: "; std::cin >> breed;
            std::cout << "Age: "; std::cin >> age;
            std::cout << "Vaccinated (1 for Yes, 0 for No): "; std::cin >> vaccinated;

            Pet newPet(name, breed, age, vaccinated);
            pets.push_back(newPet);
        }
        else if (choice == 2) {
            std::cout << "Enter owner details:\n";
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Address: "; std::cin >> address;
            std::cout << "Phone: "; std::cin >> phone;
            std::cout << "Email: "; std::cin >> email;

            Owner newOwner(name, address, phone, email);
            owners.push_back(newOwner);
        }
        else if (choice == 3) {
            if (pets.empty() || owners.empty()) {
                std::cout << "Error: No pets or owners available. Please add a pet and owner first.\n";
            }
            else {
                std::cout << "Enter appointment date and time:\n";
                std::cout << "Date: "; std::cin >> date;
                std::cout << "Time: "; std::cin >> time;

                Appointment newAppointment(date, time, &pets[0], &owners[0]);
                appointments.push_back(newAppointment);
            }
        }
        else if (choice == 4) {
            for (auto& app : appointments) {
                app.displayAppointmentDetails();
            }
        }
        else if (choice == 5) {
            break;
        }
    }

    // Save data to files at the end of program
    std::ofstream petFileOut("pets.txt");
    std::ofstream ownerFileOut("owners.txt");
    std::ofstream appointmentFileOut("appointments.txt");

    for (auto& pet : pets) pet.saveToFile(petFileOut);
    for (auto& owner : owners) owner.saveToFile(ownerFileOut);
    for (auto& appointment : appointments) appointment.saveToFile(appointmentFileOut);

    petFileOut.close();  // Close the pet file
    ownerFileOut.close();  // Close the owner file
    appointmentFileOut.close();  // Close the appointment file

    return 0;
}
