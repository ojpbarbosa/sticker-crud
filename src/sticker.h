#ifndef STICKER_H
#define STICKER_H

#include <fstream>

using namespace std;

#define throw(...)

class Sticker
{
private:
  unsigned int id;
  bool foil;
  struct
  {
    string name;
    string birth_date;
    string national_team;
    unsigned int joined_year;
    float weight;
    float height;
  } player;

public:
  static const size_t REGISTER_SIZE =
      sizeof(unsigned int) + sizeof(bool) + sizeof(char) * 71 + sizeof(char) * 11 + sizeof(char) * 31 + sizeof(unsigned int) + 2 * sizeof(float);

  // getters
  unsigned int get_id() const;
  bool get_foil() const;
  string get_player_name() const;
  string get_player_birth_date() const;
  string get_player_national_team() const;
  unsigned int get_player_joined_year() const;
  float get_player_weight() const;
  float get_player_height() const;

  // setters
  void set_id(unsigned int) throw(invalid_argument);
  void set_foil(bool) throw(invalid_argument);
  void set_player_name(string) throw(invalid_argument);
  void set_player_birth_date(string) throw(invalid_argument);
  void set_player_national_team(string) throw(invalid_argument);
  void set_player_joined_year(unsigned int) throw(invalid_argument);
  void set_player_weight(float) throw(invalid_argument);
  void set_player_height(float) throw(invalid_argument);

  // constructors and destructor
  Sticker() noexcept;
  Sticker(unsigned int, bool, string, string, string, unsigned int, float, float) throw(invalid_argument);
  ~Sticker() noexcept;

  void read_register(fstream &, int) noexcept;
  void write_register(fstream &) const;

  friend ostream &operator<<(ostream &, const Sticker &);
};

#endif
