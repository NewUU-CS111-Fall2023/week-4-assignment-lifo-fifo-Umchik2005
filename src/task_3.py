class stack:
    items=[]
    def push(self,item):
        self.items.append(item)
    def size(self):
        return len(self.items)
    def top(self):
        return self.items[len(self.items)-1]
    def pop(self):
        self.items.pop(len(self.items)-1)
    def empty(self):
        return self.items==[]
def calculation(a,b,i):
    if i=='+':
        return a+b
    elif i=='-':
        return a-b
    elif i=='*':
        return a*b
    elif i=='/':
        return a/b

s=stack()
operators='+-*/'
postfix=input()
for symbol in postfix:
    if symbol.isdigit():
        s.push(int(symbol))
    elif symbol in operators:
        b=s.top()
        s.pop()
        a=s.top()
        s.pop()
        s.push(calculation(a,b,symbol))
print(calculation(a,b,symbol))