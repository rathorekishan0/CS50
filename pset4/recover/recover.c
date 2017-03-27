/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    uint8_t buffer[512];
   	int image=0;
    char filename[8];
    FILE *img;
    
    
    while(fread(buffer,512,1,inptr)>0)
    {
        
        
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0)==0xe0)
        {
             sprintf(filename,"%03i.jpg",image);
            if(image==0)
            {
               
            
            img= fopen(filename,"w");
            fwrite(buffer, sizeof(buffer), 1, img);
            image++;
            }
            else
            {
                fclose(img);
                img= fopen(filename,"w");
                fwrite(buffer, sizeof(buffer), 1, img);
                image++;
            }
        }
        else    if(image>0)
            {
                
                fwrite(buffer,sizeof(buffer),1,img);
               
            }
    }        
            
    if(img)
    {
      fclose(img);
    }
    fclose(inptr);
    
    return 0;
}
