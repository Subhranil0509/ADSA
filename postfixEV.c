#include <stdio.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

/* Push value onto stack */
void push(int value)
{
    stack[++top] = value;
}

/* Pop value from stack */
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))   // Operand
        {
            push(postfix[i] - '0'); // Convert char to int
        }
        else  
        {
            op2 = pop();
            op1 = pop();

            switch (postfix[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
