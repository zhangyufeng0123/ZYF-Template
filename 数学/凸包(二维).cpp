#include<stdio.h>
#include<limits.h>
#include<string.h>
typedef struct
{
    int x;
    int y;
    int temp;		/*若这点在凸包上,则temp==1,否则temp==0*/
}Point;
Point s[105];
int n;
void Sechup(int a, int b);
void Sechdown(int a, int b);
int main(void)
{
    int T, i, a, b, ax, bx;
    scanf("%d", &T);
    while(T--)
    {
        memset(s, 0, sizeof(s));
        ax = INT_MAX;
        bx = INT_MIN;
        scanf("%d", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d", &s[i].x, &s[i].y);
            if(s[i].x<ax)
                ax = s[i].x, a = i;
            if(s[i].x>bx)
                bx = s[i].x, b = i;
        }
        s[a].temp = s[b].temp = 1;
        Sechup(a, b);			/*上包递归*/
        Sechdown(a, b);				/*下包递归*/
        for(i=1;i<=n;i++)
        {
            if(s[i].temp==1)
                printf("%d %d\n", s[i].x, s[i].y);
        }
    }
    return 0;
}
/*若向量叉乘为负,说明点在直线下面,否则在直线上面(参照直线方向为从左到右)*/
void Sechup(int a, int b)
{
    int i, max, c;
    max = 0;
    for(i=1;i<=n;i++)
    {
        if((s[b].x-s[a].x)*(s[i].y-s[a].y)-(s[b].y-s[a].y)*(s[i].x-s[a].x)>max)
        {
            max = (s[b].x-s[a].x)*(s[i].y-s[a].y)-(s[b].y-s[a].y)*(s[i].x-s[a].x);
            c = i;		/*用向量叉乘求三点三角形面积,使三角形面积最大的那个(非直线上的)点便是离参照直线最远的点Pmax*/
        }
    }
    if(max!=0)/*参照直线上方有点*/
    {
        s[c].temp = 1;
        Sechup(a, c);
        Sechup(c, b);
    }
}

void Sechdown(int a, int b)
{
    int i, max, c;
    max = 0;
    for(i=1;i<=n;i++)
    {
        if((s[b].x-s[a].x)*(s[i].y-s[a].y)-(s[b].y-s[a].y)*(s[i].x-s[a].x)<max)
        {
            max = (s[b].x-s[a].x)*(s[i].y-s[a].y)-(s[b].y-s[a].y)*(s[i].x-s[a].x);
            c = i;
        }
    }
    if(max!=0)
    {
        s[c].temp = 1;
        Sechdown(a, c);
        Sechdown(c, b);
    }
}
