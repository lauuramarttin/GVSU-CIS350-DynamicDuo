# Overview
This document details the functional and non-functional requirements of the train and passenger management system. This system, developed in C++, enables the reading of initial data from text files, passenger management, seat assignment, and trip registration, ensuring efficient and structured handling of information.

 # Software Requirements
 <Describe the structure of this section>
 
 ## Functional Requirements
 ### Data management
 | ID | Requirement |
 |----|-------------| 
 |FR1 |Each train must include details such as departure date, departure station, arrival station, distance, and the list of wagons it contains. | 
 |FR2 |Each passenger must have an ID, name, address, age, gender, baggage weight, and a record of their trips.| 
 |FR3 |Wagons must store details such as their number, seating capacity, and which passengers are seated in them.| 
 |FR4 |The readInitialData function must load initial data for trains and passengers from external text files and store them in containers like a list for trains and a map for passengers.|
 |FR5 |All changes made during the program's execution must be saved back to the files when the program ends, ensuring no data is lost.|

 ### Passenger management
 | ID | Requirement |
 |----|-------------| 
 |FR6 |The system must add a new passenger if their ID is not already registered.| 
 |FR7 |A passenger must be assigned an available seat in the first empty wagon on a specific train.| 
 |FR8 |The system must support removing a passenger's trip based on the provided train details.| 
 |FR9 |Users must be able to see all trips taken by a specific passenger, including details like train, departure station, and seat number.|
 |FR10 |The system must ensure that no passenger is assigned to the same train more than once, avoiding errors.|
 |FR11 |The system must validate that a passenger's baggage weight does not exceed the limit of 25 kg.|

 ### Queries and Operations
 | ID | Requirement |
 |----|-------------| 
 |FR12 |Users must be able to view a list of all passengers on a specific train, including their seat and wagon numbers.| 
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
 |NFR8 |Documentation and help features must be provided to assist users in navigating the system and understanding its functionalities.| 
 |NFR9 |The system must be compatible with both Windows and Linux operating systems, ensuring broader accessibility for users.|
 |NFR10 |All information displayed, such as passenger lists or trip details, should be organized and well-structured for easy reading.|

  ### Maintainability


 
# Software Artifacts
 <Describe the purpose of this section>
* [I am a link](to_some_file.pdf)
