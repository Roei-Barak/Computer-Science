#pragma once
class employee
{
public:
	/*void setEmployee(int ID, char name[21], float hourlyWage, int workHours, float income);*/
	void setEmployeeID(int ID);
	void setEmployeeName(char name[21]);
	void setEmployeeHourlyWage(float hourlyWage);
	void setEmployeeWorkHours(int workHours);
	void setEmployeeIncome(float income);
	int getEmployeeID();
	char* getEmployeeName();
	float getEmployeeHourlyWage();
	int getEmployeeWorkHours();
	float getEmployeeIncome();
	int salary();

private:
	int ID;
	char name[21]; 
	float hourlyWage;
	int workHours;
	float income;
};
