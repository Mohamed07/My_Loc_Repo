#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
    // Add Destination place
    stops.push_back(dist);


    if(dist <= tank)
	 return 0;

    int traveled_dist = 0, num_refills = 0;
    
    while(dist > 0)
    {
	    unsigned int i;

        int max_reached_stop = stops[0] - traveled_dist;
        //std::cout<<"first rem stop dist = "<<max_reached_stop<<"\n";
        //std::cout<<"Num of rem stops = "<<stops.size()<<"\n";
        if(max_reached_stop > tank)
        {
            //std::cout<<"cannot reach first rem stop\n";
            return -1;
        }

    	for(i = 1; i < stops.size(); i++)
    	{
            int next = stops[i] - traveled_dist;
            //std::cout<<"next stop dist = "<<next<<"\n";
            if( next <= tank )
            {
                max_reached_stop = next;
            }
            else
            {
                break;
            }
        }

	    stops.erase(stops.begin(), stops.begin()+i);
	    traveled_dist += max_reached_stop;
        dist -= max_reached_stop;
        num_refills += 1;
        //std::cout<<"==========================\n";
        //std::cout<<"next rem stops = "<<stops.size()<<"\n";
        //std::cout<<"traveled = "<<traveled_dist<<"\n";
        //std::cout<<"dist = "<<dist<<"\n";
        //std::cout<<"num refills = "<<num_refills<<"\n";
        //std::cout<<"=========================\n";
    }
    return (num_refills - 1);
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
