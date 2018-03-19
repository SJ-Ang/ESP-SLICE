#include <stdio.h>
#include <stdlib.h>

#define dap 3.80 //Define perpendicular distance above plane

int main() {

	FILE *fpesp, *fpdim, *fpxyz, *fpspecs;
	char ascii[20], asciiesp[20], dim[10], atom[5], cdn[20], specs[20];
	int i, j, k, l, N, xmat;
        double temp, max=0, dist;
//Reading the dimension of the cube 
	fpdim = fopen("dim.txt","r");
        fscanf(fpdim, "%s", dim);
        int a = strtod(dim,NULL); 
        fscanf(fpdim, "%s", dim);
        int b = strtod(dim,NULL); 
        fscanf(fpdim, "%s", dim);
        int c = strtod(dim,NULL); 
     fclose(fpdim);
        
        N=a*b*c; //total number of points 


//Reading the xyz file
      fpxyz = fopen("mol.xyz","r");
      fscanf(fpxyz,"%s",atom);
      int noa = strtod(atom,NULL);
      
      double at[noa][5];

      for(i=0;i<noa;i++)
         for(j=0;j<5;j++){
      fscanf(fpxyz,"%s",cdn);
      at[i][j] = strtod(cdn,NULL);
      }
fclose(fpxyz);


//Read Cube Specifications
      fpspecs = fopen("specs.txt","r");

      double origin[3], xu[3], yu[3], zu[3];
      for(i=0;i<3;i++){
        fscanf(fpspecs,"%s",specs);
        origin[i] = strtod(specs,NULL);
        }
      for(i=0;i<3;i++){
        fscanf(fpspecs,"%s",specs);
        xu[i] = strtod(specs,NULL);
        }
      for(i=0;i<3;i++){
        fscanf(fpspecs,"%s",specs);
        yu[i] = strtod(specs,NULL);
        }
      for(i=0;i<3;i++){
        fscanf(fpspecs,"%s",specs);
        zu[i] = strtod(specs,NULL);
        }
       fclose(fpspecs);

//Find matrix element in z direction corresponding to specified distance above plane
       for(xmat=0; dist<(dap-0.1);xmat++) {
       dist=xu[0]*xmat+origin[0];
       }
       xmat=xmat-1;
       printf("%lf and %d", dist, xmat); //debug mode

//Reading esp data
        fpesp = fopen("esp.txt","r");
	
      for(i=0;i<a;i++)
	 for(j=0;j<b;j++)
	   for(k=0;k<c;k++)
	{ 
	        fscanf(fpesp, "%s", asciiesp);
	        double y = strtod(asciiesp,NULL);
		if(i==xmat)
		{
                printf("%lf \t %lf \t %lf \n",j*yu[1]+origin[1],k*zu[2]+origin[2],y);
                
                                 }
}
                                 
			fclose(fpesp);
	return 0;
}


