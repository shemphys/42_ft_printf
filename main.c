#include "ft_printf.h"

int main(void)
{
    int number = 42;
    char c = 'a';
    char *str = "mparedes!23423";
    void *ptr = &number;

    ft_printf("Número: %d\n", number);
    ft_printf("Caracter: %c\n", c);
    ft_printf("Cadena: %s\n", str);
    ft_printf("Puntero: %p\n", ptr);
    ft_printf("Número en hexadecimal: %x\n", number);
    ft_printf("Número en MAYÚSCULAS en hexadecimal: %X\n", number);
    ft_printf("Porcentaje: %%\n");

    return 0;
}

