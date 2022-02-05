#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
	node(){
		this->data=0;
		this->next=NULL;
	}
	node(const int data){
		this->data=data;
		this->next=NULL;
	}
};
class linkedlist{
	public:
		node *head;
		node *tail;
		
	linkedlist(){
		this->head=NULL;
	}
	void addnodeFront(){   
			int n;
			cout<<"Please enter data of node to insert at the start\n";
			cin>>n;
			node *temp = new node();
			if (head == NULL) {
				temp->data=n;                    	                                       //prepend
				temp->next=NULL;   
				head=temp;
			}
			 else {
				node *another = head;
				temp->data = n;
				temp->next = another;
				head = temp;
			}
		
    }    
	void addnodeEnd(){   //append
	    int n;
		cout<<"Enter data of node to insert at the end\n";
		cin>>n;
		node *temp = new node();
		temp->data=n;
		temp->next=NULL;    
	    if(head==NULL){
			cout<<"Linked list does not exist\n"; 
			head=temp;                                      
		}   
		else{  
			node *ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=NULL;
	    }
	}
	void addnodeBetween(){
	    int n;
		cout<<"Enter data of node to insert\n";
		cin>>n;
		int count;
		cout<<"Enter index at which u want to add node \n";
		cin>>count;
		node *temp = new node();
		temp->data=n;
		temp->next=NULL;
		if(head==NULL){
			cout<<"Linked list does not exist\n";
			head=temp;	
		}
		else if(head->next==NULL){
			temp->next=head;
			head=head->next;
		}
		else{
			node *prev=head;
			node*curr=head;
			while(count!=1){
		   		prev=curr;
		   		curr=curr->next;
		   		count--;
			}
		   	 prev->next=temp;
		   	 temp->next=curr;
			}
	}
	void deleteBetween(){
		int index;
		cout<<"Enter index which u want to delete\n";
		cin>>index;
		node *curr=head;
		node *prev=head;
		if(head==NULL){
			cout<<"Linked list does not exist\n";
		}
		else if(index==1){
		   head=curr->next;
		   delete head;
		   head=NULL;
	    }
	    else{
	   	while(index!=1){
	   		prev=curr;
	   		curr=curr->next;
	   		index--;
		   }
	   	 prev->next=curr->next;
	   	 delete curr;
	   	 curr=NULL;
	   }
	}
	void deleteEnd(){  
		if(head==NULL){
			cout<<"Linked list does not exist\n";
		}
		else if(head->next==NULL){
			delete head;
		}
		else{
			node *curr=head;
			node *prev=head;
			while(curr->next!=NULL){
				prev=curr;
				curr=curr->next;
			}
			prev->next=NULL;
			delete curr;
		}
	}
	void deleteStart(){
		if(head==NULL){
			cout<<"Linked list does not exist\n";
		}
		else if(head->next==NULL){
			delete head;
		}
		else{
			node *temp=head;
			head=head->next;
			delete temp;
	    }
	}
	void traverse(){
		node *ptr=head; 
		cout<<"\nNodes\n";
			while(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
			cout<<endl;
	    }
	
	void update(){
		int value=0;int pos=0;
		if(head==NULL){
			cout<<"Link list does not exist\n";
		}
		else{
			cout<<"Enter index of node u want to update\n";
			cin>>pos;
		    cout<<"Enter data of node to update \n";
		    cin>>value;
		    node *s=head;
		    if(pos==1){
		    	head->data=value;
			}
			else{
			   for(int i=0;i<(pos-1);i++){
			   	if(s==NULL){
			   		cout<<"Node of desired position is not present\n";
				   }
				   s=s->next;
			   }
			   s->data=value;
			}
			cout<<"\nNode updated\n";
		}
	}
};
int main(){
	linkedlist obj;
	int ch=0;
	cout<<"\n***********************CHOOSE YOUR OPTION***************************\n";
	while(1){
	cout<<endl;
	cout<<"1.ADD AT FRONT \n";
	cout<<"2.ADD AT ANY POSITION \n";
	cout<<"3.ADD AT END \n";
	cout<<"4.Display \n";
	cout<<"5.DELETE AT END \n";
	cout<<"6.DELETE AT ANY POSITION \n";
	cout<<"7.DELETE AT START \n";
	cout<<"8.UPDATE AT ANY POSITION \n\n";
	cin>>ch;
	cout<<endl;
	switch(ch){
		case 1:{
	      obj.addnodeFront();
	      break;
	    }
	    case 2:{
	    	obj.addnodeBetween();
			break;
		}
	    case 3:{
		  obj.addnodeEnd();
	      break;
	    }
	    case 4:{
	      obj.traverse();
	      break;
	    }
		case 5:{
	       obj.deleteEnd();
	       break;
	    }
		case 6:{
	        obj.deleteBetween();
	        break;
	    }
		case 7:{
	      obj.deleteStart();
	      break;
	    }
		case 8:{
			obj.update();
			break;
	    }
     }
    }
}
