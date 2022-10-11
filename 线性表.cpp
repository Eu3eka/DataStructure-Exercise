#include<iostream>
using namespace std;
const int MAXSIZE=100;

template<class ElemType> 
class Sqlist{
public:
	ElemType *elem;
	int length;//最大元素个数 
	int count;//已有元素个数 
public:
	Sqlist(){//建立最大元素个数为MAXSIZE的线性表 
		if(elem!=NULL) delete []elem;
		elem = new ElemType*[MAXSIZE];
		length = MAXSIZE;
		count = 0; 
	}
	Sqlist(int size){//建立最大元素个数为size的线性表 
		if(elem!=NULL) delete []elem;
		elem = new ElemType*[size];
		length = size;
		count = 0; 
	}
	~Sqlist(){//删除线性表 
		delete []elem;
	}
	bool Full() const{//是否为空 
		return count == MAXSIZE;
	}
	bool Empty() const{//是否为满 
		return count==0;
	} 
	int Length() const{//已经有多少个元素 
		return count;
	}
	void Clear(){//清空表 
		count = 0;
	}
	void Traverse(void (*visit)(ElemType &e)){//遍历表，对每一个元素依次调用visit函数 
		for(int CurrentPosition=0;CurrentPosition<Length();CurrentPosition++){
			(*visit)(elem[CurrentPosition]);
		} 
	}
	bool GetElem(int position,ElemType &e){//判断存不存在第position个元素,并以e返回其值 
		if(position<0 || position>=Length()){
			return false
		} else {
			e = elem[position];
			return true;
		}
	}
	bool SetElem(int position,const ElemType &e){//把e赋值给第position个元素 
		if(position<0 || position>=Length()){
			return false;
		} else {
			elem[position] = e;
			return ;
		}
	}
	bool Insert(int position,const ElemType &e){//在第position个位置之前插入元素e 
		//position取值在0-length之间,闭区间,length即插入到末尾 
		//已满或者position越界,返回false
		//合法返回true
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
	bool Delete(int position,ElemType &e){//删除表中position位置元素，用e返回其值
		//position范围0-length-1;
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
