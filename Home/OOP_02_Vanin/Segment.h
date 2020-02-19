// Developed by Danylo Vanin, SE-2, 3 Group
// on 25.01.2020
// Version 1.0

//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//  Developed by Danylo Vanin
//  at 25.01.20
//  Version 1.0
//*******************************************

#include "Point.h"

// Segment class
class Segment
{
private:
    // ID
    static int _freeID;
    const int _myId;
    // Start point
    Point _a;
    // End point
    Point _b;
public:
    // Default/coordinates constructor
    Segment(const double x1 = 0, const double y1 = 0,
        const double x2 = 1, const double y2 = 0);
    // Constructor with points
    Segment(const Point& start, const Point& end);
    // Copy constructor
    Segment(const Segment&);
    // Desctructor
    ~Segment();
    // Copying operator
    Segment& operator=(const Segment&);

    // Points selector
    const Point& start() const { return _a; };
    const Point& end() const { return _b; };
    // Points selector-modifier
    Point& start() { return _a; };
    Point& end() { return _b; };
    // Points coordinates selector
    const double& startX() const { return _a.x(); };
    const double& startY() const { return _a.y(); };
    const double& endX() const { return _b.x(); };
    const double& endY() const { return _b.y(); };
    // Points coordinates selector-modifier
    double& startX() { return _a.x(); };
    double& startY() { return _a.y(); };
    double& endX() { return _b.x(); };
    double& endY() { return _b.y(); };

    // Legth of segment
    double length() const;
    // Distance from point to segment
    double distance(const Point&) const;
    // ID selector
    const int getID() const { return _myId; };
};

ostream& operator<<(ostream&, const Segment&);

// Distance from Segment ot Point
double distance(const Segment&, const Point&);