# Questions

## What's `stdint.h`?

'stdint.h' is a header file in the C standard library that allow programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It depends on the contest of the program, sometimes you need a specific range of width for your programs, so those help with that, and make sure your values don't exceed what they are intended to be. For example, in an embedded programming contest.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A 'BYTE' is 1-byte long
A 'DWORD' is 4-bytes long
A 'LONG' is 4-bytes long
A 'WORD' is 2-bytes long

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must be the file type, bfType which is "BM"

## What's the difference between `bfSize` and `biSize`?

'bfSize' is the size of the whole bmp file (including biSize), instead 'biSize' is the size of the actual image, the array of pixels + padding

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

'biBitCount' is the field in 'BITMAPINFOHEADER' that specifies the BMP's color depth 

## Why might `fopen` return `NULL` in `copy.c`?

'fopen' might return 'NULL' if it's unable to open the given file

## Why is the third argument to `fread` always `1` in our code?

Because 1 represent the whole defined structure at once, representing a whole section or pixel

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

'padding' will probably be assigned the value 3

## What does `fseek` do?

'fseek' is the function which helps move the cursor inside the file on a certain number of bytes

## What is `SEEK_CUR`?

'SEEK_CUR' is the macro representing the actual position of the cursor in the file

