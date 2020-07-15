#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

//Declaration of a cuntion

bool new_jpg(BYTE buffer[]);

//Defining the size of the block that we are covering

#define block_size 512

//Defining file name size, "xxx.jpg."

#define file_name 8

int main(int argc, char *argv[])
{

    //Tells the user its proper usage.

    if (argc != 2)
    {
        printf("Correct usage: /recover image\n");
        return 1;
    }

    //If the filne is not a image, it gives a message and quits.

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file.\n");
        return 1;
    }

    //A counter to keep track of how many jpeg we've found so far

    int file_counter = 0;

    //Creating an array of size 512 for alocating the jpg file.

    BYTE buffer[block_size];

    //Bool to see if we have found the jpg file.

    bool jpg_found = false;

    FILE *outfile;

    //Reading one blocksize into buffer array.

    while (fread(buffer, block_size, 1, file))
    {
        //Function that finds a new jpg file.

        if (new_jpg(buffer))
        {

            if (!jpg_found)

            {

                //Flip this boolean to true because we have found a new jpg

                jpg_found = true;

            }

        //closing the file

                else

            {
                fclose(outfile);
            }

            //Creating a new file name.

            char filename[file_name];

            //Representing the new file

            sprintf(filename, "%03i.jpg", file_counter++);

            //Opening the file

            outfile = fopen(filename, "w");

            //Checking if there is any error

            if (outfile == NULL)

            {
                return 1;
            }

            // No error, then write from "buffer", one time, on "outfile".

            fwrite(buffer, block_size, 1, outfile);

        }

        // If we have found a jpg we must keep on writing the previous file

        else if (jpg_found)
        {
            fwrite(buffer, block_size, 1, outfile);
        }

    }

    //colsing the files


    fclose(outfile);
    fclose(file);

}

//Function to check if it is a jpg file.

bool new_jpg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}