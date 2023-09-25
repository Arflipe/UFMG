#include <iostream>

using namespace std;

class Inc{
	public:
		static int getIncrement(){
			return 3;
		}
		
		static int increment(int x){
			return x + getIncrement();
		}
};

int main(){
	cout << Inc::increment(10) << endl;
}