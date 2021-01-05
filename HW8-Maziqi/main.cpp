#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int gc = 0;
double dis;

class Point{
private:
    double x,y;
public:
    int num;
    int cluster;
    Point(double,double);
    Point(const Point &);
    double dist(const Point &)const;
    bool inrange(const Point &)const;
    bool operator<(const Point &) const;
};

Point::Point(double tx, double ty) {
    x = tx;
    y = ty;
    num = gc++;
    cluster = -1;
}

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
    num = p.num;
    cluster = p.cluster;
}

double Point::dist(const Point &p) const {
    return sqrt(pow((x-p.x),2) + pow((y-p.y),2));
}

bool Point::inrange(const Point &p) const {
    return dist(p) <= dis;
}

bool Point::operator<(const Point &p) const {
    return num<p.num;
}


int main() {
    cout<<"Print the distance in the first line, then print the coordonate in the followling lines, if your input is over, print any letter to end."<<endl;
    cin>>dis;
    double x,y;
    vector<Point> p_list;
    while(cin>>x>>y) {
        Point p(x, y);
        p_list.push_back(p);
    }
    int c_count = 0;
    for(int i=0;i<p_list.size()-1;++i){
        for(int j=i+1;j<p_list.size();++j){
            if(p_list[i].inrange(p_list[j])){
                if(p_list[i].cluster!=-1 && p_list[j].cluster == -1){
                    p_list[j].cluster = p_list[i].cluster;
                }
                else if(p_list[i].cluster==-1 && p_list[j].cluster != -1){
                    p_list[i].cluster = p_list[j].cluster;
                }
                else if(p_list[i].cluster==-1 && p_list[j].cluster == -1){
                    p_list[i].cluster = c_count++;
                    p_list[j].cluster = p_list[i].cluster;
                }
                else{
                    for(int k=0;k<p_list.size();++k){
                        if(p_list[k].cluster==p_list[j].cluster){
                            p_list[k].cluster = p_list[i].cluster;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<p_list.size();++i){
        if(p_list[i].cluster == -1) p_list[i].cluster = c_count++;
    }

    map<int,vector<int>> output;
    for(int i=0;i<p_list.size();++i){
        if(output.find(p_list[i].cluster) == output.end()){
            vector<int> tmp;
            tmp.push_back(p_list[i].num);
            output[p_list[i].cluster] = tmp;
        }
        else{
            output[p_list[i].cluster].push_back(p_list[i].num);
        }
    }
    for(auto it=output.begin();it!=output.end();++it){
        sort(it->second.begin(),it->second.end());
    }
    for(auto it=output.begin();it!=output.end();++it){
        for(int i=0;i<it->second.size();++i){
            cout<<it->second[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
