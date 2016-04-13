truct Available_Workshops{
  int start_time[100000];
  int duration[100000];
  int n;
    
};

bool myf (pair<int,int> A, pair<int,int> B){
    return (A.first+A.second < B.first+B.second);
}

Available_Workshops* initialize(int st[], int d[], int num){
      Available_Workshops* New = new Available_Workshops;
      New->n = num;
      for (int i=0; i<num; ++i){
            New->start_time[i] = st[i];
            New->duration[i] = d[i];
      }
      return New;
};

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int N = ptr->n;
    int Time = 0;
    int Ans = 0;
    
    vector<pair<int,int>> V;
    
    for (int j=0; j<N; ++j){
        V.push_back({ptr->start_time[j], ptr->duration[j]});
    }
    
    sort(V.begin(), V.end(), myf);
    
    for (int i=0; i<N; ++i){
        if (Time<=V.at(i).first){
            ++Ans;
            Time = V.at(i).first + V.at(i).second;
        }
    }
    return Ans;
};


