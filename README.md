# **Stack-based Calculator**
A **fully functional** calculator that solves ***infix*** mathematical expressions that are represented in a string, tranforms it to ***postfix*** expressions and then calculates
its result using two stacks, one for operands and the other for the operations.<br/>

<hr/>

## Valid operations:
 - Basic operations like addition, subtraction, multiplication, and division.
 - Using parenthesis in expressions.
```
The Infix Expression: 1+2+(55)*(3/4*(99))+3*4
The Postfix Expression for the input is: 1 2 + 55 3 4 / 99 * * + 3 4 * +   
result = 4098.75
```

 - Power of both double and integer numbers.
 ```
 The Infix Expression: (1+2*3)^2
 The Postfix Expression for the input is: 1 2 3 * + 2 ^
 result = 49
 ```
  ```
 The Infix Expression: 2.3^3
 The Postfix Expression for the input is: 2.3 3 ^
 result = 12.167
 ```
 
 - Factorial (calculating factorial using a simple dynamic-programming function).
```
 The Infix Expression: 9!/8!
 The Postfix Expression for the input is: 362880 40320 /
 result = 9
```

 - Percentage.
```
The Infix Expression: 12%*12%
The Postfix Expression for the input is: 0.12 0.12 *
result = 0.0144
```

 - Using **e** (Euler's Number) and PI.
```
The Infix Expression: e^3
The Postfix Expression for the input is: 2.71828182845905 3 ^
result = 20.0855369231877
```
 ```
 The Infix Expression: 3*PI/4
 The Postfix Expression for the input is: 3 3.14159265358979 * 4 /
 result = 2.35619449019234
 ```
 
 - tan, sin, cos (whether in radians or degrees as the user specifies in the start of the program).
```
The Infix Expression: tan45 + sin30 + cos60
The Postfix Expression for the input is: 1 0.5 + 0.5 +
result = 2
```

 - Square root.
 ```
 The Infix Expression: sqrt100/sqrt25
 The Postfix Expression for the input is: 10 5 /
 result = 2
 ```
 
