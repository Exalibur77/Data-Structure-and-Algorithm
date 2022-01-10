template <typename T>

class vector{

private:
    T * arr;
    int curr_size;
    int max_size;

public:
    // Constructor
    vector(){
        curr_size=0;
        max_size=1;
        arr=new T[max_size];
    }

    void push_back(const T val){
        // Two Cases

        if(curr_size == max_size){
            // Create a new array and delete the previous one, double the capacity

            T *oldArr=arr;
            max_size=2*max_size;
            arr=new T[max_size];
            // Copy the elements to the new arr from old array

            for (int i = 0; i < curr_size; i++)
            {
                arr[i]=oldArr[i];
            }

            // Deletion of old Array
            
            delete []oldArr;

        }

        arr[curr_size]=val;
        curr_size++;

    }

    // cant make this function constant because class variable is being changed it is not constant
    void pop_back(){
        if(curr_size>0){
            curr_size--;
        }
    }

    bool isEmpty() const{
        return curr_size==0;
    }

    // Front , back , at(i), operator overloading

    T front() const{
        return arr[0];
    }

    T back() const{
        return arr[curr_size-1];
    }

    T at(const int i) const{
        return arr[i];
    }

    int size() const{
        return curr_size;
    }

    int capacity() const{
        return max_size;
    }

    // operator overloading
    // int i is now constant and given function is also constant as our function is not changing our class members.

    T operator[](const int i) const{
        return arr[i];
    }


};