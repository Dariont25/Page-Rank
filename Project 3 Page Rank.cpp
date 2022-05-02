#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class AdjacencyList {
private:
    vector<string> pages; //vector of pages
    map<string, vector<string>> graph; //adjaceny list to make graph
public:
    vector<double>* GetRank(int p) 
    {
        sort(pages.begin(), pages.end()); //O(NlogN)
        auto* rank = new vector<double>;
        rank->reserve(pages.size());
        for (int i = 0; i < pages.size(); i++) //O(N)
        { 
            double factor = 1.0 / pages.size();
            rank->push_back(factor);
        }
        if (p == 1)
        {
            return rank;
        }

        double outDegrees[pages.size()]; //master outdegs of each page
        for (int i = 0; i < pages.size(); i++)//O(N)
        {
            outDegrees[i] = 0.0; //initilize all out degree to 0
        }
        for (auto it = graph.begin(); it != graph.end(); it++) //iterate over froms in the graph O(n^2)
        { 
            int numberOfOuts;
            auto itr = find(pages.begin(), pages.end(), it->first); //O(N)
            numberOfOuts = distance(pages.begin(), itr); //O(N)
            outDegrees[numberOfOuts] = (1.0 / it->second.size());
        }
        for (int l = 0; l < p - 1; l++) //O(N^5)
        { 
            vector<double> store;
            for (int j = 0; j < pages.size(); j++)  //for each page, check whats connected to it //O(N^4)
            {
                double sum = 0.0;
                for (auto it = graph.begin(); it != graph.end(); it++)  //check all the froms, O(N^3)
                {
                    for (int k = 0; k < it->second.size(); k++)  //see if they lead to pages[j], O(N^2)
                    {                      
                        if (it->second[k] == pages[j])  //if it->first leads to desired page and we havent added
                        {
                            int dist = 0;
                            auto itr = find(pages.begin(), pages.end(), it->first); //where in pages is it->first, O(N)
                            dist = distance(pages.begin(), itr); //O(N)
                            double calc = (outDegrees[dist] * rank->at(dist));
                            sum += calc;
                            break;
                        }
                    }
                }
                store.push_back(sum);
            }
            for (int m = 0; m < pages.size(); m++) //O(N)
            {
                rank->at(m) = store[m];
            }
                
        }

        return rank;
    }
    void PrintRank(int p) 
    {
        vector<double> rank;
        rank = *GetRank(p); //O(N^5)
        for (int i = 0; i < pages.size(); i++) //O(N)
        {
            cout << pages[i] << " ";
            cout << fixed << setprecision(2) << rank[i] << endl;
        }
    }
    void InsertEdge(string& from, string& to) //insert from and to edges to vector of pages
    {
        
        if (find(pages.begin(), pages.end(), from) == pages.end()) //O(N)
        {
            pages.push_back(from);
        }
        if (find(pages.begin(), pages.end(), to) == pages.end()) //O(N)
        {
            pages.push_back(to);
        }
        sort(pages.begin(), pages.end()); //O(NlogN)

        if (graph.find(from) == graph.end()) 
        {
            vector<string> temp;
            temp.push_back(to);
            graph.insert({from, temp}); // insert pair from and to O(logN)
        }
        else 
        {
            auto it = graph.find(from);
            it->second.push_back(to);
        }
    }
};

int main() {
    //1 <= p <= 10,000
    //1 <= n <= 1,000,000
    int n, p; //n = number of lines p = number of power iterations
    string from, to;
    AdjacencyList g;
    cin >> n;
    cin >> p;

    for (int i = 0; i < n; i++) { //O(N)
        cin >> from;
        cin >> to;

        g.InsertEdge(from, to); //O(NlogN)
    }
    g.PrintRank(p);
    return 0;
}