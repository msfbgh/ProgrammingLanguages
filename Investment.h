/*
 * Project Two Airgead Banking
 *
 */
#ifndef INVESTMENT_H
#define INVESTMENT_H
#include<iostream>
#include<iomanip>
using namespace std;

//class attributes initialInvest, monthlyDeposit, AnnualInterest, months, years, openAmount
class Investment
{
	float initialInvest, monthlyDeposit, AnnualInterest, months, years, openAmount;
	float totalAmount, initialAmount, totalYearInterest;

public:
	void execute()
	{
		//display information to user
		cout << "********************************\n";
		cout << "********** Data Input **********\n";
		//get information from user
		cout << "Initial Investment Amount:$";
		cin >> initialInvest;
		openAmount = initialInvest;
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "Annual Interest: %";
		cin >> AnnualInterest;
		cout << "Number of years: ";
		cin >> years;
		months = years * 12;
		totalAmount = initialInvest;
		//display year data without monthly deposit
		cout << "\nBalance and Interest without Additional Monthly Deposits\n";
		cout << "=================================================================\n";
		cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
		cout << "-----------------------------------------------------------------\n";
		//calculate yearly interest, year end total 
		for (int i = 0; i < years; i++) {
			initialAmount = (totalAmount) * ((AnnualInterest / 100));
			totalAmount = totalAmount + initialAmount;
			cout << setw(4) << (i + 1) << setw(18) << "$" << fixed << setprecision(2) << totalAmount << setw(24) << "$" << initialAmount;
			cout << "\n";
		}
		//set initial investment amount with monthly deposit
		totalAmount = initialInvest;
		cout << "\n\nBalance and Interest with Additional Monthly Deposits\n";
		cout << "==================================================================\n";
		cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
		cout << "------------------------------------------------------------------\n";
		for (int i = 0; i < years; i++) {
			//set yearly interest to zero
			totalYearInterest = 0;
			for (int j = 0; j < 12; j++) {
				initialAmount = (totalAmount + monthlyDeposit) * ((AnnualInterest / 100) / 12);
				//calculate total year interest
				totalYearInterest = totalYearInterest + initialAmount;
				totalAmount = totalAmount + monthlyDeposit + initialAmount;
			}
			cout << right << setw(4) << (i + 1) << right << setw(18) << "$" << fixed << setprecision(2) << left << setw(8) << totalAmount << right << setw(24) << "$" << left << setw(8) << totalYearInterest;
			cout << "\n";
		}
		//display year data with additional monthly deposits
		cout << "\n\nBalance and Interest with Additional Monthly Deposits\n";
		cout << "=============================================================================================================\n";
		cout << "Month\tOpening Amount\tDeposited Amount\t$ Total\t\t$ Interest\t\tClosing Balance\n";
		cout << "-------------------------------------------------------------------------------------------------------------\n";
		float total;
		initialAmount = 0;
		totalAmount = 0;
		//calculate monthly interest
		for (int i = 0; i < months; i++) {
			totalYearInterest = 0;
			initialAmount = ((totalAmount + monthlyDeposit) * ((AnnualInterest / 100) / 12));
			total = openAmount + monthlyDeposit;
			totalAmount = total + initialAmount;
			//Display result totals calculated
			cout << right << setw(4) << (i + 1) << right << setw(8) << fixed << setprecision(2) << "$" << setw(8) << left << openAmount << setw(8) << right << "$"
				<< right << monthlyDeposit << setw(16) << "$" << setw(10) << left << total << right << setw(8) << "$" << left << setw(10) << initialAmount
				<< right << setw(14) << "$" << right << totalAmount;
			cout << "\n";
			openAmount = totalAmount;
		}
	}
};
#endif // !INVESTMENT_H
