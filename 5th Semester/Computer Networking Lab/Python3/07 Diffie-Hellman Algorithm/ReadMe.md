### Diffie Hellman Algorithm for *Key Exchange*

This Algorithm is used just for the purpose of exchanging keys between communicating parties.

#### Algorithm

1. Let there be existing 2 public key components g,p.

2. Each of them picks a secret number of their own(x,y) and then exchange a number.

3. The number is used to generate the key.

#### Demo

Choose *g* and *p* such that p is root modulo of g.

*Side 1*

1. R<sub>1</sub> = g<sup>x</sup> mod(p)
2. Send this to Side 2.
3. Receive R<sub>2</sub> from side 2.
4. Shared Key = (R<sub>2</sub>)<sup>x</sup> mod(p)


*Side 2*

1. R<sub>2</sub> = g<sup>y</sup> mod(p)
2. Send this to Side 2.
3. Receive R<sub>1</sub> from side 2.
4. Shared Key = (R<sub>1</sub>)<sup>y</sup> mod(p)


