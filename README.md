# Memory_Alignment_MSP432
Code for the MSP432P401R to demonstrate the effects of memory alignment, based on Alex Fosdick's 
"_Embedded Software and Hardware Architecture_" out of _University of Colorado Boulder_. Code was modified 
to include Timer32 to observe latency, sizeof() function used to analyze memory use. 

## Brief Summary 

__Packed__:
"Utilize the keyword `__attribute__((packed))` to create a packed structure (ex_packed_t)
that minimizes memory usage by eliminating padding bytes between members. It will however, increase computation time."


__Padded__:
Padding ensures data elements are correctly aligned to memory boundaries, enabling efficient memory access by the processor. 
This alignment reduces overhead and allows faster calculations, resulting in decreased execution time for computational tasks.


!<img width="710" alt="PaddedAndPackedStructs" src="https://github.com/rudi547317/Memory_Alignment_MSP432/assets/133919829/239ba8d1-5585-48ac-b400-2031a60d03dd">


