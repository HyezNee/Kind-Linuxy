#pragma once

#include<stdio.h>
#include<string.h>

//commandManager
void _manage();

//userInfo
void _printInfo();

//userInput
void _command();
void _parse(char *str, char *buf);

//userOutput
int _work(char **info);
void _fileopen();