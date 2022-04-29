/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Gets a number
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int calcul = 0;
    int result = 0;

    while (str[i] < 48 || str[i] > 57)
        i++;
    if (str[i] >= 48 && str[i] <= 57 && str[i - 1] == '-')
        calcul = 1;
    while ((str[i] >= 48) && (str[i] <= 57)) {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    if (result > 2147483648 || result < -2147483648)
        return 0;
    if (calcul == 1)
        return (result * (-1));
    else
        return (result);
}
