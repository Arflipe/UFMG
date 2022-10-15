#include "csv.hpp"

void CSV::split(string& str, vector<string>& out){
    int start = 0;
    string del = ";";
	int end = str.find(del);
    while (end != -1) {
        out.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(del, start);
    }
    out.push_back(str.substr(start, end - start));
}

string CSV::getHeader(IReadable& object){
	vector<string> out;
	object.GetCampos(out);
	string header;
	header = out[0] + ";" + out[1] + ";" + out[2];
	return header;
}

void CSV::readLine(string& head, string& line, IReadable& object){
	vector<string> h;
	vector<string> l;
	split(head, h);
	split(line, l);
	for(int i = 0; i < 3; i++){
		object.setAtributo(h[i], l[i]);
	}
}

string CSV::write(IReadable& object){
	string n = object.GetAtributo("nome") += ";";
	string i = object.GetAtributo("idade") += ";";
	string c = object.GetAtributo("cpf");
	return n += i += c;
}
