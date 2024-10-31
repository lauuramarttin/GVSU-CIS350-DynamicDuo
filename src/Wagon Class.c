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
