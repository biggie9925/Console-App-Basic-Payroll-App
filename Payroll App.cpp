// Payroll App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


double totalGrossPaid;
double totalTaxDeducted;
double totalNetPaid;
double overtime;
string input;
bool loop = true;


struct Week {
	string weekStartDate;
	string weekEndDate;
};


struct Employee {
	int employeeID;
	string employeeName;
	string address;
	string phoneNumber;
	string emailAddress;
	string IRDnumber;
	string taxCode;
	double hoursWorked;
	double hourlyRate;
	double grossWeeklyPay;
	double salary;
	double taxRate;
	double taxRateCalculator;
	double taxDeducted;
	double netWeeklyPay;
};


double taxrateFunction(double salary) {

	if (salary > 180000) {
		return 0.39;
	}

	else if (salary > 70000) {
		return 0.33;
	}

	else if (salary > 48000) {
		return 0.30;
	}

	else if (salary > 14000) {
		return 0.175;
	}

	else {
		return 0.105;
	}
}



double overtimeFunction(double hoursWorked, double hourlyRate) {

	double standard = 40 * hourlyRate;
	overtime = ((hoursWorked - 40) * hourlyRate) * 1.5;
	return standard + overtime;

}


double reportsFunction() {

	cout << "\n*************************************************\n\n";
	cout << "\t\tWeekly Statistics\n";
	cout << "\n*************************************************\n\n";
	cout << "Total Amount paid in Gross Pay: " << totalGrossPaid << endl;
	cout << "Total Amount deducted in Tax: " << totalTaxDeducted << endl;
	cout << "Total Amount paid in Net Pay: " << totalNetPaid << endl;
	return 0;
}


int main()
{
	Week week[5];

	for (int x = 0; x < 5; x++) {

		cout << "Enter Week Start Date: ";
		Week week;
		cin >> week.weekStartDate;
		cout << "Enter Week End Date: ";
		cin >> week.weekEndDate;
		cout << "\n*************************************************\n";

		Employee employee[5];

		for (int i = 0; i < 5; i++) {


			cout << "\nEnter information for Employee # " << i + 1 << ":\n";
			Employee employee;
			cout << "\n*************************************************\n\n";
			cout << "Enter Employee ID: ";
			cin >> employee.employeeID;
			cin.ignore();
			cout << "Enter Employee Name: ";
			getline(cin, employee.employeeName);
			cout << "Enter Street Address: ";
			getline(cin, employee.address);
			cout << "Enter Phone Number: ";
			getline(cin, employee.phoneNumber);
			cout << "Enter Email Address: ";
			cin >> employee.emailAddress;
			cin.ignore();
			cout << "Enter IRD number: ";
			getline(cin, employee.IRDnumber);
			cout << "Enter Tax Code: ";
			getline(cin, employee.taxCode);
			cout << "Enter Hours Worked (between 1 - 49 hours only):";
			cin >> employee.hoursWorked;

			if (employee.hoursWorked < 1 || employee.hoursWorked > 49) {
				while (loop) {
					cout << "Sorry, incorrect, Please enter Hours Worked (must be between 1 - 49 hours only): ";
					cin >> employee.hoursWorked;
					if (employee.hoursWorked >= 1 && employee.hoursWorked <= 49) {
						break;
					}
				}
			}

			cout << "Enter Hourly Rate: ";
			cin >> employee.hourlyRate;

			if (employee.hoursWorked > 40) {
				employee.grossWeeklyPay = overtimeFunction(employee.hoursWorked, employee.hourlyRate);
			}

			else
				employee.grossWeeklyPay = employee.hoursWorked * employee.hourlyRate;

			employee.salary = employee.grossWeeklyPay * 52;

			double taxrate = taxrateFunction(employee.salary);

			employee.taxDeducted = employee.grossWeeklyPay * taxrate;
			employee.netWeeklyPay = employee.grossWeeklyPay - employee.taxDeducted;
			cout << "Employee " << i + 1 << " gross weekly pay : " << employee.grossWeeklyPay << endl;
			cout << "Employee " << i + 1 << " tax deduction is : " << employee.taxDeducted << endl;
			cout << "Employee " << i + 1 << " net weekly pay : " << employee.netWeeklyPay << endl;
			totalGrossPaid = totalGrossPaid + employee.grossWeeklyPay;
			totalTaxDeducted = totalTaxDeducted + employee.taxDeducted;
			totalNetPaid = totalNetPaid + employee.netWeeklyPay;

			cout << "Enter another employee? (y/n) ";
			cin >> input;
			if (input == "y" || input == "Y") {
				continue;
			}

			cout << "\nWould you like to see this weeks payslips? (y/n)\n";
			cin >> input;
			if (input == "y" || input == "Y") {
				cout << "\n*************************************************\n\n";
				cout << "Payslip for week starting on " << week.weekStartDate << " and ending on " << week.weekEndDate << endl;
				cout << "\n*************************************************\n\n";
				for (int j = 0; j <= i; j++) {
					cout << "Employee ID \t:" << employee.employeeID << endl;
					cout << "Name\t\t:" << employee.employeeName << endl;
					cout << "Address\t\t:" << employee.address << endl;
					cout << "Phone\t\t:" << employee.phoneNumber << endl;
					cout << "Email\t\t:" << employee.emailAddress << endl;
					cout << "IRD Number\t:" << employee.IRDnumber << endl;
					cout << "Tax Code\t:" << employee.taxCode << endl;
					cout << "Hours Worked\t:" << employee.hoursWorked << endl;
					cout << "Hourly Rate\t:" << employee.hourlyRate << endl;
					if (employee.hoursWorked > 40) {
						cout << "Overtime Pay\t:" << overtime << endl;
					}
					cout << "Tax Rate\t:" << taxrate << endl;
					cout << "Gross Pay\t:" << employee.grossWeeklyPay << endl;
					cout << "Tax Deducted\t:" << employee.taxDeducted << endl;
					cout << "Net Pay\t\t:" << employee.netWeeklyPay << "\n\n";
				}
				break;
			}

			else
				break;
		};



		cout << "\nWould you like to see this weeks report? (y/n)\n";
		cin >> input;
		if (input == "y" || input == "Y") {
			reportsFunction();
		}

		cout << "Would you like to enter another week? (y/n) ";
		cin >> input;
		if (input == "y" || input == "Y") {
			continue;
		}

		else
			break;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
