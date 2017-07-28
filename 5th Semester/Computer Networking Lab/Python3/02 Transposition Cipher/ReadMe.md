# Transposition Cipher

In cryptography, a transposition cipher is a method of encryption by which the positions held by units of plaintext (which are commonly characters or groups of characters) are shifted according to a regular system, so that the ciphertext constitutes a permutation of the plaintext. That is, the order of the units is changed (the plaintext is reordered). Mathematically a bijective function is used on the characters' positions to encrypt and an inverse function to decrypt.

## Rail Fence cipher
The Rail Fence cipher is a form of transposition cipher that gets its name from the way in which it is encoded. In the rail fence cipher, the plaintext is written downwards on successive "rails" of an imaginary fence, then moving up when we get to the bottom. The message is then read off in rows. For example, using three "rails" and a message of 'WE ARE DISCOVERED. FLEE AT ONCE', the cipherer writes out:
```
W . . . E . . . C . . . R . . . L . . . T . . . E
. E . R . D . S . O . E . E . F . E . A . O . C .
. . A . . . I . . . V . . . D . . . E . . . N . .
```
Then reads off:
```
WECRL TEERD SOEEF EAOCA IVDEN
```
The rail fence cipher was used by the ancient Greeks in the scytale, a mechanical system of producing a transposition cipher. The system consisted of a cylinder and a ribbon that was wrapped around the cylinder. The message to be encrypted was written on the coiled ribbon. The letters of the original message would be rearranged when the ribbon was uncoiled from the cylinder. However, the message was easily decrypted when the ribbon was recoiled on a cylinder of the same diameter as the encrypting cylinder.


## Route cipher
In a route cipher, the plaintext is first written out in a grid of given dimensions, then read off in a pattern given in the key. For example, using the same plaintext that we used for rail fence:

```
W R I O R F E O E 
E E S V E L A N J 
A D C E D E T C X 
```

The key might specify "spiral inwards, clockwise, starting from the top right". That would give a cipher text of:
```
EJXCTEDECDAEWRIORFEONALEVSE
```
Route ciphers have many more keys than a rail fence. In fact, for messages of reasonable length, the number of possible keys is potentially too great to be enumerated even by modern machinery. However, not all keys are equally good. Badly chosen routes will leave excessive chunks of plaintext, or text simply reversed, and this will give cryptanalysts a clue as to the routes.

**_There are many more ciphers. We'll be demonstrating the above two only and implementing rail fence cipher._**


```
Source : Wikipedia
```
