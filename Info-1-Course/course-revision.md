simple program:


```c
#include <stdio.h>

int main(void){
	// Hello World
	printf("Hellow World.\n");
}
```

initialization


```c
	double a=1.5 * 42 * 42;
	int m;
	printf("a = %lf, m = %d\n", a,m);
```

`printf`

```c
	int length_fixed =3, width_fixed =4;
	printf("length = %d, width = %d, area = %d\n", length_fixed,width_fixed, length_fixed * width_fixed);
```
Custom Values
```c
	int length_custom, width_custom;
	printf("Input lenght and width\n");
	scanf("%i %i", &length_custom, &width_custom);
	printf("length = %i, width = %i, area = %i\n", length_custom, width_custom, length_custom * width_custom);
```

Arithmetic
```c
	double x=7.5, y=2.5, z=2.0, t, u, v, w;
	t = x + y * z;
	u = 4 * (x-1) +y;
	v = x / y / z;
	w = x * -z;
	printf("t=%g u=%g v=%g w=%g\n", t, u, v, w);
```

Declare a Var outside of main, so can you use it everywhere.

also, they have a value of 0. which can be helpful if you were just gonna set it to zero.

local vars need initialization. otherwise random -kinda-.

enum gives a whatever type value an int value

in floats/doubles = use %g instead of %f/%lf. it formates it nicely.

for pointers, it is %p.

need stdbool for logic.

the logic operators are: < > <= >= == || && !.

every operation ends with ;.

if for simple control. add else to complicate it.

for mod -int division- use % or just use them as int's.

with switch you need int cases -or just enum it- and with every order you need a break; and if there must be a default behaviour add it too. 

```c
switch(INTCase){
		case constanti:
			order;
			break;
		case ...
		...
		default:
			somthing somthing;
}
```

usually a switch case is more readable and produces better machine code.

you can also do it so:

```c
switch(z){
	case i:
	case w:
	case z:
		return something;
	default: 
		return no;
}
```

a while can not work if the condition is not met. unlike do-while.

a do-while can be useful if only a set of inputs is valid, i.e. month length range (28-31)

a for can be implemented using a while, but a for is just easier to read than a while.

a do-while with a if before it is just a while.

a while with the "to do" before it is just a do-while

the conversion from a while to a for is just easy so yep not mentioned here.

for any complex program just divide it or tackle it one step at a time. i.e.: set the main thing to do, see how it will get done, then go deeper a bit by bit. (no, not bit as in information).

a break breaks the loop and everything after it is just forgotten.

a continue ends the current loop then it just continues.

use break and continue sparsely.

do not use goto.

an unsigned int is just a natural number.

a short int uses at least 16 bit and at most the same as int.

a long int uses at least the same as int and at most 32 bit.

a long long int uses at least the same as a long int and at most 64 bit.

the maximum and minimum of the types are in `<limits.h>`.

if you want a custom int use `<stdint.h>`

a char is but an int in ASCII. sometimes also uses UNICODE.

for Unicode use wchar_t it is in `<wchar.h>,<wctype.h>`

`getchar();` is a void function that simply "echoes" the inputted character.

a float uses IEEE single precision, while a double uses the double precision and the long double uses the extended precision -128bit-.

if you want to calculate the complex numbers use `<complex.h>`

if you want to calculate, use `<math.h>` then compile with -lm

in the floating point arithmetic the distributivity and the associativity are not guaranteed.

that is why one must never compare or check for equality by floating point numbers.

`const type name = value;` for a constant.

volatile is something that can change randomly.

`auto` assigns the type. but the variable must have a value.

`typeof(x);` gives you the type of x

there is implicit type change going on with the compiler. so char into int into float into double and long and long long and so on...

if you want to manually change type then do it so: `(new-type)variable;` then variable will be of type new-type.

from a bigger type into a smaller one the information can be lost.

if you want to round a float or a double and cast it into int then `(int)(x + 0.5)`, otherwise what is after the comma will just be deleted.

post increment: `c = a++;` then `c = a` then `a = a + 1;`.

pre increment if `c = ++a;` then `a = a + 1;` then `c = a`.

the logical operators are calculated form left to right. the or `||` breaks when one part is true, the and `&&` breaks when one part is false.

the bit operators are `& | ^` and or and xor. also the right and link shifts `a >> b`, `a << b` shifts b bits of a.

cast into unsigned int before use.

if you use the variable more than one time then you can do it like this: `a += 5` for `a = a + 5`.

note though that there is an implicit bracing going on. i.e. `x *= y + 5` is `x = x * (y + 5)`.

if you have a simple if then use: `condition ? value : value2`. where the condition will be assessed first and if true then value else value 2. -is a shorter if else-.

you can use the comma to evaluate more than a variable in one line, i.e. `a = 1, i = 4`. it will be assessed from left to right.

a pointer has the value of an address in memory, i.e. `int a = 1; int* pa = &a;` then: `int b = *pa` gives b the value of a.

the use of * is called dereferencing.

if you declare more than one pointer then use `int *a, *b, ...` if the above notation is used then the first only will be a pointer and what comes after is but mere int's.

when you want to check if the pointer exists always use `NULL`.

a pointer is connected to the variable type.

in defining a function you first state the return type, otherwise use `void FuncName(){}`, you also need to specify which types of inputs the function accepts.

the `main` function is the last function in the code file.

if you want to manipulate a value without passing it to the function the you need to use call by reference. in  which you pass the address to the value and dereference it in the function.

when the program sees a return it will end.

you can basic define a function, without giving it the actual code/function, just the name and type.

recursion is just a sophisticated for loop. you can also think of it as an induction proof. so you set the basic state and then just make everything go back to it.

the enum starts with 0 up to n-1. where n is the number of the elements.

like: `enum DataType {value, value, value};`

also you can use it to make a constant, i.e. `enum {N = 10};`

also you can use typedef. i.e. `typedef int NaturalNumber;`, or `typedef int* PNaturalNumber;`, then `PNaturalNumber a,b;` both will be of type `int*`.

an array saves the value of things of the same type and has a set size -unless used with malloc/calloc-, i.e. `int[100]; char[50];`...

when reading into array do not forget the address operator `&`.

if the array size is not given, it will be determined basing off of the number of elements.

the name of the array is the pointer at the first value.

use pointer/element increment/decrement to go in the array forward/backward.

a string is but an array of char's, so `s[]="test"; ` is equal to `s[] = { 't', 'e', 's', 't', '\0'};`.

the function `fgets(ArrayName, highestIndex, stdin)` reads strings?

the function `sprintf(ArrayName, "Format", value-1, ..., value-n)` outputs an array, otherwise it is the same as `printf`.

for strings use `<string.h>`.

if you want to check the length of a string then use `strlen(Array)`.

compare two strings? `strcom(Array1, Array2)`, if A1<A2 then the value is <0, so is = and > defined.

copy? `strncpy(Goal, Source, Size)` where goal and source are arrays, and size is the number of indexes.

to use Unicode you need `<locale.h.> <stddef.h> <wchar.h> <wctype.h>`

a multi dimensional array is just an array with a `[]_k` after it (k because it can be of whatever length).

if you want to have more than one type of data for an element use `struct`s.

`struct Name{blablabla} Variable;` this creates a Variable of type Name.

if you have a pointer at a structure then use the `->` operator to get to the element. i.e. `struct X{ double a,b;} test;` then `int* pX; pX = & test; pX->a = 1;` or b.

the use of pointers for structures in functions is just more logical, since a pointer is just an int while a structure can be of any size.

in defining structures define the largest variable first, so that no memory capacity is lost doing noting.

the union is used in structures with structures if the structure to use is to be determined and can change depending on the variable.

`sizeof(Type)` or Var gives the size of this element in memory in bits.

`malloc(size)` allocates memory of size size.

`calloc(number-of-element, size-of-element)` allocates memory of n-o-e * s-o-e.

`malloc` and `calloc` both give a pointer.

you need to test for NULL just in case.

`free(void* ptr)` frees the block of `ptr`.

these functions are usually used when the size of the array is not set before runtime.

you can also use assert of `<assert.h>` that breaks if there is no memory.

if you want to define a list then `typedef struct node{ // blablabla; struct node* rest; } node; typedef node* list;`

