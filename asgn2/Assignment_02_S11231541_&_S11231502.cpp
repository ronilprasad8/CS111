/*
Student Name: Ronil Prasad; Shivan Siddharat Prasad.
Student ID: S11231541; S11231502.
Tutorial Group: Tuesday 11am-1pm.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_RECORDS = 300; // Maximum number of records
const int NUMRECS = 8;       // Number of records to process

// Structure to hold student data
struct Student {
    string id;
    string name;
    double totalMarks;
    double mathMarks;
    double scienceMarks;
    double englishMarks;
};

//Function prototype
void displayMenu();
void displayRecords(Student students[], int numRecords);
void searchStudent(Student students[], int numRecords, const string& studentId);
void calculateTotalMarks(Student students[], int numRecords);
bool compareByTotalMarks(const Student& student1, const Student& student2);
void sortRecordsByTotalMarks(Student students[], int numRecords);
void writeReportToFile(Student students[], int numRecords);

int main() {
	
    Student students[MAX_RECORDS];
    int numRecords = 0;
    char choice, choice2;

    ifstream inputFile("studentmarks.txt");
    
	// Open the input file and read student data
    if (inputFile.is_open()) {
        string line;

		// Read and parse each line of the file
        while (getline(inputFile, line)) {
            istringstream iss(line);
            iss >> students[numRecords].id >> students[numRecords].name >> students[numRecords].mathMarks >>
			students[numRecords].scienceMarks >> students[numRecords].englishMarks;
            numRecords++;
        }

        inputFile.close();//colse file after reading in the data
    } else {
        cout << "Error opening input file." << endl;
        return 0;
    }

	// Main menu loop
    do {
        displayMenu();
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            string not_an_int;
			cin>>not_an_int;
        }
		cout << "================================" <<endl<<endl;
            if (choice=='1'){
                cout << "=== STUDENT RECORDS ===" << endl;
                displayRecords(students, numRecords);
            }
            else if (choice=='2') {
                string studentId;
                bool found = false;
                while (!found) {
                    cout << "Enter student ID: ";
                    cin >> studentId;

                    for (int i = 0; i < numRecords; i++) {
                        if (students[i].id == studentId) {
                            cout << "=== STUDENT DETAILS ===" << endl;
                            searchStudent(students, numRecords, studentId);
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Student not found. Please try again." << endl;
                    }
                }
            }
            else if(choice=='3'){
            	calculateTotalMarks(students, numRecords);
            	displayMenu();
            	cin>>choice2;
            	if (choice2=='4'){
            		sortRecordsByTotalMarks(students, numRecords);
            		bool compareByTotalMarks(const Student& student1, const Student& student2);
				}
				else if(choice2=='5'){
					writeReportToFile(students, numRecords);
				}
            }
            else if (choice=='4'||choice=='5'){
            	cout<<"Please choose option 3 first"<<endl;	
            }
            else if (choice=='Q'||choice=='q'){
                cout << "=== EXIT ===" << endl;
                return 'Q';
            }
            else{
                cout << "Invalid choice. Please try again." << endl;
            }
        }while (choice != 'Q'||choice != 'q');

    return 0;
}

// Function to display menu.
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1) Print the Entire List" << endl;
    cout << "2) Print Details of Student Matching a Given ID" << endl;
    cout << "3) Calculate Total and Print Entire List with Total" << endl;
    cout << "4) Print List Sorted by Total" << endl;
    cout << "5) Write Report to File" << endl;
    cout << "6) Exit program(Press Q/q to exit)" << endl;
    cout << "Enter your choice: ";
}

// Function to display all records.
void displayRecords(Student students[], int numRecords) {
    for (int i = 1; i < numRecords; i++) {
        cout << "Student ID: " << students[i].id << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "Math Marks: " << students[i].mathMarks << endl;
        cout << "Science Marks: " << students[i].scienceMarks << endl;
        cout << "English Marks: " << students[i].englishMarks << endl;
        cout << endl;
    }
    cout << "==============================" <<endl<<endl;
}

// Function to Print Details of Student Matching a Given ID
void searchStudent(Student students[], int numRecords, const string& studentId) {
    for (int i = 1; i < numRecords; i++) {
        if (students[i].id == studentId) {
            cout << "Student ID: " << students[i].id << endl;
            cout << "Student Name: " << students[i].name << endl;
            cout << "Math Marks: " << students[i].mathMarks << endl;
            cout << "Science Marks: " << students[i].scienceMarks << endl;
            cout << "English Marks: " << students[i].englishMarks << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Function to Calculate Total and Print Entire List with Total
void calculateTotalMarks(Student students[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        students[i].totalMarks = students[i].mathMarks + students[i].scienceMarks + students[i].englishMarks;
    }

    cout << "=== STUDENT RECORDS WITH TOTAL MARKS ===" << endl;
    for (int i = 1; i < numRecords; i++) {
        cout << "Student ID: " << students[i].id << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "Math Marks: " << students[i].mathMarks << endl;
        cout << "Science Marks: " << students[i].scienceMarks << endl;
        cout << "English Marks: " << students[i].englishMarks << endl;
        cout << "Total Marks: " << students[i].totalMarks << endl;
        cout << endl;
    }
    cout << "==============================" <<endl<<endl;
}

// Function to Print List Sorted by Total
bool compareByTotalMarks(const Student& student1, const Student& student2) {
    return student1.totalMarks > student2.totalMarks;
}

void sortRecordsByTotalMarks(Student students[], int numRecords) {
    sort(students, students + numRecords, compareByTotalMarks);

    cout << "=== STUDENT RECORDS SORTED BY TOTAL MARKS ===" << endl;
    for (int i = 0; i < NUMRECS; i++) {
        students[i].totalMarks = students[i].mathMarks + students[i].scienceMarks + students[i].englishMarks;

        cout << "Student ID: " << students[i].id << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "Math Marks: " << students[i].mathMarks << endl;
        cout << "Science Marks: " << students[i].scienceMarks << endl;
        cout << "English Marks: " << students[i].englishMarks << endl;
        cout << "Total Marks: " << students[i].totalMarks << endl;
        cout << endl;
    }
    cout << "==============================" <<endl<<endl;
}

//Function to Write Report to File
void writeReportToFile(Student students[], int numRecords) {
	double mathSum = 0.0;
    double scienceSum = 0.0;
    double englishSum = 0.0;
    double totalSum = 0.0;
    double mathAvg = 0.0, scienceAvg = 0.0, englishAvg = 0.0, totalAvg = 0.0;
    ofstream outputFile;
    outputFile.open("summary.txt");
    if (outputFile.is_open()) {

    // Sort the students based on total marks
    for (int i = 0; i < NUMRECS; i++) {
        for (int j = 0; j < NUMRECS - i; j++) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                // Swap students[j] and students[j + 1]
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Calculate the class average marks for each subjects and total
    for (int i = 0; i < NUMRECS; i++) {
        mathSum = mathSum + students[i].mathMarks;
        scienceSum = scienceSum + students[i].scienceMarks;
        englishSum = englishSum + students[i].englishMarks;
        totalSum = totalSum + students[i].totalMarks;
    }
    mathAvg = mathSum/NUMRECS;
    scienceAvg = scienceSum/NUMRECS;
    englishAvg = englishSum/NUMRECS;
    totalAvg = totalSum/NUMRECS;

    // Find the highest and lowest total marks and corresponding student details
    int highestIndex = 0, lowestIndex = 0;
    for (int i = 0; i < NUMRECS; i++) {
        if (students[i].totalMarks > students[highestIndex].totalMarks) {
            highestIndex = i;
        }
        if (students[i].totalMarks < students[lowestIndex].totalMarks) {
            lowestIndex = i;
        }
    }

    // Write the report to the output file
    outputFile << "Student Report" << endl;
    outputFile << endl;

    outputFile << "Rank \tName\t Math\tScience\tEnglish\t Total" << endl;
    outputFile << "----------------------------------------------" << endl;
    for (int i = 0; i < NUMRECS; i++) {
        outputFile << i + 1 <<" "<< setw(10) << students[i].name << "\t"
            << setw(5) << students[i].mathMarks << "\t" << setw(7) << students[i].scienceMarks << "\t"
            << setw(7) << students[i].englishMarks << "\t" << setw(6) << students[i].totalMarks << endl;
    }
    outputFile << "----------------------------------------------" << endl << endl;

    outputFile << "Class Average Marks" << endl;
    outputFile << "Math: " << mathAvg << endl;
    outputFile << "Science: " << scienceAvg << endl;
    outputFile << "English: " << englishAvg << endl;
    outputFile << "Total: " << totalAvg << endl << endl;

    outputFile << "Highest Total Marks: " << students[highestIndex].totalMarks << endl;
    outputFile << "Student: " << students[highestIndex].name << endl << endl;

    outputFile << "Lowest Total Marks: " << students[lowestIndex].totalMarks << endl;
    outputFile << "Student: " << students[lowestIndex].name << endl <<endl;

    outputFile.close();

    cout << "Report generated successfully." << endl;
    cout << "==============================" <<endl<<endl;
	}
	else {
		cout << "Failed to open output file." << endl;
	}
}

