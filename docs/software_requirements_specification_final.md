# Overview
This document details the functional and non-functional requirements of the train and passenger management system. This system, developed in C++, enables the reading of initial data from text files, passenger management, seat assignment, and trip registration, ensuring efficient and structured handling of information.

 # Software Requirements
 <Describe the structure of this section>
 
 ## Functional Requirements
 ### Data management
 | ID | Requirement |
 |----|-------------| 
 |FR1 |The Train class must store private attributes like date, stations, and a list of wagons.| 
 |FR2 |The Passenger class must include data such as ID, name, age, and a list of trips.| 
 |FR3 |The Wagon class must maintain the wagon number, capacity, and passenger assignments.| 
 |FR4 |Data must be loaded from text files when the program starts.|
 |FR5 |Changes made to the system must be saved to an output file upon program termination.|

 ### Passenger management
 | ID | Requirement |
 |----|-------------| 
 |FR6 |The system must add a new passenger if their ID is not already registered.| 
 |FR7 |A passenger must be assigned an available seat on a specific train.| 
 |FR8 |A passenger's trip must be removed if requested.| 
 |FR9 |The system must display all trips associated with a specific passenger.|
 |FR10 |The system must ensure no duplicate seat assignments for a passenger on the same train.|
 
## Non-Functional Requirements
 ### <Name of Feature 1> 
| ID  | Requirement     
| 
| :-------------: | :----------: | 
| NFR1 | <Non-Functional Requirement 1> | 
| NFR2 | < Non-Functional Requirement 2> |
 | NFR3 | < Non-Functional Requirement 3> |
 | … | … | 
# Software Artifacts
 <Describe the purpose of this section>
* [I am a link](to_some_file.pdf)
