class Solution:
    def partitionLabels(self, str):
        char_indices = {}
        for i in range(len(str)):
            if str[i] not in char_indices.keys():
                char_indices[str[i]] = [i, i]
            else:
                char_indices[str[i]][1] = i
        
        partition_lengths = []
        partition_start = 0
        partition_end = char_indices[str[0]][1]
        for i in range(len(str)):
            if partition_end == len(str)-1:
                partition_lengths.append(partition_end - partition_start + 1)
                break
            if i == partition_end:
                partition_lengths.append(partition_end - partition_start + 1)
                if i < len(str)-1:
                    partition_start, partition_end = char_indices[str[i+1]]
            else:
                if char_indices[str[i]][1] > partition_end:
                    partition_end = char_indices[str[i]][1]
        
        return partition_lengths