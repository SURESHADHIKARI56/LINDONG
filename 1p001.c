/*\FIRST PRPOJECT 1
  NAME: LINKED LIST TO STORE STUDENT DATA
  DATE:12/12/2026
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct StudType{
    char SID[20];
    char name[50];
    float mk1,mk2,mk3;
    int total;
    float avg;
    int result;
}STUDENT;
//Create a new data type LISTNODE TO REPRESENT  THE NODE OF A LINK ;IST HAVING STUDENT DATA
typedef struct listtype{
    STUDENT data;
    struct listtype *next;
}LISTNODE;
LISTNODE *Head;
void initlist(){
    Head=NULL;
}
void insertlistnode(STUDENT stud){
    LISTNODE *cur,*node;
    node=(LISTNODE*)malloc(sizeof(LISTNODE));
    node->data=stud;
    node->next=NULL;
    if(Head==NULL){
        Head=node;
        return;
    }
    cur=Head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=node;
}
void searchstudent(char sid[]){
    LISTNODE *cur=Head;
    while(cur!=NULL){
        if(strcmp(cur->data.SID,sid)==0){
            printf("Student found:\n");
            printf("SID:%s\n",cur->data.SID);
            printf("Name:%s\n",cur->data.name);
            printf("Marks1:%.2f\n",cur->data.mk1);
            printf("Marks2:%.2f\n",cur->data.mk2);
            printf("Marks3:%.2f\n",cur->data.mk3);
            printf("Aerage:%.2f\n",cur->data.avg);
            printf("Result:%s\n",cur->data.result==1?"pass":"fail");
            return;
        }
        cur=cur->next;
    }
    printf("Student with SID %s not found.\n",sid); 
}
void displaylist(){
    LISTNODE *cur = Head;
    if (Head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n==================== STUDENT LIST ====================\n");
    printf("%-10s %-15s %-7s %-7s %-7s %-7s %-7s %-6s\n",
           "SID", "Name", "M1", "M2", "M3", "Total", "Avg", "Res");
    printf("------------------------------------------------------\n");

    while (cur != NULL) {
        printf("%-10s %-15s %-7.2f %-7.2f %-7.2f %-7d %-7.2f %-6s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result == 1 ? "PASS" : "FAIL");
        cur = cur->next;
    }
}
void printmkscard(char sid[]){
    LISTNODE *cur=Head;
    while(cur!=NULL){
        if(strcmp(cur->data.SID,sid)==0){
            printf("/t/t/tMarks Card for SID:%s\n",cur->data.SID);
            printf("/t/t/tName:%s\n",cur->data.name);
            printf("/t/t/tMarks1:%.2f\n",cur->data.mk1);
            printf("/t/t/tMarks2:%.2f\n",cur->data.mk2);
            printf("/t/t/tMarks3:%.2f\n",cur->data.mk3);
            printf("/t/t/tTotal:%d\n",cur->data.total);
            printf("/t/t/tAverage:%.2f\n",cur->data.avg);
            printf("/t/t/tResult:%s\n",cur->data.result==1?"pass":"fail");
            return;
        }
        cur=cur->next;
    }
    printf("Student with SID %s not found.\n",sid); 
}
void deletestudent(char sid[]){
    if(Head==NULL){
        printf("list is empty.\n");
        return;
    }
    if(strcmp(Head->data.SID, sid)==0){
        LISTNODE *del=Head;
        Head=Head->next;
        free(del);
        printf("student with SID %s deleted successfully.\n",sid);
        return;

    }
    LISTNODE *cur=Head;
    while(cur->next!=NULL && strcmp(cur->next->data.SID,sid)!=0){
        cur=cur->next;
    }
}
void classreport(){
    LISTNODE *cur = Head;

    if (Head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nCLASS REPORT\n");
    printf("-------------------------------------------------\n");
    printf("SID\tName\tM1\tM2\tM3\tTotal\tAvg\tResult\n");
    printf("-------------------------------------------------\n");

    while (cur != NULL) {
        printf("%s\t%s\t%.0f\t%.0f\t%.0f\t%d\t%.2f\t%s\n",
               cur->data.SID,
               cur->data.name,
               cur->data.mk1,
               cur->data.mk2,
               cur->data.mk3,
               cur->data.total,
               cur->data.avg,
               cur->data.result == 1 ? "PASS" : "FAIL");
        cur = cur->next;
    }
}

void enterstudentdata(){
    STUDENT stud;
    printf("Enter Student ID: ");
    scanf("%s",stud.SID);
    printf("Enter Name: ");
    scanf(" %[^\n]",stud.name);
    printf("Enter Marks for Subject 1: ");
    scanf("%f",&stud.mk1);
    printf("Enter Marks for Subject 2: ");
    scanf("%f",&stud.mk2);
    printf("Enter Marks for Subject 3: ");
    scanf("%f",&stud.mk3);
    stud.total=(int)(stud.mk1+stud.mk2+stud.mk3);
    stud.avg=(stud.total)/3.0;
    stud.result=(stud.mk1>=40 && stud.mk2>=40 && stud.mk3>=40)?1:0;
    insertlistnode(stud);
    printf("Student data inserted successfully.\n");
}
void menu(int choice){
    char sid[20];
    switch(choice){
        case 1:
            enterstudentdata();
            break;
        case 2:
            printf("Enter Student ID to search: ");
            scanf("%s",sid);
            searchstudent(sid);
            break;
        case 3:
            displaylist();
            break;
        case 4:
            printf("Enter Student ID for Marks Card: ");
            scanf("%s",sid);
            printmkscard(sid);
            break;
        case 5:
            printf("Enter Student ID to delete: ");
            scanf("%s",sid);
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
int main(){
    int choice;
    initlist();
    while(1){
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Enter Student Data\n");
        printf("2. Search Student by ID\n");
        printf("3. Display All Students\n");
        printf("4. Print Marks Card\n");
        printf("5. Delete Student by ID\n");
        printf("6. Class Report\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        menu(choice);
    }
    return 0;
}