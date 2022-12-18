class ListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap:
    def __init__(self):
        self.size = 1000
        self.hashTable = [None]*(self.size)

    def put(self, key: int, value: int) -> None:
        index = key % self.size
        if not self.hashTable[index]:
            self.hashTable[index] = ListNode(key, value)
            return
        
        list_head = self.hashTable[index]
        while list_head.next != None:
            if list_head.key == key:
                list_head.value = value
                break
            list_head = list_head.next
        if list_head.key == key:
            list_head.value = value
        else:
            list_head.next = ListNode(key, value)
        return

    def get(self, key: int) -> int:
        index = key % self.size
        if not self.hashTable[index]:
            return -1
        
        list_head = self.hashTable[index]
        while list_head.next != None:
            if list_head.key == key:
                return list_head.value
            list_head = list_head.next
        if list_head.key == key:
            return list_head.value
        return -1

    def remove(self, key: int) -> None:
        index = key % self.size
        if not self.hashTable[index]:
            return
        
        prev_head = self.hashTable[index]
        list_head = self.hashTable[index].next
        if prev_head.key == key:
            self.hashTable[index] = list_head
            del(prev_head)
            return
        while list_head != None:
            if list_head.key == key:
                prev_head.next = list_head.next
                del(list_head)
                return
            
            prev_head = list_head
            list_head = list_head.next
        
        return


        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)