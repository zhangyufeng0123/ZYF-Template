// 最大三角形
const int N=50005;
 
struct Point
{
    double x,y;
};
 
Point stack[N];
Point p[N];
Point MinA;
 
int top;
 
double dist(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
 
double cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
 
bool cmp(Point a,Point b)
{
    double k=cross(MinA,a,b);
    if(k>0) return 1;
    if(k<0) return 0;
    return dist(MinA,a)<dist(MinA,b);
}
 
void Graham(int n)
{
    int i;
    for(i=1; i<n; i++)
        if(p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
            swap(p[i],p[0]);
    MinA=p[0];
    sort(p+1,p+n,cmp);
    stack[0]=p[0];
    stack[1]=p[1];
    top=1;
    for(i=2; i<n; i++)
    {
        while(cross(stack[top-1],stack[top],p[i])<=0&&top>=1) --top;
        stack[++top]=p[i];
    }
}
 
double rotating_calipers(int n)
{
    int j=1,k=0;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        k=(j+1)%n;
        while(fabs(cross(stack[i],stack[j],stack[k]))<fabs(cross(stack[i],stack[j],stack[(k+1)%n])))
             k=(k+1)%n;
        while(j!=i&&k!=i)
        {
            ans=max(ans,fabs(cross(stack[i],stack[j],stack[k])));
            while(fabs(cross(stack[i],stack[j],stack[k]))<fabs(cross(stack[i],stack[j],stack[(k+1)%n])))
                 k=(k+1)%n;
            j=(j+1)%n;
        }
    }
    return ans*0.5;
}
 
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        for(int i=0;i<n;i++)
           scanf("%lf%lf",&p[i].x,&p[i].y);
        if(n<3)
        {
            puts("0.00");
            continue;
        }
        Graham(n);
        top++;
        if(top<3)
        {
            puts("0.00");
            continue;
        }
        if(top==3)
        {
            printf("%.2lf\n",fabs(cross(stack[0],stack[1],stack[2]))/2);
            continue;
        }
        printf("%.2lf\n",rotating_calipers(top));
    }
    return 0;
}