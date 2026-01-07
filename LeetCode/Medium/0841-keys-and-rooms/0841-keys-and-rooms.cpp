class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> roomsToVisit;
        vector<bool> hasVisitedRoom(rooms.size(), false);

        roomsToVisit.push(0);
        hasVisitedRoom[0] = true;
        while (!roomsToVisit.empty()) {
            int currentRoomIndex = roomsToVisit.front();
            roomsToVisit.pop();
            for (int keyToOtherRoom : rooms[currentRoomIndex]) {
                if (!hasVisitedRoom[keyToOtherRoom]) {
                    hasVisitedRoom[keyToOtherRoom] = true;
                    roomsToVisit.push(keyToOtherRoom);
                }
            }
        }
        for (bool visited : hasVisitedRoom) {
            if (!visited) {
                return false;
            }
        }
        return true;
    }
};
