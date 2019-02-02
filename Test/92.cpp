#include<iostream>
using namespace std;

const int n=4;//��ͼ���� 
const int m=4;// ��ͼ���� 
int t=5;//ָ����ʱ�� 
bool success=0;
char maze[n+1][m+1]={//��ͼ��Ϣ 
'X','X','X','X','X',
'X','S','.','X','.',
'X','.','.','X','.',
'X','.','.','X','D',
'X','.','.','.','.'
};


int go[][2]={//�ĸ������ߵ������ 
1,0,
-1,0,
0,1,
0,-1

};

void dfs (int x,int y,int time)//�ݹ���ʽ���������̽�� 
{
	
    
	for (int i=0;i<4;i++)//ö���ĸ�����λ�� 
	{
	    int fx=x+go[i][0];
		int fy=y+go[i][1];//���������� 
		if(maze[fx][fy]=='X') continue;//�������λ����ǽ�������� 
		if(fx>n||fx<1||fy>m||fy<1)continue;//�������Խ�磬���� 
		
		if(maze[fx][fy]=='D'){//������λ������ 
		if(time+1==t) //�����õ�ʱ��������t 
		 {
		success=true;return;}//�����ɹ������� 
		else if(time+1<t) continue;//�������ʱ����<t�ټ���Ѱ������·�� 
		 else return;//���򷵻غ��� 
	}
		maze[fx][fy]='X';//��״̬��̲��ܷ��ط��� 
	
		dfs(fx,fy,time+1);//�ݹ�����,time+1 
		maze[fx][fy]='.';//������״̬���غ���һ��̽�������õ����λ�ã���������ָ�ԭ��״̬ 
		if(success) return;//����״̬�����ɹ����򷵻أ�ֹͣ���� 
	}
	
}
int main(){
 	int dx,dy;//�����ŵ����� 
 	for(int i=1;i<=n;i++)//Ѱ��D��λ�� 
 	{
 		for (int j=1;j<=m;j++)
 		if (maze[i][j]=='D') dx=i,dy=j;
	 }
	
	for(int i=1;i<=n;i++)//Ѱ��S��λ�� 
 	{
 		for (int j=1;j<=m;j++)
 		{
		 if (maze[i][j]=='S') {
 			int sumxy=i+j;int sumdxy=dx+dy;
 			int judges=(sumxy+t)&1;int judged=sumdxy&1;//(x+y+t)��(dx+dy)��żӦ��ͬ�������������� 
 			if (judges=judged){
 				maze[i][j]='X';//S������Ϊǽ 
 				dfs(i,j,0);//��S��ݹ����� 
 				break;//�������������ѭ�� 
			 }
 			else success=false;break;//������������ 
 			
	 }
	 
}
}
	
	cout<<(success?"Yes":"No");//��successΪ�棬�����Yes 
	return 0;
	
} 
