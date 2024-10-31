//read initial data function, reads initial data from files and loads it into a list of trains and a map of passengers
void readinitialData(list<Train> &Trains, map<string,Passenger> &Passengers){
	
	//Create a list of trains
	ifstream trainfile("train.txt"); //opens the train.txt file for reading
	ifstream wagonfile("wagon.txt"); //opens the wagon.txt file for reading
	
	if(!trainfile || !wagonfile){
		cout << "File does not exist" << endl; //if a file cannot be opened, show an error
	}else{
		string codet, ddate, dst, darr; //declare variables
		string ntrain, coderef, dateref, depsref, arrsref, kref, nwref;
		int km, nwag;
		
		//reads each train's data from the file in a loop
		while(trainfile >> ntrain >> coderef >> codet >> dateref >> ddate >> depsref >> dst >> arrsref >> darr >> kref >> km >> nwref >> nwag){
			list<Wagon> wagons; //create a list of wagons for each train
			
			//read information for each wagon
			for(int i = 1; i <= nwag; i++){
				string wagonname, numsref, numpref; //declare variables
				int num, seat, npasseng;
				
				//read from the wagon.txt file
				wagonfile >> wagonname >> num >> numsref >> seat >> numpref >> npasseng;
				map<string, int> ids; //create a map to store pairs of passengers and their seats
				
				//reads the passenger ID and their seat from wagon.txt
				for(int j = 1; j <= npasseng; j++){
					string idpass, idref, sref;
					int seat;
					
					wagonfile >> idref >> idpass >> sref >> seat;
					ids.insert({idpass, seat}); //inserts ID-seat pairs into the ids map
				}
				Wagon w(num, seat, ids); //creates a Wagon object with the data read from the wagon
				wagons.push_back(w); //adds w to the wagons list
			}
			
			Train t(codet, ddate, dst, darr, km, wagons); //creates a Train object with the data read
			Trains.push_back(t); //adds the train to the Trains list
		}
		
		cout << "List of trains created successfully" << endl; 
		trainfile.close(); //closes the train.txt file
		wagonfile.close(); //closes the wagon.txt file
	}
	
	//Create a map of passengers
	ifstream passengfile("passenger.txt"); //opens the passenger.txt file for reading
	
	if(!passengfile){
		cout << "File does not exist" << endl; //if the file cannot be opened, show an error
	}else{
		string address, name, id, npass; //declare variables
		string idrf, nrf, adrf, agerf, grf,bwrf, ntripsrf; //ref
		int age, ntrips;
		char gender;
		float bweight;
		
		//reads each passenger's data from the file in a loop
		while(passengfile >> npass >> idrf >> id >> nrf >> name >> adrf >> address >> agerf >> age >> grf >> gender >> bwrf >> bweight >> ntripsrf >> ntrips){
			list<Trip> trips; //Create a Trips list to store each passenger's trips
			
			//reads each trip's details
			for(int j = 1; j <= ntrips; j++){
				string date, depst, arrivst; //declare variables
				string daterf, deprf, arrf, mrf, srf, wrf, drf;
				float money, dis;
				int seat, wag;
				
				passengfile >> daterf >> date >> deprf >> depst >> arrf >> arrivst >> mrf >> money >> srf >> seat >> wrf >> wag >> drf >> dis;
				Trip t(date, depst, arrivst, money, dis, seat, wag); //Creates a Trip object with the information read
				trips.push_back(t); //Adds Trip t to the trips list
			}
			
			Passenger p(id, name, address, age, gender, bweight, trips); //Creates a Passenger object using the data read
			Passengers.insert({id, p}); //adds the passenger to the Passengers map associating the ID with the Passenger object
		}
		
		cout << "Map of passengers created successfully" << endl;
		passengfile.close(); //closes the passenger.txt file
	}
}
