from sys import stdin
input = stdin.readline

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

# Collecting input and building graph
n, m = map(int, input().split())

adj = [[] for i in range(n + 1)]

for i in range(m):
        x, y = map(int, input().split())    
        adj[x].append(y)    # Offset by 1 -- remember that adj[n - 1] lists who n is taller than

p, q = map(int, input().split())

# Printing output
if bfs(adj, p, q):
    print("yes")
elif bfs(adj, q, p):
    print("no")
else:
    print("unknown")