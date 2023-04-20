seq -2500 2500 | shuf -n 500 | tr '\n' ' ' | xargs ./push_swap
