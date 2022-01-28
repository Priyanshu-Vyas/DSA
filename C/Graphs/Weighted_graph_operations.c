/*
Create a weighted graph of your choice and write programs to solve the following 
//To Count the total number of edges in the graph
//print the in degree and outdegree of any given vertex
//find a path between any two vertices. and print the path. Calculate the cost of the path.
*/

#include<stdio.h>
#include<stdlib.h>
#define max 20
int n,adj[max][max],edges=0,paths[max],cost=0,I=0,i,j,c,v,v1,v2;

int count()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]!=0)
            {
                edges+=1;
            }
        }
    }
    printf("\n No of Edges in the Graph= %d \n",edges);
}

int degree(int vertex)
{
    int indeg=0;
    for(i=0;i<n;i++)
    {
        if(adj[i][vertex]!=0)
            indeg+=1;
    }
    printf("\n Indegree for Vertex %d: %d \n",vertex,indeg);
    int outdeg=0;
    for(j=0;j<n;j++)
    {
        if(adj[vertex][j]!=0)
            outdeg+=1;
    }
    printf("Outdegree of Vertex %d: %d \n",vertex,outdeg);
}

int path(int a,int z)
{
    paths[I]=a;
    for(j=0;j<n;j++)
    {
        if(adj[a][j]!=0)
        {
            cost+=adj[a][j];
            path(j,z);
        }
    }
}

int main()
{
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
    while(1)
    {
        printf("\n1.count() \t");
        printf("2.degree() \t");
        printf("3.path() \t");
        printf("4.Exit() \n");
        printf("Enter Your Choice= ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                count();break;
            case 2:
                printf("\nEnter Any Vertex= ");
                scanf("%d",&v);
                degree(v);break;
            case 3:
                printf("\nEnter Source Vertex= ");
                scanf("%d",&v1);
                printf("Enter destination Vertex= ");
                scanf("%d",&v2);
                path(v1,v2);
                for(i=0;i<I;i++)
                {
                    printf("%d->",paths[i]);
                }
                printf("\n cost of the path = %d",cost);
                break;
            case 4:
                exit(0);
            default:
                printf("\n Enter A Valid Choice! \n");
        }
    }
    return 0;
}
