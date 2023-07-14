// sherpa-onnx/csrc/online-transducer-model-config.h
//
// Copyright (c)  2023  Xiaomi Corporation
#ifndef SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_MODEL_CONFIG_H_
#define SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_MODEL_CONFIG_H_

#include <string>

#include "sherpa-onnx/csrc/parse-options.h"

namespace sherpa_onnx {

struct OnlineTransducerModelConfig {
  std::string encoder_filename;
  std::string decoder_filename;
  std::string joiner_filename;
  std::string tokens;
  int32_t num_threads = 2;
  bool debug = false;
  std::string provider = "cpu";

  // With the help of this field, we only need to load the model once
  // instead of twice; and therefore it reduces initialization time.
  //
  // Valid values:
  //  - conformer
  //  - lstm
  //  - zipformer
  //  - zipformer2
  //
  // All other values are invalid and lead to loading the model twice.
  std::string model_type;

  OnlineTransducerModelConfig() = default;
  OnlineTransducerModelConfig(const std::string &encoder_filename,
                              const std::string &decoder_filename,
                              const std::string &joiner_filename,
                              const std::string &tokens, int32_t num_threads,
                              bool debug, const std::string &provider,
                              const std::string &model_type)
      : encoder_filename(encoder_filename),
        decoder_filename(decoder_filename),
        joiner_filename(joiner_filename),
        tokens(tokens),
        num_threads(num_threads),
        debug(debug),
        provider(provider),
        model_type(model_type) {}

  void Register(ParseOptions *po);
  bool Validate() const;

  std::string ToString() const;
};

}  // namespace sherpa_onnx

#endif  // SHERPA_ONNX_CSRC_ONLINE_TRANSDUCER_MODEL_CONFIG_H_
