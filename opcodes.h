#ifndef OP_CODES_H
#define OP_CODES_H

enum OP_CODES {
	/*
		| v hi/lo >   | 0x0      | 0x1       | 0x2   | 0x3   | 0x4       | 0x5       | 0x6       | 0x7   | 0x8      | 0x9       | 0xA      | 0xB   | 0xC       | 0xD       | 0xE       | 0xF   |
		|-------------|----------|-----------|-------|-------|-----------|-----------|-----------|-------|----------|-----------|----------|-------|-----------|-----------|-----------|-------|
		| 0x0         | BRK      | ORA X,IND |       |       |           | ORA ZPG   | ASL ZPG   |       | PHP      | ORA #     | ASL A    |       |           | ORA ABS   | ASL ABS   |       |
		| 0x1         | BPL      | ORA IND,Y |       |       |           | ORA ZPG,X | ASL ZPG,X |       | CLC      | ORA ABS,Y |          |       |           | ORA ABS,X | ASL ABS,X |       |
		| 0x2         | JSR ABS  | AND X,IND |       |       | BIT ZPG   | AND ZPG   | ROL ZPG   |       | PLP      | AND #     | ROL A    |       | BIT ABS   | AND ABS   | ROL ABS   |       |
		| 0x3         | BMI      | AND IND,Y |       |       |           | AND ZPG,X | ROL ZPG,X |       | SEC      | AND ABS,Y |          |       |           | AND ABS,X | ROL ABS,X |       |
		| 0x4         | RTI      | EOR X,IND |       |       |           | EOR ZPG   | LSR ZPG   |       | PHA      | EOR #     | LSR A    |       | JMP ABS   | EOR ABS   | LSR ABS   |       |
		| 0x5         | BVC      | EOR IND,Y |       |       |           | EOR ZPG,X | LSR ZPG,X |       | CLI      | EOR ABS,Y |          |       |           | EOR ABS,X | LSR ABS,X |       |
		| 0x6         | RTS      | ADC X,IND |       |       |           | ADC ZPG   | ROR ZPG   |       | PLA      | ADC #     | ROR A    |       | JMP IND   | ADC ABS   | ROR ABS   |       |
		| 0x7         | BVS      | ADC IND,Y |       |       |           | ADC ZPG,X | ROR ZPG,X |       | SEI      | ADC ABS,Y |          |       |           | ADC ABS,X | ROR ABS,X |       |
		| 0x8         |          | STA X,IND |       |       | STY ZPG   | STA ZPG   | STX ZPG   |       | DEY      |           | TXA      |       | STY ABS   | STA ABS   | STX ABS   |       |
		| 0x9         | BCC      | STA IND,Y |       |       | STY ZPG,X | STA ZPG,X | STX ZPG,Y |       | TYA      | STA ABS,Y | TXS      |       |           | STA ABS,X |           |       |
		| 0xA         | LDY #    | LDA X,IND | LDX # |       | LDY ZPG   | LDA ZPG   | LDX ZPG   |       | TAY      | LDA #     | TAX      |       | LDY ABS   | LDA ABS   | LDX ABS   |       |
		| 0xB         | BCS      | LDA IND,Y |       |       | LDY ZPG,X | LDA ZPG,X | LDX ZPG,Y |       | CLV      | LDA ABS,Y | TSX      |       | LDY ABS,X | LDA ABS,X | LDX ABS,Y |       |
		| 0xC         | CPY #    | CMP X,IND |       |       | CPY ZPG   | CMP ZPG   | DEC ZPG   |       | INY      | CMP #     | DEX      |       | CPY ABS   | CMP ABS   | DEC ABS   |       |
		| 0xD         | BNE      | CMP IND,Y |       |       |           | CMP ZPG,X | DEC ZPG,X |       | CLD      | CMP ABS,Y |          |       |           | CMP ABS,X | DEC ABS,X |       |
		| 0xE         | CPX #    | SBC X,IND |       |       | CPX ZPG   | SBC ZPG   | INC ZPG   |       | INX      | SBC #     | NOP      |       | CPX ABS   | SBC ABS   | INC ABS   |       |
		| 0xF         | BEQ      | SBC IND,Y |       |       |           | SBC ZPG,X | INC ZPG,X |       | SED      | SBC ABS,Y |          |       |           | SBC ABS,X | INC ABS,X |       |
	*/

	// ADC INSRUCTIONS
	INS_ADC_X_IND = 0x61,
	INS_ADC_ZP = 0x65,
	INS_ADC_IM = 0x69,
	INS_ADC_AB = 0x6d,
	INS_ADC_IND_Y = 0x71,
	INS_ADC_ZPX = 0x75,
	INS_ADC_AB_Y = 0x79,
	INS_ADC_AB_X = 0x7d,

	// AND INSRUCTIONS
	INS_AND_X_IND = 0x21,
	INS_AND_ZP = 0x25,
	INS_AND_IM = 0x29,
	INS_AND_AB = 0x2d,
	INS_AND_IND_Y = 0x31,
	INS_AND_ZPX = 0x35,
	INS_AND_AB_Y = 0x39,
	INS_AND_AB_X = 0x3d,

	// ASL INSRUCTIONS
	INS_ASL_ZP = 0x06,
	INS_ASL_A = 0x0a,
	INS_ASL_AB = 0x0e,
	INS_ASL_ZPX = 0x16,
	INS_ASL_AB_X = 0x1e,

	// BIT INSRUCTIONS
	INS_BIT_ZP = 0x24,
	INS_BIT_AB = 0x2c,

	// CMP INSRUCTIONS
	INS_CMP_X_IND = 0xc1,
	INS_CMP_ZP = 0xc5,
	INS_CMP_IM = 0xc9,
	INS_CMP_AB = 0xcd,
	INS_CMP_IND_Y = 0xd1,
	INS_CMP_ZPX = 0xd5,
	INS_CMP_AB_Y = 0xd9,
	INS_CMP_AB_X = 0xdd,

	// CPX INSRUCTIONS
	INS_CPX_IM = 0xe0,
	INS_CPX_ZP = 0xe4,
	INS_CPX_AB = 0xec,

	// CPY INSRUCTIONS
	INS_CPY_IM = 0xc0,
	INS_CPY_ZP = 0xc4,
	INS_CPY_AB = 0xcc,

	// DEC INSRUCTIONS
	INS_DEC_ZP = 0xc6,
	INS_DEC_AB = 0xce,
	INS_DEC_ZPX = 0xd6,
	INS_DEC_AB_X = 0xde,

	// EOR INSRUCTIONS
	INS_EOR_X_IND = 0x41,
	INS_EOR_ZP = 0x45,
	INS_EOR_IM = 0x49,
	INS_EOR_AB = 0x4d,
	INS_EOR_IND_Y = 0x51,
	INS_EOR_ZPX = 0x55,
	INS_EOR_AB_Y = 0x59,
	INS_EOR_AB_X = 0x5d,

	// INC INSRUCTIONS
	INS_INC_ZP = 0xe6,
	INS_INC_AB = 0xee,
	INS_INC_ZPX = 0xf6,
	INS_INC_AB_X = 0xfe,

	// JMP INSRUCTIONS
	INS_JMP_AB = 0x4c,
	INS_JMP_IND = 0x6c,

	// LDA INSRUCTIONS
	INS_LDA_X_IND = 0xa1,
	INS_LDA_ZP = 0xa5,
	INS_LDA_IM = 0xa9,
	INS_LDA_AB = 0xad,
	INS_LDA_IND_Y = 0xb1,
	INS_LDA_ZPX = 0xb5,
	INS_LDA_AB_Y = 0xb9,
	INS_LDA_AB_X = 0xbd,

	// LDX INSRUCTIONS
	INS_LDX_IM = 0xa2,
	INS_LDX_ZP = 0xa6,
	INS_LDX_AB = 0xae,
	INS_LDX_ZPY = 0xb6,
	INS_LDX_AB_Y = 0xbe,

	// LDY INSRUCTIONS
	INS_LDY_IM = 0xa0,
	INS_LDY_ZP = 0xa4,
	INS_LDY_AB = 0xac,
	INS_LDY_ZPX = 0xb4,
	INS_LDY_AB_X = 0xbc,

	// LSR INSRUCTIONS
	INS_LSR_ZP = 0x46,
	INS_LSR_A = 0x4a,
	INS_LSR_AB = 0x4e,
	INS_LSR_ZPX = 0x56,
	INS_LSR_AB_X = 0x5e,

	// ORA INSRUCTIONS
	INS_ORA_X_IND = 0x01,
	INS_ORA_ZP = 0x05,
	INS_ORA_IM = 0x09,
	INS_ORA_AB = 0x0d,
	INS_ORA_IND_Y = 0x11,
	INS_ORA_ZPX = 0x15,
	INS_ORA_AB_Y = 0x19,
	INS_ORA_AB_X = 0x1d,

	// ROL INSRUCTIONS
	INS_ROL_ZP = 0x26,
	INS_ROL_A = 0x2a,
	INS_ROL_AB = 0x2e,
	INS_ROL_ZPX = 0x36,
	INS_ROL_AB_X = 0x3e,

	// ROR INSRUCTIONS
	INS_ROR_ZP = 0x66,
	INS_ROR_A = 0x6a,
	INS_ROR_AB = 0x6e,
	INS_ROR_ZPX = 0x76,
	INS_ROR_AB_X = 0x7e,

	// SBC INSRUCTIONS
	INS_SBC_X_IND = 0xe1,
	INS_SBC_ZP = 0xe5,
	INS_SBC_IM = 0xe9,
	INS_SBC_AB = 0xed,
	INS_SBC_IND_Y = 0xf1,
	INS_SBC_ZPX = 0xf5,
	INS_SBC_AB_Y = 0xf9,
	INS_SBC_AB_X = 0xfd,

	// STA INSRUCTIONS
	INS_STA_X_IND = 0x81,
	INS_STA_ZP = 0x85,
	INS_STA_AB = 0x8d,
	INS_STA_IND_Y = 0x91,
	INS_STA_ZPX = 0x95,
	INS_STA_AB_Y = 0x99,
	INS_STA_AB_X = 0x9d,

	// STX INSRUCTIONS
	INS_STX_ZP = 0x86,
	INS_STX_AB = 0x8e,
	INS_STX_ZPY = 0x96,

	// STY INSRUCTIONS
	INS_STY_ZP = 0x84,
	INS_STY_AB = 0x8c,
	INS_STY_ZPX = 0x94,

	// OTHER INSRUCTIONS
	INS_PLA = 0x68,
	INS_TAX = 0xaa,
	INS_SEI = 0x78,
	INS_TXS = 0x9a,
	INS_RTS = 0x60,
	INS_PLP = 0x28,
	INS_PHP = 0x08,
	INS_SEC = 0x38,
	INS_TXA = 0x8a,
	INS_TSX = 0xba,
	INS_RTI = 0x40,
	INS_TAY = 0xa8,
	INS_SED = 0xf8,
	INS_JSR_AB = 0x20,
	INS_PHA = 0x48,
	INS_NOP = 0xea,
	INS_BCC = 0x90,
	INS_BCS = 0xb0,
	INS_BEQ = 0xf0,
	INS_BMI = 0x30,
	INS_BNE = 0xd0,
	INS_BPL = 0x10,
	INS_BRK = 0x00,
	INS_BVC = 0x50,
	INS_BVS = 0x70,
	INS_CLC = 0x18,
	INS_CLD = 0xd8,
	INS_CLI = 0x58,
	INS_CLV = 0xb8,
	INS_DEX = 0xca,
	INS_DEY = 0x88,
	INS_INX = 0xe8,
	INS_INY = 0xc8,
	INS_TYA = 0x98,
};

#endif