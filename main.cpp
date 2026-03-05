#include <iostream>
#include <windows.h>
using namespace std;

class Object{
	public:
		Object(int index){
			this->index = index;
		}

		int index;
		void func(int val){
			this->index = val;
			cout<< this->index << " = not null"<<endl;
		}
};


int main(){
	system("cls");

	cout <<"creating array"<<endl;
	Object *objects[6] = {0};
	cout <<"created array"<<endl<<endl;
	
	cout <<"created array values: "<<endl; 	
	for (int n=0; n < sizeof(objects) / sizeof(objects[0]); n++){
		if (objects[n] == nullptr){
			cout << n << " = null"<< endl;
		}else{
			objects[n]->func(n);
		}
	}

	cout<<endl<<"creating objects"<<endl;
	objects[3] = new Object(0);
	objects[1] = new Object(1);
	cout<<"created objects"<<endl<<endl;

	cout << "reading changed array"<<endl;
	for (int n=0; n < sizeof(objects) / sizeof(objects[0]); n++){
		if (objects[n] == nullptr){
			cout << n << " = null"<< endl;
		}else{
			objects[n]->func(n);
		}
	}
	cout<<"read changed array"<<endl<<endl;

	cout<<"cleaning changed array"<<endl;
	for (int n=0; n < sizeof(objects) / sizeof(objects[0]); n++){
		if (objects[n] != nullptr){
			cout << objects[n]->index << " deleted from memory"<<endl;
			delete objects[n];
			objects[n] = NULL;
		}
	}
	cout<<"cleaned"<<endl<<endl;
	
	cout<<"cleaned array:"<<endl;
	for (int n=0; n < sizeof(objects) / sizeof(objects[0]); n++){
		if (objects[n] == nullptr){
			cout << n << " is null"<< endl;
		}else{
			cout << n << " is not null"<< endl;
		}
	}

	cout <<endl<<"program shutdown"<<endl<<endl;
	return 0;
}
