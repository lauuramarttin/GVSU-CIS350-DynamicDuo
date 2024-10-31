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
