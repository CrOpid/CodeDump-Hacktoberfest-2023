	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indeg(v,0);
	    for(int i=0; i<v;i++){
	        for(auto neighbor : adj[i]){
	            indeg[neighbor]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i < v;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node = q.front(); 
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]){
	            indeg[it]--;
	            if(indeg[it]==0)q.push(it);
	        }
	    }
	    return ans;
	}