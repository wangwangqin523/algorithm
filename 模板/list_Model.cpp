//�����������뷴�������Բ�������Ϊ�� 
#include<stdio.h>
#include <string.h>
//���ַ�����list
typedef char  Type;
Type str[1000];
typedef  struct Node{
	struct Node * next;
	Type data;
Node():next(NULL){}	
}Node,*List;
Node  node_array[1000];
int loc;//����ڵ�ռ��������λ�� 

List create(){
	node_array[loc++];
	node_array[loc].next=NULL;
	return &node_array[loc];
}

void visit(List list){
	Node * current_point=list;
	while(current_point->next!=NULL)
	   {
		current_point=current_point->next;
	     printf("%c",current_point->data);}
	     printf("\n");
}
//void swap_data(Node *a,Node *b){
//	Type temp=a->data;
//	a->data=b->data;
//	b->data=temp;
//}
//void insert_sort(List &list);
//void select_sort(List &list);
//void quick_sort(List &list);
//void merge_sort(List &list);
//void bubble_sort(List &list);

//void select_sort_swapData(List &list)
//{    
//     if(NULL==list)  return;
//     Node * p_point=list->next;
//     Node * q_point=list->next;
//     Node * position;
//     
//     while(NULL!=p_point){
//     	Type min_data='z';
//     while(NULL!=q_point){
//     	if(q_point->data  <  min_data) {
//     		
//     		min_data=q_point->data;
//     		position=q_point;
//		 }
//  
//     		q_point=q_point->next;
//	 }
//	swap_data(p_point,position);
//	p_point=p_point->next;
//	q_point=p_point;
//	
//}
//}
void create_insert_tail(List &list,Type str[] ){//β��������������ÿ��������������str���� 
	Node * tail_point=list;
	for(int i=0;i<strlen(str);i++)
	{   
	    Node * new_point=create();
		new_point->data=str[i];
		tail_point->next=new_point;
		tail_point=new_point;
	}
	
	
}


void insert_order(List &list,Node * p){//���������������Pָ���һ����� 
	Node * current=list->next;
	Node * previous=list;
	while(1){
	if(current==NULL||current->data > p->data)
	{
		previous->next=p;
		p->next=current;
		return;
	}
	   else{
		previous=current;
		current=current->next;
		   }	
		}
	
	
}

void insert_head(List &list,Node  * p){//��������ͷ�巨����Pָ���һ����� 
    Node * current=list->next;
    list->next=p;
    p->next=current;

}





void insert_sort_order(List &list){//���������� 
	if(NULL==list)  return;
	Node * current=list->next;
	list->next=NULL;
	while(NULL!=current){
		Node * current_bak=current->next;
		insert_order(list,current);
		current=current_bak;
	}
	
	
}


void reverse_list(List &list){//���������� 
	
	Node * current=list->next;
	list->next=NULL;
	while(NULL!=current){
		Node * current_bak=current->next;
		insert_head(list,current);
		current=current_bak;
	}
	
	
	
}
//void insert_head(List &list,Type * str){//ͷ�巨���ַ����������� 
//	for(int i=0;i<strlen(str);i++)
//	{   
//	    Node * new_point=create();
//		new_point->data=str[i];
//		new_point->next=list->next;
//		list->next=new_point;
//	}
//	
//	
//	
//}
//void insert_head(List &list,Type c){//ͷ�巨����һ���ַ� 
//	
//	    Node * new_point=create();
//		new_point->data=c;
//		new_point->next=list->next;
//		list->next=new_point;
//}
//




int main(){
	scanf("%s",&str);
	List list=create();//����һ���ַ�����ͷ���ָ�� 
	create_insert_tail(list,str);//�������� 
	insert_sort_order(list);//���� 
	reverse_list(list);//���� 
	visit(list);//��ӡ 
	return 0;
	
} 
