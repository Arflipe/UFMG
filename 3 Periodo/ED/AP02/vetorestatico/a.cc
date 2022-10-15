#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define avisoAssert(e,m) ((bool) ((e)?0: __avisoassert (#e,__FILE__,__LINE__,m)))
#define __avisoassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Aviso: '%s' - %s\n",file,line,e,m),0)

using namespace std;

int main(){
	int a;
	cin >> a;
	if(!avisoAssert(a >= 0, "menor q 0")){
		cout << endl << endl << a << endl << endl;
	}
	else{
		cout << endl << "nao foi" << endl;
	}
}