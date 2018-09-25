class Solution:
    def addTwoNumbers(self, l1, l2):
        num1, num2, l3 = 0,0,[]
        while l1:
            l3.append(l1.val)
            l1 = l1.next
        while l3:
            num1 = num1*10+l3[-1]
            del l3[-1]
        while l2:
            l3.append(l2.val)
            l2 = l2.next
        while l3:
            num2 = num2*10+l3[-1]
            del l3[-1]
        num = self.yj(num1+num2)
        root = ListNode(num[0])
        res = root
        for i in range(1,len(num)):
            cas = ListNode(num[i])
            root.next = cas
            root = cas
        return res
        
    def yj(self, num):
        if num == 0:
            return [0]
        res = []
        while num:
            res.append(num%10)
            num //= 10
        return res