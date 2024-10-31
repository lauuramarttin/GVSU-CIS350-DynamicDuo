# Requirements

## Overview
This document outlines the software requirements for the train and passenger management system. It details the functional and non-functional requirements that guide the development process to ensure a robust and efficient application.

## Functional Requirements

1. **Data Management**
   1. The Train class should contain private attributes for departure_date, departure_station, arrival_station, distance, and a list of wagons.
   2. The Wagon class should include attributes such as wagon_number, seats_number, and a list of passenger_IDs.
   3. The Passenger class should store attributes like ID, name, address, age, gender, baggage_weight, and a list of trips.

2. **Data Loading**
   1. The readInitialData function must load initial data for trains and passengers from external text files and store them in containers like list for trains and map for passengers.
   2. Validate that the loaded data meets requirements, such as age > 0 and baggage_weight within the range [0, 25] kg.

3. **Passenger Management**
   1. addNewPassengerTrip should check if the passenger ID already exists in the passengers map, if not, add it.
   2. removePassengerTrip should remove a specific trip from the passenger’s data and update their records accordingly.

4. **Trip Management**
   1. addNewPassengerTrip must check that the passenger is not duplicated on the same train and assign an available seat in the first empty wagon if they are new.
   2. The function showTripsOfPassenger should list all trips taken by a specified passenger.

5. **Train and Passenger Queries**
   1. The function showListOfPassengers should display a list of passengers on a specified train, including ID, name, wagon_number, and seat_number.
   2. showOrderedListOfPassengers should return an alphabetically ordered list of passengers across all trains.

6. **Validation Requirements**
   1. Use assert to ensure: Passenger age is greater than 0.
   2. Use assert to ensure: Baggage weight is within the allowed range [0, 25] kg.
   3. Use assert to ensure: Valid values are assigned for seat_number and wagon_number within their respective functions.

7. **File Operations**
   1. The endProgram function must write all train and passenger information to an Output.txt file.
   2. The readInitialData function should read data from a text file to populate trains and passengers.

8. **Menu and User Interaction**
   1. The mainMenu function should present options 1 to 6, validating that the user’s selection is within range, and redirect to the appropriate functions.

9. **Data Passing by Reference**
   1. Main data-handling functions, like readInitialData, addNewPassengerTrip, and removePassengerTrip, should receive trains and passengers containers by reference for performance optimization.

10. **Search and Sorting**
   1. Implement a method to alphabetically sort passengers in showOrderedListOfPassengers.
   2. showListOfPassengers should search and display passengers on a specific train, with optimized search in suitable data structures

## Non-Functional Requirements

1. **Performance**
   1. The system must support at least 100 simultaneous users without performance degradation.
   2. Response time for user actions must be less than 2 seconds under normal load conditions.
   3. The readInitialData function must efficiently load large volumes of data from files to minimize loading time.

2. **Scalability**
   1. Design classes and functions to handle an increasing number of passengers and trains without compromising performance.
   2. List and map containers should support the addition of new records without needing system redesign.

3. **Usability**
   1. The main menu (mainMenu) should be intuitive and easy for users to navigate.
   2. Documentation and help features must be provided to assist users in navigating the system.
   3. Error messages should be clear and specific, such as in removePassengerTrip when a passenger is not found on a specified train.
  
4. **Reliability**
   1. Use standard C++ STL containers to guarantee data integrity and ease of handling for lists and maps.
   2. Validate user input in each function to prevent input errors.

5. **Data Integrity**
   1. The addNewPassengerTrip function should prevent duplicate entries by ensuring unique IDs for each passenger.
   2. removePassengerTrip must correctly update a passenger’s trip record upon deletion.
  
6. **Maintainability**
   1. Classes like Train, Wagon, Passenger, and Trip should have private attributes with public accessor methods to ensure proper encapsulation.
   2. Keep a modular code structure, separating file input/output functions, data validation, and core processing logic.

7. **Error Handling**
   1. Implement exception handling for files that cannot be opened or improperly formatted data during loading in readInitialData.
   2. Display error messages when input parameters do not meet requirements, such as an out of range baggage weight.
   
8. **Front-End Design**
   1. Console presentation of menus and lists should be clear and user-friendly.
   2. Results like passenger lists and trip details should be formatted for readability on screen and in output files.
