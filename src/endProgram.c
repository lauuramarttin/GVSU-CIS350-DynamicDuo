// Function to end the program and save train and passenger information to a file
void endProgram(list<Train> Trains, map<string, Passenger> Passengers){
	//Open a new file for output
	ofstream Outputfile;
	Outputfile.open("Output.txt");
	// Check if the file opened successfully
	if(!Outputfile){
		cout<<"file doesn't exist";
	}
	else{
		//fill this new file, with the update information
		int i=1; // Initialize train counter
		// Loop through each train in the list of trains
		for(auto it10=Trains.begin();it10!=Trains.end();++it10){
			Outputfile<<"TRAIN "<<i<<endl; 
			Train numberw=*it10;  // Get the current train from the iterator
			list<Wagon> nmbwagon=numberw.getWagons(); // Retrieve the list of wagons in the current train
			// Loop through each wagon in the current train
			for(auto it11=nmbwagon.begin();it11!=nmbwagon.end();++it11){
				Wagon w=*it11; // Get the current wagon from the iterator
				int num=w.getNum(); // Retrieve the wagon number
				
				Outputfile<<"Wagon: "<<num<<endl;
				Outputfile<<" "<<endl;
				
				// Loop through all passengers in the map of passengers
				for(auto it12=Passengers.begin(); it12!=Passengers.end();it12++){
					Passenger infopass=(*it12).second; //Get the current passenger
					
					list<Trip> infopassenger=infopass.getList(); // Retrieve the list of trips for the current passenger
					// Loop through each trip of the current passenger
					for (auto it=infopassenger.begin(); it!=infopassenger.end();it++){
						Trip t=*it; // Get the current trip
						
						// Check if trip details match the current train and wagon
						if(t.getDpst()==numberw.getDepst()&& t.getDate()==numberw.getDate()&& t.getArrivsta()==numberw.getArrivst()&&num==t.getWagon()){
							Outputfile<<"NAME:"<<infopass.getName()<<"   "<<" ID:"<<" "<<infopass.getID()<<"   "<<"ADDRESS: "<<infopass.getAddress()<<"   "<<"SEAT: "<<t.getSeat()<<"  "<<"AGE: "<<infopass.getAge()<<"  "<<"GENDER: "<<infopass.getGender()<<"  "<<" BAG WEIGHT: "<<infopass.getBagweight()<<endl;
							Outputfile<<"------------"<<"PASSENGERs TRIPS: "<<t.getDate()<<" "<<t.getDpst()<<" "<<t.getArrivsta()<<" "<<t.getDistance()<<"km"<<endl;
							Outputfile<<endl;
						}	
					}
				}
				Outputfile<<endl; // Add a blank line after each wagon's data
			}
		i++; // Increment train counter for next train
		}		
	}
	Outputfile.close();	
}
