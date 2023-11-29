//
//	This file is automatically generated
//
switch (*DCOMMAND) {
	case 1:
		switch (*DFUNCTION) {
			case 0:
				DSPReset();
				break;
			case 1:
				*((uint32_t *)DPARAMS) = TMRRead();
				break;
		}
		break;
	case 2:
		switch (*DFUNCTION) {
			case 0:
				CONWrite(*DPARAMS);
				break;
			case 1:
				*(DPARAMS) = KBDGetKey();
				break;
			case 2:
				*(DPARAMS) = KBDIsKeyAvailable() ? 0xFF: 0;
				break;
		}
		break;
	case 3:
		switch (*DFUNCTION) {
		}
		break;
	case 4:
		MATHCommon(DPARAMS);
		switch (*DFUNCTION) {
			case 1:
				if (MATHIsFloatBinary()) {
				MATHWriteFloat(MATHReadFloat(MATH_REG1)-MATHReadFloat(MATH_REG2),MATH_REG1);
				} else {
				MATHWriteInt(MATHReadInt(MATH_REG1)-MATHReadInt(MATH_REG2),MATH_REG1);
				}
				break;
			case 16:
				if (MATHIsFloatUnary()) {
				MATHWriteFloat(-MATHReadFloat(MATH_REG1),MATH_REG1);
				} else {
				MATHWriteInt(-MATHReadInt(MATH_REG1),MATH_REG1);
				}
				break;
			case 32:
				MATHProcessDecimal(DCOMMAND);
				break;
		}
		break;
}
