#include<iostream>
using namespace std;


class SwimmingPool
{
    float PoolLength;
    float PoolWidth;
    float PoolDepth;
    float FillingTime;
    float DrainTime;

public:

    SwimmingPool(){

        cout<<"Enter the Length of your Pool (in feet): ";cin>>PoolLength;
        cout<<"Enter the width of your Pool (in feet): ";cin>>PoolWidth;
        cout<<"Enter the depth of your Pool (in feet): ";cin>>PoolDepth;
        cout<<"Enter the filling time of your Pool (gallons per minute): ";cin>>FillingTime;
        cout<<"Enter the draining time of your Pool (gallons per minute): ";cin>>DrainTime;

    }

    float volumeofpool()
    {
        float volumeincubicfeet;
        volumeincubicfeet=PoolLength*PoolDepth*PoolWidth;

        float volumeingallons=volumeincubicfeet*7.48052;

        return volumeingallons;

    }



        float TimeforEmptyPool()
        {
            float timeforemptypool=volumeofpool()/FillingTime;
            return timeforemptypool;

        }

    float TimeforpartiallyfilledPool(float presentvolume)
    {
        float volume=volumeofpool()-presentvolume;

        float timeforpartiallyfilled=volume/FillingTime;
        return timeforpartiallyfilled;

    }



    float Amountofwaterforemptypool(){

        return volumeofpool();
    }

    float Amountofwaterforhalffillpool(float presentvolume){

        float amount= volumeofpool()-presentvolume;

        return amount;
    }


    float timetodrainpool()
    {
        float draintime=volumeofpool()/DrainTime;
        return draintime;
    }

    float timetodrainhalfpool(float presentvolume)
    {
        float halfvolume=volumeofpool()-presentvolume;

        float draintime=halfvolume/DrainTime;
        return draintime;
    }




};
