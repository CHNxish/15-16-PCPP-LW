#ifndef _SQ_STRING_ADT_H_
#define _SQ_STRING_ADT_H_

#define NONE_POSITION (-1)

typedef struct{
	int capacity;
	int length;
	char *data;
}SqString, *PtrSqString;

PtrSqString CreateSqString(int maxElements);
int IsEmptySqString(PtrSqString string);
int IsFullSqString(PtrSqString string);
void DisposeSqString(PtrSqString string);
void MakeEmptySqString(PtrSqString string);
int LengthSqString(PtrSqString string);
void ConcatSqString(PtrSqString string1, PtrSqString string2);
PtrSqString SubSqString(PtrSqString string, int position, int length);
int EqualSqString(PtrSqString string1, PtrSqString string2);
int IndexSqString(PtrSqString string1, PtrSqString string2);
void InsertSqString(PtrSqString string1, PtrSqString string2, int position);

#endif