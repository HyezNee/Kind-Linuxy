#pragma once

#include<stdio.h>
#include<string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

//commandManager
void _manage();

//userInfo
void _printInfo();

//userInput
void _command(char** info);

//userOutput
int _work(char **info);
void _fileopen();

//
