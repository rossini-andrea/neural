# Neural Networks

A `C++` playground for my machine learning experiments. Nothing professional or interesting at the moment. Anyway, I will use this README to write personal annotations.

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

and insert the input vales (0 or 1).

The expected results should be:

* 0 xor 0 : 0
* 0 xor 1 : 1
* 1 xor 0 : 1
* 1 xor 1 : 0

Obviously it doesn't work.
