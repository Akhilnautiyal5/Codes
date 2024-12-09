// FIFO
#include<bits/stdc++.h>

using namespace std;
int main(){
    int numpages,numframe,pagefaults=0,pagetoreplace=0;
    cout<<"enter the number of pages /length of refrence string :";
    cin>>numpages;
    vector<int>refstr(numpages);
    cout<<"enter the reference string:"<<endl;
    for(int i=0;i<numpages;i++){
        cin>>refstr[i];
    }
    cout<<"enter the number of frames:";

    cin>>numframe;
    vector<int>frame(numframe,-1);
    for(int i=0;i<numpages;i++){
        bool pagefound=find(frame.begin(),frame.end(),refstr[i])!=frame.end();
      

            if(pagefound==false){
                frame[pagetoreplace]=refstr[i];
                pagetoreplace=(pagetoreplace+1)%numframe;
                pagefaults++;
    }

    for(int j=0;j<numframe;j++){
        if(frame[j]!=-1){
            cout<<frame[j]<<"\t";
        }
        else{
            cout<<"_"<<"\t";
        }
    }

    if(pagefound==false){
        cout<<"pagefault="<<pagefaults<<"\t";
    }

    cout<<"\n";
    }
    cout<<"total pagefaults="<<pagefaults<<endl;
    cout<<"pagefault ratio="<<(float)pagefaults/numpages<<endl;
    cout<<"pagefault ratio="<<(float)(pagefaults-numpages)/numpages<<endl;



    return 0;

}
