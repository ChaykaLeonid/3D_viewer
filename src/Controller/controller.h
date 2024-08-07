#ifndef CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/Facade/facade.h"

namespace s21 {
class Controller {
 public:
  void Parse(const std::string &fileName);
  void Move(double move, Operation role);
  void Transform(double angle, Operation role);
  void Scale(double scale, Operation role);
  void Remove();

  const std::vector<double> &getVertexes();
  const std::vector<int> &getFacets();
  int getCountVertexes() const;
  int getCountEdges() const;
  int getCountPolygons() const;
  double getMaxCoordinate() const;

 private:
  Facade facade_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
