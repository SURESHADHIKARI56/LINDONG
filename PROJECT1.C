/* FIRST PROJECT 1
   LINKED LIST TO STORE STUDENT DATA
   NAME:SURESH
   DATE: 18/12/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Student structure */
typedef struct StudType
{
    char SID[20];
    char name[50];
    float mk1, mk2, mk3;
    int total;
    float avg;
    char result[15]; // PASS / FAIL / DISTINCTION
} STUDENT;

/* Linked list node */
typedef struct listtype
{
    STUDENT data;
    struct listtype *next;
} LISTNODE;

LISTNODE *Head;

/* Initialize list */
void initlist()
{
    Head = NULL;
}

/* Insert node at end */
void insertlistnode(STUDENT stud)
{
    LISTNODE *cur, *node;
    node = (LISTNODE *)malloc(sizeof(LISTNODE));
    node->data = stud;
    node->next = NULL;

    if (Head == NULL)
    {
        Head = node;
        return;
    }

    cur = Head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
}

/* Enter student data */
void enterstudentdata()
{
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

    stud.total = (int)(stud.mk1 + stud.mk2 + stud.mk3);
    stud.avg = stud.total / 3.0;

    /* PASS / FAIL / DISTINCTION logic */
    if (stud.mk1 < 35 || stud.mk2 < 35 || stud.mk3 < 35)
    {
        strcpy(stud.result, "FAIL");
    }
    else if (stud.avg >= 80)
    {
        strcpy(stud.result, "DISTINCTION");
    }
    else
    {
        strcpy(stud.result, "PASS");
    }

    insertlistnode(stud);
    printf("Student data inserted successfully.\n");
}

/* Search student */
void searchstudent(char sid[])
{
    LISTNODE *cur = Head;

    while (cur != NULL)
    {
        if (strcmp(cur->data.SID, sid) == 0)
        {
            printf("\nStudent Found\n");
            printf("SID     : %s\n", cur->data.SID);
            printf("Name    : %s\n", cur->data.name);
            printf("Marks   : %.2f %.2f %.2f\n",
                   cur->data.mk1, cur->data.mk2, cur->data.mk3);
            printf("Total   : %d\n", cur->data.total);
            printf("Average : %.2f\n", cur->data.avg);
            printf("Result  : %s\n", cur->data.result);
            return;
        }
        cur = cur->next;
    }
    printf("Student with SID %s not found.\n", sid);
}

/* Display all students */
void displaylist()
{
    LISTNODE *cur = Head;

    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\n==================== STUDENT LIST ====================\n");
    printf("%-10s %-15s %-6s %-6s %-6s %-6s %-6s %-12s\n",
           "SID", "Name", "M1", "M2", "M3", "Total", "Avg", "Result");
    printf("------------------------------------------------------\n");

    while (cur != NULL)
    {
        printf("%-10s %-15s %-6.0f %-6.0f %-6.0f %-6d %-6.2f %-12s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result);
        cur = cur->next;
    }
}

/* Print marks card */
void printmkscard(char sid[])
{
    LISTNODE *cur = Head;

    while (cur != NULL)
    {
        if (strcmp(cur->data.SID, sid) == 0)
        {
            printf("\n\t\tMARKS CARD\n");
            printf("\t\tSID     : %s\n", cur->data.SID);
            printf("\t\t\tName    : %s\n", cur->data.name);
            printf("\tMarks 1 : %.2f\n", cur->data.mk1);
            printf("\tMarks 2 : %.2f\n", cur->data.mk2);
            printf("\tMarks 3 : %.2f\n", cur->data.mk3);
            printf("\tTotal   : %d\n", cur->data.total);
            printf("\tAverage : %.2f\n", cur->data.avg);
            printf("\t\tResult  : %s\n", cur->data.result);
            return;
        }
        cur = cur->next;
    }
    printf("Student with SID %s not found.\n", sid);
}

/* Delete student */
void deletestudent(char sid[])
{
    LISTNODE *cur = Head, *del;

    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (strcmp(Head->data.SID, sid) == 0)
    {
        del = Head;
        Head = Head->next;
        free(del);
        printf("Student with SID %s deleted successfully.\n", sid);
        return;
    }

    while (cur->next != NULL && strcmp(cur->next->data.SID, sid) != 0)
    {
        cur = cur->next;
    }

    if (cur->next == NULL)
    {
        printf("Student with SID %s not found.\n", sid);
        return;
    }

    del = cur->next;
    cur->next = del->next;
    free(del);
    printf("Student with SID %s deleted successfully.\n", sid);
}

/* Class report */
void classreport()
{
    LISTNODE *cur = Head;

    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nCLASS REPORT\n");
    printf("-------------------------------------------------\n");
    printf("SID\tName\tM1\tM2\tM3\tTotal\tAvg\tResult\n");
    printf("-------------------------------------------------\n");

    while (cur != NULL)
    {
        printf("%s\t%s\t%.0f\t%.0f\t%.0f\t%d\t%.2f\t%s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result);
        cur = cur->next;
    }
}

/* Menu handler */
void menu(int choice)
{
    char sid[20];

    switch (choice)
    {
    case 1:
        enterstudentdata();
        break;
    case 2:
        printf("Enter Student ID to search: ");
        scanf("%s", sid);
        searchstudent(sid);
        break;
    case 3:
        displaylist();
        break;
    case 4:
        printf("Enter Student ID for Marks Card: ");
        scanf("%s", sid);
        printmkscard(sid);
        break;
    case 5:
        printf("Enter Student ID to delete: ");
        scanf("%s", sid);
        deletestudent(sid);
        break;
    case 6:
        classreport();
        break;
    case 7:
        printf("Exiting program...\n");
        exit(0);
    default:
        printf("Invalid choice! Try again.\n");
    }
}

/* Main */
int main()
{
    int choice;
    initlist();

    while (1)
    {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Enter Student Data\n");
        printf("2. Search Student by ID\n");
        printf("3. Display All Students\n");
        printf("4. Print Marks Card\n");
        printf("5. Delete Student by ID\n");
        printf("6. Class Report\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        menu(choice);
    }
    return 0;
}
/*END OF PROGRAM*/