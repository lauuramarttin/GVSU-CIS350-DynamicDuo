#include<iostream> // Input and output library
#include<map> // Use of maps (dictionaries)
#include<list> // Use of lists
#include<fstream> // File reading and writing
#include<cstring> // Functions to work with strings
#include<cassert> // Condition verification

using namespace std;

//Class of trips
class Trip{
	private:
		string date, depstat, arrivestat; // Variables for the date, departure station, and arrival station
		float money, distance; // Cost and distance of the trip
		int seat, wagon; // Seat and wagon number.
		
	public:
		//Default constructor, initializes values with default data
		Trip(){
			date="00:00:00";
			depstat="";
			arrivestat="";
			money=0;
			distance=0;
			seat=0;
			wagon=0;
		}
		//Parameterized constructor, allows you to set values
		Trip(string d, string ds, string as, float m, float dis, int s, int w){
			date = d;
			depstat = ds;
			arrivestat = as;
			money = m;
			distance = dis;
			seat = s;
			wagon = w;
			
			assert((m >= 0) && (dis >= 0) && (s >= 0) && (w >= 0)); // Verifies that values are valid.
		}
	
		//Get individual values
		int getSeat(){
			return seat;
		}
		
		int getWagon(){
			return wagon;
		}
		
		string getDate(){
			return date;
		}
		
		string getDpst(){
			return depstat;
		}
		
		string getArrivsta(){
			return arrivestat;
		}
		
		float getDistance(){
			return distance;
		}
		float getMoney(){
			return money;
		}

};

//Class of passenger
class Passenger{
	private:
		string address, name, ID; // Address, name, and ID of the passenger.
		int age;
		char gender;
		float bagweight;  // Weight of the passenger's luggage.
		list<Trip> ptrip; // List of trips associated with the passenger.
	public:
		//Default constructor
		Passenger(){
			ID="";
			name="";
			address="";
			age=0;
			gender=' ';
			bagweight=0;
			list<Trip> ptrip;
		}
		//Parameterized constructor
		Passenger(string id, string n, string ads, int ag, char gnd, float bagw, list<Trip> trip){
			ID = id;
			name = n;
			address = ads;
			age = ag;
			gender = gnd;
			bagweight = bagw;
			ptrip = trip;	
			assert(age >= 0); // Verifies that age is valid
			assert((bagw >= 0) && (bagw <= 25)); // Luggage weight must be between 0 and 25
			assert(gender == 'M' || gender == 'F');
		}
		
		//Get individual values
		string getID(){
			return ID;
		}
		string getAddress(){
			return address;
		}
		int getAge(){
			return age;
		}
		
		char getGender(){
			return gender;
		}
		
		float getBagweight(){
			return bagweight;
		}
		list<Trip> getList(){
			return ptrip;
		}
		
		void setList(list<Trip> trips){
			ptrip = trips;
		}
		
		string getName(){
			return name;
		}
		
};

//Class of wagon
class Wagon{
	private:
		int num, seats;  // Wagon number and number of seats per wagon.
		map<string, int> wpassengers; // Map of passenger IDs and their seats.
    
	public:
		// Default constructor
		Wagon(){
			num = 0;
			seats = 0;
			map<string, int> wpassengers;	
		}
		
		// Parameterized constructor
		Wagon(int n, int seat, map<string, int> wpass){
			num = n;
			seats = seat;
			wpassengers = wpass;	
			assert((n >= 0) && (seat >= 0) && (wpass.size() <= seat)); // Verifies the wagon's capacity.
		}
		
		//Get individual values
		int getNum(){
			return num;
		}
		
		int getnumSeats(){
			return seats;
		}
		
		map<string, int> getIds(){
			return wpassengers;
		}
		
		void setIds(map<string, int> ids){
			wpassengers = ids;
		}
	
};

//Class train
class Train{
	private:
		string depdate, depst, arrivals, code; // Departure date, departure station, arrival station, and train code.
		int km; // Distance
		list<Wagon> infowagon; // List of wagons in the train.
	public:
		// Default constructor
		Train(){
			code="";
			depdate="00:00:00";
			depst=" ";
			arrivals=" ";
			km=0;
			list<Wagon> infowagon;
		}
		
		// Parameterized constructor
		Train(string cd, string depd, string deps, string arrist, int kmeter, list<Wagon> wagons){
			code = cd;
			depdate = depd;
			depst = deps;
			arrivals = arrist;
			km = kmeter;
			infowagon = wagons;	
			assert(kmeter >= 0); // Verifies that the distance is valid.
		}
		
		//Get individual values
		string getCode(){
			return code;
		}
		
		string getDate(){
			return depdate;
		}
		
		string getDepst(){
			return depst;
		}
		
		string getArrivst(){
			return arrivals;
		}
		
		list<Wagon> getWagons(){
			return infowagon; // Shows the train's list of wagons
		}
		
		float getDist(){
			return km;
		}
		
		void setWagons(list<Wagon> w){
			infowagon = w; // Assigns a new list of wagons to the train
		}
		
};

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

// menu function
bool menu(list<Train> &Trains, map<string, Passenger> &Passengers){
	cout<<"Wellcome to the main menu, what do you want to do?"<<endl;
	int option;
	//display menu
	cout<<"1. Add new passenger’s trip to a train"<<endl;
	cout<<"2. Remove a passenger’s trip from a train"<<endl;
	cout<<"3. Show trips of a passenger"<<endl;
	cout<<"4. Show list of passengers in a specific train"<<endl;		
	cout<<"5. Show an alphabetically ordered list of passengers in all the trains"<<endl;
	//see when to finish the program
	cout<<"6. End program"<<endl;
	bool follow=1;
	cout<<"Choose an option: ";
	cin>>option;
	if(option==6){
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

int main (){
	list<Train> Trains;
	map<string,Passenger> Passengers;
	readinitialData(Trains,Passengers);
	bool follow;
	do{
		follow=menu(Trains, Passengers);
	} while(follow!=0);
}
