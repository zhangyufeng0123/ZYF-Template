// 最小三角形，注意longlong
const int maxn = 5000+10;
struct  Point{

	long long  x,y;
	Point(long long  xx = 0,long long  yy = 0):x(xx),y(yy){}
};
typedef Point Vector ;

Point operator - (const Point A,const Point B){
	return Point(A.x-B.x,A.y-B.y);
}
long long  Cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}
Point A[maxn],B[maxn];
bool operator <(const Point &A,const Point &B){

	return A.y*B.x  < A.x*B.y;
}
int main(void)
{
	int N;cin>>N;
	for(int i = 0;i < N; ++i){
		cin>>A[i].x>>A[i].y;
	}
	double   ans = inf;
	for(int i = 0;i < N; ++i){
		int t = 0;
		for(int j = 0;j < N; ++j)
			if(i != j)
				B[t++] = A[j]-A[i];
		sort(B,B+t);
		// assert(t == N-1);
		for(int j = 0;j < t-1; ++j){
			ans = min(ans,fabs(Cross(B[j],B[j+1]))/2.0);
		}
	}
    printf("%.3f",ans);

   return 0;
}