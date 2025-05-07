#include <stdio.h>

int isEmpty(const char *string) {
    return *string == '\0';
}

int stringLengthR(char *string) {
    if (isEmpty(string)) {
        return 0;
    }
    return 1 + stringLengthR(string + 1);
}

int stringLength(char *string) {
    int count = 0;
    while (*string != '\0') {
        count++;
        string++;
    }
    return count;
}


char* concat(char *string1, char *string2) {
    int newLength = stringLength(string1) + stringLength(string2);
    printf("new length es: %d\n", newLength);
    char newString[newLength];
    newString[newLength] = '\0';

    for (int i = 0; i < stringLength(string1); i++) {
        newString[i] = string1[i];
        // printf("Partial string: %s\n", newString);
    }

    for (int i = 0; i < stringLength(string2); i++) {
        newString[stringLength(string1) + i]= string2[i];
        // printf("Partial string: %s\n", newString);
    }
    char *returnString = newString;
    return returnString;
}

int main(void) {
    //CANTIDAD DE CARACTERES DE UNA CADENA
    char *stringToCount = "kevin";
    int cant = stringLength(stringToCount);
    printf("La cantidad de caracteres de '%s' es: %d\n", stringToCount, cant);

    //CANTIDAD DE CARACTERES DE UNA CADENA RECURSIVAMENTE
    int cant2 = stringLengthR(stringToCount);
    printf("La cantidad de caracteres recursivamente de '%s' es: %d\n", stringToCount, cant2);

    //ES VACIA UNA CADENA
    if (isEmpty("")) {
        printf("Es vacia\n");
    }else {
        printf("No es vacia\n");
    }

    //CONCATENAR 2 CADENAS
    char *str1 = "ARGEN";
    char *str2 = "TINA";
    printf("Cadena 1: %s y cadena 2: %s \n", str1, str2);
    printf("Concatenadas: %s\n", concat(str1, str2));
    return 0;
}
