#include <iostream>
#include <cstdint>
#include <vector>
#include <deque>
/** /
struct ECBit {
	bool A = {};


	enum op {
		And = 0,
		Or = 1,
	};

	op OP = op::And;
	static constexpr bool b =1;

};
/**/
bool EnCode(bool A, bool B=true) {

	bool R = ((A & B) & B) & B;
	

	return R;

}

bool EcCodition(bool A,bool B=true) {
	bool R = !(A & B);  R=(R | B)& B;

	return R;
}

bool ErrorCheck(bool A, bool B=false) {
		return (A && B) || B;
}

int main(){

	char oxbe = 0xBE;
	std::vector<bool> bits;

	for (int i = 0; i < 8; ++i) {
		bool bit;
		bit = (oxbe >> (7 - i)) & 1;
		bits.push_back(bit);
	}

	std::deque<bool> bits2;
	for (int i = 0; i < 8; ++i) {
		bool bit;
		bit = (oxbe >> (7 - i)) & 1;
		bits2.push_back(EnCode(bit));
	}

	for (auto& bit : bits2) {
		std::cout << bit;
	}
	std::deque<bool> bits4;
	std::cout << std::endl;
	for (auto& bit : bits2) {
		bits4.push_back(ErrorCheck(bit));
		std::cout<<(bits4.back() ? 't' : 'f');
	}
	std::cout << std::endl;

	std::deque<bool> bits3;
	for (int i = 0; i < 8; ++i) {
		bool bit;
		bit = (oxbe >> (7 - i)) & 1;
		bits3.push_back(EcCodition(bit));
	}

	for (auto& bit : bits3) {
		std::cout << bit;
	}
	std::cout << std::endl;
	for (auto& bit : bits3) {
		std::cout<<(ErrorCheck(bit) ? 't' : 'f');
	}
	std::cout << std::endl;

	std::deque<bool> bits5;
	for (int i = 0; i < 8; ++i) {
		bits5.push_back(EcCodition(bits3[i],bits4[i]));
	}

	for (auto& bit : bits5) {
		std::cout << bit;
	}
	std::cout << std::endl;
	for (auto& bit : bits5) {
		std::cout<<(ErrorCheck(bit) ? 't' : 'f');
	}
	std::cout << std::endl;

	char C = 0;
	
	for (int i = 0; i < 8; ++i) {
		bool bit;
		bit = (oxbe >> (7 - i)) & 1;
		bool bit2=EnCode(bit);
		bool bit3 = EcCodition(bit2);
		if (!ErrorCheck(bit3)) {
			//std::cout << "Error detected at bit position: " << i << std::endl;
			bit3 = !bit3;
		}

		std::cout << (bit!=bit3 ? 't' : 'f');

		C |= ((bit3>0) << i);
	}
	std::cout << std::endl;	

	std::cout << "Original byte: 0x" << oxbe << std::endl;	
	std::cout << "Processed byte: 0x" << C << std::endl;

	C = oxbe;
	std::cout << "Processed byte: 0x" << C << std::endl;
}
/*

int main() {
	{
		ECBit bit;
		bit.A = true;
		bool result = EnCode(bit.A, true);
		std::cout << "EnCode result: " << result << std::endl;
		bool conditionResult = EcCodition(bit.A);
		std::cout << "EcCodition result: " << conditionResult << std::endl;
		bool errorCheckResult = ErrorCheck(bit.A, true);
		std::cout << "ErrorCheck result: " << errorCheckResult << std::endl;
	//	return 0;
	}
	ECBit bit;
	bit.A = false;
	bool result = EnCode(bit.A, true);
	std::cout << "EnCode result: " << result << std::endl;
	bool conditionResult = EcCodition(bit.A);
	std::cout << "EcCodition result: " << conditionResult << std::endl;
	bool errorCheckResult = ErrorCheck(bit.A, true);
	std::cout << "ErrorCheck result: " << errorCheckResult << std::endl;
	return 0;
}
*/
