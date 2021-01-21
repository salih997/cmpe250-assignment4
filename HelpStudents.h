#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <limits>
#include <climits>

using namespace std;


class HelpStudents{

public:
    HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();
    long long int fourthRecursive(int,long long int);
    long long int getMinNode(long long int[], long long int []);

    const long long int INF = LONG_LONG_MAX;


    list< pair<long long int,long long  int> > *adjList;
    //vector<int> distance();



    //  list<bool> *visited;
    //  set <pair<int,int>> *visitedEdges;
    int N;
    int M;
    int K;

    //   vector<list<pair<int,int>>> adjList;
    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
