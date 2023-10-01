Here we will discuss Kruskal’s algorithm to find the MST of a given weighted graph. 

In Kruskal’s algorithm, sort all edges of the given graph in increasing order. Then it keeps on adding new edges and nodes in the MST if the newly added edge does not form a cycle. It picks the minimum weighted edge at first and the maximum weighted edge at last. Thus we can say that it makes a locally optimal choice in each step in order to find the optimal solution. Hence this is a Greedy Algorithm.

How to find MST using Kruskal’s algorithm?
Below are the steps for finding MST using Kruskal’s algorithm:


Sort all the edges in non-decreasing order of their weight. 
Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
Repeat step#2 until there are (V-1) edges in the spanning tree.