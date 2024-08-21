def reverse_number(number):
    	reverse_number = 0
    
    	if number < 0:
    		number = number * -1
    
    	while number > 0:
    		reminder = number % 10
    		reverse_number = (reverse_number * 10) + reminder
   		number = number // 10
   
   	print(reverse_number)
   
   number = input('Enter any number to return its reverse number: ')
   number = int(number)
   reverse_number(number)
   
   """ 
   while number > 0 
   number = 251 > 0 
   reverse_number = 0  
    
   reminder = 251 % 10 --> reminder = 1 
   reverse_number = (0 * 10) + 1  ---> reverse_number = 1 
   number = number // 10 --> number = 25 > 0 
    
   number = 25 
   reminder = 25 % 10 ---> reminder = 5 
   reverse_number = (1 * 10) + 5 --> reverse_number = 15 
   number = 25 // 10 --> number = 2 > 0 
    
   number = 2 
   reminder = 2 % 10 ==> reminder = 2 
   reverse_number = (15 * 10) + 2 --> reverse_number = 152 
  number = 2 // 10 ---> number = 0 = 0 
  """