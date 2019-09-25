#ifndef METEOR_CORE_TEX_POOL_H_
#define METEOR_CORE_TEX_POOL_H_
#include <deque>
#include <memory>
#include "ll_graphic/engine/engine.h"
#include "meteor/core/loader.h"

class TexPool {
 public:
  TexPool(ll::engine::Env *env, ll::engine::core::Renderer *renderer, int width,
          int height, int cmode);
  ~TexPool();

  void *GetTexID();

  void Update(char *data);

 private:
  ll::engine::Env *env_;
  ll::engine::core::Renderer *rdr_;
  ll::engine::core::Texture *tex_;
  std::deque<ll::engine::core::Texture *> stg_;
};

#endif  // METEOR_CORE_TEX_POOL_H_
