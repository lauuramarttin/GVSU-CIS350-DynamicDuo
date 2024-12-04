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
			SetConsoleTextAttribute(hconsole,6);
			assert((m >= 0) && (dis >= 0) && (s >= 0) && (w >= 0)); // Verifies that values are valid.
			SetConsoleTextAttribute(hconsole,7);
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
