/*
✅ Max heap
Top = largest
👉 Max heap → DESCENDING

✅ Min heap
Top = smallest
👉 Min heap → ASCENDING
*/
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    void addNum(int num) {
        if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
            leftMaxHeap.push(num);
        } else {
            rightMinHeap.push(num);
        }
        if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        } else if (leftMaxHeap.size() < rightMinHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    double findMedian() {
        if (leftMaxHeap.size() == rightMinHeap.size()) {
            return (leftMaxHeap.top() + rightMinHeap.top()) * 0.5;
        }
        return leftMaxHeap.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */