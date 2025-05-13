#ifndef INPUT_HELPERS_H
#define INPUT_HELPERS_H

int get_valid_int(const char* prompt, int min, int max);
void get_valid_string(const char* prompt, char* dest, int max_len);

#endif 