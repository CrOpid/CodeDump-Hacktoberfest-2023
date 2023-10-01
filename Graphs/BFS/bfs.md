### BFS traversal of a graph is similar to BFS traversal of a tree.

Similar to a bfs traversal of a tree , we will use a queue to push nodes and pop them out one by one, then put them in answer vector.

The catch here is that we have cycles in a graph, so we can end up traversing infinitely over & over, again & again.
To prevent this never ending cyclic traversal, we will use an tracker, known as visited array(or list).
If the node has been traversed before then it won't be added in queue and hence not processed again.
