class ListNode:
    def __init__(self, val=[-1, -1], prev=None, next=None):
        self.value = val
        self.next = next
        self.prev = prev

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def append(self, val):
        if not self.tail:
            self.tail = ListNode(val, None, None)
            self.head = self.tail
            self.size += 1
        else:
            self.tail.next = ListNode(val, self.tail, None)
            self.tail = self.tail.next
            self.size += 1

    def pop(self):
        if not self.tail:
            return [-1, -1]
        else:
            temp = self.tail.prev
            pop_val = self.tail.value
            self.tail = temp
            if not self.tail:
                self.head = None
            else:
                self.tail.next = None
            self.size -= 1
            return pop_val
    
    def isEmpty(self):
        return self.size == 0

    def popLeft(self):
        if not self.head:
            return [-1, -1]
        else:
            temp = self.head.next
            pop_val = self.head.value
            del(self.head)
            self.head = temp
            if not temp:
                self.tail = None
            else:
                self.head.prev = None
            self.size -= 1
            return pop_val

class Solution:
    def findCircleNum(self, isConnected):
        if not isConnected:
            return 0
        
        no_of_provinces = 0
        for i in range(len(isConnected)):
            if isConnected[i][i] == 1:
                self.bfs(isConnected, i, i)
                no_of_provinces += 1
        
        return no_of_provinces

    def bfs(self, isConnected, x, y):
        ll = LinkedList()
        ll.append([x, y])
        while not ll.isEmpty():
            node_x, node_y = ll.popLeft()
            isConnected[node_x][node_y] = 0
            isConnected[node_y][node_x] = 0
            for j in range(len(isConnected)):
                if isConnected[node_x][j] == 1:
                    ll.append([j, node_x])