clear && gcc -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope $(ls *.c | grep -v main_bonus.c) -o push_swap
