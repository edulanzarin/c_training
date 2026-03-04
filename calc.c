#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

// func pra calcular dois num com op
double apply(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

// func de prioridade de op
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// avaliar expressao simples usando duas pilhas
double evaluate(char *expr) {
    double values[MAXLEN];
    char ops[MAXLEN];
    int vtop = -1, otop = -1;
    int i = 0;

    while (expr[i]) {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        // num
        if (isdigit(expr[i])) {
            double val = 0;
            while (isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values[++vtop] = val;
        }
        // parentese esquerdo
        else if (expr[i] == '(') {
            ops[++otop] = expr[i];
            i++;
        }
        // parentese direito
        else if (expr[i] == ')') {
            while (otop >= 0 && ops[otop] != '(') {
                double b = values[vtop--];
                double a = values[vtop--];
                char op = ops[otop--];
                values[++vtop] = apply(a, b, op);
            }
            otop--; // remove parentese esquerdo
            i++;
        }
        // op
        else {
            while (otop >= 0 && precedence(ops[otop]) >= precedence(expr[i])) {
                double b = values[vtop--];
                double a = values[vtop--];
                char op = ops[otop--];
                values[++vtop] = apply(a, b, op);
            }
            ops[++otop] = expr[i];
            i++;
        }
    }

    while (otop >= 0) {
        double b = values[vtop--];
        double a = values[vtop--];
        char op = ops[otop--];
        values[++vtop] = apply(a, b, op);
    }

    return values[vtop];
}

int main() {
    char expr[MAXLEN];

    printf("pressione 'q' para sair\n");

    while (1) {
        printf("\ndigite a expressao: ");
        if (!fgets(expr, MAXLEN, stdin))
            break;

        // remover newline
        expr[strcspn(expr, "\n")] = 0;

        if (strcmp(expr, "q") == 0)
            break;

        double resultado = evaluate(expr);
        printf("r = %.2f\n", resultado);
    }

    printf("saindo...\n");
    return 0;
}
