#include <stdlib.h>
#include <stdio.h>

/*
Mali programčić koji ispisuje binarni zapis brojeva u računalu na kojem se pokreće.

Program se poziva sa sljedećim argumentima:
  1) tipom podataka (c|s|i|l|f|d za char, short, integer, long, float ili double)
  2) brojem čiji se binarni zapis želi vidjeti (a koji će po tipu biti ono što je zadano prvim argumentom)
  3) brojem brojeva koji će se prikazati, s tim da za cijelobrojne tipove će to biti uzastopni brojevi (+1), a za float/double će biti uzastopni količnici s brojem 3 (/3)

Ispis je "(signed|unsigned|ASCII) binarno" za cijelobrojne tipove, a
"(decimal|scientific|integer) binarno" za float i double

Primjer pozivanja: binarni_ispis.exe c 70 2
Ispis:
(70|70|F) 01000110
(71|71|G) 01000111

Primjer pozivanja: binarni_ispis.exe i -9 2
Ispis:
(-9|4294967287|�) 11111111111111111111111111110111
(-8|4294967288|�) 11111111111111111111111111111000

Primjer pozivanja: binarni_ispis.exe f 90 3
Ispis:
(        90.000000000|9.00000000e+01|131040571293696) 01000010101101000000000000000000
(        30.000000000|3.00000000e+01|131040558448640) 01000001111100000000000000000000
(        10.000000000|1.00000000e+01|131040544817152) 01000001001000000000000000000000

autor: Eugen Rožić, prof.
*/

char* binary(int bytesize, char *bytes){
	
	int bitsize = bytesize*8;
	char* ret = (char*)malloc(bitsize+1);
	ret[bitsize] = '\0';
	char mask;
	
	for (int i=0; i<bytesize; i++){
		for (int j=0; j<8; j++){
			mask = 1 << j;
			if ((bytes[i]&mask) == 0){
				ret[bitsize-i*8-j-1] = '0';
			} else {
				ret[bitsize-i*8-j-1] = '1';
			}
		}
	}
	return ret;
}

int main(int argc, char** argv){
    
	char type = argv[1][0];
	int count = atoi(argv[3]);
	
	char *bitrep;
	
	if (type == 'c'){
			char c = atoi(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(c), (char*)&c);
				printf("(%d|%u|%c) %s\n", c, (unsigned char)c, c, bitrep);
				c++;
			}
	} else if (type == 's'){
			short s = atoi(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(s), (char*)&s);
				printf("(%d|%u|%c) %s\n", s, (unsigned short)s, s, bitrep);
				s++;
			}
	} else if (type == 'i'){
			int d = atoi(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(d), (char*)&d);
				printf("(%d|%u|%c) %s\n", d, (unsigned int)d, d, bitrep);
				d++;
			}
	} else if (type == 'l'){
			long l = atoi(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(l), (char*)&l);
				printf("(%ld|%lu|%c) %s\n", l, (unsigned long)l, (int)l, bitrep);
				l++;
			}
	} else if (type == 'f'){
			float f = atof(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(f), (char*)&f);
				printf("(%20.9f|%.8e|%11ld) %s\n", f, f, *(long*)(&f), bitrep);
				f /= 3;
			}
	} else if (type == 'd'){
			double d = atof(argv[2]);
			for (int i = 0; i<count; i++){
				bitrep = binary(sizeof(d), (char*)&d);
				printf("(%36.17f|%.16e|%11ld) %s\n", d, d, *(long*)(&d), bitrep);
				d /= 3;
			}
	} else {
			printf("ERROR: Unknown type!\n");
	}
	
	free(bitrep);
	
	return 0;
}
