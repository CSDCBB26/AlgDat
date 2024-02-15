//
//  array.c
//  pointer
//
//  Created by Juergen Falb on 08.03.21.
//

#include <stdio.h>

void fill(char *text, int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        text[i] = 'A' + (i % 26);
        *(text + i) = 65 + (i % 26);
    }
    *(text +i) = '\0';
}

int main() {
    char text[100];
    
    fill(text, 100);
    printf("%s\n", text);
    
    return 0;
}
