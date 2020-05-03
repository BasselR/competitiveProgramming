from sys import stdin
input = stdin.readline

# Gathering input
n = int(input())
grid = [[] for i in range(n)]
for i in range(n):

# Returning (boolean) connectivity (whether or not dest can be reached from src)
def bfs(adjList, src, dest):
    queue = []
    visited = [False for i in range(n + 1)]

    queue.append(src)
    visited[src] = True

    while len(queue) > 0:
        node = queue.pop(0)

        if node == dest:
            return True

        for adjNode in adjList[node]:
            if visited[adjNode] == False:
                queue.append(adjNode)
                visited[adjNode] = True

    return False