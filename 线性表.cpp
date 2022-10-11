#include<iostream>
using namespace std;
const int MAXSIZE=100;

template<class ElemType> 
class Sqlist{
public:
	ElemType *elem;
	int length;//���Ԫ�ظ��� 
	int count;//����Ԫ�ظ��� 
public:
	Sqlist(){//�������Ԫ�ظ���ΪMAXSIZE�����Ա� 
		if(elem!=NULL) delete []elem;
		elem = new ElemType*[MAXSIZE];
		length = MAXSIZE;
		count = 0; 
	}
	Sqlist(int size){//�������Ԫ�ظ���Ϊsize�����Ա� 
		if(elem!=NULL) delete []elem;
		elem = new ElemType*[size];
		length = size;
		count = 0; 
	}
	~Sqlist(){//ɾ�����Ա� 
		delete []elem;
	}
	bool Full() const{//�Ƿ�Ϊ�� 
		return count == MAXSIZE;
	}
	bool Empty() const{//�Ƿ�Ϊ�� 
		return count==0;
	} 
	int Length() const{//�Ѿ��ж��ٸ�Ԫ�� 
		return count;
	}
	void Clear(){//��ձ� 
		count = 0;
	}
	void Traverse(void (*visit)(ElemType &e)){//��������ÿһ��Ԫ�����ε���visit���� 
		for(int CurrentPosition=0;CurrentPosition<Length();CurrentPosition++){
			(*visit)(elem[CurrentPosition]);
		} 
	}
	bool GetElem(int position,ElemType &e){//�жϴ治���ڵ�position��Ԫ��,����e������ֵ 
		if(position<0 || position>=Length()){
			return false
		} else {
			e = elem[position];
			return true;
		}
	}
	bool SetElem(int position,const ElemType &e){//��e��ֵ����position��Ԫ�� 
		if(position<0 || position>=Length()){
			return false;
		} else {
			elem[position] = e;
			return ;
		}
	}
	bool Insert(int position,const ElemType &e){//�ڵ�position��λ��֮ǰ����Ԫ��e 
		//positionȡֵ��0-length֮��,������,length�����뵽ĩβ 
		//��������positionԽ��,����false
		//�Ϸ�����true
		int len=Length();
		ElemType temp;
		if(Full()){
			return false;
		} else if(position<0 || position>len){
			return false;
		} else {
			count++;
			for(int CurrentPosition=len-1;CurrentPosition>=position;CurrentPosition--){
				GetElem(CurrentPosition,temp);
				SetElem(CurrentPosition+1,temp);
			}
			SetElem(position,e);
			return true;
		}
	}
	bool Delete(int position,ElemType &e){//ɾ������positionλ��Ԫ�أ���e������ֵ
		//position��Χ0-length-1;
		int len=Length();
		ElemType temp;
		if(position<0 || position>len-1){
			return false;
		} else if(Empty()){
			return false;
		} else {
			GetElem(position,e);
			for(int CurrentPosition=position;CurrentPosition<len;CurrentPosition++){
				GetElem(CurrentPosition,temp);
				SetElem(CurrentPosition-1,temp);
			}
			count--;
			return true;
		}
	}
	
	
};

int main(){
	
}
