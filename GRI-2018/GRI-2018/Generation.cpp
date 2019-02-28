#include "pch.h"
#include "Generation.h"
#define Head "import sys \nimport os\n" //"шапка" нашей генерации
#define OUT generate
ofstream generate("..//Generation.py");

bool isFunction = false;
int idFunc;
int buf;
void Generation(LT::LexTable &Lextable, In::StToken *tokens, IT::IdTable &idtable)
{
	OUT << Head;
	for (int i = 0; i < Lextable.size; i++)
	{
		switch (Lextable.table[i].lexema)
		{
		case LEX_NUM:
			break;
		case LEX_GLAVN:
		{
			isFunction = true;
			OUT << "\ndef main():";
			break;
		}
		case LEX_FUNCTION:
		{
			isFunction = true;
			idFunc = Lextable.table[i + 1].idxTI;
			buf = Lextable.table[i + 1].idxTI;
			OUT << "def " << idtable.table[buf].id;
			i++;
			break;
		}
		case LEX_LEFTBRACE:
		{
			OUT << "\n" << "    ";
			break;
		}
		case LEX_BRACELET:
		{
			if (isFunction)
				OUT << "\n" ;
			break;
		}
		case LEX_DEF:
		{
			if (Lextable.table[i + 1].lexema == LEX_NUM && Lextable.table[i + 3].lexema == LEX_EQUAL)
			{
				OUT << tokens[i + 2].token << '=' << tokens[i + 4].token << "\n    ";
				i += 5;
				break;
			}
			while (Lextable.table[i].lexema != LEX_SEPARATOR)
				i++;
			break;
		}
		case LEX_STANDART:
		{
			OUT << "import GRI as GRI" << "\n";
			break;
		}
		case LEX_ID:
		{
			int y;
			y = Lextable.table[i].idxTI;
			if (Lextable.table[i - 2].lexema == LEX_OUT) {			OUT << idtable.table[y].id; }
			else if (idtable.table[y].iddatatype == IT::STR || IT::NUM && Lextable.table[i - 2].lexema != LEX_OUT) { OUT << idtable.table[y].id; }
		/*	if (Lextable.table[i + 1].lexema == LEX_ID || Lextable.table[i + 1].lexema == LEX_LITERAL)
			{
				int j = i;
				while (Lextable.table[j].lexema != LEX_SEPARATOR)
				{
					switch (Lextable.table[j].lexema)
					{
					case LEX_PLUS:
					{	if (Lextable.table[j-1].lexema != LEX_PLUS && Lextable.table[j-1].lexema != LEX_STAR)
						OUT << "+";
						break;
					}
					case LEX_STAR:
					{if (Lextable.table[j - 1].lexema != LEX_STAR) {
						OUT << "*"; j++;
					}
						break;
					}
					case LEX_MINUS:
					{
						if (Lextable.table[j - 1].lexema != LEX_MINUS)
						OUT << "-";
						break;
					}
					case LEX_DIRSLASH:
					{
						if (Lextable.table[j - 1].lexema != LEX_DIRSLASH)
						OUT << "/";
						break;
					}
					default:
						break;
					} 
					j++;
				}
			}*/
			break;
		}
		case LEX_EQUAL:
		{
			OUT << "=";
			break;
		}
		case LEX_SEPARATOR:
		{
			if (isFunction)
				OUT << "\n    ";
			break;
		}
		case LEX_STRLEN:
		{
			OUT << "len";
			break;
		}
		case LEX_SUBSTR:
		{
			OUT << "GRI.Substr";
			break;
		}
		case LEX_DOUBLE:
		{
			OUT << "GRI.Doub";
			break;
		}
		case LEX_LITERAL:
		{
			if (tokens[i].isLiteral == true)
			{
				if (tokens[i].isStr == true)
				{
					OUT << tokens[i].token;
				}
				else
				{
					int tp;
					tp = atoi(tokens[i].token);
					if (tp > INT_MAXSIZE)
					{
						throw ERROR_THROW(6);
					}
					else if (tp < INT_MIN)
					{
						throw ERROR_THROW(6);
					}
					OUT << tp;
					break;
				}
			}
			break;
		}
		case LEX_OUT:
		{
			OUT << "print ";
			break;
		}
		case LEX_LEFTHESIS:
		{
			OUT << "(";
			break;
		}
		case LEX_RIGHTTHESIS:
		{
			OUT << ")";
			if (Lextable.table[i + 1].lexema == LEX_LEFTBRACE)
				OUT << ':';
			break;
		}
		case LEX_PLUS:
		{
			OUT << "+";
			break;
		}
		case LEX_STAR:
		{
			OUT << "*";
			break;
		}
		case LEX_MINUS:
		{
			OUT << "-";
			break;
		}
		case LEX_DIRSLASH:
		{
			OUT << "//";
			break;
		}
		case LEX_COMMA:
		{
			OUT << ",";
			break;
		}
		case LEX_BACK:
		{
			if (isFunction)
				OUT << "return ";
			break;
		}
		default:
		{
			//OUT << tokens[i].token;
			break;
		}
		}
	}
	OUT << "\nmain()";
	OUT << "\nos.system('pause')";
	OUT.close();
}
