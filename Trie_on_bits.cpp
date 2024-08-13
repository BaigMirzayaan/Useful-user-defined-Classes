class Node{
public: 
    Node* bit[2];
    bool flag = false;
    Node(){
        bit[0] = NULL; bit[1] = NULL;
    }
    bool contain(int bit_value){
        return bit[bit_value] == NULL ? false : true;
    }
    void put(int bit_value, Node* node){
        bit[bit_value] = node;
    }
    Node* get(int bit_value){
        return bit[bit_value];
    }
    void setEnd(){
        flag = true;
    }
};
