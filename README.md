# Encryption Arduino
To use XxteaTest you must have all the files in a rar, removing the folders that Arduino generates by default.
In the txt that is in the rar you can see the effectiveness of Xxtea against other encryption methods. Attach the DES.h library as it is necessary.
ExampleComputer and ExampleComputer2 can be run normally, just set COM5 to 115200 baud. They only need the xxtea library that they can find in the search for arduino libraries within the IDE (It is the only one that comes out).

### Abstract— In computing, encryption is the method by which plaintext or any other type of data is converted from a readable form to an encoded version that can only be decoded by another entity if they have access to a decryption key. Encryption is one of the most important methods for providing data security, especially for end-to-end protection of data transmitted across networks. In cryptography, the Tiny Encryption Algorithm (TEA) is a block cipher notable for its simplicity of description and implementation, typically a few lines of code.
## I. INTRODUCTION
In cryptography, Corrected Block TEA (often referred to as XXTEA) is a block cipher designed to correct weaknesses in the original Block TEA.
XXTEA is vulnerable to a chosen-plaintext attack requiring 259 queries and negligible work. See cryptanalysis below.
The cipher's designers were Roger Needham and David Wheeler of the Cambridge Computer Laboratory, and the algorithm was presented in an unpublished technical report in October 1998 (Wheeler and Needham, 1998). It is not subject to any patents.
Formally speaking, XXTEA is a consistent incomplete source-heavy heterogeneous UFN (unbalanced Feistel network) block cipher. XXTEA operates on variable-length blocks that are some arbitrary multiple of 32 bits in size (minimum 64 bits). The number of full cycles depends on the block size, but there are at least six (rising to 32 for small block sizes). The original Block TEA applies the XTEA round function to each word in the block and combines it additively with its leftmost neighbour. Slow diffusion rate of the decryption process was immediately exploited to break the cipher. Corrected Block TEA uses a more involved round function which makes use of both immediate neighbours in processing each word in the block.
XXTEA is likely to be more efficient than XTEA for longer messages.
Needham & Wheeler make the following comments on the use of Block TEA
1. For ease of use and general security the large block version is to be preferred when applicable for the following reasons.
2. A single bit change will change about one half of the bits of the entire block, leaving no place where the changes start.
3. There is no choice of mode involved.
4. Even if the correct usage of always changing the data sent (possibly by a message number) is employed, only
identical messages give the same result and the information leakage is minimal.
5. The message number should always be checked as this redundancy is the check against a random message being accepted.
6. Cut and join attacks do not appear to be possible.
7. If it is not acceptable to have very long messages, they can be broken into chunks say of 60 words and chained analogously to the methods used for DES.
However, due to the incomplete nature of the round function, two large cipher texts of 53 or more 32-bit words identical in all but 12 words can be found by a simple brute-force collision search requiring 296−N memory, 2N time and 2N+2^96−N chosen plaintexts, in other words with a total time*memory complexity of 296, which is actually 2wordsize*full cycles/2 for any such cipher. It is currently unknown if such partial collisions pose any threat to the security of the cipher. Eight full cycles would raise the bar for such collision search above complexity of parallel brute-force attacks.
## II. CRYPTANALYSIS
An attack published in 2010 by E. Yarrkov presents a chosen-plaintext attack against full-round XXTEA with wide block, requiring 259 queries for a block size of 212 bytes or more, and negligible work. It is based on differential cryptanalysis.
## III. REFERENCE CODE
The original formulation of the Corrected Block TEA algorithm, published by David Wheeler and Roger Needham, is as the Fig. 1.
According to Needham and Wheeler:
1. BTEA will encode or decode n words as a single block where n > 1
2. v is the n word data vector
3. k is the 4-word key
4. n is negative for decoding
5. If n is zero result is 1 and no coding or decoding takes place, otherwise the result is zero
6. Assumes 32 bit 'long' and same endian coding and decoding
Note that the initialization of z is Undefined behavior for n < 1 which may cause a segmentation fault or other unwanted behavior – it would be better placed inside the 'Coding Part' block. Also, in the definition of MX some programmers would prefer to use bracketing to clarify operator precedence. A clarified version including those improvements is shown in the Fig. 2
Fig. 1 Corrected Block TEA algorithm
Fig. 2 Clarified version of TEA algorithm
## IV.TESTS
Encryption and decryption speed tests were performed in a text block of 64byts to 16Mhz, obtaining the results shown in fig. 3, where we can see that XXTEA is more efficient than other methods such as the encryption by blocks of Data Encryption Standard and XXTEA itself, as well as XXTEA overwriting the plain text.
1. DES in CBC mode takes 284568us and occupies 2572 bytes of flash
2. XTEA in CBC mode takes 11008us and occupies 916 bytes of flash
3. XXTEA takes 4168us and occupies 1086 bytes of flash
Fig. 3 Results of the test
## V. APPLICATIONS
The unusually small size of the XXTEA algorithm would make it a viable option in situations where there are extreme constraints e.g. legacy hardware systems (perhaps embedded) where the amount of available RAM is minimal, or alternatively single-board computers such as the Raspberry Pi, Banana Pi or Arduino.
A. PC Examples
Using the library of XXTEA in Arduino, available in the list of libraries to download in the official IDE of Arduino, the code shown in Fig. 4 and Fig. 5 was implemented, where the encryption and decryption are shown, respectively.
Fig. 4 Encryption
Fig. 5 Decryption
Fig. 6 Encrypted and decrypted message
B. Arduino + Android
On screen 0 the search for Bluetooth devices is established, when the button is pressed it connects with the Android module. Which is waiting for the buttons to encrypt and decrypt to show in the text fields.
Fig. 7 Screen 0
Fig. 8 block programming of Screen0
Fig. 9 Screen1
Fig. 10 block programming of Screen1
Fig. 11 Screen2
Fig. 12 block programming of Screen2
Fig. 13 Screen3
Fig. 14 block programming of Screen3
Fig. 15 Encryption, Decryption and send of the messages
## III.DISCUSSION
During the development of this project the main challenge was to find information on the use of XXTEA with Arduino, since it was mostly used with other programming languages.
## IV.CONCLUSION
XXTEA is very small and fast, which makes it very good to be used in embedded systems, so it is very good in IOT systems. It is also very easy to use, so, coupled with its free software feature, it can be used by anyone to be modified and, therefore, improved and be more efficient.
#### GLOSSARY
1. IOT:
The internet of things, or IoT, is a system of interrelated computing devices, mechanical and digital machines, objects, animals or people that are provided with unique identifiers ( UIDs ) and the ability to transfer data over a network without requiring human-to-human or human-to-computer interaction.Compiler.
2. DES:
Data Encryption Standard.
3. CBC:
Cipher Block Chaining.
#### REFERENCES
David J. Wheeler and Roger M. Needham (October 1998). "Correction to XTEA" (PDF). Computer Laboratory, Cambridge University, England. Retrieved 2019-05-29.
Matthew D. Russell (2004-02-27). "Tinyness: An Overview of TEA and Related Ciphers". Archived from the original on 2019-05-29.
Roger M. Needham and David J. Wheeler (October 1997). "Tea extensions" (PDF). Computer Laboratory, Cambridge University, England. Retrieved 2019-05-29.
Margaret Rouse (2016). “Internet of things (IoT)” Extracted of IoT Agenda: https://internetofthingsagenda.techtarget.com/definition/Internet-of-Things-IoT
TheFreeDictionary.com. S.v. "DES-CBC." Retrieved May 30 2019 from https://acronyms.thefreedictionary.com/DES-CBC
