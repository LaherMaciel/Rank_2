clear && gcc -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope *.c -o push_swap && ./push_swap
