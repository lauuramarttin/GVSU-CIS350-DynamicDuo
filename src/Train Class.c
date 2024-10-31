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
