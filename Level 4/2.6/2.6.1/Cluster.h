#include <sstream>

using namespace std;
namespace Cluster {
namespace CAD {
class Point;
class Line;
class Circle;
} // namespace CAD

namespace Containers {
class Array;
}
ostream &operator<<(ostream &os, const Cluster::CAD::Point &p);
ostream &operator<<(ostream &os, const Cluster::CAD::Line &l);
ostream &operator<<(ostream &os, Cluster::CAD::Circle &O);
} // namespace Cluster
