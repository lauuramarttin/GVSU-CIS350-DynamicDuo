def menu(trains, passengers):
    print("Welcome to the main menu, what do you want to do?")
    print("1: Add new passenger’s trip to a train")
    print("2: Remove a passenger’s trip from a train")
    print("3: Show trips of a passenger")
    print("4: Show list of passengers in a specific train")
    print("5: End program")    

    option = int(input("Choose an option: "))

    if option == 5:
        print("End program")
        end_program(trains, passengers)
        return False

    if option == 1:
        print("Add new passengers trip to a train")
        add_new_passenger_trip(trains, passengers)
    elif option == 2:
        print("Remove a passenger’s trip from a train")
        remove_passenger_trip(trains, passengers)
    elif option == 3:
        print("Show trips of a passenger")
        show_trips_of_passenger(passengers)
    elif option == 4:
        print("Show list of passengers in a specific train")
        show_list_of_passengers(trains, passengers)

    else:
        print("You've entered the wrong number")

    return True

# Define functions
def read_initial_data(trains, passengers):
    print("Read initial data...")

def add_new_passenger_trip(trains, passengers):
    print("Adding a new trip...")

def remove_passenger_trip(trains, passengers):
    print("Removing a trip...")

def show_trips_of_passenger(passengers):
    print("Showing trips of a passenger...")

def show_list_of_passengers(trains, passengers):
    print("Showing passengers in a train...")

def end_program(trains, passengers):
    print("Ending the program...")


# Example usage
if __name__ == "__main__":
    trains = [] 
    passengers = {} 
    read_initial_data(trains, passengers)
    follow= True
    while follow:
        follow=menu(trains,passengers)
