/*
Student Name:Salih Bedirhan Eker
Student Number:2017400030
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <set>
#include "HelpStudents.h"

using namespace std;

HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    this->N = N;
    this->M = M;
    this->K = K;

    adjList = new list< pair<long long int,long long  int> >[N+1];
    vector <pair <pair <int, int> ,int> >::iterator i;
    for(i=ways.begin(); i!=ways.end(); ++i){
        long long int f_node = (*i).first.first;
        long long int s_node = (*i).first.second;
        long long  int weight = (*i).second;
        adjList[f_node].push_back(make_pair(s_node,weight));
        adjList[s_node].push_back(make_pair(f_node,weight));
    }
    // IMPLEMENT ME!
}

long long int HelpStudents::firstStudent() {
    set <pair<long long int,long long int>> mySet;

    vector<long long int> distance(N+1, -1);
    mySet.insert(make_pair(0, 1));
    distance[1] = 0;

    while(!mySet.empty()){

        pair<long long int, long long int> getMinDist = *(mySet.begin());
        mySet.erase(mySet.begin());

        long long  int tempNode = getMinDist.second;
        ////u
        list< pair<long long int,long long  int> >::iterator i;
        for (i = adjList[tempNode].begin(); i != adjList[tempNode].end(); ++i){
            //// o anki node un adj lerini git ve gidilen adj ler daha kisa olcaksa guncelle.
            int currNeighbor = (*i).first;
            int dist = (*i).second;

                if(distance[currNeighbor] > distance[tempNode] + dist || distance[currNeighbor] == -1) {

                    if (distance[currNeighbor] != -1) {
                        mySet.erase(mySet.find(make_pair(distance[currNeighbor], currNeighbor)));
                    }

                    distance[currNeighbor] = distance[tempNode] + dist;
                    mySet.insert(make_pair(distance[currNeighbor], currNeighbor));
                }

        }

    }
    return distance[K];
    // IMPLEMENT ME!
}


long long int HelpStudents::secondStudent() {
    long long int parent[N+1];
    long long int distance[N+1];
    bool visited [N+1];

    set<pair <long long int,long long int>> myset;

    for (long long int i = 0; i < N+1; i++){
        distance[i] = INF, visited[i] = false;
    }

    distance[0] = INF;
    distance[1] = 0;
    parent[1] = -1;

    for(long long int i= 0; i<N; i++){
        myset.insert(make_pair(distance[i+1],i+1));
    }

  ////  long long int tempNode = 1;
    for(long long int i=1; i<N;i++){

       long long int tempNode = myset.begin()->second;
       //long long int tempDist = myset.begin()->first;
       myset.erase(myset.begin());
        visited[tempNode] = true;

        list< pair<long long int,long long  int> >::iterator j;
        for(j = adjList[tempNode].begin(); j != adjList[tempNode].end(); ++j){

            long long  int myadj = (*j).first;
            long long  int dist = (*j).second;

            if(visited[myadj] == false){
                if(distance[myadj] > dist ){
                    myset.erase(myset.find(make_pair(distance[myadj],myadj)));
                    distance[myadj] = dist;
                    parent[myadj] = tempNode;
                    myset.insert(make_pair(distance[myadj],myadj));
                }
            }
        }

        ////
        /*
        long long int currMin = INF;
        long long int minNode = 0;

        for(long long int i=1; i <N+1; i++){
            if(visited[i] == false && distance[i] < currMin){
                currMin = distance [i];
                minNode = i;
            }
        }
         */
        ////
        //tempNode = ;
    }

    ////
    long long int maxEdge = 0;
    long long int currNode = K;
    while(parent[currNode] != -1){

        if(distance[currNode] > maxEdge)
            maxEdge = distance[currNode];


        currNode = parent[currNode];


    }
    return maxEdge;
    ////
    // IMPLEMENT ME!
}
long long int HelpStudents::thirdStudent() {
    set <pair<long long int,long long int>> mySet;

    vector<long long int> distance(N+1, -1);
    mySet.insert(make_pair(0, 1));
    distance[1] = 0;

    while(!mySet.empty()){

        pair<long long int, long long int> getMinDist = *(mySet.begin());
        mySet.erase(mySet.begin());

        long long  int tempNode = getMinDist.second;
        ////u
        list< pair<long long int,long long  int> >::iterator i;
        for (i = adjList[tempNode].begin(); i != adjList[tempNode].end(); ++i){
            //// o anki node un adj lerini git ve gidilen adj ler daha kisa olcaksa guncelle.
            int currNeighbor = (*i).first;
            int dist = 1;

            if(distance[currNeighbor] > distance[tempNode] + dist || distance[currNeighbor] == -1) {

                if (distance[currNeighbor] != -1) {
                    mySet.erase(mySet.find(make_pair(distance[currNeighbor], currNeighbor)));
                }

                distance[currNeighbor] = distance[tempNode] + dist;
                mySet.insert(make_pair(distance[currNeighbor], currNeighbor));
            }

        }

    }
    return distance[K];
    // IMPLEMENT ME!
    // IMPLEMENT ME!
}
long long int HelpStudents::fourthStudent() {
    fourthRecursive(1,0);
    // IMPLEMENT ME!
}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}


long long int HelpStudents::fourthRecursive(int currNode,long long int prevDist){

    if(currNode == K){
        return prevDist;
    }else {
        if(adjList[currNode].empty()){
            return -1;
        }
        ////min komsuyu bul onu adjlistten cikar ve ona git
        int gidilecekneigh = INF;
        int eklenecekdist = INF;

        list< pair<long long int,long long  int> >::iterator i,j;
        for(i = adjList[currNode].begin(); i != adjList[currNode].end(); ++i){

            long long  int myadj = (*i).first;
            long long  int dist = (*i).second;
            if(dist < eklenecekdist){
                eklenecekdist = dist;
                gidilecekneigh = myadj;

            }else if(dist == eklenecekdist && myadj < gidilecekneigh ){
                eklenecekdist = dist;
                gidilecekneigh = myadj;
            }
        }

        pair<long long int,long long  int> A = make_pair(gidilecekneigh,eklenecekdist);
        pair<long long int,long long  int> B = make_pair(currNode,eklenecekdist);

        adjList[currNode].remove(A);
        adjList[gidilecekneigh].remove(B);


        return fourthRecursive(gidilecekneigh,eklenecekdist+prevDist);

    }

}




// YOU CAN ADD YOUR HELPER FUNCTIONS