#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PROCESSES 10

pid_t running_processes[MAX_PROCESSES];
int num_processes = 0;

void execute_command(char *command, char *args[]) 
{
	pid_t pid = fork();
	
	if (pid == -1) 
	{
		perror("Erreur lors de la création du processus enfant");
		exit(EXIT_FAILURE);
	} 
	else if (pid == 0) 
	{
	/*Processus enfant*/
	/* execvp(command, args);*/
	/* Si execvp échoue, affichez une erreur*/
		perror("Erreur lors de l'exécution de la commande");
		exit(EXIT_FAILURE);
	} else 
	{
        /* Processus parent*/
        /* Ajouter le PID du processus en cours d'exécution à la liste*/
		if (num_processes < MAX_PROCESSES) 
		{
			running_processes[num_processes++] = pid;
		} 
		else 
		{
			printf("Nombre maximal de processus en cours atteint. Attendre la fin d'un processus...\n");
			waitpid(running_processes[0], NULL, 0);
            /* Retirer le PID du processus terminé de la liste*/
			for (int i = 0; i < num_processes - 1; ++i) 
			{
				running_processes[i] = running_processes[i + 1];
			}
			running_processes[num_processes - 1] = pid;
		}
	}
}

void wait_for_processes() 
{
    /* Attendre la fin de tous les processus en cours*/
	for (int i = 0; i < num_processes; ++i)
	{
		waitpid(running_processes[i], NULL, 0);
	}
	num_processes = 0;
}

int main() 
{
	char *input = NULL;
	size_t input_size = 0;
	
	while (1) {
        /* Affiche le prompt ou toute autre information de votre shell*/
		printf("MonShell> ");
		
		/* Utilise getline pour lire l'entrée de l'utilisateur*/
		if (getline(&input, &input_size, stdin) == -1) 
		{
			perror("Erreur lors de la lecture de l'entrée");
			exit(EXIT_FAILURE);
		}

        /* Supprime le caractère de nouvelle ligne à la fin de l'entrée*/
		size_t input_length = strlen(input);
		if (input_length > 0 && input[input_length - 1] == '\n') 
		{
			input[input_length - 1] = '\0';

            /* Affiche le prompt uniquement si la chaîne n'est pas vide*/
			if (input_length > 1) 
			{
				/* Analyse de la commande*/
				char *token = strtok(input, " ");
				if (token != NULL) 
				{
                    /* Comparaison avec différentes commandes*/
					if (strcmp(token, "ls") == 0) 
					{
                        /* Récupérer les arguments après la commande 'ls'*/
						char *ls_args[MAX_INPUT_SIZE];
						int ls_arg_count = 0;
						token = strtok(NULL, " ");  /* Récupère le premier argument (peut être une option)*/
						
						while (token != NULL) 
						{
							ls_args[ls_arg_count] = token;
							ls_arg_count++;
							token = strtok(NULL, " ");  // Récupère les arguments suivants
						}

                        // Ajouter NULL à la fin des arguments
                        ls_args[ls_arg_count] = NULL;

                        // Exécutez la commande 'ls' avec ses arguments
                        execute_command("/bin/ls", ls_args);
                    } else if (strcmp(token, "cd") == 0) {
                        // ... (code existant pour 'cd')
                    } else if (strcmp(token, "cp") == 0) {
                        // ... (code existant pour 'cp')
                    } else if (strcmp(token, "rm") == 0) {
                        // ... (code existant pour 'rm')
                    } else if (strcmp(token, "man") == 0) {
                        // ... (code existant pour 'man')
                    } else if (strcmp(token, "echo") == 0) {
                        // Exécutez la commande 'echo' avec ses arguments
                        token = strtok(NULL, "");  // Récupère tous les arguments après 'echo'
                        char *args[] = {"/bin/echo", token, NULL};
                        execute_command("/bin/echo", args);
                    } else if (strcmp(token, "wait") == 0) {
                        // ... (code existant pour 'wait')
                    } else {
                        // Commande inconnue
                        printf("Commande inconnue : %s\n", token);
                    }
                }
            }
        } else {
            // Si la chaîne lue est vide, affichez le prompt à nouveau
            free(input);
            input = NULL;
            input_size = 0;
            continue;
        }

        // Réinitialisez la mémoire utilisée par getline pour la prochaine itération
        free(input);
        input = NULL;
        input_size = 0;
    }

    return 0;
}
