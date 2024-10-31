## Relational Schema

Trains ( TrainID (PK), TrainName, Capacity )

Wagons ( WagonID (PK), TrainID (FK), WagonNumber, WagonCapacity )

Passengers ( PassID (PK), Name, PhoneNumber, Age )

Seat ( SeatID (PK), WagonID (FK), SeatNumber, IsAvailable )

Trips ( TripID (PK), TrainID (FK), PassID (FK), SeatID (FK), Date, Origin, Destination )

## Definition
* Trains: Stores information for each train, with TrainID as the primary key.
* Wagons: Stores wagons associated with each train, with TrainID as a foreign key to link each wagon to a specific train.
* Passengers: Contains information on passengers, with PassID as the primary key.
* Seat: Defines seats in each wagon, with WagonID as a foreign key to link each seat to a specific wagon, and IsAvailable as an indicator of availability.
* Trips: Records each journey of a passenger, with foreign keys TrainID, PassID, and SeatID to link a journey with a specific train, passenger, and seat.
