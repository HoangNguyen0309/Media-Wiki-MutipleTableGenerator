  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fp;
    fp = fopen("sample.txt", "r");
    char buffer[2000];
    char buffer2[2000][200];
    int length = 0;
    int a = 1;
    
    while(fgets(buffer, 2000, fp) != NULL) {
    	buffer2[a][0] = '|';    
        strcat(buffer2[a], buffer);
        printf("%s", buffer2[a]);
        length++;
        a = a + 6;
    }
    fclose(fp);
    for (int i = 0; i < a; i = i + 6) {
    	strcpy(buffer2[i], "|-\n");
    }
    for (int i = 2; i < a; i = i + 6) {
    	strcpy(buffer2[i], "|Empty\n");
    }
    for (int i = 3; i < a; i = i + 6) {
    	strcpy(buffer2[i], "|default\n");
    }
    for (int i = 4; i < a; i = i + 6) {
    	strcpy(buffer2[i], "|[[Updates/10.0.0|10.0.0]]\n");
    }
    for (int i = 5; i < a; i = i + 6) {
    	strcpy(buffer2[i], "| ''(Not removed)'' \n");
    }
    
    FILE * fp2;
    fp2 = fopen("bruh.txt", "w");
    for (int i = 0; i < a; i++) {
    	fputs(buffer2[i], fp2);
    }
    fclose(fp2);
}
