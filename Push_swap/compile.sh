clear && gcc -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope *.c && ./a.out 10 -10000 1 
