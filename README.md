# Project8-1_Enigma_machine

## Contributor
1063514 李晨宇 Tasaky-cyber
>Build enigma simulator

1051537 康宇良 aksulk1587
>Build input permutation combination of all possibility to break the encrypted text 
>
## Version

### Enigma: 
original

### Enigma_v2: 
it can't work on the Visual Studio,strlen()=>Error, so we correct it

### Enigma_v3: 
ROTOR 3 will get problem so will delete the code under

        //if(start3==index3-1)
        
            //start3++;          
### Engima_decipher 
use it to try every possibility to decode the encrypt text

## Enigma Simulation
---
![](https://i.imgur.com/ZKXBXwJ.png)
Enigma Simulation: http://www.enigmaco.de/enigma/
:::info
:mega:
1. Graph and Our C++ code different nomination (from right to left 1,2,3)
 >Rotor I   = incir3[26]
 >Rotor II  = incir2[26]
 >Rotor III = incir1[26]
2. remember the number cauclate and the range cauclate will get the more 1 than the accurate one
:::
## Basic flow
![](https://i.imgur.com/lkrYRTo.png)
### Initial value-Enigma Status
    assume:
     start1=X
     start2=D
     start3=H
     index1=W
     index2=F
     index3=R
    
### 1.Plaintext -> plugboard  (Red line)
    A->one of the alphabet
    ex:A->A
### 2.plugboard -> Rotor III
    A.Number-> correspond to the rotate table
    ex:A->Y
### 3.plugboard -> inner Rotor III
    through LRmove know how many steps on the left
    ex:Y->Q
### 4.inner Rotor III -> Rotor II
    by step3 LRmove consequence+ Rotor II start2 to get corresponding loacation
    ex:Q->V
### 5.Rotor II -> inner Rotor II
    same concept of step 2
The below step, and so on
### 6.inner Rotor II -> Rotor I
### 7.Rotor I -> inner Rotor I
### 8.inner Rotor I -> Reflector 
### 9.Reflector -> inner Rotor I  (Green line)
### 10.inner Rotor I -> Rotor I
### 11.Rotor I -> inner Rotor II
### 12.inner Rotor II -> Rotor II
### 13.Rotor II -> inner Rotor III
### 14.inner Rotor III -> Rotor III
### 15.Rotor III ->plugboard
### 16.plugboard -> plaintext
In my C++ code I set //consequence below the execution line; if you don't understand clarify, you can just cancel comment to know each answer in each step.
### Function
#### LRmove
LRmove function is the core of this code.(to know how many step to move left or right)
Find the inner rotor value and find the next rotor value
#### Ctrlrange
the number will overflow because the number of the alphabet only 26. If the number is over the 26, we have to make it back to 0 means it run full circle(return to zero)
#### Find alphabet
find the number sequence of alphbet in that rotor array.

---
## Decipher


kerrypear write here<=


### lifting efficiency
 The data is too big to computing,so we have to do some tricks to speed up computing.
1. WWII,military of germany write Heil Hitler in the last of telegram. Heil Hitler is a big  hint of last 10 words of encrypted text. We detect the last 6 words(hitler) on encrypted text. Surprisingly, this method will detect a little bit more match of last 6 words in ciphertext. Detection of word increase to 10 words to decrease lots of match situation happened.

2. If the first word not the same we directly break it,we don't waste any computing power
Example:
>char s[10] = { 9, 16, 17, 8, 21, 7, 3, 24, 26, 13 };//INPUT:IPQHUGCXZM
>last 7words
>Ciphertext=IPQHUGCXZM
>Detection=^
>If not equal to H,break to do next input

3. Parallelization
   We use a special way to insert our 0 on our input text to make it be devided by many parts. We can throw the parts to different computers to cauclate the value. This method also decrease the risk of the computer going wrong. If the computer crash, we don't need to run the input from the initial. We can just run that part which  computer handle again.   
