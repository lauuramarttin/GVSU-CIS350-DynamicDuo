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
 |FR7 |A passenger must be assigned an available seat in the first empty wagon on a specific train.| 
 |FR8 |The system must support removing a passenger's trip based on the provided train details.| 
 |FR9 |The system must display all trips associated with a specific passenger, including details such as travel date, departure station, arrival station, seat number, and wagon number.|
 |FR10 |The system must ensure no duplicate seat assignments for a passenger on the same train.|
 |FR11 |The system must validate that a passenger's baggage weight does not exceed the limit of 25 kg.|

 ### Queries and Operations
 | ID | Requirement |
 |----|-------------| 
 |FR12 |The system must display the list of passengers on a specific train, including seat information.| 
 |FR13 |The system must notify users if a train or passenger is not found.| 
 |FR14 |The main menu must provide clear and functional options for adding trips, removing trips, querying data, and ending the program. Each option must redirect the user to the appropriate function.|
 |FR15 |Base files (wagon.txt, passenger.txt, train.txt) must be updated with any modifications made during the program's execution.|
 |FR16 |Invalid user inputs should trigger descriptive error messages without crashing the program.|
 
## Non-Functional Requirements
 ### Performance
 | ID | Requirement |
 |----|-------------| 
 |NFR1 |The response time for operations, such as adding or removing passenger's trip, must be less than 3 seconds under normal load conditions.| 
 |NFR2 |Searches and assignments must execute efficiently using maps and lists.| 
 |NFR3 |File operations must minimize reading and writing times.| 
 |NFR4 |The system must load initial data from the passenger.txt, train.txt, and wagon.txt files in less than 5 seconds.|
 |NFR5 |The application must recover gracefully from unexpected terminations by saving partial data.|

 ### Usability
 | ID | Requirement |
 |----|-------------| 
 |NFR6 |The main menu must be intuitive and user-friendly, presenting clear options for adding trips, removing trips, viewing trips, and terminating the program.| 
 |NFR7 |Error messages must be clear and descriptive, indicating the exact issue.| 
 |NFR8 |Basic documentation must be provided to explain main functionalities.| 
 |NFR9 ||
 |NFR10 ||

 
# Software Artifacts
 <Describe the purpose of this section>
* [I am a link](to_some_file.pdf)
