##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

all:
	cd lib/my/ && make all
	gcc -o bsq *.c -I./include -L./lib/my -lmy

clean:
		rm -f *.o
		rm -f *~

fclean:	clean

		rm lib/libmy.a
		cd lib/my/ && make fclean

re:		fclean all