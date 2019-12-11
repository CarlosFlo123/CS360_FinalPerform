/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on December 10, 2019, 7:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Package{
protected:
    string sName;
    string sAddress;
    string sCity;
    string sState;
    string sZip;
    
    string rName;
    string rAddress;
    string rCity;
    string rState;
    string rZip;
    
    double weight;
    double costPerOunce;
    
public:
    Package(string sn, string sa, string sc, string ss, string sz, string rn, string ra, string rc, string rs, string rz, double w, double c): sName(sn), sAddress(sa), sCity(sc), sState(ss), sZip(sz), rName(rn), rAddress(ra), rCity(rc), rState(rs), rZip(rz), weight(w), costPerOunce(c) {
        if (weight < 0)
            weight *= -1;
        if (costPerOunce < 0)
            costPerOunce *= -1;
    }
    Package(const Package &p2): sName(p2.sName), sAddress(p2.sAddress), sCity(p2.sCity), sState(p2.sState), sZip(p2.sZip), rName(p2.rName), rAddress(p2.rAddress), rCity(p2.rCity), rState(p2.rState), rZip(p2.rZip), weight(p2.weight), costPerOunce(p2.costPerOunce){} 
    virtual double calculateCost(){
        cout << "The cost is:" << weight*costPerOunce;
    }
    friend ostream& operator << (ostream &os, const Package &p){
        os << "Sender info: \n\t" << p.sName << "\n\t" << p.sAddress << "\n\t" << p.sCity << "\n\t" << p.sState << "\n\t" << p.sZip << "\n\n Recipient info: \n\t" << p.rName << "\n\t" << p.rAddress << "\n\t" << p.rCity << "\n\t" << p.rState << "\n\t" << p.rZip << "\n\nPackage info: \n\t" << p.weight << "\n\t" << p.costPerOunce<< "\n\n_______________________________\n";      
        return os;
    }
    
};

class TwoDayPackage : Package{
private:
    double flatFee;
public:
    TwoDayPackage(string sn, string sa, string sc, string ss, string sz, string rn, string ra, string rc, string rs, string rz, double w, double c, double f): Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w, c), flatFee(f) {}
    TwoDayPackage(const TwoDayPackage &p2): Package(p2.sName, p2.sAddress, p2.sCity, p2.sState, p2.sZip, p2.rName, p2.rAddress, p2.rCity, p2.rState, p2.rZip, p2.weight, p2.costPerOunce), flatFee(p2.flatFee){} 
    virtual double calculateCost(){
        cout << "The cost is:" << calculateCost() + flatFee;
    }
    friend ostream& operator << (ostream &os, const TwoDayPackage &p){
        os << "Sender info: \n\t" << p.sName << "\n\t" << p.sAddress << "\n\t" << p.sCity << "\n\t" << p.sState << "\n\t" << p.sZip << "\n\n Recipient info: \n\t" << p.rName << "\n\t" << p.rAddress << "\n\t" << p.rCity << "\n\t" << p.rState << "\n\t" << p.rZip << "\n\nPackage info: \n\t" << p.weight << "\n\t" << p.costPerOunce << "\n\t" << p.flatFee << "\n\n";      
        return os;
    }
};

//class OvernightPackage : Package{};

int main(int argc, char** argv) {
    Package normalPack("Virgilio", "1243 San Mathew st", "Santa Barbara", "CA", "95671", "Gaston", "Jockey Plaza", "San Francisco", "CA", "94761", 48.3, 6.2);
    cout << normalPack;
    TwoDayPackage fastPack("Enrique", "343 SantaMonica ave", "Standford", "CA", "95671", "Rogerio", "Jockey Plaza", "San Francisco", "CA", "94761", 48.3, 6.2, 10.0);
    cout<<fastPack;
    return 0;
}

