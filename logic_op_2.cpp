#include "logic_op_2.h"
#include "math.h"

typedef int ValueType;
typedef std::vector<ValueType> ValueTypeVector;

returns scan_values(logic l){
    returns res;
    fstream file(l.file_name);
    string str, header;
    int i, j;
    getline(file, header);
    while (getline(file, str)){
        res.data[i][j]=split(str, ',').c_str();
    }
}


ValueTypeVector& split(string &s, char delim, ValueTypeVector &elems)
{
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
    {
        elems.push_back(stoi(item));
    }
    return elems;
}


ValueTypeVector splits(string &str, char delim){
    ValueTypeVector elems;
    split(str, delim, elems);
    return elems;
}
