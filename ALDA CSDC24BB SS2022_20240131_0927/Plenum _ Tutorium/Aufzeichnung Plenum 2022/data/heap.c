//
//  heap.c
//  pointer
//
//  Created by Juergen Falb on 08.03.21.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char * createTextArray(int size) {
    char *text;
    int i;

    text = (char *)malloc(sizeof(char)*size); // memory allocation = new Befehl in Java
    for (i = 0; i < size - 1; i++) {
        text[i] = 'a' + (i % 26);
    }
    text[i] = '\0';
    return text;
}

void deleteTextArray(char *text) {
    free(text);
}

int main() {
    char *text;
    int size;
    
    printf("Bitte gib eine Größe ein: ");
    scanf("%i", &size);
    
    text = createTextArray(size);
    printf("%s\n", text);
    deleteTextArray(text);
    
    return 0;
}
