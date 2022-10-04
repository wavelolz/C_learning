#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*To initialize a struct*/


struct stu{
    int id;
    char name[20];
    int score;
} stu;


int main(){
    stu.id = 410;
    strcpy(stu.name, "Ray");
    stu.score = 30;

    printf("Id is : %d \n", stu.id);
    printf("Name is : %s \n", stu.name);
    printf("Score is : %d \n", stu.score);
}


/*We can also define a nested struct*/


struct cls{
    char teacher[20];
    char stu[20];
};

struct stu{
    struct cls cls;
    char gender[20];
    char name[20];
};

int main(){
    struct stu student;
    strcpy(student.cls.stu, "student");
    strcpy(student.gender, "male");
    strcpy(student.name, "Ray");
    printf("Status : %s, Gender : %s, Name : %s", student.cls.stu, student.gender, student.name);
}



/*struct with pointer. We can create a variable that stores the address of struct, and
then access the attribute in the struct through pointer*/


struct stu{
    int age;
    char name [20];
};

int main(){
    struct stu *ptr, student; // ptr is a pointer to struct
    ptr = &student;
    (*ptr).age = 30;
    scanf("%s", &(ptr -> name));
    printf("Name is %s, Age is %d", (*ptr).name, ptr -> age);

}


/*
Here, ptr stores the address of student. So (*ptr).age set the value of age to 30.
And &(ptr -> name) will return the address of name. ptr -> age will return the
address of age.

*/





// Next, we use malloc() on struct



struct stu{
    int age;
    char name [20];
};

int main(){
    struct stu *ptr;
    int n = 3;
    ptr = (struct stu*) malloc(n * sizeof(struct stu)); // This declares a dynamic memory with 3 times size of struct
    for (int i = 0; i < n; i ++){
        printf("Enter %d Students Age :", i);
        scanf("%d", &(ptr + i) -> age); // This extracts the address of age
        printf("\n");
        printf("Enter %d Students Name :", i);
        scanf("%s", (ptr + i) -> name); // Since char array is a address, we don't have to use dereference operator
        printf("-------------\n");
    }

    for (int i = 0; i < n; i ++){
        printf("The %d Student's Age is %d, Name is %s", i, (ptr + i) -> age, (ptr + i) -> name);
        printf("-------------\n");
    }

}





/*Next, we'll show how to pass structure as a function argument*/

struct student{
    int age;
    char name [20];
};

void show(struct student s);

void main(){
    struct student stu;
    printf("Enter student's age :");
    scanf("%d", &stu.age);
    printf("\nEnter student's name :");
    scanf("%s", stu.name);
    show(stu);
}

void show(struct student s){
    printf("\n");
    printf("Student's name is : %s \n", s.name);
    printf("Student's age is : %d", s.age);

}





// Next, we'll return a structure from a function

struct student{
    int age;
    char name [20];
};

struct student show();

void main () {
    struct student stu;
    stu = show();
    printf("\n");
    printf("Student's age is %d", stu.age);
    printf("\nStudent's name is %s", stu.name);



}

struct student show(){
    struct student s1;

    printf("Enter Student's age : ");
    scanf("%d", &s1.age);
    printf("\nEnter Student's name : ");
    scanf("%s", s1.name);

    return s1;


}






// We can also pass the address of structure to a function

typedef struct Complex_Number_Definition{
    float real;
    float imag;
} cpx;

void add_Number(cpx c1, cpx c2, cpx *result);
void main(){
    cpx c1, c2, result;
    printf("Enter the real part of c1 :");
    scanf("%f", &c1.real);
    printf("\nEnter the imaginary part of c1 :");
    scanf("%f", &c1.imag);

    printf("Enter the real part of c2 :");
    scanf("%f", &c2.real);
    printf("\nEnter the imaginary part of c2 :");
    scanf("%f", &c2.imag);

    add_Number(c1, c2, &result);

    printf("The result of real part is : %f\n", result.real);
    printf("The result of imaginary part is : %f", result.imag);
}

void add_Number(cpx c1, cpx c2, cpx *result){
    result -> real = c1.real + c2.real;
    result -> imag = c1.imag + c2.imag;
}
