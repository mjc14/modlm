#pragma once

#include <iostream>
#include <string>
#include <modlm/sentence.h>
#include <modlm/dist-base.h>

namespace modlm {

// A class for the n-gram distribution
class DistUniform : public DistBase {

public:

  // Signature should be of the form "uniform"
  DistUniform(const std::string & sig);
  virtual ~DistUniform() { }

  // Get the signature of this class that uniquely identifies it for loading
  // at test time. In other words, the signature can collapse any information
  // only needed at training time.
  virtual std::string get_sig() const override { return "uniform"; }

  // Add stats from one sentence at training time for count-based models
  virtual void add_stats(const Sentence & sent) override { }

  // Get the number of ctxtual features we can expect from this model
  virtual size_t get_ctxt_size() const override { return 0; } 
  // And calculate these features
  virtual void calc_ctxt_feats(const Sentence & ctxt, WordId held_out_wid, float * feats_out) const override { }

  // Get the number of distributions we can expect from this model
  virtual size_t get_dense_size() const override { return 1; }
  virtual size_t get_sparse_size() const override { return 0; }
  // And calculate these features given ctxt, for words wids. uniform_prob
  // is the probability assigned in unknown ctxts. leave_one_out indicates
  // whether we should subtract one from the counts for cross-validation.
  // prob_out is the output, which should be incremented after writing.
  virtual void calc_word_dists(const Sentence & ctxt,
                               const Sentence & wids,
                               float uniform_prob,
                               bool leave_one_out,
                               std::vector<TrainingTarget> & trgs,
                               int & dense_offset,
                               int & sparse_offset) const override;

  // Read/write model. If dict is null, use numerical ids, otherwise strings.
  virtual void write(DictPtr dict, std::ostream & str) const override { }
  virtual void read(DictPtr dict, std::istream & str) override { }

protected:

};

}