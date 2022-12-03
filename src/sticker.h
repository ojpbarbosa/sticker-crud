#include <stdio.h>

#ifndef STICKER
#define STICKER

class Sticker
{
private:
  static const size_t REGISTER_SIZE =
      sizeof(char) * 3 + sizeof(unsigned int) + sizeof(float) * 2;

  // char attributes
  char *player_name;
  char *birth_date;
  char *national_team;

  // int attributes
  unsigned int *joined_year;

  // float attributes
  float player_weight;
  float player_height;

public:
  // constructors and destructors
  Sticker();
  Sticker(char *, char *, char *, unsigned int *, float, float);
  ~Sticker();

  // see BinaryReader equivalent
  Sticker *read_register(FILE *file);
  // see BinaryWriter equivalent
  void write_register(FILE *file);

  // overrides
  int compare(Sticker *sticker);
  char *to_string();
};

#endif
