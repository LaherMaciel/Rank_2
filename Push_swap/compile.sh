clear && gcc -g -Wall -Werror -Wextra -fsanitize=address -fsanitize-address-use-after-scope *.c -o push_swap
shuf -z -i 1-10 -n 10 | tr '\0' ' ' | tr -d '\n' | xargs ./push_swap
