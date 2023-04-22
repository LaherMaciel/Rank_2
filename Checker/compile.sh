clear && gcc -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope *.c -o checker
./checker 2 1 3 sa
