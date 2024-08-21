while True:
        income = int(input("What your income by (dollor): "))
        taxPayable = 0
    
        if income <= 10000:
            taxPayable = 0
            print("Tax payable is: ", taxPayable)
    
       elif income <= 20000:
           taxPayable = (income - 10000) * 10 / 100
           print("Tax payable is: ", taxPayable)
   
       else:
           # First 10.000 dollor
           taxPayable = 0
   
           # Next 10.000 dollor
           taxPayable = (10000 * 10 / 100)
   
           # Remaining
           taxPayable += (income - 20000) * 20 / 100
   
           print("Tax payable is: ", taxPayable, 'D')