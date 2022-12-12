#ifndef STICKERS_H
#define STICKERS_H

#include <string>
#include "sticker.h"
#include <vector>

using namespace std;

class Stickers
{
private:
  string filename;

public:
  Stickers(string) noexcept;
  ~Stickers() noexcept;

  unsigned int get_next_id() const;
  unsigned int count() const;
  bool is_registered(Sticker *) const;

  void create(Sticker *) const;
  void update(Sticker *) const;
  Sticker *find_by_id(unsigned int) const;
  Sticker *find_by_player_name(string) const;
  vector<Sticker *> find_all() const;
  void exclude(Sticker *) const;
};

#endif
