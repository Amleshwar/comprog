#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdio>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#define rep(i, a, b) for(__typeof(a) i = (a); i < (b); ++i)
#define all(c) c.begin(), c.end() 
#define iter(it, c) for(__typeof((c).begin)it = (c).begin; it != (c).end(); it++)
using namespace std;

struct Query
{
	string type;
	string s;
	size_t ind;
};

class QueryProcessor
{
	int bucket_count;
	vector <string> elems;
	size_t hash_func(const string& s)const
	{
		static const size_t multiplier = 263;
		static const size_t prime = 1000000007;
		unsigned long long hash = 0;
		for(int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
			hash = (hash*multiplier + s[i]) % prime;

		return hash % bucket_count;
	}



public:
	explicit QueryProcessor(int bucket_count)
		: bucket_count(bucket_count){}

	Query readQuery() const
	{
		Query query;
		cin >> query.type;
		if(query.type != "check")
			cin >> query.s;
		else
			cin >> query.ind; 

		return query;
	}

	void writeSearchResult(bool was_found) const
	{
		cout << (was_found ? "yes\n" : "no\n"); 
	}

	void processQuery(const Query& query)
	{
		if(query.type == "check")
		{
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
				if(hash_func(elems[i]) == query.ind)
					cout << elems[i] << " " ;
			cout << "\n";
		}
		else
		{
			vector <string> :: iterator it = find(all(elems), query.s);
			if(query.type == "find")
				writeSearchResult(it != elems.end());
			else if(query.type == "add")
			{
				if(it == elems.end())
					elems.push_back(query.s);
			}
			else if(query.type == "del")
				if(it != elems.end())
					elems.erase(it);
		}		
	}
	void processQueries()
	{
		int n;
		cin >> n;
		rep(i, 0, n)
			processQuery(readQuery());
	
	}	
	
};
	
	
int main()
{
	int bucket_count;
	cin >> bucket_count;
	QueryProcessor proc(bucket_count);
	proc.processQueries();
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	












