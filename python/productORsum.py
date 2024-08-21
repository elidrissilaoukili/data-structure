    """ 
    Exercise 1:  
                Given two integer numbers return their product. If the  
                product is greater than 1000, then return their sum  
    """	
    
    while True:
    	numbre_1 = int(input('Give the first number: '))
   	numbre_2 = int(input('Give the second number: '))
   
   	summ = numbre_1 + numbre_2
   	product = numbre_1 * numbre_2
   
   	if product > 1000:
   		print("The summ is", summ)
   
   	else:
   		print("The product is", product)
   
   	print('\n')