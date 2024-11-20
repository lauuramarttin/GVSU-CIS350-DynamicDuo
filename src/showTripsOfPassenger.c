//show the trips of passengers
void showTripsOfPassenger(map<string,Passenger> &Passengers){
	string id;
	cout<<"introduce the id ";
	cin>>id;
	int find=0; // Flag to check if the passenger exists
	
	// Iterate through the map to find the passenger
	for(auto ite=Passengers.begin(); ite!=Passengers.end();ite++){
		if((*ite).first==id){ // If the ID matches
			find=1; // Set flag to indicate passenger was found
			// Access the passenger's data using the ID
			auto it= Passengers.find(id);
			Passenger idtrip= it->second; // Get the passenger object
			
			// Get the list of trips associated with this passenger
			list<Trip> idtrips= idtrip.getList();
			
			// Iterate through the list of trips and display their details
			for (auto itr=idtrips.begin(); itr!=idtrips.end();++itr){
				Trip t; 
				t=*itr; // Dereference the iterator to access the Trip object
				// Extract trip details
				string date=t.getDate();
				string depstat=t.getDpst();
				string arrivestat=t.getArrivsta();
				float money=t.getMoney();
				float distance=t.getDistance();
				int seat=t.getSeat();
				int wagon=t.getWagon();
				// Print all the trip details
				cout<<"information about trip:\n"<<date<<" "<<depstat<<" "<<arrivestat<<" "<<money<<" "<<distance<<" "<<seat<<" "<<wagon<<endl;
			}
			
		}
	}
	// If the passenger ID is not found in the map
	if (find==0){
		cout<< "user not found"; // Notify the user
	}
}
