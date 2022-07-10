//A mother vertex in a graph G = (V, E) is a vertex v such that all other 
//vertices in G can be reached by a path from v.


do topo sort by dfs. 
first node in toposort is the mv if mother vertex exists. 
proof - agr first node ni h aur uske niche wale nodes me se koi h (visualise stack of topo sort) 
to us node se first node pe ek na ek rasta hoga and aesa h to first 
node kavi top pe ni rahega which is false. so agr h to first wala node hi h.