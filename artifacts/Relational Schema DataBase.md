## Relational Schema

Trains ( TrainID (PK), TrainName, Capacity )

Wagons ( WagonID (PK), TrainID (FK), WagonNumber, WagonCapacity )

Passengers ( PassID (PK), Name, PhoneNumber, Age )

Seat ( SeatID (PK), WagonID (FK), SeatNumber, IsAvailable )

Trips ( TripID (PK), TrainID (FK), PassID (FK), SeatID (FK), Date, Origin, Destination )
