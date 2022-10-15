// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_excecoes.hpp"
#include "LimitedQueue.hpp"
#include "Exceptions.hpp"

int main() {
	LimitedQueue* queue = nullptr;
	char command;
	int k, maxsize;
	while(cin >> command){
		try{
			switch (command){
			case 'i':
				cin >> maxsize;
				queue = new LimitedQueue(maxsize);
				break;
			case 'p':
				cin >> k;
				queue->push_back(k);
				break;
			case 'o':
				queue->pop_front();
				break;
			case 'f':
				cout << queue->front() << endl;
				break;
			case 'l':
				cout << queue->back() << endl;
				break;
			case 'm':
				queue->print();
				break;
			case 'd':
				cin >> k;
				cout << queue->find(k) << endl;
				break;
			case 'b':
				avaliacao_basica();
				break;
			default:
				break;
			}
		} catch(InvalidSizeException& e){
			cout << "Excecao: " << e.name << endl;
		} catch(QueueFullException& e){
			cout << "Excecao: " << e.name << endl;
		} catch(QueueEmptyException& e){
			cout << "Excecao: " << e.name << endl;
		} catch(ItemNotFoundException& e){
			cout << "Excecao: " << e.name << endl;
		}
	}
	return 0;
}