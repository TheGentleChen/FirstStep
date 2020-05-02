/*
 * @Author: HandsomeChen 
 * @Date: 2019-09-07 22:50:13 
 * @Last Modified by:   HandsomeChen 
 * @Last Modified time: 2019-09-07 22:50:13 
 */
#include "def.hpp"

static int CNT_GRP = 0; //the counter of command group
static int CNT_CMD = 0; //the counter of command
static int fd[2];

int main(int argc, char const *argv[])
{
    char cmdLine[BUF_SIZE]; //the char array storing the command line
    while (1)
    {
        make_prompt();
        read_command(cmdLine);
        run_cmdLine();
        clear_cmdLine();
    }

    return 0;
}

/**
 * make prompt for USER,
 * print the prompt.
 */
void make_prompt()
{
    char cwd[BUF_SIZE];
    struct passwd *pwd = getpwuid(getuid());
    getcwd(cwd, BUF_SIZE);
    int size = strlen(pwd->pw_name) + strlen(cwd) + 20;
    char *prompt = malloc(size);
    strcpy(prompt, "[");
    strncat(prompt, pwd->pw_name, strlen(pwd->pw_name));
    strcat(prompt, "@handsomeshell ");
    strncat(prompt, cwd, strlen(cwd));
    strcat(prompt, "]");
    if (getuid() == 0)
        strcat(prompt, "# \0");
    else
        strcat(prompt, "$ \0");
    printf(prompt);
    free(prompt);
}

/**
 * split the COMMAND in one line,
 * Separator is ';'.
 */
void parse_semicolon(char *cmdLine)
{
    int len = strlen(cmdLine);
    if (cmdLine[len - 1] != ';')
    {
        cmdLine[len] = ';';
        cmdLine[++len] = '\0';
    }
    int j = 0;
    for (int i = 0; i < len; ++i)
    {
        if (cmdLine[i] == ';')
        {
            cmdLine[i] = '\0';
            parse_grp(cmdLine + j);
            j = i + 1;
        }
    }
}

/**
 * parse a command group including some '|' characters,
 * separater is '|'.
 */
void parse_grp(char *grp)
{
    int len = strlen(grp), j = 0;
    array_grp[CNT_GRP].first = CNT_CMD;
    for (int i = 0; i < len; ++i)
    {
        if (grp[i] == '|')
        {
            grp[i] = '\0';
            parse_command(grp + j);
            j = i + 1;
        }
    }
    parse_command(grp + j);
    array_grp[CNT_GRP++].last = CNT_CMD;
}

/**
 * parse a command including some redirect characters such as '>',
 * '>>', '<', then, the command and params will store into the array of array_cmd.
 */
void parse_command(char *cmd)
{
    int len = strlen(cmd), i = 0, j = 0;
    int GET_CMD = 0, GET_ARGS = 0;
    int CNT_PARAM = 0;
    array_cmd[CNT_CMD].param = malloc(sizeof(char *) * MAX_ARGS);
    while (cmd[i] == ' ' || cmd[i] == '\t')
        i++, j++;
    for (; i < len; ++i)
    {
        if (!GET_ARGS)
        {
            if (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\0')
            {
                cmd[i] = '\0';
                if (!GET_CMD)
                {
                    GET_CMD = 1;
                    array_cmd[CNT_CMD].cmd = cmd + j;
                }
                array_cmd[CNT_CMD].param[CNT_PARAM++] = cmd + j;
            }
            while (i < len && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\0'))
            {
                i++;
                j = i;
            }
        }

        if (cmd[i] == '>')
        {
            GET_ARGS = 1;
            if (cmd[i + 1] == '>')
            {
                array_cmd[CNT_CMD].type |= OUT_REDIRECT_APPEND;
                ++i;
            }
            else
            {
                array_cmd[CNT_CMD].type |= OUT_REDIRECT;
            }
            ++i;
            while (i < len && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\0'))
                i++;
            array_cmd[CNT_CMD].output = cmd + i;
        }
        else if (cmd[i] == '<')
        {
            GET_ARGS = 1;
            array_cmd[CNT_CMD].type |= IN_REDIRECT;
            ++i;
            while (i < len && (cmd[i] == ' ' || cmd[i] == '\t' || cmd[i] == '\0'))
                i++;
            array_cmd[CNT_CMD].input = cmd + i;
        }
    }
    array_cmd[CNT_CMD].paramLen = CNT_PARAM;
    ++CNT_CMD;
}

/**
 * read a command line from the standard input stream.
 */
void read_command(char *cmdLine)
{
    gets(cmdLine);
    parse_semicolon(cmdLine);

    // printf("%d %d\n", CNT_GRP, CNT_CMD);
    // for (int i = 0;i < CNT_CMD;++i)
    // {
    //     printf("%s %d %s %s\n", array_cmd[i].cmd, array_cmd[i].type ,array_cmd[i].input, array_cmd[i].output);
    //     for (int j = 0;j < array_cmd[i].paramLen;++j)
    //         printf("%s\n", array_cmd[i].param[j]);
    // }
}
void run_cmdLine()
{
    fd[0] = open(PIPE, O_CREAT | O_RDONLY, 0666);
    fd[1] = open(PIPE, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    for (int i = 0;i < CNT_GRP;++i)
    {
        if (fork() == 0)
        {
            run_grp(array_grp[i].first, array_grp[i].last-1, i);
            return 1;
        }
        else
        {
            waitpid(0, NULL, 0);
        }
        
    }
}
void run_grp(int first, int last, int index)
{
    if (first != last)
    {
        if (fork() == 0)
        {
            run_grp(first, last-1, index);
            return 1;
        }
        else
            waitpid(0, NULL, 0);
        dup2(fd[0], fileno(stdin));
    }
    if (last != array_grp[index].last-1)
        dup2(fd[1], fileno(stdout));

    execvp(array_cmd[last].cmd, array_cmd[last].param);
}

/**
 * clear all of global params after running a command line.
 */
void clear_cmdLine()
{
    CNT_CMD = 0;
    CNT_GRP = 0;
    close(fd[0]);
    close(fd[1]);
}