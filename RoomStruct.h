#ifndef ROOMSTRUCT_H
#define ROOMSTRUCT_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
struct Room{
	int rn,room_item,required_item,life_w_item,life_wo_item,life_regardless;
	string storyline,str_had_item,str_no_item;
	void print();
	void readfile(ifstream & file);
	Room * left_rm;
	Room * right_rm;
};	

void Room::print(){
	cout<<"room_number: "<<rn<<endl;
	cout<<"storyline: "<<storyline<<endl;
	cout<<"room_item: "<<room_item<<endl;
	cout<<"required_item: "<<required_item<<endl;
	cout<<"does_have_item: "<<str_had_item<<endl;
	cout<<"life_w_item: "<<life_w_item<<endl;
	cout<<"not_have_item: "<<str_no_item<<endl;
	cout<<"life_wo_item: "<<life_wo_item<<endl;
	cout<<"life_regardless: "<<life_regardless<<endl;
}
void Room::readfile(ifstream & file){
	string dummy;
	file>>rn;getline(file,dummy);
	getline(file,storyline);	
	file>>room_item;
	file>>required_item;getline(file,dummy);
	getline(file,str_had_item);
	file>>life_w_item;getline(file,dummy);
	getline(file,str_no_item);
	file>>life_wo_item;
	file>>life_regardless;
}

#endif