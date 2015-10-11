#include <iostream>
#include <sstream>

using namespace std;

#define MAXI 500
#define MAXF 100
#define MAXINT 0x7fffffff

int stations[MAXF + 1];
int weight[MAXI + 1][MAXI + 1];
int df[MAXI + 1];

inline void init(int nI){
	for (int i = 1; i <= nI; i++)
		for (int j = 1; j <= nI; j++)
			weight[i][j] = MAXINT;    
}

inline void floyd(int nI){
    for (int k = 1; k <= nI; k++)
		for (int i = 1; i <= nI; i++)
			for (int j = 1; j <= nI; j++)
				if (weight[i][k] + weight[k][j] < weight[i][j] && weight[k][j] != MAXINT && weight[i][k] != MAXINT)
					weight[i][j] = weight[i][k] + weight[k][j];
    for (int i = 1; i <= nI; i++)
		weight[i][i] = 0;
    
}

inline int solve(int nF, int nI){
	int max_path = 0;
	for (int i = 1; i <= nI; i++){
		df[i] = MAXINT;
		
		for (int j = 1; j <= nF; j++)
			if (weight[i][stations[j]] < df[i])
				df[i] = weight[i][stations[j]];
				
        max_path = max(df[i], max_path);
	}

	int intersection = 1;
	for (int i = nI; i >= 1; i--){
		int new_max_path = 0;
		for (int j = 1; j <= nI; j++)
			if (weight[j][i] < df[j])
				new_max_path = max(new_max_path, weight[j][i]);
			else
                new_max_path = max(new_max_path, df[j]);
					
		if (new_max_path <= max_path){
			intersection = i;
			max_path = new_max_path;
		}
	}    
	
	return intersection;
}

int main(int ac, char *av[]){
	int cases;
	int nF, nI;

	cin >> cases;
	while (cases--){
		cin >> nF >> nI;
		
		for (int c = 1; c <= nF; c++)
	        cin >> stations[c];
		
		init(nI);
		 
		cin.ignore();
		string line;
		while (getline(cin, line), line.length()){
		    int fi, si, wi;
			stringstream ss(line);
			ss >> fi >> si >> wi;
			weight[fi][si] = weight[si][fi] = wi;
		}

        floyd(nI);

		cout << solve(nF, nI) << endl;
		if(cases) cout << endl;
	}
	
	return 0;
}