#include <iostream>
#include <string>

using namespace std;

const int size_queue = 5;

// Flight class definition and implementation
class Flight {
public:
    string id;
    int fuel;
    int passenger;
    string status;

    Flight(void);
    Flight(string, int, int, string);
    void printInfo(void);
    void updateFuel(void);
    void landing(void);

    ~Flight() {
        cout << "Destroy " << id << " flight\n";
    }
};

Flight::Flight(void) {}

Flight::Flight(string i, int f, int p, string s) {
    id = i;
    fuel = f;
    passenger = p;
    status = s;
}

void Flight::printInfo(void) {
    cout << id << " [" << fuel << ", " << passenger << ", " << status << "]\n";
}

void Flight::updateFuel(void) {
    if (fuel > 0) {
        fuel--;
    } else {
        status = "Crash";
    }
}

void Flight::landing(void) {
    if (fuel > 0) {
        if (status == "Flying") {
            status = "Change altitude";
        } else if (status == "Change altitude") {
            status = "Change direction";
        } else if (status == "Change direction") {
            status = "Landing";
        }
    } else {
        status = "Crash";
    }
}

// Queue class definition and implementation
class Queue {
private:
    int front;
    int rear;
    Flight* items[size_queue];

public:
    Queue(void);
    void enQueue(Flight* f);
    Flight* deQueue(void);
    bool isFull(void);
    bool isEmpty(void);
    void prioritizeQueue();
};

Queue::Queue(void) {
    front = 0;
    rear = -1;
}

void Queue::enQueue(Flight* f) {
    if (!isFull()) {
        rear++;
        items[rear] = f;
        prioritizeQueue(); // Reorder the queue based on fuel levels
    } else {
        cout << "Queue is full...\n\n";
    }
}

Flight* Queue::deQueue(void) {
    if (!isEmpty()) {
        Flight* f = items[front];
        front++;
        return f;
    } else {
        cout << "Queue is empty...\n";
        return NULL;
    }
}

bool Queue::isFull(void) {
    return rear == (size_queue - 1);
}

bool Queue::isEmpty(void) {
    return front > rear;
}

void Queue::prioritizeQueue() {
    for (int i = front; i < rear; ++i) {
        for (int j = i + 1; j <= rear; ++j) {
            if (items[i]->fuel > items[j]->fuel) {
                Flight* temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Function to print info of arriving flights
void arrivingFlightInfo(int f_arv[], Flight* f[], int size) {
    cout << "Arriving flights info.:\n";
    for (int i = 0; i < size; i++) {
        if (f_arv[i] > -1) {
            string f_status = f[f_arv[i]]->status;
            if (f_status != "Landing" && f_status != "Crash") {
                f[f_arv[i]]->updateFuel();
            }
            f[f_arv[i]]->printInfo();
        }
    }
    cout << endl;
}

// Function to handle emergency landing
Flight* emergencyLanding(Queue& q, Flight* currentLanding) {
    if (!q.isEmpty() && q.items[q.front]->fuel <= 2) {
        cout << "Emergency landing for flight " << q.items[q.front]->id << " due to critically low fuel!\n";
        return q.deQueue();
    }
    return currentLanding;
}

// Main function
int main(int argc, char* argv[]) {
    const int size_arrive = 10;
    const int size_incoming = 17;

    Queue q;

    Flight* f[size_arrive] = {
        new Flight("MH123", 13, 100, "Flying"),
        new Flight("FR320", 10, 120, "Flying"),
        new Flight("SG078", 18, 120, "Flying"),
        new Flight("FR747", 8, 250, "Flying"),
        new Flight("MH118", 14, 150, "Flying"),
        new Flight("AS103", 13, 200, "Flying"),
        new Flight("FR240", 24, 100, "Flying"),
        new Flight("MH308", 20, 150, "Flying"),
        new Flight("SG090", 11, 220, "Flying"),
        new Flight("AS303", 15, 120, "Flying")
    };

    int f_incoming[size_incoming] = {0, -1, 1, 2, -1, -1, 3, 4, -1, -1, 5, -1, 6, 7, -1, 8, 9};
    int f_arrive[size_arrive] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    char c;
    int i = 0, cycle = 1;
    bool stop = false;
    Flight* f2land = NULL;

    while (!stop) {
        cout << "\nSIMULATION CYCLE: " << cycle << "\n";
        cout << "---------------------\n";
        cycle++;

        if (i < size_incoming) {
            if (f_incoming[i] == -1) {
                cout << "No incoming flight...\n\n";
            } else {
                cout << f[f_incoming[i]]->id << " flight is coming...\n\n";
                f_arrive[f_incoming[i]] = f_incoming[i];

                cout << "Try to en-queue " << f[f_incoming[i]]->id << " flight...\n\n";
                q.enQueue(f[f_incoming[i]]);
            }
        }

        // Emergency landing override
        f2land = emergencyLanding(q, f2land);

        if (f2land == NULL) {
            if (!q.isEmpty()) {
                f2land = q.deQueue();
                cout << "De-queue " << f2land->id << " flight...\n\n";
            }
        }

        if (f2land != NULL) {
            string f_status = f2land->status;
            if (f_status == "Flying" || f_status == "Change altitude" || f_status == "Change direction") {
                f2land->landing();
            } else {
                if (f_status == "Landing") {
                    cout << "Good news, " << f2land->passenger << " passengers are safely landed :-)\n\n";
                } else {
                    cout << "Soo sad, " << f2land->passenger << " passengers are dead :-(\n\n";
                }
                f2land = NULL;
            }
        }

        arrivingFlightInfo(f_arrive, f, size_arrive);

        cout << "Press 'c' to continue and 's' to stop: ";
        cin >> c;
        i++;

        if (c == 's') {
            stop = true;
        }
    }

    int crash = 0, comfort = 0, critical = 0, alive = 0, dead = 0;

    for (int i = 0; i < size_arrive; i++) {
        if (f[i]->status == "Landing") {
            alive += f[i]->passenger;
            if (f[i]->fuel > 3) {
                comfort++;
            } else {
                critical++;
            }
        } else {
            crash++;
            dead += f[i]->passenger;
        }
    }

    cout << "\nSimulation result & statistic:\n\n";
    cout << "           Crash: " << crash << endl;
    cout << " Comfort landing: " << comfort << endl;
    cout << "Critical landing: " << critical << "\n\n";
    cout << " Passenger alive: " << alive << endl;
    cout << "  Passenger dead: " << dead << endl;

    for (int i = 0; i < size_arrive; i++) {
        delete f[i];
    }

    return 0;
}
