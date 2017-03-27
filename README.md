# Neural Networks

A `C++` playground for my machine learning experiments. Nothing professional or interesting at the moment. Anyway, I will use this README to write personal annotations.

## Compile

To build all the test programs, enter the project root and type:

```
make all
```

## The pool file format

It is a very simple list of genomes and genes, I expect the format to change frequently.

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

## The XOR test - Human created version

I chose to solve the problem by expanding it into the boolean expression:

```
a xor b = (a or b) and (!a or !b)
```

Experimenting step by step, I created an `or`, an `and` and a `nand` gate. Every gate has a fixed additional input, always set to 1, to use as constant bias generator. I created their corresponding genomes to play with: `or.pool`, `and.pool`, `nand.pool`. A fourth, the `nor.pool` file was made as an exercise.

To launch the XOR test run the command:

```
bin/test002 assets/xor.pool
```

Then insert the input vales (0 or 1), remember to always put 1 for the third parameter.

The expected results should be:

* 0 xor 0 : 0
* 0 xor 1 : 1
* 1 xor 0 : 1
* 1 xor 1 : 0

## References

Here is a set of links I gathered while studying the subject:

* [Mar I/O video](https://www.youtube.com/watch?v=qv6UVOQ0F44)
* [Mar I/O code](http://pastebin.com/ZZmSNaHX)
* [NEAT](http://nn.cs.utexas.edu/downloads/papers/stanley.ec02.pdf)
