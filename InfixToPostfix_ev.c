#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

/* Stack operations */
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

/* Operator precedence */
int precedence(char x)
{
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2; 
    return 0;
}

/* Infix to Postfix conversion */
void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, k = 0;
    char x;

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))   // operand
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }
        else    // operator
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

/* Evaluate Postfix expression */
int evaluatePostfix(char postfix[])
{
    int i = 0;
    int valStack[MAX];
    int valTop = -1;

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            valStack[++valTop] = postfix[i] - '0';
        }
        else
        {
            int b = valStack[valTop--];
            int a = valStack[valTop--];

            switch (postfix[i])
            {
                case '+': valStack[++valTop] = a + b; break;
                case '-': valStack[++valTop] = a - b; break;
                case '*': valStack[++valTop] = a * b; break;
                case '/': valStack[++valTop] = a / b; break;
            }
        }
        i++;
    }
    return valStack[valTop];
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluation result: %d\n", evaluatePostfix(postfix));

    return 0;
}
