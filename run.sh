#!/bin/bash
make
valgrind --show-leak-kinds=all --leak-check=full --verbose --show-mismatched-frees=yes --read-var-info=yes --log-file=valgrind-out.log ./push_swap "$@"
< valgrind-out.log grep "==" | cat > valgrind.log


#valgrind --show-leak-kinds=all --leak-check=full --track-fds=yes --trace-children=yes --verbose --show-mismatched-frees=yes --read-var-info=yes --suppressions=__ignore_leaks.txt --log-file=valgrind-out.txt ./minishell
