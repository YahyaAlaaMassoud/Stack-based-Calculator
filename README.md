# **Stack-based Calculator**
A **fully functional** calculator that solves infix mathematical expressions, tranforms it to postfix expressions and then calculates
its result using two stacks, one for operands and the other for the operations.<br/>
#### Valid operations:
 - Basic operations (addition, subtraction, multiplication, division).
 - Using parenthesis in expressions.
```
1+2+(55)*(3/4*(99))+3*4
The Postfix Expression for the input is: 1 2 + 55 3 4 / 99 * * + 3 4 * +   
result = 4098.75
```

 - Power.
 ```
 (1+2*3)^2
 The Postfix Expression for the input is: 1 2 3 * + 2 ^
 result = 49
 ```
  ```
 2.3^3
 The Postfix Expression for the input is: 2.3 3 ^
 result = 12.167
 ```
 
 - Factorial.
```
 9!/8!
 The Postfix Expression for the input is: 362880 40320 /
 result = 9
```

 - Percentage.
```
12%*12%
The Postfix Expression for the input is: 0.12 0.12 *
result = 0.0144
```

 - Using **e** (Euler's Number).
```
e^3
The Postfix Expression for the input is: 2.71828182845905 3 ^
result = 20.0855369231877
```

 - tan, sin, cos (in radians or degrees).
```
tan45 + sin30 + cos60
The Postfix Expression for the input is: 1 0.5 + 0.5 +
result = 2
```


 - PI.
 ```
 3*PI/4
 The Postfix Expression for the input is: 3 3.14159265358979 * 4 /
 result = 2.35619449019234
 ```
 
 - Square root.
 ```
 sqrt100/sqrt25
 The Postfix Expression for the input is: 10 5 /
 result = 2
 ```
 
