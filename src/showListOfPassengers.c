// Function to show the list of passengers of a specific train
void showListOfPassengers(list<Train> Trains, map<string,Passenger> Passengers){
	string code;
	cout<<"Introduce code of the train: "; // Ask the user to enter the train code
	cin>>code;
	int findTrain=0; // Flag to track if the specified train is found
	
	// Iterate over each train in the list to check if the code matches
	for(auto it1=Trains.begin(); it1!=Trains.end(); it1++){
		string actCode;
		Train actTrain=*it1; // Get the current train from the list
		actCode=actTrain.getCode(); // Retrieve the train's code
		// Check if the entered code matches the current train's code
		if(code.compare(actCode)==0){
			findTrain=1; // Mark that the train was found
			list<Wagon> wagons=actTrain.getWagons(); // Get the list of wagons in the train
			cout<<"Passengers of train with code "<<code<<" :"<<endl;
			// Iterate over each wagon in the train
			for(auto it2=wagons.begin(); it2!=wagons.end(); it2++){
				Wagon actWagon=*it2; // Get the current wagon
				int actNumwagon=actWagon.getNum(); // Get the wagon number
				map<string,int> ids= actWagon.getIds(); // Get the IDs of passengers in the wagon
				// Iterate over each passenger ID in the wagon
				for(auto it3=ids.begin(); it3!=ids.end(); it3++){
					string actId=(*it3).first; // Passenger ID
					int actSeat=(*it3).second; // Seat number
					auto it4=Passengers.find(actId); // Find the passenger by ID
					// Retrieve the passenger details
					Passenger actPass=(*it4).second;
					string actName=actPass.getName();
					// Print the passenger information: ID, name, seat, and wagon number
					cout<<actId<<" "<<actName<<" Seat: "<<actSeat<<" Wagon: "<<actNumwagon<<endl;
				}
				break; //this solved the problem we had
			}
		}
		
	}
	// If the train was not found, print a message
	if (findTrain==0){
		cout<<"this train was not found"<<endl;
	}
}
