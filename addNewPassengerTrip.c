//takes a list of Train objects and a map of Passenger objects
void addNewPassengerTrip(list<Train> &Trains, map<string,Passenger> &Passengers){
	string date, dpst, arrivst, id;
	cout << "Introduce date of the trip: ";
	cin >> date;
	cout << "Introduce departure station: ";
	cin >> dpst;
	cout << "Introduce arrival station: ";
	cin >> arrivst;
	cout << "Introduce ID: ";
	cin >> id;
	int findPass = 0; //checks if the passenger exists
	int findTrain = 0; //checks if the train exists
	//check if the passenger already exists
	for (auto it2 = Passengers.begin(); it2 != Passengers.end(); it2++) {
		string actID;
		actID = (*it2).first;
		if (id.compare(actID) == 0) {
			findPass = 1;
		}
	}
	//introduce the data of the new passenger
	if (findPass == 0) {
		string name, address;
		int age;
		char gender;
		float bw;
		cout << "Introduce data about passenger:\n" << "Name: ";
		cin >> name;
		cout << "Address: ";
		cin >> address;
		cout << "Age: ";
		cin >> age;
		cout << "Gender: ";
		cin >> gender;
		cout << "Maximun bag weight: ";
		cin >> bw;
		list<Trip> trips;
		Passenger p(id, name, address, age, gender, bw, trips); //creates a new Passenger object for the new passenger
		Passengers.insert({id, p}); //inserts into the Passengers map
	}
	// if the passenger already exists, this gives all of his/her information
	//iterates over the Trains list and obtains the date, depst, and arrivst of each train
	for (auto it1 = Trains.begin(); it1 != Trains.end(); it1++) {
		string actDATE, actDS, actAS;
		Train t;
		t = (*it1); //assigns the Train object pointed to by it1 to t
		actDATE = t.getDate();
		actDS = t.getDepst();
		actAS = t.getArrivst();
		//compares the input data with the train data
		if ((date.compare(actDATE) == 0) && (dpst.compare(actDS) == 0) && (arrivst.compare(actAS) == 0)) {
			findTrain = 1; //train found
			Train acttrain = *it1; //it1 points to the train, *it1 gets the Train object and stores it in acttrain
			list<Wagon> wagons;
			wagons = acttrain.getWagons(); //get the list of wagons
			//verify if the passenger is already assigned to the train
			int findPass = 0;
			//goes through the wagons
			for (auto it3 = wagons.begin(); it3 != wagons.end(); it3++) {
				map<string, int> ids; //map storing the passenger IDs and their respective seat numbers
				Wagon w = *it3; //gets the Wagon object that it3 points to
				ids = w.getIds(); //gets the wagon's passenger map
				//goes through the passenger, seat map
				for (auto it4 = ids.begin(); it4 != ids.end(); it4++) {
					string actID;
					actID = (*it4).first; //gets the ID
					if (id.compare(actID) == 0) { //compares the ID with the entered passenger ID
						findPass = 1;
						int num = w.getNum(); //gets wagon number
						int seat;
						seat = (*it4).second; //gets seat number
						cout << "Passenger with id " << id << " found in the train. Wagon: " << num << ". Seat: " << seat << endl;
					}
				}
			}
			//if the passenger is not found, we assign him/her a new seat and wagon
			if (findPass == 0) {
				cout << "Passenger does not found in this train" << endl;
				int assign = 0; //to store assigned seat
				int wagon; //to store assigned wagon
				auto it5 = wagons.begin();
				while (assign == 0) {
					Wagon w = *it5; //extracts the Wagon object pointed to by it5
					map<string, int> ids = w.getIds(); //gets the passenger, seat map of the wagon
					int seats = w.getnumSeats(); //get the number of seats
					int numids = ids.size(); //number of passengers in the wagon
					if (numids < seats) { //if there are free seats, assign one
						assign = numids + 1;
						wagon = w.getNum();
						cout << "The passenger has been assigned in wagon: " << wagon << " seat: " << assign << endl;
						ids[id] = assign; //add the passenger and seat to the ids map
						w.setIds(ids);
						wagons.insert(it5, w); //insert the modified wagon
					}
					it5 = ++it5;
				}
				//update the information
				acttrain.setWagons(wagons);
				auto it6 = Passengers.find(id);
				Passenger actpass = (*it6).second;
				list<Trip> trips = actpass.getList();
				float money = 50;
				float dis = acttrain.getDist();
				Trip t(date, dpst, arrivst, money, dis, assign, wagon);
				trips.push_back(t);
				actpass.setList(trips);
				Passengers[id] = actpass;
			}
		}
	}
	//if all trains have been iterated over and no matching train exists
	if (findTrain == 0) {
		cout << "This train does not exist" << endl;
	}
}
