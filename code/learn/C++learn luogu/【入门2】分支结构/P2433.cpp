#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int n = 15;
    cin>>n;
    switch(n){
        case(1):{
            cout<<"I love Luogu!";
            break;
        }
        case(2):{
            cout<<6<<" "<<4;
            break;        
        }
        case(3):{
            cout<<3<<" "<<12<<" "<<2;
            break;        
        }
        case(4):{
            printf("%.3lf\n",500.0/3.0);
            break;        
        }
        case(5):{
            cout<<15<<endl;
            break;        
        }
        case(6):{
            cout<<sqrt(6*6+9*9)<<endl;
            break;        
        }
        case(7):{
            cout<<110<<endl<<90<<endl<<0<<endl;
            break;        
        }
        case(8):{
            double const pi=3.141593;
    	double const r=5;
    	cout<<pi*r*2<<endl<<pi*r*r<<endl<<4.0/3*pi*r*r*r<<endl;
            break;        
        }
        case(9):{
            cout<<22<<endl;
            break;        
        }
        case(10):{
            cout<<9<<endl;
            break;        
        }
        case(11):{
            cout<<100.0/(8-5)<<endl;
            break;        
        }
        case(12):{
            cout<<13<<endl<<"R"<<endl;
            break;            
            }
        case(13):{
            double const pi=3.141593;
    	double V=pi*4*4*4*4/3+pi*10*10*10*4/3;
    	cout<<floor(pow(V,1.0/3))<<endl;
            break;            
            }
        case(14):{
            cout<<50<<endl;
            break;            
            }

    }
    return 0;
}