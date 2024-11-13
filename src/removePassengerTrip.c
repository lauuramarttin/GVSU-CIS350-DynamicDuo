//function for removing passenger's trips
void removePassengerTrip(list<Train> &Trains, map<string,Passenger> &Passengers){
	string date,dpst,arrivst,id;
	cout<<"Introduce date of the trip: ";
	cin>>date;
	cout<<"Introduce departure station: ";
	cin>>dpst;
	cout<<"Introduce arrival station: ";
	cin>>arrivst;
	int findTrain=0;
	cout<<"Introduce ID: ";
	cin>>id;
	//check if the passenger is inside the train and delate it
	for(auto it1=Trains.begin();it1!=Trains.end(); it1++){
		string actDATE,actDS,actAS;
		Train t;
		t=*it1;
		actDATE=t.getDate();
		actDS=t.getDepst();
		actAS=t.getArrivst();
		if((date.compare(actDATE)==0) && (dpst.compare(actDS)==0) && (arrivst.compare(actAS)==0)){
			findTrain=1;
			Train acttrain=*it1;
			list<Wagon> wagons;
			wagons=acttrain.getWagons();
			int findPass=0;
			for(auto it2=wagons.begin();it2!=wagons.end();it2++){
				map<string,int> ids;
				Wagon w=*it2;
				ids=w.getIds();
				for(auto it3=ids.begin();it3!=ids.end();it3++){
					string actID;
					actID=(*it3).first;
					if(id.compare(actID)==0){
						findPass=1;
						ids.erase(it3);
						auto it5=Passengers.find(id);
						Passenger actPass=(*it5).second;
						list<Trip> trips=actPass.getList();
						for(auto it6=trips.begin(); it6!=trips.end(); it6++){
							Trip t=*it6;
							string tripDate=t.getDate();
							string tripDs=t.getDpst();
							string tripAs=t.getArrivsta();
							if((tripDate.compare(actDATE)==0) && (tripDs.compare(actDS)==0) && (tripAs.compare(actAS)==0)){
								trips.erase(it6);
							}
						}
						actPass.setList(trips);
						Passengers[id]=actPass;
					}
				}
			}
			//check if the passenger is in the map and delate it 
			if(findPass==0){
				cout<<"Passenger was not found in this train"<<endl;
			}else{
				auto it4=Passengers.find(id);
				Passenger actpass=(*it4).second;
				list<Trip> trips=actpass.getList();
				for(auto it5=trips.begin();it5!=trips.end();it5++){
					Trip t=*it5;
					string actDate, actDpst,actArriv;
					actDate=t.getDate();
					actDpst=t.getDpst();
					actArriv=t.getArrivsta();
					if((date.compare(actDate)==0) && (dpst.compare(actDpst)==0) && (arrivst.compare(actArriv)==0)){
						trips.erase(it5);
					}
				}
				actpass.setList(trips);
			}
			cout<<"Passenger's trip removed succesfully"<<endl;
		}
	}
	if(findTrain==0){
		cout<<"This train does not exist"<<endl;
	}
	
}
