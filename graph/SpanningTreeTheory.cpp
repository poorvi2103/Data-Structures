A spanning tree is a subgraph of a graph which should satisfy following properties:
	1.Spanning tree contains exactly same no. of vertices as of graph.
	2.No.of edges in the spanning tree will be no. of vertices-1.
	3.Spanning tree should not contain any cycle.
	4.Spanning tree must be connected.
	5.If we remove any edge from spanning tree,then it will be disconnected. anf if add any vertex,then can become cyclic.
note:A graph can have multiple spanning tree.
no. of spanning tree=E
                      C        - no.of edges.
	                    v-1
complete greaph:can reach any vertex from any vertex directly. 
for complete,spanning tree=n^(n-2).	                   

minimum cost spanning tree:
	if weights of all edges ae different,then mcs will be always unique for a graph.
	but if weights of any tw edges are same ,then thereCAN be multiple MCS
	
For a graph,there can be multiole MCS if two or more than two edges having equal weight.

to find MCS tree for a graph,there are two famous algorithms:
	1.prim's algo
	2.kruskels algo.
