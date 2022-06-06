#include "train.h"

Train::Train()
{

}
//int Train::input()
//{
//    std::ofstream fileObj;

//    fileObj.open("Input.txt", std::ios::app);

//    Train obj;
//    obj.SetCode(this->GetCode());
//    obj.SetTo(this->GetTo());
//    obj.SetFrom(this->GetFrom());
//    obj.SetAVS(this->GetAvSeats());

//    fileObj.write((char*)&obj,sizeof(obj));
//    fileObj.close();
//    return 0;
//}
int Train::outputTest()
{
    // Object to read from file
    std::ifstream file_obj;

    // Opening file in input mode
    file_obj.open("Input.txt", std::ios::app);

    // Object of class contestant to input data in file
    Train obj;

    // Reading from file into object "obj"
    file_obj.read((char*)&obj, sizeof(obj));
    file_obj.close();


    return 0;
}
