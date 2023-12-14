#include <stdio.h>
#include <stdlib.h>


struct Employee{                //This declares a struct type containing all information of a employee globally            

    int id;
    char name[55];              
    char designation[30];
    char department[30];
    char doj[10];
    int salary;
    int increment;
    int decrement;
};

void enteremployee(){

    struct Employee *e;
    int i = 0, i1;
    char choice = 'y';
    int count=0;
    printf("Enter how many employee records you want to enter:");
    scanf("%d" , &i1);

    e = (struct Employee *)malloc(i1 * sizeof(struct Employee));

    FILE *fp = fopen("employee_details.txt","a");

    while((choice == 'Y' || choice == 'y') && (i < i1) ){

        printf("Enter the Employee ID:\n");
        scanf("%d",&((e + i))->id);

        printf("Enter the Employee name:\n");
        scanf(" %[^\n]",(e + i)->name);

        printf("Enter the designation:\n");
        scanf(" %[^\n]",(e + i)->designation);

        printf("Enter Employee's department:\n");
        scanf(" %[^\n]",(e + i)->department);

        printf("Enter date of joining of the Employee(DD/MM/YYYY):\n");
        scanf(" %[^\n]",(e + i)->doj);

        printf("Enter the Employee's monthly salary(in rupees):\n");
        scanf("%d",&((e + i))->salary);

        printf("Enter the increment precentage(per annum):\n");
        scanf("%d",&((e + i))->increment);

        printf("Enter the decrement percentage(per annum):\n");
        scanf("%d",&((e + i))->decrement);
        
        fprintf(fp,"Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                        (e + i)->id,(e + i)->name,(e+i)->designation,(e+i)->department,(e+i)->doj,
                        (e+i)->salary,(e+i)->increment,(e+i)->decrement);
        
        i++;
        
         if (i < i1) {
            printf("\nDo you wish to continue (Y/N)? ");
            scanf(" %c", &choice);
            }

    }
	
    fclose(fp);
   
   printf("Employee Record Stored Successfully!!");

}

void displayinfo(){

    FILE *fp = fopen("employee_details.txt","r");
    char ch;


    while((ch = fgetc(fp))!= EOF){
        printf("%c",ch);
    }

    fclose(fp);

}

void deleterecords(int deleteid) {
    FILE *fp = fopen("employee_details.txt", "r");
    FILE *temp= fopen("temp_employee_details.txt", "w");

    struct Employee emp;
   
    while (fscanf(fp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                  &emp.id, emp.name, emp.designation, emp.department,
                  emp.doj, &emp.salary, &emp.increment, &emp.decrement) == 8) {
        if (emp.id != deleteid) {
            fprintf(temp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                    emp.id, emp.name, emp.designation, emp.department,
                    emp.doj, emp.salary, emp.increment, emp.decrement);
        }
    }

    rewind(fp);
    rewind(temp);

    while ((fscanf(temp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                    &emp.id, emp.name, emp.designation, emp.department,
                    emp.doj, &emp.salary, &emp.increment, &emp.decrement) == 8)) {
        fprintf(fp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                emp.id, emp.name, emp.designation, emp.department,
                emp.doj, emp.salary, emp.increment, emp.decrement);
    }

    fclose(fp);
    fclose(temp);

    printf("Employee with ID %d deleted successfully.\n", deleteid);
}


void updaterecord(FILE *file,int updateid){

    FILE *temp = tmpfile();

    struct Employee e1;

    




}



int main(){

    int choice;
    
    printf("\t\tWelcome to our program.");

    while(1){
    printf("\n\n What do you wish to do? \n1.Enter Employee Records.\n2.Display all the Employee records.\n3.Delete an Employee Record.\n4.Update Employee Records.\n5.Exit\n\n");

    printf("\n\nSelect your choice: ");
    scanf("%d",&choice);

   
    switch(choice){

        case 1: enteremployee();
                break;
        case 2: displayinfo();
                break;  

        case 3: 
                int deleteid;
                printf("\nEnter the Employee ID to be deleted:");
                scanf("%d",&deleteid);

                deleterecords(deleteid);
                break;
        case 4: FILE *file = fopen("employee_details.txt","r+");

                int updateid;
                printf("\nEnter the ID of the employee to update records: ");
                scanf("%d", &updateid);
                
                updaterecord(file, updateid);
                break;
        case 5: return 0;       
    }    

    }
   
}
