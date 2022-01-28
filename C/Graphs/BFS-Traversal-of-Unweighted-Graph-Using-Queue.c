// BFS TRAVERSAL OF UNWEIGHTED GRAPH USING QUEUE

#include<stdio.h>
#include<stdlib.h>
#define max 10
int n,adj[max][max],visited[max],queue[max],front=-1,rear=-1;
void push(int v)
{
	if(rear==max-1)
		printf("Queue is Full!");
	else
	{
		if(front==-1)
			front=0;
		queue[++rear]=v;
	}
}

int pop()
{
	int v;
	if(front==-1||front>rear)
	{
		exit(0);
	}
	else
	{
		v=queue[front++];
	}
	return v;
}

void bfs()
{
	int v;
	for(v=0;v<n;v++)
	{
		visited[v]=0;
	}
	printf("Enter first vertex:\t");
	scanf("%d",&v);
	int i;
	push(v);
	printf("BFS Traversal :\t");
	while(front!=-1||front<rear) //while queue is not empty
	{
		v=pop();
		if(!visited[v])
		{
			printf("%d\t",v);
			visited[v]=1;
			for(i=0;i<n;i++)
			{
				if(adj[v][i]==1 && visited[i]==0)
				{
					push(i);
				}
			}
		}
	}
}

int main()
{
	int i,j;
	printf("Enter No. of Vertices:\t");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	bfs();
	return 0;
}
