#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i = 0, num = 0;

    printf("Enter Postfix Expression (use comma): ");
    scanf("%s", postfix);

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            num = 0;
            while (isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
            i--; // adjust index
        }
        else if (postfix[i] == ',')
        {
            // skip comma
        }
        else
        {
            int op2 = pop();
            int op1 = pop();

            switch (postfix[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }

    printf("Result = %d\n", pop());
    return 0;
}
