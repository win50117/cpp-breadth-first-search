#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>  

using namespace std;

int main(int argc, char *argv[])
{
    int num[5][4],fn[5],an[5];
    ifstream fin("test.txt");                              //�}�� 
    if(!fin)                                              //�p�G���� 
    { 
        cout << "�}�ҥ���\n";                          //�C�L 
        system("pause");                             
        return 0;
    }
    for(int i=0;i<5;i++)                              //Ū�� �M�w�x�}�� 
    { 
      for(int j=0;j<4;j++)                            //�M�w�x�}�C 
      {
        fin >> num[i][j];                            //�s�J�x�} 
        //cout << num[i][j] << " ";                  //�ˬd�x�}�O�_���T 
      }
      //cout << "\n";                                //���� 
    } 
    fin.close();                                     //���� 
    
    for(int i=0;i<5;i++)                             //�C�L fn,an 
    { 
         fn[i] = num[i][0];
         an[i] = num[i][1];   
         cout << "fn[" << i+1 << "]= " << num[i][0];   //�C�Ltail 
         cout << "  an[" << i+1 << "]= " << num[i][1]; //�C�Lhand  
         cout << "\n";
    }
    
    cout << "\n"; 
    
    int a[4]={0,0,0,0};             //�ŧi[1][4]���x�},�s��fn[i]�U�I���Ӽ�  (a[] �Ω�s��۾F�`�I���X��)
    for(int k=1;k<=4;k++)           //�M�w�ˬd����(�C���Itail���`��) (1 2 3 4�`�I����) 
    {
       for(int i=0;i<5;i++)         // �ˬd�C��fn 
       { 
          if(num[i][0] == k)        //�P�_�C��fn�O�_����k 
          {
             a[k-1]++;              //�p�G����k�N�|�[1 
          }
       }
       cout << "a[" << k << "]= " << a[k-1] << "\n";  //�C�La[i] 
    }
    
    cout << "\n";
    
    int b[5]={1,0,0,0,0};       // a[i]���֥[ �ŧi b ���@��[1][5]���x�} ,b[0]=1 
    for(int i=0;i<4;i++)        //��@�֥[ 
    {
       b[i+1] = b[i] + a[i];     
    }
    for(int i=0;i<5;i++)         //�C�Lb[i]���j�� 
    {
       cout << "b[" << i+1 << "]= " << b[i] << "\n";
    }
    cout << endl; 
    
    //////////////////////////////////////////////////////////// 
    
    queue<int> myqueue;                     //�ŧi�@�Ӷ��C               
    bool visit[5];                          //�s���`�I�O�_�Q�����L 
    int path[4];                            //path�������| �s���`�I���W�@�Ӹ`�I 
    int pa = 0;                             //path�s�񪺸`�I�� 
    
    for(int root=1;root<=4;root++)          //r��root 
    {   
        cout <<"root : " << root << endl ;  
        for(int i=0;i<5;i++)               //��ڸ`�I�é�Jqueue 
        {    
             if(fn[i]==root) 
             {          
                   myqueue.push(fn[i]);    //��Jqueue 
                   visit[fn[i]] = true;    //�`�I�]���w���� 
                   break;                  //���X�j�� 
             }    
        }
        while(!myqueue.empty())       //�Yqueue���O�Ū� 
        {               
            int rt = myqueue.front(); //�ŧirt���ثequeue���Y�`�I
            myqueue.pop();            //�N�`�I���X                     
            for(int r=0;r<5;r++)      //�F�`�I��Jqueue 
            {                      
                 if(fn[r]==rt)        //�M��`�I==�Y�`�I  (fn->an �Y->��) 
                 {    
                       if(visit[an[r]]!=true)      //�Y�F�`�I���Q�����L 
                       {   
                            if(path[pa-1]!=fn[r])  //�Ypath���e�@�`�I�������Y�`�I (�קK���Ʀs���e�@�`�I) 
                            {
                                 path[pa]=fn[r];   //�s���e�@�Ӹ`�I 
                                 pa++;             //��l�Ჾ
                            }   
                            visit[an[r]]=true;     //�N�F�`�I�Ь��w���� 
                            myqueue.push(an[r]);   //�N�F�`�I��Jqueue 
                            cout << root << "->" << an[r] << " path: "; //�L�X�ثe���j�M 
                            
                            for(int pin=0;pin<pa;pin++)                 //�L�X�w���L��path���|            
                            {
                                 cout << path[pin] << "->" ;   
                            }     
                            cout << an[r] << endl;                      //�L�Xpath�����I (�u�s�e�@�`�I ���|�����I)    
                       } 
                 }                 
            } 
        }
        cout << endl;
        for(int v=0;v<5;v++) //�N�����ȥ��k�������� 
        {               
           visit[v]=false;
        }  
        pa=0;                //�N���|�`�I�k0 ���s�s��                
    }    
    system("PAUSE");
    return EXIT_SUCCESS;
}

