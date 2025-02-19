/*
//Minimum steps by knight to reach the target
//Expected Time Complexity: O(N2).
//Expected Auxiliary Space: O(N2).
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1=KnightPos[0],y1=KnightPos[1],x2=TargetPos[0],y2=TargetPos[1];
	    int a[N][N];
	    
	    if(x1==x2 && y1==y2) return 0;
	    
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            a[i][j]=0;
	        }
	    }
	    
	    queue<pair<int,int>>q;
	    q.push({x1-1, y1-1});
	    while(!q.empty()){
	        auto cur=q.front();
	        int i=cur.first;
	        int j=cur.second;
	        q.pop();
	        
            if((i+1)>=0 && (i+1)<N && (j+2)>=0 && (j+2)<N && a[i+1][j+2]==0){
                a[i+1][j+2]=a[i][j]+1;
                q.push({i+1, j+2});
            }
	        if((i-1)>=0 && (i-1)<N && (j+2)>=0 && (j+2)<N && a[i-1][j+2]==0){
	            a[i-1][j+2]=a[i][j]+1;
                q.push({i-1, j+2});
	        }
	        if((i+1)>=0 && (i+1)<N && (j-2)>=0 && (j-2)<N && a[i+1][j-2]==0){
	            a[i+1][j-2]=a[i][j]+1;
                q.push({i+1, j-2});
	        }
	        if((i-1)>=0 && (i-1)<N && (j-2)>=0 && (j-2)<N && a[i-1][j-2]==0){
	            a[i-1][j-2]=a[i][j]+1;
                q.push({i-1, j-2});
	        }
	        if((i-2)>=0 && (i-2)<N && (j+1)>=0 && (j+1)<N && a[i-2][j+1]==0){
	            a[i-2][j+1]=a[i][j]+1;
                q.push({i-2, j+1});
	        }
	        if((i-2)>=0 && (i-2)<N && (j-1)>=0 && (j-1)<N && a[i-2][j-1]==0){
	            a[i-2][j-1]=a[i][j]+1;
                q.push({i-2, j-1});
	        }
	        if((i+2)>=0 && (i+2)<N && (j+1)>=0 && (j+1)<N && a[i+2][j+1]==0){
	            a[i+2][j+1]=a[i][j]+1;
                q.push({i+2, j+1});
	        }
	        if((i+2)>=0 && (i+2)<N && (j-1)>=0 && (j-1)<N && a[i+2][j-1]==0){
	            a[i+2][j-1]=a[i][j]+1;
                q.push({i+2, j-1});
	        }
	    }
	    return a[x2-1][y2-1];
	}
*/