//Used to solve system of Linear Congruences:
// x%2=1
// can be written as x ≡1(mod2){=->3lines}

//given a system of congruences,crt is used to find x
//x≡1(mod2)
//x≡5(mod7)
//x≡2(mod3)
//find x;

//Acc to CRT:
//Generalization:
//nums=[2,3,7]
//rem =[1,2,5]
//x % num[0] = rem[0]
//x % num[2] = rem[1]
    .
    .
    .
    .
//x % num[k] = rem[k]

//CRT Formula:
// x = summation(0,k-1){ rem[i] + pp[i] * inv[i]}%prod;

//rem[i] -> array of remainders
//prod -> product of all nos in num[i]
//pp[i] -> produyt of all nos / i
//inv[i] -> modular MI of PP[i] wrt num[i]