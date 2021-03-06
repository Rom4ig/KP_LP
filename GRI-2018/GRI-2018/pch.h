// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define LENGTH(x)(sizeof(x)/sizeof(*x))
using namespace std;
#include <iostream>
#include <iomanip>
#include <locale>
#include <stdio.h>
#include <tchar.h>
#include <clocale>
#include <fstream>
#include <string.h>
#include <ctime>
#include <stack>
#include <string>
#include "Error.h"
#include "FST.h"
#include "Generation.h"
#include "Graphs.h"
#include "Greibach.h"
#include "IdTable.h"
#include "In.h"
#include "LexAnalys.h"
#include "LexTable.h"
#include "Log.h"
#include "MFST.h"
#include "Parm.h"
#include "PolishNotation.h"
#include "SemanticAnalys.h"
// TODO: add headers that you want to pre-compile here
#endif //PCH_H


