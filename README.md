# Memory_Alignment_MSP432

**Table of Contents** 
1. [Brief Summary](#bs-id)
1. [Project Features](#pf-id)
1. [Important repos/links](#pm-id)
1. [Availible Parameter Modifications](#il-id)

<br>
<br>

<a id="bs-id"></a>
## Brief Summary 
Code for the MSP432P401R to demonstrate the effects of memory alignment, based on Alex Fosdick's 
"_Embedded Software and Hardware Architecture_" out of _University of Colorado Boulder_. Code was modified 
to include Timer32 to observe latency, sizeof() function used to analyze memory use. 

__Packed__:
"Utilize the keyword `__attribute__((packed))` to create a packed structure (ex_packed_t)
that minimizes memory usage by eliminating padding bytes between members. It will however, INCREASE COMPUTATION TIME."


__Padded__:
Padding ensures data elements are correctly aligned to memory boundaries, enabling efficient memory access by the processor. 
This alignment reduces overhead and allows faster calculations, resulting in decreased execution time for computational tasks. However, padding does INCRESE MEMORY USAGE!


!<img width="710" alt="PaddedAndPackedStructs" src="https://github.com/rudi547317/Memory_Alignment_MSP432/assets/133919829/239ba8d1-5585-48ac-b400-2031a60d03dd">


### Project Specs

| Compiler                 | Framework                 | CCS Version                             |
|--------------------------|---------------------------|-----------------------------------------|
|TI v20.2.7.LTS            |Bare-metal programming     | 11.1.0.00011                            |


<br>
<br>

<a id="pf-id"></a>
## Project Features


