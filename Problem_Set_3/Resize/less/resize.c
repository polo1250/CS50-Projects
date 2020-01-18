// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

//Important used functions
void prepare_outfile_headers(BITMAPINFOHEADER *outBi, BITMAPFILEHEADER *outBf, int n);
int get_padding(BITMAPINFOHEADER h);
void copy_from_to(FILE *infile, FILE *outfile, BITMAPINFOHEADER *inBi, BITMAPINFOHEADER *outBi, int n);


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    //Get n
    int n = atoi(argv[1]);

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

    //Create new BITMAPFILEHEADER varibale for output file to manipulate
    BITMAPFILEHEADER obf = bf;

    //Create new BITMAPINFOHEADER varibale for output file to manipulate
    BITMAPINFOHEADER obi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Modify headers values for output adapting to resizing scale
    prepare_outfile_headers(&obi, &obf, n);

    // determine padding for scanlines for input and output files
    int padding = get_padding(bi);
    int newpadding = get_padding(obi);

    // write outfile's BITMAPFILEHEADER
    fwrite(&obf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&obi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //Copy the pixels from the input file to the output file
    copy_from_to(inptr, outptr, &bi, &obi, n);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}


//Calculate the needed padding
int get_padding(BITMAPINFOHEADER h)
{
    return (4 - (h.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
}

//Prepare the headers for the outfile
void prepare_outfile_headers(BITMAPINFOHEADER *outBi, BITMAPFILEHEADER *outBf, int n)
{
    outBi->biWidth *= n;
    outBi->biHeight *= n;
    int pad = (4 - (outBi->biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    outBi->biSizeImage = ((sizeof(RGBTRIPLE) * outBi->biWidth) + pad) * abs(outBi->biHeight);
    outBf->bfSize = outBi->biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
}


void copy_from_to(FILE *infile, FILE *outfile, BITMAPINFOHEADER *inBi, BITMAPINFOHEADER *outBi, int n)
{
    int padding = get_padding(*inBi);
    int newpadding = get_padding(*outBi);
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inBi->biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < inBi->biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, infile);

                // write RGB triple to outfile
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outfile);
                }
            }

            // Add the padding at the end of the scanline
            for (int m = 0; m < newpadding; m++)
            {
                fputc(0x00, outfile);
            }

            // skip back to the beginning of the scanline
            fseek(infile, -(inBi->biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }

        for (int k = 0; k < inBi->biWidth; k++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, infile);

            // write RGB triple to outfile
            for (int l = 0; l < n; l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outfile);
            }
        }

        // Add the padding at the end of the scanline
        for (int m = 0; m < newpadding; m++)
        {
            fputc(0x00, outfile);
        }

        // skip over padding, if any
        fseek(infile, padding, SEEK_CUR);
    }

}
