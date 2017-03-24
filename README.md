# Neural Networks

A `C++` playground for my machine learning experiments. Nothing professional or interesting at the moment. Anyway, I will use this README to write personal annotations.

## Compile

To build all the test programs, enter the project root and type:

```
make all
```

## The pool file format

```
Pool
inputs,outputs
Genome
from,to,weight,innovation,enabled
...
Genome
from,to,weight,innovation,enabled
...
```

## The XOR test

To launch the XOR test run the command:

```
bin/test002 assets/xor.pool
```

and insert the input vales (0 or 1), remember to always put 1 for the third input parameter, that being the constant bias generator.

The expected results should be:

* 0 xor 0 : 0
* 0 xor 1 : 1
* 1 xor 0 : 1
* 1 xor 1 : 0

I want to solve the problem by expanding it into the boolean expression:

```
a xor b = (a or b) and (!a or !b)
```

Experimenting step by step, I created an `or` gate and an `and` gate. Gates have a fixed additional input, always set to 1, to use as bias. I created 3 genomes to play with `or.pool`, `and.pool`, `nand.pool`. A fourth, the `nor.pool` file was made as an exercise.
