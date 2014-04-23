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
	Room();
	~Room();
};	
Room::Room(){

}
Room::~Room(){
	if(left_rm != NULL){
		delete left_rm;
	}
	if(right_rm != NULL){
		delete right_rm;
	}
}
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

struct player
{
	int life;
	int inventory[7];
	int roomnum;
	ifstream file;
	Room * root;
	Room * curRoom;
	Room * rooms;
	player();
	~player();
	void heapify(Room * parent, Room * child);
	void buildheap();
	void startGame();
	void getInput();
	void setUp();
	void RoomPlay(Room * curr);

};
player::player(){
	rooms = new Room[41];
	file.open("info.txt");
	for(int r = 0; file.good(); ++r){
		rooms[r].readfile(file);
	}
	curRoom = root;
	buildheap();
	setUp();
}
player::~player(){
	delete root;
	delete[] rooms;
}
void player::heapify(Room * parent, Room * child ){
	if(child->rn < parent->rn){
		if(parent->left_rm == NULL){
			parent->left_rm = child;
		}else{
			heapify(parent->left_rm, child);
		}
	}else{
		if(parent->right_rm == NULL){
			parent->right_rm = child;
		}else{
			heapify(parent->right_rm, child);
		}
	}
}
void player::buildheap(){
	root = &rooms[0];
	for(int r = 1; r< 41; ++r){
		heapify(root,&rooms[r]);
	}
}

void player::setUp()
{
 	life = 0;
 	for(int x=0; x<=7; ++x)
        inventory[x]=0;
 	roomnum = 100;
}
void player::startGame()
{
	RoomPlay(root);
}
void player::RoomPlay(Room * curr)
{	
	curRoom = curr;
 	int take;
 	char choice;
 	cout<<curRoom->storyline<<endl;
 	cout<<curRoom->room_item <<endl;
 	/*-------------PICKUP ITEM--------------*/
 	if (curRoom->room_item != 0){
        cout <<"Take it (0) or Nah (1)\n";
        cin >>take;
        if (take == 0)
            inventory[curRoom->room_item] = 1;
        cout <<"Item: " <<inventory[curRoom->room_item] <<endl;
 	}
 	if (curRoom->required_item != 0){
        if (inventory[curRoom->required_item] == 1){
                 cout <<curRoom->str_had_item;
                 life = curRoom->life_w_item;
        }else{
            cout <<curRoom->str_no_item;
            life = curRoom->life_wo_item;
        }
 	}else{
        life = curRoom->life_regardless;
        cout <<"Current life status: " <<life <<endl;
 	}
 	/*-------------PICK NEXT ROOM0--------------*/
 	if (life == 0){
        cout<<"LEFT or RIGHT"<<endl;
        cin>>choice;
        if ((curRoom->rn == 1) || (curRoom->rn == 6)
            || (curRoom->rn == 170) || (curRoom->rn == 190)
            || (curRoom->rn == 290) || (curRoom->rn ==340)){
            cout <<"You've survived the cave! Whew. Onward to save the lady!\n";
            //Add 1 to # of wins
            //Exit game
        }else if ((choice == 'l') || (choice == 'L')){
        	RoomPlay(curRoom->left_rm);
        }else{
	        RoomPlay(curRoom->right_rm);
        }
 	}else{
        cout <<"GAME OVER\n";
        //Add 1 to # of deaths
        //Exit game
	}
}

#endif