/* FIRST PROJECT 1
   NAME: LINKED LIST TO STORE STUDENT DATA
   DATE: 12/12/2026
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>   // For strcmp()

/* ---------- STUDENT STRUCTURE ----------
   Stores all details related to a student
*/
typedef struct StudType{
    char SID[20];      // Student ID
    char name[50];     // Student Name
    float mk1, mk2, mk3; // Marks of 3 subjects
    int total;         // Total marks
    float avg;         // Average marks
    int result;        // 1 = Pass, 0 = Fail
} STUDENT;

/* ---------- LINKED LIST NODE ----------
   Each node stores one STUDENT record
*/
typedef struct listtype{
    STUDENT data;           // Student data
    struct listtype *next;  // Pointer to next node
} LISTNODE;

LISTNODE *Head;   // Head pointer of linked list

/* ---------- INITIALIZE LIST ----------
   Sets head pointer to NULL
*/
void initlist(){
    Head = NULL;
}

/* ---------- INSERT STUDENT ----------
   Adds a new student at the end of the list
*/
void insertlistnode(STUDENT stud){
    LISTNODE *cur, *node;

    node = (LISTNODE*)malloc(sizeof(LISTNODE));
    node->data = stud;
    node->next = NULL;

    if(Head == NULL){
        Head = node;
        return;
    }

    cur = Head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = node;
}

/* ---------- SEARCH STUDENT ----------
   Searches student using Student ID
*/
void searchstudent(char sid[]){
    LISTNODE *cur = Head;

    while(cur != NULL){
        if(strcmp(cur->data.SID, sid) == 0){
            printf("\nStudent Found\n");
            printf("SID     : %s\n", cur->data.SID);
            printf("Name    : %s\n", cur->data.name);
            printf("Marks 1 : %.2f\n", cur->data.mk1);
            printf("Marks 2 : %.2f\n", cur->data.mk2);
            printf("Marks 3 : %.2f\n", cur->data.mk3);
            printf("Average : %.2f\n", cur->data.avg);
            printf("Result  : %s\n",
                   cur->data.result ? "PASS" : "FAIL");
            return;
        }
        cur = cur->next;
    }

    printf("Student with SID %s not found.\n", sid);
}

/* ---------- DISPLAY ALL STUDENTS ----------
   Displays complete student list in table format
*/
void displaylist(){
    LISTNODE *cur = Head;

    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("\n================ STUDENT LIST ================\n");
    printf("%-10s %-15s %-5s %-5s %-5s %-6s %-6s %-6s\n",
           "SID","Name","M1","M2","M3","Total","Avg","Res");
    printf("---------------------------------------------\n");

    while(cur != NULL){
        printf("%-10s %-15s %-5.0f %-5.0f %-5.0f %-6d %-6.2f %-6s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result ? "PASS" : "FAIL");
        cur = cur->next;
    }
}

/* ---------- PRINT MARKS CARD ----------
   Prints detailed marks card for one student
*/
void printmkscard(char sid[]){
    LISTNODE *cur = Head;

    while(cur != NULL){
        if(strcmp(cur->data.SID, sid) == 0){
            printf("\n========== MARKS CARD ==========\n");
            printf("SID     : %s\n", cur->data.SID);
            printf("Name    : %s\n", cur->data.name);
            printf("Marks 1 : %.2f\n", cur->data.mk1);
            printf("Marks 2 : %.2f\n", cur->data.mk2);
            printf("Marks 3 : %.2f\n", cur->data.mk3);
            printf("Total   : %d\n", cur->data.total);
            printf("Average : %.2f\n", cur->data.avg);
            printf("Result  : %s\n",
                   cur->data.result ? "PASS" : "FAIL");
            printf("================================\n");
            return;
        }
        cur = cur->next;
    }

    printf("Student with SID %s not found.\n", sid);
}

/* ---------- DELETE STUDENT ----------
   Deletes student node using Student ID
*/
void deletestudent(char sid[]){
    LISTNODE *cur, *del;

    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    if(strcmp(Head->data.SID, sid) == 0){
        del = Head;
        Head = Head->next;
        free(del);
        printf("Student deleted successfully.\n");
        return;
    }

    cur = Head;
    while(cur->next != NULL && strcmp(cur->next->data.SID, sid) != 0){
        cur = cur->next;
    }

    if(cur->next == NULL){
        printf("Student not found.\n");
        return;
    }

    del = cur->next;
    cur->next = del->next;
    free(del);
    printf("Student deleted successfully.\n");
}

/* ---------- CLASS REPORT ----------
   Displays summary of all students
*/
void classreport(){
    LISTNODE *cur = Head;

    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("\nCLASS REPORT\n");
    printf("SID\tName\tM1\tM2\tM3\tTotal\tAvg\tResult\n");
    printf("-------------------------------------------------\n");

    while(cur != NULL){
        printf("%s\t%s\t%.0f\t%.0f\t%.0f\t%d\t%.2f\t%s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result ? "PASS" : "FAIL");
        cur = cur->next;
    }
}

/* ---------- ENTER STUDENT DATA ----------
   Accepts input and inserts into linked list
*/
void enterstudentdata(){
    STUDENT stud;

    printf("Enter Student ID: ");
    scanf("%s", stud.SID);

    printf("Enter Name: ");
    scanf(" %[^\n]", stud.name);

    printf("Enter Marks for Subject 1: ");
    scanf("%f", &stud.mk1);

    printf("Enter Marks for Subject 2: ");
    scanf("%f", &stud.mk2);

    printf("Enter Marks for Subject 3: ");
    scanf("%f", &stud.mk3);

    stud.total = stud.mk1 + stud.mk2 + stud.mk3;
    stud.avg = stud.total / 3.0;
    stud.result = (stud.mk1 >= 40 &&
                   stud.mk2 >= 40 &&
                   stud.mk3 >= 40);

    insertlistnode(stud);
    printf("Student data inserted successfully.\n");
}

/* ---------- MENU FUNCTION ----------
   Controls program operations
*/
void menu(int choice){
    char sid[20];

    switch(choice){
        case 1: enterstudentdata(); break;
        case 2:
            printf("Enter Student ID: ");
            scanf("%s", sid);
            searchstudent(sid);
            break;
        case 3: displaylist(); break;
        case 4:
            printf("Enter Student ID: ");
            scanf("%s", sid);
            printmkscard(sid);
            break;
        case 5:
            printf("Enter Student ID: ");
            scanf("%s", sid);
            deletestudent(sid);
            break;
        case 6: classreport(); break;
        case 7: exit(0);
        default: printf("Invalid choice!\n");
    }
}

/* ---------- MAIN FUNCTION ----------
   Program execution starts here
*/
int main(){
    int choice;
    initlist();

    while(1){
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Enter Student Data\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Print Marks Card\n");
        printf("5. Delete Student\n");
        printf("6. Class Report\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        menu(choice);
    }
    return 0;
}
/* End of PROJECT1.C */