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
int main (){
	list<Train> Trains;
	map<string,Passenger> Passengers;
	readinitialData(Trains,Passengers);
	cout<<"Read"<<endl;
}
