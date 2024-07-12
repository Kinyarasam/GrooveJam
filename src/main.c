#include <stdio.h>
#include <stdlib.h>
#include "player.h"

/**
 * main - Entry Point for the music player program.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 * 
 * Checks the command-line arguments and calls the play_music
 * function to play a specific file.
 * 
 * Return: Always 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <mp3 file>\n", argv[0]);
        return (1);
    }

    play_music(argv[1]);

    return (0);
}
