#include <stdlib.h>

#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char* a = "Bilgisayar";
    char* b = ft_strdup(a);
    void* result;
    result = ft_strdup(b);

    printf("%s-", a);
    printf("%s", b);
    printf("%p", result);
    free(b);
    free(result);

    return 0;
}
