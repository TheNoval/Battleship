/*

*/
#pragma once
#include <string>

void colorOn(int id);
void colorOff(int id);
void vertPrint(int startY, int X, std::string input);
char wrongInput();
int intInput(std::string prompt, std::string failPrompt);