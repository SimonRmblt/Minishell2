/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copies n char from a string into an other
*/

int my_putchar(char c);

char *my_strncpy(char *dest, char const *src, int n, int a)
{
    int i = 0;

    while (i != n) {
        dest[i] = src[a];
        if (src[a] == '\0')
            break;
        i++;
        a++;
    }
    dest[i] = '\0';
    return dest;
}
