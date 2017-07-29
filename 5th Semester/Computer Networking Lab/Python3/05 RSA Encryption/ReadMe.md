# RSA Encryption

RSA is algorithm used by modern computers to encrypt and decrypt messages. It is an asymmetric cryptographic algorithm. Asymmetric means that there are two different keys. This is also called public key cryptography, because one of them can be given to everyone. The other key must be kept private. It is based on the fact that finding the factors of an integer is hard (the factoring problem). RSA stands for Ron Rivest, Adi Shamir and Leonard Adleman, who first publicly described it in 1978. A user of RSA creates and then publishes the product of two large prime numbers, along with an auxiliary value, as their public key. The prime factors must be kept secret. Anyone can use the public key to encrypt a message, but with currently published methods, if the public key is large enough, only someone with knowledge of the prime factors can feasibly decode the message.

## Methodology

RSA involves a public key and private key. The public key can be known to everyone; it is used to encrypt messages. Messages encrypted using the public key can only be decrypted with the private key. The keys for the RSA algorithm are generated the following way:

```
1. Choose two different large random prime numbers p and q. [Order 100 in given situation]
2. Calculate n = pq
    n is the MODULUS for the public keys and the private key.
3. Calculate the TOTIENT : φ(n) = (p-1)(q-1)
4. Choose an integer e such that 1 < e < φ(n), and e is coprime to φ(n).
    e is released as the public key exponent
5. Compute d such that de = 1 + kφ(n)
    d is kept as private key exponent
```


## Display Using Example

1. Say `p = 131` and `q = 157`

2. `n = p * q = 20567`

3. `φ(n) = (p-1)(q-1) = 20280`

4. `e = 103`(Say)

5. Putting in equation 
    `k = 75` to get `d = 14767`
    
Therefore:

Public Key **(n = 20567, e = 103)**

Private Key **(n = 20567, d = 14767)**

Let the message to be hidden is `m = 123`

#### Encryption


* m = 123

* c = (m<sup>e</sup>)%n = (123<sup>103</sup>) % 20567  = 14763

Hence Our Encrypted message is 14763

#### Decryption

* c = 14763

* m = (c<sup>d</sup>)%n = (14763<sup>14767</sup>) % 20567 = 123

Hence The message is successfully recovered.clear


