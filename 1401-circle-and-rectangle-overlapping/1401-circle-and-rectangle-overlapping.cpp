class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       int NearX = max(x1, min(x2,xCenter));
       int NearY = max(y1, min(y2,yCenter));

       int DistancefromX = xCenter - NearX;
       int DistancefromY = yCenter - NearY;

       return DistancefromX*DistancefromX + DistancefromY*DistancefromY <= pow(radius,2); 
    }
};