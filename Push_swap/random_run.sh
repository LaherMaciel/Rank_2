shuf -z -i 1-500 -n 500 | tr '\0' ' ' | tr -d '\n' | xargs ./push_swap
