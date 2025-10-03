#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int id;
    char name[20];
    float marks;
    char dept[20];
};
void file_write_students(struct student *students, int n){
    FILE *file = fopen("students.txt", "w");
    if(file != NULL){
        for(int i = 0; i < n; i++){
            fprintf(file, "Student %d: ID=%d, Name=%s, Marks=%.2f, Dept=%s\n", i + 1, students[i].id, students[i].name, students[i].marks, students[i].dept);
        }
        fclose(file);
        printf("Student info written to students.txt\n");
    } else {
        printf("Failed to open file for writing.\n");
    }
}
int main(){
    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);
    struct student *students = malloc(n * sizeof(struct student));
    for(int i = 0; i < n; i++){
        printf("Enter details for student %d (ID Name Marks Dept(Each info seperated by space)): ", i + 1);
        scanf("%d %s %f %s", &students[i].id, students[i].name, &students[i].marks, students[i].dept);
    }
    file_write_students(students, n);
    
    printf("Do you want to enter more students? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y'){
        printf("Enter the number of additional students: ");
        int m;
        scanf("%d", &m);
        students = realloc(students, (n + m) * sizeof(struct student));
        for(int i = n; i < n + m; i++){
            printf("Enter details for student %d (ID Name Marks Dept): ", i + 1);
            scanf("%d %s %f %s", &students[i].id, students[i].name, &students[i].marks, students[i].dept);
        }
        file_write_students(students, n + m);
    }
    free(students);
    printf("Do you want to search a student by ID? (y/n): ");
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y'){
        printf("Enter the student ID to search: ");
        int search_id;
        scanf("%d", &search_id);
        int found = 0;
        for(int i = 0; i < n; i++){
            if(students[i].id == search_id){
                printf("Student found: ID=%d, Name=%s, Marks=%.2f, Dept=%s\n", students[i].id, students[i].name, students[i].marks, students[i].dept);
                found = 1;
                break;
            }
        }
        if(!found){
            printf("Student with ID %d not found.\n", search_id);
        }
    }   
    return 0;
}