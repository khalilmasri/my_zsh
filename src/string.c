#include "../include/include.h"

size_t my_strlen(char *str){

    size_t size = 0;

    while(str[size])
        size++;

    return size+1;
}

int my_memset(char *buffer, char c, int size)
{
    int index = 0;

    while (index < size){
        buffer[index] = c;
        index += 1;
    }
    return index;
}

char *my_strcpy(char *dest, char *src){
    while (*src != '\0'){
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for (start = 0, end = len - 1; start < end; start++, end--)
    {
        temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
    }
}

char *my_itoa(int number, char *string) //to convert my signed decimal to string
{
    int i = 0;
    int negative_num = 0;

    //if 0, print "0" string
    if (number == 0)
    {
        string[i] = '0';
        string[i + 1] = '\0';
        return string;
    }

    //if base decimal and negative, otherwise ignore sign.
    if (number < 0)
    {
        negative_num = 1;
        number = -number;
    }

    while (number != 0)
    {
        unsigned int remainder = number % 10;
        if (remainder > 9)
        {
            string[i++] = (remainder - 10) + 'a';
        }
        else
        {
            string[i++] = remainder + '0';
        }
        number = number / 10;
    }

    /* Append negative sign for negative numbers */
    if (negative_num)
    {
        string[i++] = '-';
    }

    string[i] = '\0';

    my_reverse(string, i);

    return string;
}

long my_atoi(char *number_string, int size)
{
    int index = 0;
    long res = 0;
    while (index < size && number_string[index])
    {
        if (number_string[index] >= '0' && number_string[index] <= '9')
        {
            res *= 10;
            res += number_string[index] - '0';
        }
        index++;
    }
    return res;
}

int my_strcmp(char *ptr1, char *ptr2)
{
    int i = 0;

    while ((ptr1[i] != '\0') || (ptr2[i] != '\0'))
    {
        if (ptr1[i] > ptr2[i])
            return 1;
        if (ptr1[i] < ptr2[i])
            return -1;
        i++;
    }

    return 0;
}

//function to check if is digit
int is_digit(char c) {
    if (c >= '0' && c <= '9') 
    {
        return 1;
    }
    return 0;
}

int is_char(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
        return 1;
    }
    return 0;
}

int arg_count(char *str){

    int index   = 0,
        size    = 0;

    while(str[index]){

        if(str[index] == ' '){
            size++;
            index++;
        }

        index++;
    }

    size++;

    return size;
}

int my_getchar(){

    static char buff[MAX_STR_LEN],
    *buff_ptr = buff;
    static int index = 0;

    if(index == 0){
        index = read(0, buff, 1);
        buff_ptr = buff;
    }

    if(--index >= 0)
        return *buff_ptr++;

    return EOF;
}

void my_putstr(char *str){
    write(0, str, my_strlen(str));
}

void my_putchar(int fd, char*str){

    int index = 0;

    while(str[index]){
        if(str[index] != '"'){
            write(fd, &str[index], 1);
        }
            index++;
    }
}

char* my_strcat(char *dest, char* src){

    char *ptr = dest + my_strlen(dest);

    while(*src){
        *ptr++ = *src++;
    }

    *ptr = '\0';

    return dest;
}

