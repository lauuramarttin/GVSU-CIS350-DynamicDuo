// menu function
bool menu(list<Train> &Trains, map<string, Passenger> &Passengers){
	cout<<"Wellcome to the main menu, what do you want to do?"<<endl;
	int option;
	//display menu
	cout<<"1. Add new passenger’s trip to a train"<<endl;
	cout<<"2. Remove a passenger’s trip from a train"<<endl;
	cout<<"3. Show trips of a passenger"<<endl;
	cout<<"4. Show list of passengers in a specific train"<<endl;		
	//see when to finish the program
	cout<<"5. End program"<<endl;
	bool follow=1;
	cout<<"Choose an option: ";
	cin>>option;
	if(option==5){
		follow=0;
	}
	// stablish what to do for each option
	switch (option){
			case 1:
				cout<<"Add new passengers trip to a train"<<endl;
				addNewPassengerTrip(Trains,Passengers);
				break;
			case 2:
				cout<<"Remove a passenger’s trip from a train"<<endl;
				removePassengerTrip(Trains,Passengers);
				break;
			case 3:
				cout<<"Show trips of a passenger"<<endl;
				showTripsOfPassenger(Passengers);
				break;
			case 4:
				cout<<"Show list of passengers in a specific train"<<endl;
				showListOfPassengers(Trains, Passengers);
				break;
			case 5:
				cout<<"End program"<<endl;
				endProgram(Trains, Passengers);
				break;
			default:
				cout<<"you've entered the wrong number"<<endl;
				
	}
	return follow;	
}
