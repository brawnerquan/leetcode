// OJ: https://leetcode.com/problems/design-underground-system/
// Author: https://github.com/brawnerquan
// Time: O(1) supposed to be constant time insertion since its a map but lets be real here lol
// Space: O(all strings and ids) lots of stuff
class UndergroundSystem {
public:
    UndergroundSystem() {
    }
    void checkIn(int id, string stationName, int t) {
        if(customers.count(id) > 0)
            cerr << "CUSTOMER ALREADY CHECKED IN" << endl;
        customer *new_customer = new struct customer;
        new_customer->source = stationName;
        new_customer->enter_time = t;
        customers.insert({id, new_customer});
    }
    void checkOut(int id, string stationName, int t) {
        //get the customer
        unordered_map<int, customer *>::iterator cust_iter = customers.find(id);
        assert(cust_iter != customers.end());
        //grab the customer struct
        customer *leaving_customer = cust_iter->second;
        //now remove the customer from the map so when they return we can add them again
        customers.erase(cust_iter);
        string trip_id = leaving_customer->source + stationName;
        unordered_map<string, station *>::iterator avg_iter = average_time.find(trip_id);
        //if we have no previous station data, just add the trip time
        if(avg_iter == average_time.end()){
            station *new_station = new station;
            new_station->total_trip_time = t - leaving_customer->enter_time;
            new_station->num_trips = 1;
            average_time.insert({trip_id, new_station});
        }else{
            avg_iter->second->total_trip_time += (double) t - leaving_customer->enter_time;
            avg_iter->second->num_trips++;
        }
        delete leaving_customer;
    }
    double getAverageTime(string startStation, string endStation) {
        unordered_map<string, station *>::iterator avg_iter= average_time.find(startStation + endStation);
        return (double) avg_iter->second->total_trip_time / avg_iter->second->num_trips;
    }
private:
    struct customer {
        string source;
        int enter_time;
    };
    struct station {
        int total_trip_time;
        int num_trips;
    };
    unordered_map<string, station *> average_time;
    unordered_map<int, customer *> customers;
};