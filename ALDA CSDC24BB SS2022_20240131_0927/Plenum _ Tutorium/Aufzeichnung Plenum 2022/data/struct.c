//
//  struct.c
//  pointer
//
//  Created by Juergen Falb on 08.03.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

struct person {
    char firstname[20];
    char lastname[50];
    int age;
};

struct person *createPerson(const char *firstname, char *lastname, int age) {
    struct person *p;
    p = (struct person *)malloc(sizeof(struct person));
    
    p->age = age;
    strcpy(p->firstname, firstname);
    strcpy(p->lastname, lastname);
    
    return p;
}

int main() {
    struct person *p1;
    
    p1 = createPerson("Juergen", "Falb", 46);
    printf("%s %s ist %i Jahre alt.\n", p1->firstname, p1->lastname, p1->age);
    
    free(p1);
    return 0;
}
