#include<stdio.h>
#include<math.h>

struct Point{
    float x; // x coordinate
    float y; // y 
};

void input(struct Point pts[], unsigned int n){
    for(int i=0;i<n ;i++){
        printf("\nPoint %d \n", i);
        printf("x = ");
        scanf("%f", &(pts[i].x));
        printf("y = ");
        scanf("%f", &(pts[i].y));
    }
} 

void print(struct Point pts[], unsigned int n){
    for(int i =0;i<n ;i++){
        printf("(%f, %f)\n", pts[i].x, pts[i].y);
    }
}

float edistance(struct Point p1, struct Point p2){
    return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y, 2) );
}

float cpair_dist(struct Point pts[], unsigned int n){
    float mindistance = INFINITY;
    for(int i=0;i<n-1; i++){
        for(int j=i+1; j<n; j++){
            float dist = edistance(pts[i], pts[j]);
            if(mindistance > dist){
                mindistance = dist;
            }
        }
    }
    return mindistance;
}

int main()
{
    unsigned int n =0;
    printf("Enter n: ");
    scanf("%u", &n);

    struct Point pts[n];
    input(pts, n);

    //printf("\n %p", pts);
    //printf("\n %p", &pts[0]);
    
    print(pts, n); 
    float mindistance  = cpair_dist(pts, n);

    printf("\nClosest Pair distance : %f\n", mindistance);
    return 0;
}
