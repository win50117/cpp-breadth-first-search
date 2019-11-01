#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>  

using namespace std;

int main(int argc, char *argv[])
{
    int num[5][4],fn[5],an[5];
    ifstream fin("test.txt");                              //開檔 
    if(!fin)                                              //如果失敗 
    { 
        cout << "開黨失敗\n";                          //列印 
        system("pause");                             
        return 0;
    }
    for(int i=0;i<5;i++)                              //讀檔 決定矩陣行 
    { 
      for(int j=0;j<4;j++)                            //決定矩陣列 
      {
        fin >> num[i][j];                            //存入矩陣 
        //cout << num[i][j] << " ";                  //檢查矩陣是否正確 
      }
      //cout << "\n";                                //換行 
    } 
    fin.close();                                     //關檔 
    
    for(int i=0;i<5;i++)                             //列印 fn,an 
    { 
         fn[i] = num[i][0];
         an[i] = num[i][1];   
         cout << "fn[" << i+1 << "]= " << num[i][0];   //列印tail 
         cout << "  an[" << i+1 << "]= " << num[i][1]; //列印hand  
         cout << "\n";
    }
    
    cout << "\n"; 
    
    int a[4]={0,0,0,0};             //宣告[1][4]的矩陣,存放fn[i]各點之個數  (a[] 用於存放相鄰節點有幾個)
    for(int k=1;k<=4;k++)           //決定檢查的數(每個點tail的總數) (1 2 3 4節點的值) 
    {
       for(int i=0;i<5;i++)         // 檢查每個fn 
       { 
          if(num[i][0] == k)        //判斷每個fn是否等於k 
          {
             a[k-1]++;              //如果等於k就會加1 
          }
       }
       cout << "a[" << k << "]= " << a[k-1] << "\n";  //列印a[i] 
    }
    
    cout << "\n";
    
    int b[5]={1,0,0,0,0};       // a[i]的累加 宣告 b 為一個[1][5]的矩陣 ,b[0]=1 
    for(int i=0;i<4;i++)        //實作累加 
    {
       b[i+1] = b[i] + a[i];     
    }
    for(int i=0;i<5;i++)         //列印b[i]的迴圈 
    {
       cout << "b[" << i+1 << "]= " << b[i] << "\n";
    }
    cout << endl; 
    
    //////////////////////////////////////////////////////////// 
    
    queue<int> myqueue;                     //宣告一個隊列               
    bool visit[5];                          //存取節點是否被探索過 
    int path[4];                            //path紀錄路徑 存取節點的上一個節點 
    int pa = 0;                             //path存放的節點數 
    
    for(int root=1;root<=4;root++)          //r為root 
    {   
        cout <<"root : " << root << endl ;  
        for(int i=0;i<5;i++)               //找根節點並放入queue 
        {    
             if(fn[i]==root) 
             {          
                   myqueue.push(fn[i]);    //放入queue 
                   visit[fn[i]] = true;    //節點設為已探索 
                   break;                  //跳出迴圈 
             }    
        }
        while(!myqueue.empty())       //若queue不是空的 
        {               
            int rt = myqueue.front(); //宣告rt為目前queue的頭節點
            myqueue.pop();            //將節點取出                     
            for(int r=0;r<5;r++)      //鄰節點放入queue 
            {                      
                 if(fn[r]==rt)        //尋找節點==頭節點  (fn->an 頭->尾) 
                 {    
                       if(visit[an[r]]!=true)      //若鄰節點未被探索過 
                       {   
                            if(path[pa-1]!=fn[r])  //若path的前一節點不等於頭節點 (避免重複存取前一節點) 
                            {
                                 path[pa]=fn[r];   //存取前一個節點 
                                 pa++;             //位子後移
                            }   
                            visit[an[r]]=true;     //將鄰節點標為已探索 
                            myqueue.push(an[r]);   //將鄰節點放入queue 
                            cout << root << "->" << an[r] << " path: "; //印出目前的搜尋 
                            
                            for(int pin=0;pin<pa;pin++)                 //印出已走過的path路徑            
                            {
                                 cout << path[pin] << "->" ;   
                            }     
                            cout << an[r] << endl;                      //印出path的終點 (只存前一節點 不會有終點)    
                       } 
                 }                 
            } 
        }
        cout << endl;
        for(int v=0;v<5;v++) //將探索值全歸為未探索 
        {               
           visit[v]=false;
        }  
        pa=0;                //將路徑節點歸0 重新存放                
    }    
    system("PAUSE");
    return EXIT_SUCCESS;
}

