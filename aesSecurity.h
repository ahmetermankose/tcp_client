
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <openssl/aes.h>

void print_data(const char *tittle, const void* data, int len);
char* encryptJson(char *value);