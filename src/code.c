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
