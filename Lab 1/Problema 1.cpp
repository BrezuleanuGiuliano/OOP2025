#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int suma(const char* str) {
    int result = 0;
   
    
    
    for(int i=0;i<strlen(str);i++)
    {
        if (str[i]>='0'&& str[i] <= '9') 
        {
            result = result * 10 + (str[i] - '0');
        }
        
    }

    return  result;
}

int main() {
    FILE* file=NULL;
         fopen_s(&file,"in.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\\n");
        return 1;
    }

    char linie[100];
     int sum = 0; 

    while (fgets(linie, sizeof(linie), file) != NULL) {
      
        sum += suma(linie);
    }

    fclose(file);

    printf("%d", sum);

    return 0;
}
