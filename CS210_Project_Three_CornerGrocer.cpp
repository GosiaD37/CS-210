#include <iostream> 
#include <map>
#include <fstream>
#include <string>

using namespace std;

class GroceryTracker {

private:
	map < string, int> itemFrequency; // Map to store item frequencies

public:
	// Function to read data from input file and populate itemFrequency map
	void readDataFromFile(const string& filename) {
		ifstream file(filename);
		if (file.is_open()) {
			string item;
			while (file >> item) {
				itemFrequency[item]++;
			}
			file.close();
		}
		else {
			cout << "Unable to open file: " << filename << endl;
		}
	}
	//Function to print frequency of a specific item
	void printItemFrequency(const string& item) {
		cout << "Frequency of " << item << " :" << itemFrequency[item] << endl;
	}
	//Function to print frequency of all the items
	void printAllItemFrequency() {
		for (const auto& pair : itemFrequency) {
			cout << pair.first << " " << pair.second << endl;
		}
	}
	//Function to print histogram of item frequencies
	void printItemHistogram() {
		for (const auto& pair : itemFrequency) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
				cout << " *";
			}
			cout << endl;
		}
	}
	//Function to backup data to a file
	void backupData(const string& filename) {
		ofstream file(filename);
		if (file.is_open()) {
			for (const auto& pair : itemFrequency) {
				file << pair.first << " " << pair.second << endl;
			}
			file.close();
		}
		else {
			cout << " Unable to create backup file." << endl;
		}
	}
};
int main() {
	GroceryTracker tracker;
	tracker.readDataFromFile("CS210_Project_Three_Input_File.text");
	int choice;
	do {
		cout << "Menu:\n"
			<< "1. Search for an item\n"
			<< "2. Print frequency of all items\n"
			<< "3. Print item frequency histogram\n"
			<< "4. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			string item;
			cout << "Enter item to search for:";
			cin >> item;
			tracker.printItemFrequency(item);
			break;
		}
		case 2:
			tracker.printAllItemFrequency();
			break;
		case 3:
			tracker.printItemHistogram();
			break;
		case 4:
			tracker.backupData("frequency.dat");
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please enter a number between 1 and 4.\n";
		}
	} while (choice != 4);
	return 0;
}

		

