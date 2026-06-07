#include <stdio.h>

struct Settings
{
    int addition;
    int subtraction;
    int multiplication;
    int division;
};

int main()
{
    struct Settings s = {0, 0, 0, 0};

    FILE *fp;

    fp = fopen("settings.dat", "rb");

    if (fp != NULL)
    {
        fread(&s, sizeof(struct Settings), 1, fp);
        fclose(fp);
    }

    char name_initial;

    printf("Enter Name Initial : ");
    scanf(" %c", &name_initial);

    if (name_initial == 'T' || name_initial == 't')
    {
        int choice;
        char yn;

        while (1)
        {
            printf("\n===== ADMIN PANEL =====\n");
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Division\n");
            printf("5. Save And Exit\n");

            printf("Enter Choice : ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("Enable Addition (y/n): ");
                scanf(" %c", &yn);

                if (yn == 'y' || yn == 'Y')
                    s.addition = 1;
                else
                    s.addition = 0;
            }

            else if (choice == 2)
            {
                printf("Enable Subtraction (y/n): ");
                scanf(" %c", &yn);

                if (yn == 'y' || yn == 'Y')
                    s.subtraction = 1;
                else
                    s.subtraction = 0;
            }

            else if (choice == 3)
            {
                printf("Enable Multiplication (y/n): ");
                scanf(" %c", &yn);

                if (yn == 'y' || yn == 'Y')
                    s.multiplication = 1;
                else
                    s.multiplication = 0;
            }

            else if (choice == 4)
            {
                printf("Enable Division (y/n): ");
                scanf(" %c", &yn);

                if (yn == 'y' || yn == 'Y')
                    s.division = 1;
                else
                    s.division = 0;
            }

            else if (choice == 5)
            {
                fp = fopen("settings.dat", "wb");

                fwrite(&s, sizeof(struct Settings), 1, fp);

                fclose(fp);

                printf("\nSettings Saved Successfully.\n");
                break;
            }

            else
            {
                printf("Invalid Choice.\n");
            }
        }
    }

    else
    {
        int choice;
        float num1, num2, result;

        while (1)
        {
            printf("\n===== USER PANEL =====\n");

            if (s.addition)
                printf("1. Addition\n");

            if (s.subtraction)
                printf("2. Subtraction\n");

            if (s.multiplication)
                printf("3. Multiplication\n");

            if (s.division)
                printf("4. Division\n");

            printf("0. Exit\n");

            printf("Enter Choice : ");
            scanf("%d", &choice);

            if (choice == 0)
            {
                printf("Thank You.\n");
                break;
            }

            printf("Enter First Number : ");
            scanf("%f", &num1);

            printf("Enter Second Number : ");
            scanf("%f", &num2);

            if (choice == 1 && s.addition)
            {
                result = num1 + num2;
                printf("Answer = %.2f\n", result);
            }

            else if (choice == 2 && s.subtraction)
            {
                result = num1 - num2;
                printf("Answer = %.2f\n", result);
            }

            else if (choice == 3 && s.multiplication)
            {
                result = num1 * num2;
                printf("Answer = %.2f\n", result);
            }

            else if (choice == 4 && s.division)
            {
                if (num2 == 0)
                {
                    printf("Division By Zero Not Allowed\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Answer = %.2f\n", result);
                }
            }

            else
            {
                printf("Operation Not Enabled By Admin\n");
            }
        }
    }

    return 0;
}