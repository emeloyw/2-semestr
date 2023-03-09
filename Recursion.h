#pragma once

#include "Header.h"


void RecTable();

typedef
struct _stRecItem {
	int nIdSet;				//идентификатор набора данных
	double nValue1,			//значение 1
		nValue2;			//значение 2

	_stRecItem() :nIdSet(0), nValue1(0), nValue2(0) {}
	_stRecItem(int pID, double pValue1, double pValue2) :nIdSet(pID), nValue1(pValue1), nValue2(pValue2){}


}stRecItem, *pstRecItem;

typedef
struct _stRecursion {
	int nCount;						//Кол-во эл-ов структур в наборе данных
	pstRecItem setRec;				//массив структур

	_stRecursion() :nCount(0), setRec(NULL){}
	_stRecursion(int pCount) { setRec = new stRecItem[pCount]; }
	~_stRecursion() { delete[]setRec; }

	int Additem(int pId, double pV1, double pV2) {					//добавить в конец новый набор данных
		nCount++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * nCount);		//создать новый набор данных

		setRec[nCount - 1].nIdSet = pId;
		setRec[nCount - 1].nValue1 = pV1;
		setRec[nCount - 1].nValue2 = pV2;
		return nCount;
	}

	void Clear() {
		nCount = 0;
		if(setRec != NULL) {
			free(setRec);
			setRec = NULL;
		}
	}
	
	int SetCount(int pnCount) {
		Clear();
		nCount = pnCount;
		setRec = new stRecItem[pnCount];
		return nCount;
	}

}stRecursion, *pstRecursion;