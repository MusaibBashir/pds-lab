/*Name= Musaib Bin Bashir
Roll No.= 24IM10047
Group No.= 1
PC No= 81
Description= "PDS Lab Section 04, Assignment 1"*/


#include<stdio.h>
#include<math.h>
int main()
{
    /*Declare all variables required for the program*/
    int x1,y1,x2,y2,x3,y3,x4,y4,c,rh,t1,t2,t3;
    float d1,d2,d3,d4,d5,per,h;

    /*Take the input coordinates P,Q and R and print them and raise warning if negative number detected*/
    printf("Enter coordinate of point P\n");
    scanf("%d%d",&x1,&y1);
    if (x1<0||y1<0)
        printf("Negative coordinates detected\n");
    printf("P=(%d,%d)\nEnter coordinate of point Q\n",x1,y1);
    scanf("%d%d",&x2,&y2);
    if (x1<0||y1<0)
        printf("Negative coordinates detected\n");
    printf("Q=(%d,%d)\nEnter coordinate of point R\n",x2,y2);
    scanf("%d%d",&x3,&y3);
    if (x1<0||y1<0)
        printf("Negative coordinates detected\n");
    printf("R=(%d,%d)\n",x3,y3);
    printf("P=(%d,%d), Q=(%d,%d), R=(%d,%d)\n", x1,y1,x2,y2,x3,y3);




    /*Euclidean Distance*/
    d1=sqrt(pow(x2-x1,2)+ pow(y2-y1,2));
    d2=sqrt(pow(x2-x3,2)+ pow(y2-y3,2));
    d3=sqrt(pow(x3-x1,2)+ pow(y3-y1,2));
    printf("Distance between P&Q=%2.3f,\nDistance between Q&R=%2.3f,\nDistance between P&R=%2.3f\n",d1,d2,d3);

    /*If point R lies on line segment PQ*/
    if(d3+d2==d1)
        printf("R lies on line segment PQ\n");
    else if (d2>d3)
        printf("R lies closer to P\n");
    else if (d3>d2)
        printf("R lies closer to Q\n");
    else
        printf("R does not lie on line segment PQ and is equidistant from the ends P&Q\n");




    /*Perimeter of Triangle formed*/
    if(d1+d2==d3 || d2+d3==d1 || d1+d3==d2)
        {
            printf("No triangle possible, as given points are collinear\n");
            c=1; /*This c has been initialized here so that in next part of right angle calculation we can skip collinear case, hence reducing calculation*/
        }
    else
        {
        per= d1+d2+d3;
        if (per>20)
            printf("Large Triangle\nPerimeter=%2.3f\n",per);
        else
            printf("Small Triangle\nPerimeter=%2.3f\n",per);
        }




    /*Check for right angle triangle*/
    t1=pow(x2-x1,2)+ pow(y2-y1,2); /*using squares instead of squaring the root due to approximation in float in case of irrational numbers, which was leading to errors and was declaring unequal where it should have been equal*/
    t2=pow(x2-x3,2)+ pow(y2-y3,2);
    t3=pow(x3-x1,2)+ pow(y3-y1,2);
    if (c==1)
        printf("Not a right angled triangle\n");
    else
        {
        h=t1>t2?t1:t2; /*we choose the larger between t1 and t2 and then compare that with t3*/
        h=t3>h?t3:h;


        if (h=t1+t2+t3-h)
            {
                printf("Right Angled Triangle\n");
                rh=1;
                if (h==t1)
                    printf("Right angle= Angle PQR\n"); /*We use the logic that hypotenuse lies opposite to right angle*/
                else if (h==t2)
                    printf("Right angle= Angle QPR\n");
                else
                    printf("Right angle= Angle PRQ\n");

            }
        else
            printf("Not a Right Angled Triangle\n");
        }



    /*Check for rhombus and rectangle*/
    printf("Enter fourth coordinate\n");
    scanf("%d%d", &x4,&y4);
    if (x4<0||y4<0)
        printf("Negative coordinates detected\n");
    printf("S=(%d,%d)\n",x4,y4);
    d4=sqrt(pow(x3-x4,2)+ pow(y3-y4,2));
    d5=sqrt(pow(x4-x1,2)+ pow(y4-y1,2));
    if(d1==d2&&d2==d4&&d4==d5)
        printf("Rhombus\n"); /*To calculate which side without using loops would be tedious and as I haven't brought rough with me it is getting difficult to keep track of cases, So I have skipped that particular part of this question*/
        if (d1==d4 && d2==d5 && rh==1)
            printf("Rectangle\n");
        else if ((d1!=d4 || d2!=d5)&& rh==1)
            printf("Opposite sides not equal\n");
        else if ((d1==d4 && d2==d5)&& rh!=1)
            printf("Not Right angled\n");
        else
            printf("Nor rhombus, Nor rectangle :Neither Opposite sides are equal nor angle is right angle\n");




}



