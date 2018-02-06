// Assignment #2      USE TEXT FILE LDB.txt TO TEST CODE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 4800


typedef struct sensor_str{
        double x[SIZE];
        double y[SIZE];
        double z[SIZE];
}sensor_data;

sensor_data data;

/*----------------------------------------------------------------*/

float read_data(sensor_data s)
{
    FILE* file; 
    int i;
    file=fopen("LDB.txt", "r");
    if(file==NULL){
       printf("File not found. \n");
       return(0);
       }
    for(i=0;i<SIZE;i++){
         fscanf(file,"%lf\t%lf\t%lf \n",(&data.x[i]), (&data.y[i]),(&data.z[i]));
         //printf("The following is the data set: \n %lf\t%lf\t%lf \n",(data.x[i]), (data.y[i]),(data.z[i]));
    }
    fclose(file);
    return(0);
}

float maximum_acc(sensor_data s)
{
    double A_x;A_x=0;
    double A_y;A_y=0;
    double A_z;A_z=0;
    double maximum;maximum=0;
    double magnitude;magnitude=0;
    int p; 
    for(p=0;p<SIZE;p++)
    {

        if ((fabs(data.x[p]))>A_x)
            (A_x=fabs(data.x[p]));
        

        if ((fabs(data.y[p]))>A_y)
            (A_y=fabs(data.y[p]));
        
        if ((fabs((data.z[p])))>A_z)
            (A_z=fabs(data.z[p]));
        
        magnitude=sqrt(((data.x[p])*(data.x[p]))+((data.y[p])*(data.y[p])));
                    if(fabs(magnitude>maximum))
                            maximum=magnitude;
}

    printf("The maximumimum acceleration in the x axis is %f \n",fabs(A_x));
    printf("The maximumimum acceleration in the y axis is %f \n",fabs(A_y));
    printf("The maximumimum acceleration in the z axis is %f \n",fabs(A_z));
    printf("The maximumimum acceleration in the x-y axis is %f \n",fabs(maximum));
}

/*----------------------------------------------------------------*/

int main(void)
{
    read_data(data);
    maximum_acc(data);

    return(0);
}
