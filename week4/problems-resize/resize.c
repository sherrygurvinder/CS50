/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{   
    int k,z;
    // ensure proper usage
   int size=atoi(argv[1]);
    if (argc!=4||size<0||size>100)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biWidth = bi.biWidth*size;
    bi.biHeight = bi.biHeight*size;

            printf("\n %d biHeight",bi.biHeight);
            printf(" \n %d biwidth",bi.biWidth);
    bi.biSizeImage = ((sizeof(RGBTRIPLE)*bi.biWidth)+padding)*abs(bi.biHeight); 
    bf.bfSize= bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    int New_Padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // write outfile's BITMAPFILEHEADER
    printf("%d New_Padding\n",New_Padding );
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight/size); i < biHeight; i++)
    {
        for(z=0;z<size-1;z++)
        {
        // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth/size; j++)
            {
                //printf("%d\size biHeight",biHeight);
                //printf("%d biwidth",bi.biWidth);
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for(k=0;k<size;k++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
                }              
            }

           
            // then add it back (to demonstrate how)
            for (int k = 0; k <New_Padding; k++)
            {
                fputc(0x00, outptr);
            }
             // skip over padding, if any
            fseek(inptr,-9, SEEK_CUR);

        }
    //iterate over pixels in scanline
       for (int j = 0; j < bi.biWidth/size; j++)
        {
            //printf("%d\size biHeight",biHeight);
            //printf("%d biwidth",bi.biWidth);
            // temporary storage
            RGBTRIPLE triple;
       
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            for(k=0;k<size;k++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
            }              
        }
        // then add it back (to demonstrate how)
        for (int k = 0; k <New_Padding; k++)
        {
            fputc(0x00, outptr);
        }
         // skip over padding, if any
        fseek(inptr,padding, SEEK_CUR);
        
    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
