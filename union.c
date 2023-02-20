#include <unistd.h>

int check_db(char *str, char c, int idx) {
    int i = 0;
    while (i < idx) {
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int check_db_str(char *str, char c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == c) 
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int i = 0;
    if (argc == 3) {
        while (argv[1][i]) {
            if (check_db(argv[1], argv[1][i], i))
                write(1, &argv[1][i], 1);
            i++;
        }
        i = 0;
        while (argv[2][i]) {
            if (check_db_str(argv[1], argv[2][i])) {
                if (check_db(argv[2], argv[2][i], i))
                    write(1, &argv[2][i], 1);
            }
            i++;
        }
    }
    write(1, '\n', 1);
    return 0;
}