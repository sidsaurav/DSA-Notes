//Author : Siddharth Saurav (Chem 23)

Eulerian Path -> Path which visits every edge once and only once.
Eulerian Circuit -> Eulerian Path whose start and end nodes are same.
 
Agr eulerian circuit h to wo path v h.
 
Undirected Graph :-
 
E Circuit -> every node degree is even
E Path -> Atmost 2 node degree odd else every node degree even
// Logic -> agr degree even hoga to jane ka and aane ka rasta hoga sare nodes se. for path agr degree odd h to wo src ya dest banega.
 
Directed Graph :-
 
E Circuit -> indegree == outdegree for every node
E path -> One node may have indegree == out + 1 and one have outdegree = in + 1
 
To find Eulerian Path for directed graph : https://leetcode.com/problems/reconstruct-itinerary/




//https://www.youtube.com/watch?v=w99el8bl-DM