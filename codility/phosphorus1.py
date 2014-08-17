#!/usr/bin/env python

graph = {}
position = {}

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

def sub_sum(v, sub_list):
    global position

    neigh_count = len(sub_list)
    count = 0
    if neigh_count == 0: count = 0
    elif v in position:
        count = sum(sub_list) + sub_list.count(0)
    elif v not in position:
        count = sum(sub_list) 
        if 0 in sub_list and count > 0:
            count += 1

    return count

guard = []
def accumulate(root, node):
    global graph
    global position
    global guard

    ulist = graph[node]
    ucount = len(ulist)

    sub_list = []

    for u in ulist:
        if u == root: continue

        sub_count = accumulate(node, u)
        sub_list.append(sub_count)

    count = sub_sum(node, sub_list)
        
    print node, sub_list, count

    return count

def solution(A, B, C):
    if len(C) == 0: return 0

    global position
    global graph
    global guard
    graph = {}
    guard = []
    position = {}

    graph, N = init_graph(A, B)

    for v in C:
        if len(graph[v]) == 1: 
            return -1;
        else :
            position[v] = 1

    accumulate(-1, C[0])
    print "finish "
    return len(guard)

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
