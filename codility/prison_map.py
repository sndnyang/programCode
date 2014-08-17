#!/bin/env python

def init_map(A, B, C):
    prison_map = {}
    N = len(A)

    for i in range(N + 1):
        prison_map[i] = []

    for i in range(N):
        begin = A[i];
        end   = B[i];

        prison_map[begin].append(end);
        prison_map[end].append(begin);

    for x in C:
        if len(prison_map[x]) == 1: N = -1;
        prison_map[x] = [];

    return prison_map, N;

paint_graph = None

def paint(graph, node, gid):
    global paint_graph
    paint_graph[node] = gid;
    for v in graph[node]:
        if paint_graph[v] != -1:
            continue;
        if len(graph[v]) == 0:
            paint_graph[v] = -2
            continue
        paint(graph, v, gid);

def solution(A, B, C):
    global paint_graph
    prison_map, N = init_map(A, B, C);

    if N == -1: return -1;

    exits = []
    for x in prison_map:
        if len(prison_map[x]) == 1:
            exits.append(x);

    paint_graph = [-1] * (N+1)
    gid = 0

    for node in exits:
        if len(prison_map[node]) == 0 or paint_graph[node] != -1:
            continue
        paint(prison_map, node, gid);
        gid += 1;

    print paint_graph
    return gid;

assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 6]) == 4
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 3, 6]) == 5
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [3, 6]) == 5
assert solution([0,1,2,2,3,3,6,6], [1,2,3,6,4,5,7,8], [1, 3, 6, 7]) == -1
assert solution([0,1,2,3,4], [5,5,5,5,5], [5]) == 5
assert solution([0,1,2,3,4], [1,2,3,4,5], [2, 3]) == 2
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [0, 6]) == 4
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [2, 3]) == 3
assert solution([0,1,2,3,4,5,6,7,8,9], [5,0,1,2,0,6,10,3,0,2], [2, 6]) == 4
