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

        printf("Enter the des:\n");
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
        
        fprintf(fp,"\n %d \t\t\t\t %s \t\t\t\t %s \t\t\t\t %s \t\t\t\t %s \t\t\t\t %d \t\t\t\t\t %d \t\t\t\t\t %d \n\n",
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

void deleterecords() {

    int deleteid;

    printf("Enter the employee's id of which you want to delete the record:\n");
    scanf("%d",&deleteid);

    FILE *fp = fopen("employee_details.txt", "r");
    FILE *temp = fopen("temp_employee_details.txt", "w");

    struct Employee emp;

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id != deleteid) {
            fwrite(&emp, sizeof(struct Employee), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employee_details.txt");
    rename("temp_employee_details.txt", "employee_details.txt");

    printf("Employee with ID %d deleted successfully.\n", deleteid);
}




int main(){

    int choice;
    
    printf("\t\tWelcome to our program.");

    while(1){
    printf("\n\n What do you wish to do? \n1.Enter Employee Records.\n2.Display all the Employee records.\n3.Delete an Employee Record.\n4.Exit.\n\n");

    printf("\n\nSelect your choice: ");
    scanf("%d",&choice);

   
    switch(choice){

        case 1: enteremployee();
                break;
        case 2: displayinfo();
                break;  
        case 3: deleterecords();
                break;
        case 4: return 0;       
    }    

    }
   
}
