# Lab 8: Nicolás González Mazuelos

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-- | :-: |
   | `add r24, r0` | 0000 1101 1000 0000 | 0xD80 | D80 |
   | `com r26` | 1001 0101 1010 0000 | 0x95A0 | 95A0 |
   | `eor r26, r27` | 0010 0111 1010 1011 | 0x27AB | 27AB |
   | `mul r22, r20` | 1001 1111 0110 0100 | 0x9F64 | 9F64 |
   | `ret` | 1001	0101	0000	1000 | 0x9508 | 9508 |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 4 | 4 |
   | 4, 2 | 7 | 7 |
   | 4, 1 | 15 | 15 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()