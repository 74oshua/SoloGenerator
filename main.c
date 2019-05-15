#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define C   0
#define Db  1
#define D   2
#define Eb  3
#define E   4
#define F   5
#define Gb  6
#define G   7
#define Ab  8
#define A   9
#define Bb  10
#define B   11

void gen_solo(unsigned char * scale, int notes, int len, int key);

// Print the name of the note
void print_note(int note)
{
    switch (note)
    {
        case C:
            printf("C");
            break;
        case Db:
            printf("Db");
            break;
        case D:
            printf("D");
            break;
        case Eb:
            printf("Eb");
            break;
        case E:
            printf("E");
            break;
        case F:
            printf("F");
            break;
        case Gb:
            printf("Gb");
            break;
        case G:
            printf("G");
            break;
        case Ab:
            printf("Ab");
            break;
        case A:
            printf("A");
            break;
        case Bb:
            printf("Bb");
            break;
        case B:
            printf("B");
    };
}

int main(int argc, char ** argv)
{
    // random seed generation
    srand(time(NULL));

    // avalible scales
    unsigned char major[] = { 2, 2, 1, 2, 2, 2, 1 };
    unsigned char nminor[] = { 2, 1, 2, 2, 1, 2, 2 };
    unsigned char hminor[] = { 2, 1, 2, 2, 1, 3, 1};

    // simple text interface
    printf("Welcome! What scale would you like to use?\n");
    printf("1: Major\n");
    printf("2: Natural Minor\n");
    printf("3: Harmonic Minor\n");

    char * scale = 0;
    int scale_len = 0;

    while (scale == 0)
    {
        switch (fgetc(stdin))
        {
            case '1':
                scale = major;
                scale_len = sizeof(major);
                break;
            case '2':
                scale = nminor;
                scale_len = sizeof(nminor);
                break;
            case '3':
                scale = hminor;
                scale_len = sizeof(hminor);
                break;
        }
    }
    
    char key[] = { 0, 0, 0 };
    int keyval = 12;

    printf("What key would you like it to be in?\n");
    printf("Enter a note (Ex: C, Db, F#)\n");

    // flush last newline
    while (getchar() != '\n');

    while (keyval == 12)
    {
        fgets(key, sizeof(key), stdin);
        
        if (!strncmp(key, "C\n", sizeof(key)))
        {
            keyval = C;
        }
        else if (!strncmp(key, "Db", sizeof(key)) || !strncmp(key, "C#", sizeof(key)))
        {
            keyval = Db;
        }
        else if (!strncmp(key, "D\n", sizeof(key)))
        {
            keyval = D;
        }
        else if (!strncmp(key, "Eb", sizeof(key)) || !strncmp(key, "D#", sizeof(key)))
        {
            keyval = Eb;
        }
        else if (!strncmp(key, "E\n", sizeof(key)))
        {
            keyval = E;
        }
        else if (!strncmp(key, "F\n", sizeof(key)))
        {
            keyval = F;
        }
        else if (!strncmp(key, "Gb", sizeof(key)) || !strncmp(key, "F#", sizeof(key)))
        {
            keyval = Gb;
        }
        else if (!strncmp(key, "G\n", sizeof(key)))
        {
            keyval = G;
        }
        else if (!strncmp(key, "Ab", sizeof(key)) || !strncmp(key, "G#", sizeof(key)))
        {
            keyval = Ab;
        }
        else if (!strncmp(key, "A\n", sizeof(key)))
        {
            keyval = A;
        }
        else if (!strncmp(key, "Bb", sizeof(key)) || !strncmp(key, "A#", sizeof(key)))
        {
            keyval = Bb;
        }
        else if (!strncmp(key, "B\n", sizeof(key)))
        {
            keyval = B;
        }
    }

    int notes = 0;

    printf("How many notes would you like to generate?\n");
    scanf("%d", &notes);

    gen_solo(scale, scale_len, notes, keyval);
}

void gen_solo(unsigned char * scale, int notes, int len, int key)
{
    // generate avalible notes in the scale and key
    int anotes[notes];
    anotes[0] = key;
    for (int i = 1; i < notes; i++)
    {
        anotes[i] = (anotes[i - 1] + scale[i - 1]) % 12;
    }

    // spit out random notes from the scale
    for (int i = 0; i < len; i++)
    {
        print_note(anotes[rand() % notes]);
        printf(" ");
    }
    printf("\n");
}