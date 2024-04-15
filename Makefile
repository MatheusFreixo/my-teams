##
## EPITECH PROJECT, 2024
## my_teams
## File description:
## Makefile
##

all:
	make -C src/server/
	make -C src/client/

clean:
	make clean -C src/server/
	make clean -C src/client/

fclean:
	make fclean -C src/server/
	make fclean -C src/client/

re: fclean all
