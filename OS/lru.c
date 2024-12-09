//LRU
#include<bits/stdc++.h>
using namespace std;
int main(){
    int numpages,numframes,pagefault=0;
    cout<<"enter length of ref str:";
    cin>>numpages;
    cout<<"enter number of frames:";
    cin>>numframes;
    vector<int>refstr(numpages);
    cout<<"enter the ref string:"<<endl;
    for(int i=0;i<numpages;i++){
        cin>>refstr[i];
    }
    vector<int>frame;
    vector<int>record;
    for(int i=0;i<numpages;i++){
        bool pagefound=find(frame.begin(),frame.end(),refstr[i])!=frame.end();
        if(pagefound==false){
            pagefault++;
            if(frame.size()<numframes){
                frame.push_back(refstr[i]);
            }
            else{
                int lru=record[0];
                auto it=find(frame.begin(),frame.end(),lru);
                *it=refstr[i];
                record.erase(record.begin());
            }
            record.push_back(refstr[i]);
        }
        else{
        record.erase(find(record.begin(),record.end(),refstr[i]));
        record.push_back(refstr[i]);

        }
        for(int j=0;j<numframes;j++){
              if(j<frame.size()){
                cout<<frame[j]<<"\t";
              }
              else{
                cout<<"_"<<"\t";
              }
        }

        if(pagefound==false){
            cout<<"pagefault="<<pagefault;
        }
        cout<<"\n";
    }

    cout<<"pagefault="<<pagefault<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"pagefault ratio="<<(float)pagefault/numpages<<endl;
    cout<<"hit ratio"<<(float)(numpages-pagefault)/numpages<<endl;
}
