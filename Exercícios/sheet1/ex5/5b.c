#include <stdio.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

int main(int argc, char *argv[], char **envp) {
    for (char **env = envp; *env != 0; ++env) {
        for(int i = 0; i < argc; ++i){
            if (strncmp(*env, argv[i], MIN(strlen(argv[i]), strlen(*env))) == 0) {
                printf("%s\n", *env);
                break;
            }
        }
    }
    return 0;
}