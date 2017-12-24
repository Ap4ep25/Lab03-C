#include <stdio.h>
#include <math.h>

int main() {
    double a, x, G, F, Y, xmin, xmax, T;
    int K, s;

    do {

        printf("Для выхода из программы, введите 0\n");
        printf("Формула 1: Рассчет G, введите 1\n");
        printf("Формула 2: Рассчет F, введите 2\n");
        printf("Формула 3: Рассчет Y, введите 3\n");
        scanf("%d", &K);

        if (K == 0) {
            printf("До свидания!");
            return 0;
        }

        if ((K < 0) || (K > 3)) {
            printf("Неверно введено значение, введите его заного!\n");
            scanf("%d", &K);
        } else

            printf("Введите минимальное значение х: ");
        scanf("%lf", &xmin);
        printf("Введите максимальное значение x: ");
        scanf("%lf", &xmax);

        if (xmin >= xmax) {
            printf("Максимальное значение х должно быть больше минимального\n");
            printf("Введите еще раз х: ");
            scanf("%lf", &xmax);
        }
        printf("Введите колличество шагов: ");
        scanf("%d", &s);

        while (s <= 0) {
            printf("Число шагов не может быть меньше или равно 0\n");
            printf("Введите число шагов еще раз: ");
            scanf("%d", &s);
        }


        switch (K) {
            case 1: {
                printf("Введите а: ");
                scanf("%lf", &a);
                for (x = xmin; x <= xmax; x += (xmax - xmin) /
                                               (s - 1)) {
                    T = (10 * pow(a, 2) + 11 * a * xmin + 3 * pow(xmin, 2));
                    if (fabs(T) < (10e-6)) {
                        printf("Введите другие значения");
                        break;
                    }
                    G = (5 * (-2 * pow(a, 2) + a * x + 3 * pow(x, 2)) / T);
                    printf("G=%lf\n", G);

                }
                break;
                case 2: {
                    printf("Введите а: ");
                    scanf("%lf", &a);
                    for (x = xmin; x <= xmax; x += (xmax - xmin) / (s - 1)) {
                        F = sin(10 * pow(a, 2) - 7 * a * x + pow(x, 2));
                        printf("F=%lf\n", F);
                    }
                    break;
                    case 3: {
                        printf("Введите а: ");
                        scanf("%lf", &a);

                        for (x = xmin; x <= xmax; x += (xmax - xmin) / (s - 1)) {
                            Y = atan(45 * pow(a, 2) + 79 * a * x + 30 * pow(x, 2));
                            printf("Y=%lf\n", Y);
                        }
                        break;
                    }
                }
            }
        }
    } while (K != 0);
    return 0;
}