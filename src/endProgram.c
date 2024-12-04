// Function to end the program and save train and passenger information to a file and update files
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
	
	//Update passengers file
	ofstream passengerFile("passenger.txt"); // Open the file 'passenger.txt' for writing
    if (!passengerFile) { // Check if the file was successfully opened
        cout << "Error." << endl;
    } else {
        int passengerNumber = 1; // Initialize a variable to keep track of the passenger number
        for (auto &entry : Passengers) { // Iterate over each entry in the Passengers collection
            Passenger p = entry.second; // Retrieve the Passenger object associated with the entry
            
			// Write passenger details to the file: ID, Name, Address, Age, Gender, Bag weight, and the number of trips
            passengerFile << "Passenger" << passengerNumber++ << ": ID: " << p.getID()
                          << " Name: " << p.getName()
                          << " Address: " << p.getAddress()
                          << " Age: " << p.getAge()
                          << " Gender: " << p.getGender()
                          << " BWeight: " << p.getBagweight()
                          << " NTrips: " << p.getList().size();
            
            // Iterate over each trip the passenger has made and write the details of each trip
            for (Trip t : p.getList()) {
                passengerFile << " Date: " << t.getDate()
                              << " Departure: " << t.getDpst()
                              << " Arrival: " << t.getArrivsta()
                              << " Price: " << t.getMoney()
                              << " Seat: " << t.getSeat()
                              << " Wagon: " << t.getWagon()
                              << " Distance: " << t.getDistance();
            }
            passengerFile << endl; 
        }
        passengerFile.close(); // Close the file after writing all passenger data
    }
    
    
    //Update wagons file
    ofstream wagonFile("wagon.txt"); // Open the file 'wagon.txt' for writing
    if (!wagonFile) {
        cout << "Error opening wagon.txt for writing." << endl;
        return;
    }

    for (Train &t : Trains) { // Iterate over each train in the Trains collection
        list<Wagon> wagons = t.getWagons(); // Get the list of wagons for the current train
        list<Wagon> validWagons; // Create a list to store valid wagons

        for (Wagon &w : wagons) { // Iterate over each wagon in the train
            if (w.getIds().size() > 0) { // Check if the wagon has passengers (IDs)
                map<string, int> validIds; // Create a map to store valid IDs and seat numbers
                for (auto &idSeat : w.getIds()) { // Iterate over each passenger ID and seat number
                    if (!idSeat.first.empty()) { // Only process valid IDs (non-empty)
                        validIds[idSeat.first] = idSeat.second; // Store the valid ID and seat number
                    }
                }

                if (!validIds.empty()) { // Check if there are valid passengers in the wagon
                    // Create a new valid wagon with valid IDs and seat numbers
					Wagon validWagon(w.getNum(), w.getnumSeats(), validIds);
                    validWagons.push_back(validWagon); // Add the valid wagon to the list

                    // Write the wagon and its passengers to the file
                    wagonFile << "Wagon: " << w.getNum()
                              << " NumSeats: " << w.getnumSeats()
                              << " NumPass: " << validIds.size();
                    for (auto &idSeat : validIds) { // Iterate over valid passenger IDs and seat numbers
                        wagonFile << " ID: " << idSeat.first
                                  << " Seat: " << idSeat.second;
                    }
                    wagonFile << endl;
                }
            }
        }

        // Reassign the valid wagons to the train
        t.setWagons(validWagons);
    }

    wagonFile.close(); // Close the file after writing all wagon data
    
}
