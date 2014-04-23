#include <string>
#include <iostream>
#include <fstream>
#include "RoomStruct.h"

using namespace std;


// void buildheap();
// void heapify(Room * parent, Room * child);
// Room * root;
// Room rooms[41];


// void startGame(player &user);
// void getInput();
// void setUp(player &person);
// void RoomPlay(Room &curRoom, player &p);

int main(){
	player p;
	p.startGame();
	// ifstream file;
	// file.open("info.txt");
	// if(file.is_open()){
	// 	cout<<"file opened\n";
	// }
	// else{
	// 	cout<<"couldn't open file\n";
	// 	return 0;
	// }
	// for(int r = 0; file.good(); ++r){
	// 	rooms[r].readfile(file);
	// }
	// buildheap();

	// //Initialize a player
 // 	player p1;
	// //Set up the game
 // 	setUp(p1);
	// //Play the game
 // 	startGame(p1);

	return 0;
}

// void heapify(Room * parent, Room * child ){
// 	if(child->rn < parent->rn){
// 		if(parent->left_rm == NULL){
// 			parent->left_rm = child;
// 		}else{
// 			heapify(parent->left_rm, child);
// 		}
// 	}else{
// 		if(parent->right_rm == NULL){
// 			parent->right_rm = child;
// 		}else{
// 			heapify(parent->right_rm, child);
// 		}
// 	}
// }
// void buildheap(){
// 	root = &rooms[0];
// 	for(int r = 1; r< 41; ++r){
// 		heapify(root,&rooms[r]);
// 	}
// }

// void setUp(player &person)
// {
//  	person.life = 0;
//  	for(int x=0; x<=7; ++x)
//         person.inventory[x]=0;
//  	person.roomnum = 100;
// }
// void startGame(player &user)
// {
// 	RoomPlay(*root, user);
// }
// void RoomPlay(Room &curRoom, player &p)
// {
//  	int take;
//  	char choice;
//  	cout<<curRoom.storyline<<endl;
//  	cout<<curRoom.room_item <<endl;
//  	/*-------------PICKUP ITEM--------------*/
//  	if (curRoom.room_item != 0){
//         cout <<"Take it (0) or Nah (1)\n";
//         cin >>take;
//         if (take == 0)
//             p.inventory[curRoom.room_item] = 1;
//         cout <<"Item: " <<p.inventory[curRoom.room_item] <<endl;
//  	}
//  	if (curRoom.required_item != 0){
//         if (p.inventory[curRoom.required_item] == 1){
//                  cout <<curRoom.str_had_item;
//                  p.life = curRoom.life_w_item;
//         }else{
//             cout <<curRoom.str_no_item;
//             p.life = curRoom.life_wo_item;
//         }
//  	}else{
//         p.life = curRoom.life_regardless;
//         cout <<"Current life status: " <<p.life <<endl;
//  	}
//  	/*-------------PICK NEXT ROOM0--------------*/
//  	if (p.life == 0){
//         cout<<"LEFT or RIGHT"<<endl;
//         cin>>choice;
//         if ((curRoom.rn == 1) || (curRoom.rn == 6)
//             || (curRoom.rn == 170) || (curRoom.rn == 190)
//             || (curRoom.rn == 290) || (curRoom.rn ==340)){
//             cout <<"You've survived the cave! Whew. Onward to save the lady!\n";
//             //Add 1 to # of wins
//             //Exit game
//         }else if ((choice == 'l') || (choice == 'L')){
//         	RoomPlay(*curRoom.left_rm, p);
//         }else{
// 	        RoomPlay(*curRoom.right_rm, p);
//         }
//  	}else{
//         cout <<"GAME OVER\n";
//         //Add 1 to # of deaths
//         //Exit game
// 	}
// }