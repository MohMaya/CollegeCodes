# Playfair Cipher

The **Playfair cipher** or **Playfair square** or **Wheatstone-Playfair cipher** or **Wheatstone cipher** is a manual `symmetric encryption` technique and was the first literal `digram substitution cipher`. The scheme was invented in 1854 by Charles Wheatstone, but bears the name of Lord Playfair who promoted the use of the cipher.

The technique encrypts pairs of letters (bigrams or digrams), instead of single letters as in the simple substitution cipher and rather more complex Vigenère cipher systems then in use. The Playfair is thus significantly harder to break since the frequency analysis used for simple substitution ciphers does not work with it. The frequency analysis of bigrams is possible, but considerably more difficult. With 600 possible bigrams rather than the 26 possible monograms (single symbols, usually letters in this context), a considerably larger cipher text is required in order to be useful.

## Methodology

The Playfair cipher uses a 5 by 5 table containing a key word or phrase. Memorization of the keyword and 4 simple rules was all that was required to create the 5 by 5 table and use the cipher.

To generate the key table, one would first fill in the spaces in the table with the letters of the keyword (dropping any duplicate letters), then fill the remaining spaces with the rest of the letters of the alphabet in order (usually omitting "J" or "Q" to reduce the alphabet to fit; other versions put both "I" and "J" in the same space). The key can be written in the top rows of the table, from left to right, or in some other pattern, such as a spiral beginning in the upper-left-hand corner and ending in the center. The keyword together with the conventions for filling in the 5 by 5 table constitute the cipher key.

To encrypt a message, one would break the message into digrams (groups of 2 letters) such that, for example, "HelloWorld" becomes "HE LL OW OR LD", and map them out on the key table. If needed, append an uncommon monogram to complete the final digram. The two letters of the digram are considered as the opposite corners of a rectangle in the key table. Note the relative position of the corners of this rectangle. Then apply the following 4 rules, in order, to each pair of letters in the plaintext:

```
1. If both letters are the same (or only one letter is left), add an "X" after the first letter. Encrypt the new pair and continue. Some variants of Playfair use "Q" instead of "X", but any letter, itself uncommon as a repeated pair, will do.
2. If the letters appear on the same row of your table, replace them with the letters to their immediate right respectively (wrapping around to the left side of the row if a letter in the original pair was on the right side of the row).
3. If the letters appear on the same column of your table, replace them with the letters immediately below respectively (wrapping around to the top side of the column if a letter in the original pair was on the bottom side of the column).
4. If the letters are not on the same row or column, replace them with the letters on the same row respectively but at the other pair of corners of the rectangle defined by the original pair. The order is important – the first letter of the encrypted pair is the one that lies on the same row as the first letter of the plaintext pair.
5. **To decrypt**, use the INVERSE (opposite) of the last 3 rules, and the 1st as-is (dropping any extra "X"s, or "Q"s that do not make sense in the final message when finished).
```

There are several minor variations of the original Playfair cipher.

## Example

Using `playfair example` as the key (assuming that I and J are interchangeable), the table becomes (omitted letters in red):
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_building_grid_omitted_letters.png "Creating Cipher Table")

Thus The Final Table Becomes

```
P L A Y F
I R E X M
B C D G H
K N O Q S
T U V W Z
```

Encrypting the message "Hide the gold in the tree stump" (note the null "X" used to separate the repeated "E"s) :

1. Break Into Digrams
```
HI DE TH EG OL DI NT HE TR EX ES TU MP
```

2. The pair HI forms a rectangle, replace it with BM
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_01_HI_to_BM.png "Step 1")


3. The pair DE is in a column, replace it with OD
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_02_DE_to_OD.png "Step 2")


4. The pair TH forms a rectangle, replace it with ZB
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_03_TH_to_ZB.png "Step 3")


5. The pair EG forms a rectangle, replace it with XD
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_04_EG_to_XD.png "Step 4")


6. The pair OL forms a rectangle, replace it with NA
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_05_OL_to_NA.png "Step 5")


7. The pair DI forms a rectangle, replace it with BE

8. The pair NT forms a rectangle, replace it with KU

9. The pair HE forms a rectangle, replace it with DM

10. The pair TR forms a rectangle, replace it with UI
![Image Unavailable](https://github.com/MohMaya/CollegeCodes/raw/master/5th%20Semester/Computer%20Networking%20Lab/Python3/03%20Play%20Fair%20Cipher/assets/Playfair_Cipher_10_EX_to_XD.png "Step 9")


11. The pair EX (X inserted to split EE) is in a row, replace it with XM

12. The pair ES forms a rectangle, replace it with MO

13. The pair TU is in a row, replace it with UV

14. The pair MP forms a rectangle, replace it with IF

Final Encrypted Bigram : 
`BM OD ZB XD NA BE KU DM UI XM MO UV IF`

```
Source : Wikipedia
```