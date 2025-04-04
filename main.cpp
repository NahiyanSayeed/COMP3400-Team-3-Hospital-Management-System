#include <iostream>
#include <vector>
#include <fstream>
#include "hospitals.h"
#include "pharmacies.h"
using namespace std;

//object instances declared for the Hospitals section
Hospitals Windsor("H001", "Windsor Regional Hospital", 20);
Hospitals Erie("H002", "Erie Shore Regional Hospital", 20);
Hospitals Tecumseh("H003", "Tecumseh Regional Hospital", 20);
Hospitals Kingsville("H004", "Kingsville Regional Hospital", 20);
Hospitals Amherstburg("H005", "Amherstburg Regional Hospital", 20);


//function for the hopsitals window
void hospitalsection() {
    std::cout << "\nHospitals Location (100 Patients total)" << "\n";
    int choicev1;
    do {
        std::cout << "1. Windsor Regional Hospital" << "\n";
        std::cout << "2. Erie Shore Regional Hospital" << "\n";
        std::cout << "3. Tecumseh Regional Hospital" << "\n";
        std::cout << "4. Kingsville Regional Hospital" << "\n";
        std::cout << "5. Amherstburg Regional Hospital" << "\n";
        std::cout << "6. Return" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choicev1;

        switch (choicev1) {
            case 1:
                std::cout << "Selected Windsor Regional Hospital" << "\n";
                Windsor.listpatients();
                break;
            case 2:
                std::cout << "Selected Erie Shore Regional Hospital" << "\n";
                Erie.listpatients();
                break;
            case 3:
                std::cout << "Selected Tecumseh Regional Hospital" << "\n";
                Tecumseh.listpatients();
                break;
            case 4:
                std::cout << "Selected Kingsville Regional Hospital" << "\n";
                Kingsville.listpatients();
                break;
            case 5:
                std::cout << "Selected Amherstburg Regional Hospital" << "\n";
                Amherstburg.listpatients();
                break;
            case 6:
                std::cout << "Returning to Hospital Management System..." << "\n";
                return;
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choicev1 !=6);
}

//function to relocate patient
void relocatepatientsection () {
    std::cout << "\nSelect Hospital to Relocate Patient" << "\n";
    int choicev2;
    do {
        std::cout << "1. Windsor Regional Hospital" << "\n";
        std::cout << "2. Erie Shore Regional Hospital" << "\n";
        std::cout << "3. Tecumseh Regional Hospital" << "\n";
        std::cout << "4. Kingsville Regional Hospital" << "\n";
        std::cout << "5. Amherstburg Regional Hospital" << "\n";
        std::cout << "6. Return" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choicev2;
        switch (choicev2) {
            case 1:
                std::cout << "Selected Windsor Regional Hospital" << "\n";
                Windsor.relocatepatient();
                break;
            case 2:
                std::cout << "Selected Erie Shore Regional Hospital" << "\n";
                Erie.relocatepatient();
                break;
            case 3:
                std::cout << "Selected Tecumseh Regional Hospital" << "\n";
                Tecumseh.relocatepatient();
                break;
            case 4:
                std::cout << "Selected Kingsville Regional Hospital" << "\n";
                Kingsville.relocatepatient();
                break;
            case 5:
                std::cout << "Selected Amherstburg Regional Hospital" << "\n";
                Amherstburg.relocatepatient();
                break;
            case 6:
                std::cout << "Returning to Hospital Management System..." << "\n";
                return;
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choicev2 !=6);
}

void pharmaciessection() {
    int hospitalchoice, pharmacychoice, drugchoice;

    Pharmacies::createpharmacies();

    std::cout << "\nSelect Hospital in which the prescription drug will be delivered to:" << "\n";
    std::cout << "1. Windsor Regional Hospital" << "\n";
    std::cout << "2. Erie Shore Regional Hospital" << "\n";
    std::cout << "3. Tecumseh Regional Hospital" << "\n";
    std::cout << "4. Kingsville Regional Hospital" << "\n";
    std::cout << "5. Amherstburg Regional Hospital" << "\n";
    std::cout << "6. Return" << "\n";
    std::cout << "Enter your choice of option: ";
    std::cin >> hospitalchoice;

    if (hospitalchoice == 6) {
        return;
    }

    string hospitalName;
    switch (hospitalchoice) {
        case 1:
            hospitalName = "Windsor Regional Hospital";
            break;
        case 2:
            hospitalName = "Erie Shore Regional Hospital";
            break;
        case 3:
            hospitalName = "Tecumseh Regional Hospital";
            break;
        case 4:
            hospitalName = "Kingsville Regional Hospital";
            break;
        case 5:
            hospitalName = "Amherstburg Regional Hospital";
            break;
        default:
            std::cout << "Invalid selection, returning to main menu" << "\n";
            return;
    }

    std::cout << "\nSelect any of the 20 Pharmacies:" << "\n";
    for (size_t i = 0; i < Pharmacies::pharmacieslist.size(); i++) {
        std::cout << i + 1 << ". " << Pharmacies::pharmacieslist[i] << "\n";
    }
    std::cout << "Enter your choice of Pharmacy: ";
    std::cin >> pharmacychoice;

    if (pharmacychoice < 1 || pharmacychoice > 20) {
        std::cout << "Invalid choice, returning to main menu" << "\n";
        return;
    }

    string pharmacyName = Pharmacies::pharmacieslist[pharmacychoice - 1];

    std::cout << "\nSelect a Prescription Drug that will be delievered:" << "\n";
    for (size_t i = 0; i < Pharmacies::prescriptiondruglist.size(); i++) {
        std::cout << i + 1 << ". " << Pharmacies::prescriptiondruglist[i] << "\n";
    }
    std::cout << "Enter your choice of Prescription Drug: ";
    std::cin >> drugchoice;

    if (drugchoice < 1 || drugchoice > 10) {
        std::cout << "Invalid choice, returning to main menu" << "\n";
        return;
    }

    string drugName = Pharmacies::prescriptiondruglist[drugchoice - 1];

    Pharmacies::Deliver_Meds(hospitalName, pharmacyName, drugName);
    Pharmacies::Bill_Hosp(hospitalName, pharmacyName, drugName);
}

//prints the pharmacybill records that were placed in the pharmacy section
void pharmacybillrecords() {
    ifstream inputfile("pharmacybilling.txt");
    if (!inputfile) {
        std::cout << "No pharmacy billing records found at the moment..." << "\n";
        return;
    }

    if (inputfile.peek() == ifstream::traits_type::eof()) {
        std::cout << "No pharmacy billing records found at the momment..." << "\n";
        inputfile.close();
        return;
    }

    string line;
    std::cout << "\nPharmacy Billing Records" << "\n";
    while (getline(inputfile, line)) {
        std::cout << line << "\n";
    }
    inputfile.close();
}

void patientssection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

void doctorsection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

void nursesection() {
    std::cout << "To be implemented by assgined group member" << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2){
        std::cerr << "Error: please provide a txt file" << "\n";
        return 1;
    }

    string filename = argv[1];

    std::cout << "Loading Hospital Management System..." << "\n";
    std::cout << "Welcome to the Hospital Management System! Developed by Team 3" << "\n";

    Windsor.loadpatients(filename);
    Erie.loadpatients(filename);
    Tecumseh.loadpatients(filename);
    Kingsville.loadpatients(filename);
    Amherstburg.loadpatients(filename);

    int choice;
    do {
        std::cout << "\nHospital Management System" << "\n";
        std::cout << "1. Hospital" << "\n";
        std::cout << "2. Relocate Patient" << "\n";
        std::cout << "3. Pharmacies" << "\n";
        std::cout << "4. Pharmacies Billing Records" << "\n";
        std::cout << "5. Patients" << "\n";
        std::cout << "6. Doctors" << "\n";
        std::cout << "7. Nurses" << "\n";
        std::cout << "8. Exit System" << "\n";
        std::cout << "Enter your choice of option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                hospitalsection();
                break;
            case 2:
                relocatepatientsection();
                break;
            case 3:
                pharmaciessection();
                break;
            case 4:
                pharmacybillrecords();
                break;    
            case 5:
                patientssection();
                break;
            case 6:
                doctorsection();
                break;
            case 7:
                nursesection();
                break;
            case 8:
                std::cout << "Exiting Hospital Management System..." << "\n";
                break;
            default:
                std::cout << "Invalid choice, please enter a valid choice" << "\n";
        }
    } while (choice !=8);
    
    return 0;
}