clear && gcc -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope *.c
