#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Truck
{
    Truck(int w, int t): weight(w), startTime(t) {};
    
    int weight;
    int startTime;
};


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<Truck> bridge;
    int time = 0;
    int weightOnBridge = 0;
    
    for(int i = 0 ; i < truck_weights.size(); i++)
    {
        int currentWeight = truck_weights[i];
        
        if(weightOnBridge + currentWeight <= weight && bridge.size() < bridge_length)
        {
            //ok
            time++;
            bridge.push(Truck(currentWeight,time));
            weightOnBridge += currentWeight;
            
            //빠져나가는 차가 있나 확인
            while(true)
            {
                auto truck = bridge.front();
                
                if(time - truck.startTime >= bridge_length) 
                {
                    bridge.pop();
                    weightOnBridge -= truck.weight;
                }
                else break;
            }
        }
        else
        {
            //wait
            //무게가 ok 일때까지 앞에있는애 빼야함 && 길이 check
            
            while(!bridge.empty())
            {
                int waitTime = bridge_length - (time - bridge.front().startTime);
                int frontTruckWeight = bridge.front().weight;
                bridge.pop();
                
                weightOnBridge -= frontTruckWeight;
                
                if(weightOnBridge + currentWeight <= weight && bridge.size() < bridge_length)
                {
                    weightOnBridge += currentWeight;
                    time += waitTime;
                    bridge.push(Truck(currentWeight,time));
                    
                    break;
                }
            }
        }
    }
    
    time += bridge_length;
    
    
    return time;
}