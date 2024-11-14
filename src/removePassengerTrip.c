//function for removing passenger's trips
void removePassengerTrip(list<Train> &Trains, map<string,Passenger> &Passengers){
	string date,dpst,arrivst,id;
	cout<<"Introduce date of the trip: ";
	cin>>date;
	cout<<"Introduce departure station: ";
	cin>>dpst;
	cout<<"Introduce arrival station: ";
	cin>>arrivst;
	int findTrain=0; // Flag to track if the specified train is found
	cout<<"Introduce ID: ";
	cin>>id;
	
	// Iterate over each train in the list to find a matching trip and delete it
	for(auto it1=Trains.begin();it1!=Trains.end(); it1++){
		string actDATE,actDS,actAS;
		Train t =*it1; // Current train being examined
		actDATE=t.getDate();
		actDS=t.getDepst();
		actAS=t.getArrivst();
		// Check if train details match the given trip information
		if((date.compare(actDATE)==0) && (dpst.compare(actDS)==0) && (arrivst.compare(actAS)==0)){
			findTrain=1;  // Mark that the train was found
			Train acttrain=*it1;
			list<Wagon> wagons;
			wagons=acttrain.getWagons();
			int findPass=0; // Flag to track if the passenger is found in the train
			// Iterate over each wagon in the train to find the passenger
			for(auto it2=wagons.begin();it2!=wagons.end();it2++){
				map<string,int> ids;
				Wagon w=*it2;
				ids=w.getIds(); // Get passenger IDs from the current wagon
				
				// Iterate over IDs to find the specified passenger
				for(auto it3=ids.begin();it3!=ids.end();it3++){
					string actID;
					actID=(*it3).first;
					
					// Check if the ID matches the input passenger ID
					if(id.compare(actID)==0){
						findPass=1; // Passenger found
						ids.erase(it3); // Remove passenger from the wagon's ID list
						// Find the passenger in the map and update their trip list
						auto it5=Passengers.find(id);
						Passenger actPass=(*it5).second;
						list<Trip> trips=actPass.getList();
						// Iterate over the passenger's trips to remove the specified trip
						for(auto it6=trips.begin(); it6!=trips.end(); it6++){
							Trip t=*it6;
							string tripDate=t.getDate();
							string tripDs=t.getDpst();
							string tripAs=t.getArrivsta();
							// Check if trip details match, then erase it from the list
							if((tripDate.compare(actDATE)==0) && (tripDs.compare(actDS)==0) && (tripAs.compare(actAS)==0)){
								trips.erase(it6);
							}
						}
						actPass.setList(trips); // Update passenger's trip list
						Passengers[id]=actPass; // Update the passenger in the map
					}
				}
			}
			
			//check if the passenger was found and notify it
			if(findPass==0){
				cout<<"Passenger was not found in this train"<<endl;
			}else{
				cout<<"Passenger's trip removed succesfully"<<endl;
			}
		}
	}
	// If no matching train was found, notify the user
	if(findTrain==0){
		cout<<"This train does not exist"<<endl;
	}
	
}
