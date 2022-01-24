#include <stdio.h>

//Set Up Structure
typedef struct
{
	char name[40];
	int companyReg, companyVAT;
	float averageSales[12];
}company;

void main()
{
	//Variables
	int input;
	float averSales, sales;

	//Ask user how many companys they wish to enter
	printf("Please Enter the amount of companies you wish to enter:\t");
	scanf("%d", &input);

	//Only need to display info dont need to store
	company company;

	//Reading into group
	for (int i = 1; i <= input; i++)
	{
		sales = 0;
		averSales = 0;

		printf("Please Enter Company %ds Name:\t", i);
		scanf("%s", company.name); 

		printf("Please Enter Company %ds Registration Number:\t", i);
		scanf("%d", &company.companyReg);

		printf("Please Enter Company %ds VAT Number:\t", i);
		scanf("%d", &company.companyVAT);

		for (int j = 0; j < 12; j++)
		{
			printf("Please Enter Company %ds Average Sales for month %d:\t", i, (j+1));
			scanf("%f", &company.averageSales[j]);

			sales += company.averageSales[j];
		}

		averSales = sales / 12;

		//Display
		printf("\n\nCompanies Name: %s\nCompanies Reg: %d\nCompanies VAT Number: %d\nTotal Average Sales: %,.2f\n\n", 
			company.name, company.companyReg, company.companyVAT, averSales);
	
		//Print to file
		FILE* companyDetails;
		companyDetails = fopen("Companies.txt", "a");

		fprintf(companyDetails, "\n\nCompanies Name: %s\nCompanies Reg: %d\nCompanies VAT Number: %d\nTotal Average Sales: %,.2f\n\n", 
			company.name, company.companyReg, company.companyVAT, averSales);
	
		fclose(companyDetails);
	}
}