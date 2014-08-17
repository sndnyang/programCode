#!/usr/bin/env python

def init_graph(A, B):
    prison_map = {}
    N = len(A)

    for i in range(N + 1): 
        prison_map[i] = [] 

    for i in range(N):
        begin = A[i];
        end   = B[i];

        prison_map[begin].append(end);
        prison_map[end].append(begin); 

    return prison_map, N

def delete_edge(graph, v, u):
    assert v in graph and u in graph[v]

    vlist = graph[v]
    ulist = graph[u]

    vlist.remove(u)
    ulist.remove(v)

    return graph

prison = {}
prison_map = {}
exist_count = None
exists = None
inner = []

def join(root, node):
    global prison_map
    global prison
    global exist_count
    global exists
    global inner

    for u in prison_map[node]:
        if u == root: continue

        print node, u, prison_map[u]

        if exist_count[u]:
            if u not in inner:
                exists.append(u)
                inner.append(u)
                print exists
            return

        join(node, u)


def solution(A, B, C):
    global prison_map
    global prison
    global exist_count
    global exists
    global inner
    inner = []
    if len(C) == 0: return 0

    prison_map, N = init_graph(A, B)

    prison = {}
    for v in C:
        if len(prison_map[v]) == 1: 
            return -1;
        else :
            prison[v] = 1

    queue = []
    for v in prison_map:
        if len(prison_map[v]) == 1:
            queue.append(v)

    #print queue
    i = 0

    exists = []

    from collections import defaultdict
    exist_count = defaultdict(int)

    while 0 < len(queue):
        v = queue.pop()
        u = prison_map[v][0]
        #print v,u, prison_map[u],

        prison_map = delete_edge(prison_map, v, u)

        if u in prison:
            exists.append(v)
            #print 
            continue

        rev = prison_map[u]
        #print rev
        print exists, v, u, rev

        if len(rev) == 1: 
            queue.append(u)
        else:
            exist_count[u] += 1

    print exist_count
    print prison_map
    for x in C:
        join(-1, x)

    print exists
    return len(exists)

assert solution([0,1,2,3,4], [5,5,5,5,5], []) == 0
assert solution([0,1,2,3,4], [5,5,5,5,5], [5]) == 5
assert solution([0,1,2,3,4], [5,5,5,5,5], [1]) == -1
assert solution([0,1,2,3,4], [1,2,3,4,5], [2, 3]) == 2
assert solution([0,1,2,3,4,5,7,8,9], [1,2,3,6,3,4,2,4,5], [1,5]) == 4
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 6]) == 4
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 3, 6]) == 5
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [3, 6]) == 5
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 3, 6, 7]) == -1
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [0, 6]) == 4
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [2, 3]) == 3
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [2, 6]) == 4
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [2, 6]) == 5
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [0, 9]) == 7
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [0, 9, 12]) == 7
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [0,2]) == 7
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [0, 3, 6, 9, 12]) == 10
assert solution([1,2,3,6,4,5,7,8,9,10,11,12,13,14,15,16], [0,1,2,2,3,3,6,6,2,9,9,1,12,0,0,0], [0, 9, 13]) == -1
