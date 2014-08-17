#ifndef _morse_h
#define _morse_h

static const char* CHAR_TO_MORSE[128] = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, "-.-.--", ".-..-.", NULL, NULL, NULL, NULL, ".----.",
	"-.--.", "-.--.-", NULL, NULL, "--..--", "-....-", ".-.-.-", "-..-.",
	"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
	"---..", "----.", "---...", NULL, NULL, "-...-", NULL, "..--..",
	".--.-.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
	"....",	"..", ".---", "-.-", ".-..", "--", "-.", "---",
	".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
	"-..-", "-.--", "--..", NULL, NULL, NULL, NULL, "..--.-",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

static const char* MORSE_TO_CHAR[128] = {
	NULL, NULL, "E", "T", "I", "A", "N", "M",
	"S", "U", "R", "W", "D", "K", "G", "O",
	"H", "V", "F", NULL, "L", NULL, "P", "J",
	"B", "X", "C", "Y", "Z", "Q", NULL, NULL,
	"5", "4", NULL, "3", NULL, NULL, NULL, "2",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, "1",
	"6", "=", "/", NULL, NULL, NULL, "(", NULL,
	"7", NULL, NULL, NULL, "8", NULL, "9", "0",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, "?", "_", NULL, NULL,
	NULL, NULL, "\"", NULL, NULL, ".", NULL, NULL,
	NULL, NULL, "@", NULL, NULL, NULL, "'", NULL,
	NULL, "-", NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, "!", NULL, ")", NULL, NULL,
	NULL, NULL, NULL, ",", NULL, NULL, NULL, NULL,
	":", NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

const char* char_to_morse(char);
const char* morse_to_char(const char*);
int morse_to_index (const char*);

#endif

