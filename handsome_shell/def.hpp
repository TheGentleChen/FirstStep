/*
 * @Author: HandsomeChen 
 * @Date: 2019-09-07 22:50:08 
 * @Last Modified by:   HandsomeChen 
 * @Last Modified time: 2019-09-07 22:50:08 
 */
#ifndef _DEF_
#define _DEF_
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_CMD 20
#define MAX_GRP 10
#define BUF_SIZE 1024
#define PIPE 1
#define BACKGROUND 2
#define IN_REDIRECT 4
#define OUT_REDIRECT 8
#define OUT_REDIRECT_APPEND 16

struct command_info
{
    int type;
    char *input;
    char *output;
    char *cmd;
    char **param;
    int paramLen;
};
struct command_info array_cmd[MAX_CMD];

struct command_grp
{
    int first, last;  
};
struct command_grp array_grp[MAX_GRP];

void parse_semicolon(char *cmdLine);
void parse_grp(char *grp);
void parse_command(char *cmd);
void make_prompt();
void read_command(char *cmdLine);
void run_cmdLine();
void run_grp(int first, int last, int index);
void clear_cmdLine();
#endif //_DEF_