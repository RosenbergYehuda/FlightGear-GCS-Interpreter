#include "headerFiles/pathValueMap.h"

// singel tone
PathValueMap PathValueMap::instance ;
PathValueMap& PathValueMap::getinstance()
{
    return instance;
}

unordered_map<string, double> PathValueMap::umap;

void PathValueMap::pathValueMap(vector<double> values)
{
    vector<string> paths;
    paths = {"/instrumentation/airspeed-indicator/indicated-speed-kt", "/sim/time/warp", "/controls/switches/magnetos", "/instrumentation/heading-indicator/offset-deg", "/instrumentation/altimeter/indicated-altitude-ft", "/instrumentation/altimeter/pressure-alt-ft", "/instrumentation/attitude-indicator/indicated-pitch-deg", "/instrumentation/attitude-indicator/indicated-roll-deg", "/instrumentation/attitude-indicator/internal-pitch-deg", "/instrumentation/attitude-indicator/internal-roll-deg", "/instrumentation/encoder/indicated-altitude-ft", "/instrumentation/encoder/pressure-alt-ft", "/instrumentation/gps/indicated-altitude-ft", "/instrumentation/gps/indicated-ground-speed-kt", "/instrumentation/gps/indicated-vertical-speed", "/instrumentation/heading-indicator/indicated-heading-deg", "/instrumentation/magnetic-compass/indicated-heading-deg", "/instrumentation/slip-skid-ball/indicated-slip-skid", "/instrumentation/turn-indicator/indicated-turn-rate", "/instrumentation/vertical-speed-indicator/indicated-speed-fpm", "/controls/flight/aileron", "/controls/flight/elevator", "/controls/flight/rudder", "/controls/flight/flaps", "/controls/engines/engine/throttle", "/controls/engines/current-engine/throttle", "/controls/switches/master-avionics", "/controls/switches/starter", "/engines/active-engine/auto-start", "/controls/flight/speedbrake", "/sim/model/c172p/brake-parking", "/controls/engines/engine/primer", "/controls/engines/current-engine/mixture", "/controls/switches/master-bat", "/controls/switches/master-alt", "/engines/engine/rpm"};

    // creating a map which the key is a path and the value is the  value recived from the drone for that path.
    for (int i = 0; i < paths.size(); i++)
    {
        umap[paths[i]] = values[i];
    }
};

/*
int main()
{
    vector<double> val = {11.2, 10.3, 20.4};
    PathValueMap::getinstance().pathValueMap(val);
    cout<<PathValueMap::getinstance().umap["2"]<<endl;
    return 0;
}
*/
