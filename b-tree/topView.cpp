#include <iostream>
#include <map>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    int level;
    int range;
}TNODE;

std::map<int, TNODE*> gMtopViewMap;
int minRange = 0, maxRange = 0;

TNODE *create_t_node(int data){
    TNODE *tnode = (TNODE*)calloc(sizeof(TNODE), 1);
    tnode->data = data;
}

void topViewMap(TNODE *root, int level, int range){
    if(root == NULL) return;
    
    root->level = level;
    root->range = range;
    
  //  std::cout<<" level:"<<level<<" , range:"<<range<<", data:"<<root->data<<", level:"<<level<<std::endl;
    
    if(gMtopViewMap.find(range) == gMtopViewMap.end()){
        
    //    std::cout<<" adding to map:"<< range<<std::endl;
        if(range < minRange) minRange = range;
        if(range > maxRange) maxRange = range;
        
        gMtopViewMap.insert(std::pair<int, TNODE*>(range, root));
        
    }else{
        std::map<int, TNODE*>::iterator it = gMtopViewMap.find(range);
        
        if(it->second->level > level){
            it->second = root;
        }
        
    }
    
    topViewMap(root->left, level+1, range+1);
    topViewMap(root->right, level+1, range-1);
}

void displayTopView(){
    
    int i;
   // std::cout<<" maxRange:"<<maxRange<<" minRange:"<<minRange<<std::endl;
    for(i = maxRange; i>=minRange; i--){
        std::map<int, TNODE*>::iterator it = gMtopViewMap.find(i);
        std::cout<< it->second->data << " ";
    }

}

int main(){
    
    TNODE *head = create_t_node(1);
    head->left = create_t_node(2);
    head->right = create_t_node(3);
    head->left->right = create_t_node(4);
    head->left->right->right = create_t_node(5);
    head->left->right->right->right = create_t_node(6);
    /*
    head->left->left = create_t_node(4);
    head->left->right = create_t_node(5);
    head->right->left = create_t_node(6);
    head->right->right = create_t_node(7);
    */
    topViewMap(head, 0, 0);
    displayTopView();
    
    return 0;
}