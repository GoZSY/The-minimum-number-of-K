/**************************************************************
利用快排的思想找到前K个最小的数字，复杂度为O（n）
***************************************************************/
class Solution {
public:
    void Swap(int &x,int &y)
    {
        int temp = x;
        x=y;
        y=temp;
    }
    int Partition(vector<int> &numbers, int length, int start, int end)
    {
        if(numbers.size()<1 || length < 0 || start < 0 || end >= length) 
            return 0;
        int index = rand()%(end-start+1)+start;
        Swap(numbers[index],numbers[end]);
         
        int small = start -1;
        for(index = start;index < end; ++index)
            if(numbers[index] < numbers[end])
            {
                ++ small;
                if(small != index)
                    Swap(numbers[index],numbers[small]);
            }
        ++small;
        Swap(numbers[small],numbers[end]);
        return small;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> output;
        int length = input.size();
        if(length < 1 || k <=0 || k > length)
            return output;
        int start = 0;
        int end = length -1;
        int index = Partition(input,length,start,end);
        while(index != k-1)
        {
            if(index > k-1)
            {
                end = index - 1;
                index = Partition(input,length,start,end);
            }
            else
            {
                start = index + 1;
                index = Partition(input,length,start,end);
            }
        }
       for(int i = 0; i < k; ++i)
           output.push_back(input[i]);
        return output;
    }
};
/*******************************************************
利用长度为K的最大堆实现O（nlog(k)）
********************************************************/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        maxHeap(input,k);
        vector<int> result;
        if(intSet.size()==0)
            return result;
        setIterator = intSet.end();
        setIterator--;
        for(int i = 0;i < k;i++,setIterator--)
        {
            result.push_back(*setIterator);
        }
        return result;
    }
private:
    multiset<int, greater<int> > intSet;
    multiset<int, greater<int> >::iterator setIterator;
    void maxHeap(vector<int> input,int k)
    {
        intSet.clear();
        if(k < 1 || input.size() < k)
            return;
        for(int i = 0; i < input.size(); ++i)
        {
            if(static_cast<int>(intSet.size()) < k)
                intSet.insert(input[i]);
            else
            {
                setIterator = intSet.begin();
                if(input[i] < *(intSet.begin()))
                {
                    intSet.erase(setIterator);
                    intSet.insert(input[i]);
                }
            }
        }
    }
};
