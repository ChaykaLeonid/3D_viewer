#include "affine.h"

namespace s21 {

void Affine::Move(Figure &figure, double move, int coordinate) {
  std::vector<double> tmp = figure.GetVertexes();
  for (size_t i = 0; i < size_t(figure.GetCountVertexes()); i++) {
    tmp.at(i * 3 + coordinate) += move;
  }
  figure.SetVertexes(tmp);
}

void Affine::Transform(Figure &figure, double angle, int coordinate) {
  std::vector<double> tmp = figure.GetVertexes();
  for (size_t i = 0; i < size_t(figure.GetCountVertexes()); i++) {
    double x = tmp.at(i * 3);
    double y = tmp.at(i * 3 + 1);
    double z = tmp.at(i * 3 + 2);
    if (coordinate == kX) {
      tmp.at(i * 3 + 1) = cos(angle) * y - sin(angle) * z;
      tmp.at(i * 3 + 2) = sin(angle) * y + cos(angle) * z;
    } else if (coordinate == kY) {
      tmp.at(i * 3) = cos(angle) * x + sin(angle) * z;
      tmp.at(i * 3 + 2) = (-sin(angle)) * x + cos(angle) * z;
    } else if (coordinate == kZ) {
      tmp.at(i * 3) = cos(angle) * x - sin(angle) * y;
      tmp.at(i * 3 + 1) = sin(angle) * x + cos(angle) * y;
    }
  }
  figure.SetVertexes(tmp);
}

void Affine::Scale(Figure &figure, double scale, int coordinate) {
  std::vector<double> tmp = figure.GetVertexes();
  int i = coordinate;
  if (coordinate == kAll) {
    i = 0;
  }
  while (i < (static_cast<int>(figure.GetCountVertexes()) * 3)) {
    tmp.at(i) *= scale;
    if (coordinate == kAll) {
      i++;
    } else {
      i += 3;
    }
  }
  figure.SetVertexes(tmp);
}
}  // namespace s21
