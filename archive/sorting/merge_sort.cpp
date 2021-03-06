#include<iostream>
using namespace std;

void divide(int array[], int num);
void conquer(int array1[], int num1, int array2[], int num2, int array[]);
void print(int array[], int size){
	for(int i=0; i<size; i++){
		cout<<array[i];
		if(i<size-1) cout<<", ";
	}
	cout<<endl;
}

int main(){
	int num; //the number of elements we want to sort
	cout<<"Enter the number of elements you want to sort: "; cin>>num;
	int array[num]; //the array of the elements
	for(int i=0; i<num; i++){
		cout<<"Enter value "<<(i+1)<<": "; cin>>array[i];
	}
	
	cout<<"Original sequence: ";
	for(int i=0; i<num; i++){
		cout<<array[i];
		if(i!=num-1) cout<<", ";
	}
	cout<<endl;
	
	//sorting begins here
	divide(array, num);
	
	cout<<"Sorted sequence: ";
	for(int i=0; i<num; i++){
		cout<<array[i];
		if(i!=num-1) cout<<", ";
	}
	cout<<endl;
}

void divide(int array[], int num){
	int mid = num/2;
	if(mid==0) return;
	int array1[mid];
	int array2[num-mid];
	for(int i=0; i<mid; i++){
		array1[i] = array[i];
	}
	for(int i=0; i<num-mid; i++){
		array2[i] = array[mid+i];
	}
	divide(array1, mid);
	divide(array2, num-mid);
	conquer(array1, mid, array2, num-mid, array);
}

void conquer(int array1[], int num1, int array2[], int num2, int array[]){
	int pos1 = 0, pos2 = 0, pos = 0;
	for(int i=0; i<num1+num2; i++){
		
		if(pos1==num1){
			array[i] = array2[pos2];
			pos2++;
			continue;
		}
		
		if(pos2==num2){
			array[i] = array1[pos1];
			pos1++;
			continue;
		}
		
		if(array1[pos1]<array2[pos2]){
			array[i] = array1[pos1];
			pos1++;
		}else{
			array[i] = array2[pos2];
			pos2++;
		}
	}
}
