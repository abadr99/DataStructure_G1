#include <iostream>
using namespace std;
#include <string>
#include "Simulate.h"
#include <queue>
int main(){

    int firstLine[2],packet[2];
    int MaxSizeBuffer,SizeBuffer,NoPackets;
    int counter =0;
    int nextprocesse=0;
    queue<int> packets;
    for (int i=0; i<2;i++){
        cin>>firstLine[i];
    }
    NoPackets=GetNoPackets(firstLine);
    MaxSizeBuffer=GetMaxSize(firstLine);
    while(counter<NoPackets)
    {       
        SizeBuffer=packets.size();
        if(MaxSizeBuffer==0)
        {
            packets.push(-1);
        }         
        else if(SizeBuffer==0)
        {
            for (int i=0; i<2;i++)
            {
                cin>>packet[i];
            }
            packets.push(GetAi(packet));
            nextprocesse=GetAi(packet)+GetPi(packet);
            
        }
        else if (SizeBuffer<=MaxSizeBuffer)
        {
            for (int i=0; i<2;i++)
            {
                cin>>packet[i];
            }
            if(nextprocesse<=GetAi(packet))
            {
                packets.push(GetAi(packet));
                nextprocesse=GetAi(packet)+GetPi(packet);                
            }
            //else if
            else 
            {
                packets.push(-1);
            }
        }
        else if (SizeBuffer>MaxSizeBuffer)
        {
            packets.push(-1);
        }
    counter++;
    }
    while (!packets.empty())
    {
    
        cout<<packets.front()<<endl;

        packets.pop();
    }
    

    return 0;
}