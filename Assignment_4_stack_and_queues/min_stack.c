
 
long long int minEle = -1 ;


typedef struct {
    int top;
    long long int arr[10000];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    static MinStack stack;
    stack.top = -1;
    return &stack;
}

void minStackPush(MinStack* obj, long long int val) {
    if(obj->top == -1)
    {
        obj->top++;
        obj->arr[obj->top] = val;
        minEle = val;
    }
    else
    {
        if(val >= minEle)
        {
            obj->top++;
            obj->arr[obj->top] = val;
        }
        else if(val < minEle)
        {
            obj->top++;
            obj->arr[obj->top] = 2*val - minEle;
            minEle = val;
        }
            
    }
}

void minStackPop(MinStack* obj) {
    long long int y;
    if(obj->arr[obj->top] >= minEle)
    {
        y = obj->arr[obj->top];
        obj->top--;
    }
    else if(obj->arr[obj->top] < minEle)
    {
        y = minEle;
        minEle = 2*minEle - obj->arr[obj->top];
        obj->top--;
    
    }
        
}

int minStackTop(MinStack* obj) {
    if(obj->arr[obj->top] >= minEle)
    {
        return obj->arr[obj->top];
    }
    else 
    {
        return minEle;
    }
}


int minStackGetMin(MinStack* obj) {
    return minEle;
}

void minStackFree(MinStack* obj) {
    obj->top = -1;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
