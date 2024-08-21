"""Write a function called exponent(base, exp) that returns an int value of base raises to the power of exp. 
    Note here exp is a non-negative integer, and the base is an integer."""
    
    def exponent(base, exp):
    
    	if (base == 0) and (exp != 0):
    		result = 0
    		print(f'{base} the power of {exp} is', result)
    
   	elif (base != 0) and (exp == 0):
   		result = 1
   		print(f'{base} the power of {exp} is', result)
   
   	else:
   		result = base ** exp
   		print(f'{base} the power of {exp} is', "%.2f" % result)
   
   
   base = float(input('Enter the base number: '))
   exp = float(input('Enter the exponent number: '))
   
   exponent(base, exp)
   
   print('\n')
   
   def power(base, exp):
   	number = exp
   	result = 1
   
   	while number > 0:
   		result = result * base
   		number = number - 1
   
   	print("The result is", base, 'raises of the power of', exp, 'is:', result)
   
   power(2, 3)