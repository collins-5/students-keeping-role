#include <stdio.h>
#include <string.h>

// define a student struct
struct student {
    char name[50];
    int rollno;
    float marks;
    char email[50];
};

// function to add a new student record
void add_student(struct student s[], int n) {
    printf("Enter student name: ");
    scanf("%s", s[n].name);
//confirming the validity of the school email
    int email_exists = 1;
    while (email_exists) {
        printf("Enter email: ");
        scanf("%s", s[n].email);
        if (strstr(s[n].email, "@student.cuk.ac.ke") == NULL) {
            printf("Please enter an email ending with @student.cuk.ac.ke\n");
        } else {
            email_exists = 0;
            for (int j = 0; j < n; j++) {
                if (strcmp(s[n].email, s[j].email) == 0) {
                    printf("This email already exists, please enter another email.\n");
                    email_exists = 1;
                    break;
                }
            }
        }
    }

    printf("Enter roll number: ");
    scanf("%d", &s[n].rollno);

                int unit;
            int c;
            int Totalunits = 8;
            printf("Enter the number of units taken:  ");
            scanf("%d",&c);
            int totalmarks=0;
            if((0<c)&&(c<(Totalunits))){
                for(int i=0;i<c;i++){
                    char unitname[10];
                    int exammark;

                    printf("\n.    Enter unit name: ");
                    scanf("%s",unitname);
                    printf("\n.    Enter the exam mark of the student in the unit: ");
                    scanf("%d",&exammark);
                    totalmarks+=exammark;
                }
            }else { printf("\n.    Ooops! invalid number of units");}
            printf("\naverage marks this semester is: %d",(totalmarks)/c);
    printf("\nEnter average marks for previous semester: ");
    scanf("%f", &s[n].marks);
    if((totalmarks/c)>(s[n].marks)){
        printf("\ngreat keep it up!...you have improved on your grades");
    }else{
        printf("\nWork harder you are on wrong truck!!");
    }
}

// function to display all student records
void display_students(struct student s[], int n) {
    printf("Name\t  student email. \t        Roll No.\tprev Marks\tcurr marks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t  %s\t%d\t    %.2f\t\n", s[i].name,s[i].email, s[i].rollno, s[i].marks);
    }
}

// function to search for a student record by roll number
void search_student(struct student s[], int n) {
    int rollno;
    printf("Enter roll number to search: ");
    scanf("%d", &rollno);

    for (int i = 0; i < n; i++) {
        if (s[i].rollno == rollno) {
            printf("Name: %s\n", s[i].name);
            printf("Roll No.: %d\n", s[i].rollno);
            printf("Marks: %.2f\n", s[i].marks);
            return;
        }
    }
    printf("Student record not found.\n");
}

int main() {

    struct student s[100]; // define an array of student structs
    int n = 0; // initialize number of students to zero
    int pin;
    pin= 4321;//initializing the default security pin as 4321.
    printf("enter records security pin( DEFAULT SECURITY PIN 4321): ");//let the user put the security pin before accessing the records.

    scanf("%d",&pin);
    while(!(pin==4321))
    {
        printf("incorect password!!\n**maybe the roll pinwas updated**   ");//if the pin is incorrect the user is reguired to reload the program
        printf("\nEnter another pin: ");
        scanf("%d",&pin);
        continue;
    }
    while (1) { //the user is supposed to choose an operation among the given ones. continuously until he/she decides to exit the program
        printf("\nStudent Record System\n");
        printf("----------------------\n");
        printf("1. Add student record\n");
        printf("2. Display all student records\n");
        printf("3. Search student record by roll number\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(s, n);
                n++; // increment number of students
                break;
            case 2:
                printf("******************\n");
                printf("_____STUDENT RECORDS______\n");
                display_students(s, n);
                break;
            case 3:
                search_student(s, n);
                break;
            case 4:
                return 0; // exit program
            default:
                printf("Invalid choice.\n");
            }

    }
        return 0;

}
