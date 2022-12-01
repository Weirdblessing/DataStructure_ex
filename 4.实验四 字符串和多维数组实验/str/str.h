#ifndef STR_H_INCLUDED
#define STR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
int strlen(char *);
char *strcat(char *s1,char *s2);
int strcmp(char *s1,char *s2);
void BF(char S[],char T[]);
const int Max=1000;
#endif // STR_H_INCLUDED
