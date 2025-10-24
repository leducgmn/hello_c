#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Student {
    char* name;
    char* dob;
    char gender;

    char* student_code;
    char* class;
} StudentStruct;

// typedef struct Student StudentStruct;

void update_class(StudentStruct *student, char* new_class) {
    student->class = new_class;
    printf("> Toi chuyen sang hoc lop %s.\n", (*student).class);
}

int main() {
    char name[100];
    printf("Input your name: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = 0; 

    char class[100];
    printf("Input your class: ");
    fgets(class, 100, stdin);
    class[strlen(class) - 1] = 0;

    char dob[100];
    printf("Input your dob: ");
    fgets(dob, 100, stdin);
    dob[strlen(dob) - 1] = 0; 

    char gender;
    printf("Input your gender: ");
    scanf("%c", &gender);
    struct Student student = {
        .name = name,
        .dob = dob,
        .gender = gender,
        .student_code = "B25DCTC006",
        .class = class,
    };

    printf("Toi ten la %s, toi sinh ngay %s. Nam nay toi hoc lop %s.\n", student.name, student.dob, student.class);

    update_class(&student, "12A3");
    //student.class = "12A3";
    printf("Toi ten la %s. Nam nay toi hoc lop %s.\n", student.name, student.class);
}