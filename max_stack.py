
class MaxStack:

	def __init__(self):
		#use one stack for enqueue operation
		self.main_stack = []
		#use another stack for the dequeue operation
		self.max_stack = []
		
	#adding an item to the queue is O(1) operation
	def push(self, data):
		
		#push the new item onto the stack
		self.main_stack.append(data)
		
		#first item is the same in both stacks
		if(len(self.main_stack)==1):
			self.max_stack.append(data)
			return
			
		#if the item is the largest one so far: we insert it onto the stack 
		#stack[-1] is the peek operation: returns the last item we have inserted (without removal)
		if data>self.max_stack[-1]:
			self.max_stack.append(data)
		else:
			#if not the largest one then we duplicate the largest one on the max_stack
			self.max_stack.append(self.max_stack[-1])
		
	#getting items
	def pop(self):
		self.max_stack.pop()
		return self.main_stack.pop()
		
	#max item is the last item we have inserted into the maxStack O(1)	
	def get_max_item(self):
		return self.max_stack.pop()		
	
if __name__ == "__main__":		
	
	max_stack = MaxStack()
	
	max_stack.push(10)
	max_stack.push(5)
	max_stack.push(1)
	max_stack.push(120)
	max_stack.push(100)
	
	print(max_stack.get_max_item())