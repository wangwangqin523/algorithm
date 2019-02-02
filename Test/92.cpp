#include<iostream>
using namespace std;

const int n=4;//地图的行 
const int m=4;// 地图的列 
int t=5;//指定的时间 
bool success=0;
char maze[n+1][m+1]={//地图信息 
'X','X','X','X','X',
'X','S','.','X','.',
'X','.','.','X','.',
'X','.','.','X','D',
'X','.','.','.','.'
};


int go[][2]={//四个方向走的坐标差 
1,0,
-1,0,
0,1,
0,-1

};

void dfs (int x,int y,int time)//递归形式的深度优先探索 
{
	
    
	for (int i=0;i<4;i++)//枚举四个相邻位置 
	{
	    int fx=x+go[i][0];
		int fy=y+go[i][1];//计算其坐标 
		if(maze[fx][fy]=='X') continue;//如果坐标位置是墙，则跳过 
		if(fx>n||fx<1||fy>m||fy<1)continue;//如果坐标越界，跳过 
		
		if(maze[fx][fy]=='D'){//如果这个位置是门 
		if(time+1==t) //若所用的时间正好是t 
		 {
		success=true;return;}//搜索成功，返回 
		else if(time+1<t) continue;//否则如果时间仍<t再继续寻找其他路径 
		 else return;//否则返回函数 
	}
		maze[fx][fy]='X';//该状态后继不能返回访问 
	
		dfs(fx,fy,time+1);//递归搜索,time+1 
		maze[fx][fy]='.';//若其后继状态返回后，下一论探索可能用到这个位置，则先让其恢复原来状态 
		if(success) return;//其后继状态搜索成功，则返回，停止搜索 
	}
	
}
int main(){
 	int dx,dy;//定义门的坐标 
 	for(int i=1;i<=n;i++)//寻找D的位置 
 	{
 		for (int j=1;j<=m;j++)
 		if (maze[i][j]=='D') dx=i,dy=j;
	 }
	
	for(int i=1;i<=n;i++)//寻找S的位置 
 	{
 		for (int j=1;j<=m;j++)
 		{
		 if (maze[i][j]=='S') {
 			int sumxy=i+j;int sumdxy=dx+dy;
 			int judges=(sumxy+t)&1;int judged=sumdxy&1;//(x+y+t)与(dx+dy)奇偶应相同，否则跳过搜索 
 			if (judges=judged){
 				maze[i][j]='X';//S点设置为墙 
 				dfs(i,j,0);//从S点递归搜索 
 				break;//完成搜索后，跳出循环 
			 }
 			else success=false;break;//否则，搜索不到 
 			
	 }
	 
}
}
	
	cout<<(success?"Yes":"No");//若success为真，则输出Yes 
	return 0;
	
} 
