/* C based interface for IRI model
This interface reads user's request from 'request.txt' and pass it to 
the subroutine 'iritest_" which along with supporting subroutines and 
data files, runs the IRI model. The output for the requested range is 
stored in 'output.txt'
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


extern float iritest_(int *, float[],float[], int *,int *,int *, float[],float[], int *,float[],float[],float[], int *,float[],int *, float[1000][20],float[1000][100]);

int main()
{

// Read user's request

FILE *fp;
int buff;
char def[100];

fp = fopen("request.txt", "r");

int jm;           // Coordinates type geographical/geometrical (0/1)
fscanf(fp, "%d %s",&jm,def);
printf("%s : %d\n",def, jm );

int iy;        // Year
fscanf(fp, "%d %s",&iy,def);
printf("%s : %d\n",def, iy );

int imd;       // Month, day (mmdd)
fscanf(fp, "%d %s",&imd,def);
printf("%s : %d\n",def, imd );

int iut;          // local/ universal time (0/1)
fscanf(fp, "%d %s",&iut,def);
printf("%s : %d\n",def, iut );

int ivar;         // variable
fscanf(fp, "%d %s",&ivar,def);
printf("%s : %d\n",def, ivar );

float xlat;      // Latitude
fscanf(fp, "%f %s",&xlat,def);
printf("%s : %f\n",def, xlat );

float xlon;      // Longitude
fscanf(fp, "%f %s",&xlon,def);
printf("%s : %f\n",def, xlon );

float hour; // Time in decimal notation
fscanf(fp, "%f %s",&hour,def);
printf("%s : %f\n",def, hour );

float hx;       // Height
fscanf(fp, "%f %s",&hx,def);
printf("%s : %f\n",def, hx );

float htec_max; // Max height for TEC integration
fscanf(fp, "%f %s",&htec_max,def);
printf("%s : %f\n",def, htec_max );

float vbeg;      // Initial value for choosen variable
fscanf(fp, "%f %s",&vbeg,def);
printf("%s : %f\n",def, vbeg );

float vend;    // Final value for choosen variable
fscanf(fp, "%f %s",&vend,def);
printf("%s : %f\n",def, vend );

float vstp;      // Increment step for choosen variable
fscanf(fp, "%f %s",&vstp,def);
printf("%s : %f\n",def, vstp );

int jchoice;      // Options standard/custom  (0/1)
fscanf(fp, "%d %s",&jchoice,def);
printf("%s : %d\n",def, jchoice );

int piktab = 0;       // choosen output
//fscanf(fp, "%d %s",&piktab,def);
//printf("%s : %d\n",def, piktab );

fclose(fp);


//int jm = 0;           // Coordinates type geographical/geometrical (0/1)
//int iy = 2021;        // Year
//int imd = 0303;       // Month, day (mmdd)
//int iut = 1;          // local/ universal time (0/1)
//int ivar = 1;         // variable
//float xlat = 35;      // Latitude
//float xlon = 70;      // Longitude
//float hour = 11.0000; // Time in decimal notation
//float hx = 100;       // Height
//float htec_max = 1500;// Max height for TEC integration
//float vbeg = 60;      // Initial value for choosen variable
//float vend = 1000;    // Final value for choosen variable
//float vstp = 10;      // Increment step for choosen variable
//int jchoice = 0;      // Options standard/custom  (0/1)
//int piktab = 5;       // choosen output


float outf[1000][20], oar[1000][100];
iritest_(&jm,&xlat,&xlon,&iy,&imd,&iut,&hour,&hx,&ivar,&vbeg,&vend,&vstp,&piktab,&htec_max,&jchoice,outf,oar);

// Print to output

FILE *fq;
fq = fopen("output.txt", "w+");
  
for(int i = 1; vbeg + i*vstp <= vend; i++) {
    fprintf(fq,"%f ", (vbeg + i*vstp));
    for(int j = 0; j < 20; j++) {
        fprintf(fq,"%e ", outf[i][j]);
    }
    for(int j = 0; j < 100; j++) {
        fprintf(fq,"%f ", oar[i][j]);
    }
     fprintf(fq,"\n");
}   
  
  
  fclose(fq);
printf("%f",oar[1][1]);
}
