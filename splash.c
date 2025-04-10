#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 11  // yyyy-mm-dd + null

int main() {
    char name[MAX_NAME_LEN];
    char date[MAX_DATE_LEN];
    int year, month, day;
    int i;

    /* Input date */
    printf("[Enter the current date in \"yyyy-mm-dd\" format]: ");
    if (fgets(date, sizeof(date), stdin) == NULL) {
        printf("Error reading date input.\n");
        return 1;
    }

    /* Remove newline character */
    for (i = 0; date[i] != '\0'; i++) {
        if (date[i] == '\n') {
            date[i] = '\0';
            break;
        }
    }

    /* Input name */
    printf("[Enter your name]: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading name input.\n");
        return 1;
    }

    /* Remove newline character */
    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    /* Parse date */
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("Date format error. Example: 2023-08-20\n");
        return 1;
    }

    printf("**Input has been successfully processed.**\n");

    /* Display splash screen */
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                         [Magrathea ver 0.1]                              \n");
    printf("           A place that creates shining planets from barren wastelands, Magrathea, \n");
    printf("         Where hidden potential is discovered and polished by the touch of experts, \n");
    printf("           Welcome to Magrathea.   \n");
    printf("                                                                                     \n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[User]: %s                                   [Execution Date]: %d-%02d-%02d\n", name, year, month, day);
    printf("================================================================================\n");

    return 0;
}
