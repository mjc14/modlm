#pragma once

#include <vector>
#include <unordered_map>

namespace modlm {

class Whitener {
public:
  Whitener(const std::string & type, float epsilon) : type_(type), epsilon_(epsilon) { }
  // Find the transformation matrix for whitening in Eigen column-major format
  void calc_matrix(const std::vector<std::vector<float> > & data, const std::vector<int> & use_in_training);
  // Perform whitening
  void whiten(std::vector<std::vector<float> > & data);
  void whiten(std::vector<float> & data);
  void save(const std::string & filename) const;
  void load(const std::string & filename);

protected:
  std::string type_;
  float epsilon_;
  std::vector<float> mean_vec_, rotation_vec_;

};

}
