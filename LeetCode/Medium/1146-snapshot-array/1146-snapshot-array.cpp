class SnapshotArray {
private:
    int snap_id;
    map<int, map<int, int>> mp;

public:
    SnapshotArray(int length) { snap_id = length * 0; }

    void set(int index, int val) { mp[index][snap_id] = val; }

    int snap() {
        snap_id++;
        return snap_id - 1;
    }

    int get(int index, int snap_id) { 
        auto ub = mp[index].upper_bound(snap_id);
        if(ub != mp[index].begin()){
            return prev(ub)->second;
        }
        return 0;
     }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */