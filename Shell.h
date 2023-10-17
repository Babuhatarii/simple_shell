#ifndef SHELL_H
#define SHELL_H

#define GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdarg.h>

extern char **environ;
/**
 * struct builtin_cmd - Built in command structure
 * @cmd_name: command name
 * @cmd_fxn: pointer to a function
 */
typedef struct builtin_cmd
{
	char *cmd_name;
	int (*cmd_fxn)();
}builtin_cmd_struct;

int (*find_builtin_cmd(char *input))();
int exit_shell(void);
int print_env_vars(void);
void replace_equals_with_colon(char *str);
char *find_path_env();
void p_error(char **args);
char **get_path(char *args);
char **insert_path_to_cmd(char**args, char **path);
char **get_env_path_dir(void);
void free_memory(int n, ...);
int non_interactive_mode(char **av);
int Interactve_shell(char **av __attribute__((unused)));
int count_delim_str(char *buf);
char **tokenize(char *buf, int num_tokens);
int execcmd(char *cmd, char **args);
void all_free(char **path_dirs, char **user_args, char *s_ptr1, char *s_ptr2);
void logo(void);
int strn_comp(char *str1, char *str2, size_t n);
int str_length(char *str);
int *_strdup(char *str);
int strcomp(char *str1, char *str2);
char *strk(char *dest, char *src);
int contains_only_spaces(char *buf);
int num_len(int n);
char *int_to_str(int n);
char *my_str_concat(char *destination, char *src);
char *_strdup(char *s);
char *_itoa(int num);
char *str_contains(char str1, char str2);
int comp_str(char str1, char str2);
int _strlen(char *str);
int strcmp(char *str1, char str2);
int _strncmp(char *str1, char str2, size_t n);
char *str_copy(char *dest, char *str);
void handle_bad_cmd(char **args, char *buf);
char **constr_cmd_args(char *buf);
void handle_lines(char *buf, int buf_len, char **args, char **env_args);
int exec_piped_cmd(char **av __attribute__((unused)));
void free_envargs(char **path_dirs, char **args);
#endif
