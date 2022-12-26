class Solution:
    def allPathsSourceTarget(self, graph):
        if not graph:
            return []
        
        square_matrix = [0]*len(graph)
        for i in range(len(graph)):
            square_matrix[i] = [0]*len(graph)
        
        for i in range(len(graph)):
            for j in graph[i]:
                square_matrix[i][j] = 1
        
        return self.getPaths(square_matrix, len(graph)-1)
    
    def getPaths(self, graph, node_j):
        paths_found = []
        found_atleast_one = False
        for i in range(len(graph)):
            if graph[i][node_j] == 1:
                found_atleast_one = True
                temp_paths = self.getPaths(graph, i)
                for i in range(len(temp_paths)):
                    temp_paths[i].append(node_j)
                    paths_found.append(temp_paths[i])
        
        if not found_atleast_one:
            if node_j == 0:
                return [[node_j]]
            else:
                return []
        else:
            return paths_found