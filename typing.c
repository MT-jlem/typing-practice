#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./get-next-line/get_next_line.h"
#include "./lib/libft.h"
#include <fcntl.h>
#include <time.h>

typedef long long t_time;

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	s3;
	unsigned char	s4;
	int				i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		s3 = s1[i];
		s4 = s2[i];
		if (s3 != s4)
			return (s3 - s4);
		i++;
	}
	return (s3 - s4);
}

t_time	my_time(void)
{
	t_time			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	my_sleep(t_time time)
{
	t_time	expected_time;
	t_time	temp_time;

	expected_time = my_time() + time;
	temp_time = my_time();
	while (temp_time < expected_time)
	{
		usleep(100);
		temp_time = my_time();
	}
}

char    **init_text(){

    char **str = malloc(sizeof(char *) * 10000);
    int fd =open("text.txt",O_RDONLY);

    str[0] = get_next_line(fd);
    int i = 1;
    while(str && i < 10000){

        str[i] = get_next_line(fd);
        i++;
    }
    return str;
}

// display text
//take input 
// display time
// some other 

void	print_time(t_time start, int words){
	double timeInSec = (double)start / 60.0;
	printf("%lld min %lld sec\n", start / 60 , start % 60);
	printf("your speed: %.2f word per min\n",words / timeInSec);
}

int main(){
    
    
    char **text;
    int wordCount;
   text = init_text();
    printf("You will be asked to enter a group of words one by one. Type it as fast as you can and hit Enter.\n");
    printf("enter number between 1 and 10000\n");
    scanf("%d", &wordCount);
    if (wordCount < 0 || wordCount > 10000)
    {
        printf("WA SIR T9AWD\n");
        return 1;
    }
    // printf("you will start in 1");
    ft_putstr_fd("you will start in 1", 1);
    my_sleep(500);
    ft_putstr_fd(" 2", 1);
    my_sleep(500);
    ft_putstr_fd(" 3\n", 1);
    my_sleep(500);
    int i = 0;
    int r;
    int score = wordCount;
    char str[30];
    srand(time(NULL));
    t_time start = time(NULL);
    while (i < wordCount)
    {
        r = rand() % 10000;
        printf("-------------------------\n");
        printf("%s\n",text[r]); 
        if (scanf("%s", str) == EOF)
        {
            score = wordCount - score; 
            break;
        }
       fflush(stdin);
        if (ft_strcmp(text[r], str))
            score--;
        i++;
    }
    print_time(time(NULL) - start, i+1);
    printf("your score : %d/%d\n", wordCount , score);
}
