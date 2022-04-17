#include <bits/stdc++.h>

using namespace std;

class node{
      public:
      int pageid;
      int pagesize;
      int nrecords;
      int rspace;
      vector <int> v;
      int aofspace;
      node* next;
      node* prev;
      node* head;

};

int main()
{
    int spage;
    int npages=0;
    cin >> spage;
    node* heapfile = new node;
    heapfile->pagesize = spage;
    heapfile->rspace = spage-16;
    heapfile->nrecords=0;
    heapfile->pageid=0;
    heapfile->next=nullptr;
    heapfile->prev=nullptr;
    node* head = heapfile;



    int inp;
    cin >> inp;
    while(inp!=4)
    {
        if(inp==2)
        {
            if(npages==0)
            {
                cout << npages << endl;
            }
            else
            {
                cout << npages ;
                while(heapfile!=nullptr)
                {
                    cout <<" " << heapfile->nrecords;
                    heapfile = heapfile->next;

                }
                cout << endl;

            }
            heapfile = head;

        }
        if(inp==1)
        {
            int rsize;
            int pkey;
            cin >> rsize >> pkey;
            if(npages==0)
            {
                if(rsize+4 <= (heapfile->rspace))
                {
                    (heapfile->nrecords)++;
                    (heapfile->v).push_back(pkey);
                     heapfile->rspace = (heapfile->rspace) - rsize - 4;
                     npages++;
                }
            }
            else
            {
               while(heapfile->next!=nullptr)
               {
                   if(rsize+4 <= (heapfile->rspace))
                   {
                        (heapfile->nrecords)++;
                        (heapfile->v).push_back(pkey);
                         heapfile->rspace = (heapfile->rspace) - rsize - 4;
                         break;
                   }
                   heapfile = heapfile->next;
               }
               if(heapfile->next==nullptr)
               {

                    if(rsize+4 <= (heapfile->rspace))
                    {
                        (heapfile->nrecords)++;
                        (heapfile->v).push_back(pkey);
                         heapfile->rspace = (heapfile->rspace) - rsize - 4;

                    }
                    else
                    {

                        node* newnode = new node;
                        heapfile->next = newnode;
                        newnode->next = nullptr;
                        newnode->prev = heapfile;
                        heapfile = newnode;
                        heapfile->pagesize = spage;
                        heapfile->rspace = spage-16;
                        heapfile->nrecords=0;
                        heapfile->pageid = (heapfile->prev->pageid)+1;
                        (heapfile->nrecords)++;
                        (heapfile->v).push_back(pkey);
                        heapfile->rspace = (heapfile->rspace) - rsize - 4;
                        npages++;

                    }
               }

            }
            heapfile = head;
        }
        if(inp==3)
        {
            int prkey;
            cin >> prkey;
            int pid = -1;
            int sid = -1;
            while(heapfile!=nullptr)
            {
                for(int i=0;i<heapfile->v.size();i++)
                {
                    if(heapfile->v[i]==prkey)
                    {
                        pid = heapfile->pageid;
                        sid = i;
                        break;
                    }
                }
                if(pid!= -1 && sid!=-1)
                {
                    break;
                }
                heapfile = heapfile->next;
            }
            cout << pid << " " << sid << endl;
            heapfile = head;
        }
        cin >> inp;

    }

    return 0;
}
