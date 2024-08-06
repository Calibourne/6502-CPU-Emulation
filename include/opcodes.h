#ifndef OP_CODES_H
#define OP_CODES_H

enum OP_CODES {
/*
		| v hi/lo > | 0x0    | 0x1       | 0x2    | 0x3 | 0x4       | 0x5       | 0x6       | 0x7 | 0x8 | 0x9       | 0xA   | 0xB | 0xC       | 0xD       | 0xE       | 0xF |
		|-----------|--------|-----------|--------|-----|-----------|-----------|-----------|-----|-----|-----------|-------|-----|-----------|-----------|-----------|-----|
		| 0x0       | BRK    | ORA X,IND |        |     |           | ORA ZPG   | ASL ZPG   |     | PHP | ORA IM    | ASL A |       |         | ORA ABS   | ASL ABS   |     |
    | 0x1       | BPL    | ORA IND,Y |        |     |           | ORA ZPG,X | ASL ZPG,X |     | CLC | ORA ABS,Y |       |     |           | ORA ABS,X | ASL ABS,X |     |
		| 0x2       | JSR    | AND X,IND |        |     | BIT ZPG   | AND ZPG   | ROL ZPG   |     | PLP | AND IM    | ROL A |     | BIT ABS   | AND ABS   | ROL ABS   |     |
		| 0x3       | BMI    | AND IND,Y |        |     |           | AND ZPG,X | ROL ZPG,X |     | SEC | AND ABS,Y |       |     |           | AND ABS,X | ROL ABS,X |     |
		| 0x4       | RTI    | EOR X,IND |        |     |           | EOR ZPG   | LSR ZPG   |     | PHA | EOR IM    | LSR A |     | JMP ABS   | EOR ABS   | LSR ABS   |     |
		| 0x5       | BVC    | EOR IND,Y |        |     |           | EOR ZPG,X | LSR ZPG,X |     | CLI | EOR ABS,Y |       |     |           | EOR ABS,X | LSR ABS,X |     |
		| 0x6       | RTS    | ADC X,IND |        |     |           | ADC ZPG   | ROR ZPG   |     | PLA | ADC IM    | ROR A |     | JMP IND   | ADC ABS   | ROR ABS   |     |
		| 0x7       | BVS    | ADC IND,Y |        |     |           | ADC ZPG,X | ROR ZPG,X |     | SEI | ADC ABS,Y |       |     |           | ADC ABS,X | ROR ABS,X |     |
		| 0x8       |        | STA X,IND |        |     | STY ZPG   | STA ZPG   | STX ZPG   |     | DEY |           | TXA   |     | STY ABS   | STA ABS   | STX ABS   |     |
		| 0x9       | BCC    | STA IND,Y |        |     | STY ZPG,X | STA ZPG,X | STX ZPG,Y |     | TYA | STA ABS,Y | TXS   |     |           | STA ABS,X |           |     |
		| 0xA       | LDY IM | LDA X,IND | LDX IM |     | LDY ZPG   | LDA ZPG   | LDX ZPG   |     | TAY | LDA IM    | TAX   |     | LDY ABS   | LDA ABS   | LDX ABS   |     |
		| 0xB       | BCS    | LDA IND,Y |        |     | LDY ZPG,X | LDA ZPG,X | LDX ZPG,Y |     | CLV | LDA ABS,Y | TSX   |     | LDY ABS,X | LDA ABS,X | LDX ABS,Y |     |
		| 0xC       | CPY IM | CMP X,IND |        |     | CPY ZPG   | CMP ZPG   | DEC ZPG   |     | INY | CMP IM    | DEX   |     | CPY ABS   | CMP ABS   | DEC ABS   |     |
		| 0xD       | BNE    | CMP IND,Y |        |     |           | CMP ZPG,X | DEC ZPG,X |     | CLD | CMP ABS,Y |       |     |           | CMP ABS,X | DEC ABS,X |     |
		| 0xE       | CPX IM | SBC X,IND |        |     | CPX ZPG   | SBC ZPG   | INC ZPG   |     | INX | SBC IM    | NOP   |     | CPX ABS   | SBC ABS   | INC ABS   |     |
		| 0xF       | BEQ    | SBC IND,Y |        |     |           | SBC ZPG,X | INC ZPG,X |     | SED | SBC ABS,Y |       |     |           | SBC ABS,X | INC ABS,X |     |
*/

  // BRK INS (Break)
  
  INS_BRK = 0x00,

  
  // ADC INSRUCTIONS (Add with Carry)
  
  INS_ADC_IM = 0x69,
  INS_ADC_ZP = 0x65,
  INS_ADC_ZPX = 0x75,
  INS_ADC_ABS = 0x6D,
  INS_ADC_ABX = 0x7D,
  INS_ADC_ABY = 0x79,
  INS_ADC_INX = 0x61,
  INS_ADC_INY = 0x71,


  // LDA INSRUCTIONS (Load Accumulator)
  
  INS_LDA_IM = 0xA9,
  INS_LDA_ZP = 0xA5,
  INS_LDA_ZPX = 0xB5,
  INS_LDA_ABS = 0xAD,
  INS_LDA_ABX = 0xBD,
  INS_LDA_ABY = 0xB9,
  INS_LDA_INX = 0xA1,
  INS_LDA_INY = 0xB1,

  
  // Jump to Subroutine
  INS_JSR = 0x20,

};

#endif