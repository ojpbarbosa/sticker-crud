#ifndef STICKER_H
#define STICKER_H

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Sticker
{
private:
  static const size_t REGISTER_SIZE =
      sizeof(char) * 3 + sizeof(unsigned int) + sizeof(float) * 2;

  // string attributes
  string player_name;
  string birth_date;
  string national_team;

  // int attributes
  unsigned int joined_year;

  // float attributes
  float player_weight;
  float player_height;

  static string to_string(Sticker *sticker);

public:
  // constructors and destructors
  Sticker();
  Sticker(string, string, string, unsigned int, float, float);
  ~Sticker();

  void *read_register(FILE *file, int offset);
  void write_register(FILE *file);

  // override
  int compare(Sticker sticker);

  friend ostream &operator<<(ostream &, const Sticker &);
};

#endif
