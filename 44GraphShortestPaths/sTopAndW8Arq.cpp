#include<iostream>
#include<windows.h>
#include<time.h>
#define Index 5
using namespace std;



struct Data {
	int dataFrame;
	int dataRecieved;
	int extractedDatavar;
	int data[Index];
	int *Sn;
	int *Rn;
	int frame;
	int deliverDat;
	bool turn = true;
	bool input = true;
	bool Event = true;
	bool canSent = true;
	bool Extrachk = true;
	bool Extrachk1 = true;
};


//Functions of Sender-Side
void waitForEvent() {
	cout << "Waiting for event";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;
}

Data object;

void getData() {


	cout << "(Network Layer Sender Side)Please, Enter the data:";
	for (int i = 0; i < Index; i++) {
		cin >> object.data[i];
	}
	object.data;
	cout << "(Data Link Layer Sender Side)Making Frame";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;


}
void makeFrame() {
	if (object.Extrachk == true) {
		object.Sn = object.data;
		object.Extrachk = false;
	}

	object.frame = *(object.Sn);


}
int sendFrame() {
	cout << "(Physical Layer Sender Side)Sending Frame";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;
	object.dataFrame = object.frame;
	object.turn = false;

	return object.dataFrame;
}
void ackFrame() {
	cout << "(FROM RECEIVER SIDE TO SENDER SIDE)Note:Acknowledgement Send to receiver" << endl;
}

//Functions of Reciver-Side
int recieveFrame() {
	if (object.Extrachk1 == true) {
		object.Rn = object.data;
		object.Extrachk1 = false;
	}
	cout << "(Physical Layer Receiver side)Receiving Frame";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;

	if (*(object.Sn) == *(object.Rn)) {
		object.dataRecieved = object.dataFrame;
	}
	object.Sn++;
	object.Rn++;

	return object.dataRecieved;
}

int extractData() {
	cout << "(Data Link Layer Receiver Side)Extracting the Data";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;
	object.extractedDatavar = object.dataRecieved;

	return object.extractedDatavar;
}

int deliverData() {

	if (object.turn == false) {
		object.turn == true;
	}
	object.deliverDat = object.extractedDatavar;
	cout << "(Data Link Layer Receiver)Delivering Data";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;
	cout << "Note:(Network Layer Receiver Side)Data delivered" << endl;

	cout << "Recieved Data:" << object.deliverDat;
	return object.deliverDat;
}

int main() {
	//variables of main
	time_t start=0, end=0;
	double difference;

	object.canSent = true;
	for (int i = 0; i < Index; i++) {
		//Sender-side code
		while (object.turn == true && object.canSent == true) {
			waitForEvent();
			time(&start);
			if (object.Event == true) {
				if (object.input == true) {
					getData();
					object.input = false;
				}
				makeFrame();
				sendFrame();
				object.canSent = false;
			}

			break;
		}

		//Reciever side code
		while (object.turn == false) {
			if (object.Event == true) {
				recieveFrame();
				waitForEvent();
				//Reciever to Sender code

				ackFrame();
				time(&end);
				difference = difftime(end,start);
				cout << "Time take :" << difference << endl;
				object.canSent = true;

				extractData();
				deliverData();
				object.turn = true;
				break;
			}
		}

	}
}