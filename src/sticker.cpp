#include "sticker.h"
#include <string>
#include <sstream>

using namespace std;

// constructors and destructors
Sticker::Sticker() : player_name(""),
                     birth_date(""),
                     national_team(""),
                     joined_year(0),
                     player_weight(0.0),
                     player_height(0.0)
{
}

Sticker::Sticker(
    string player_name,
    string birth_date,
    string national_team,
    unsigned int joined_year,
    float player_weight,
    float player_height) : player_name(player_name),
                           birth_date(birth_date),
                           national_team(national_team),
                           joined_year(joined_year),
                           player_weight(player_weight),
                           player_height(player_height)
{
}

Sticker::~Sticker()
{
}

string Sticker::to_string(Sticker *sticker)
{
  stringstream ss;

  ss << "Player name: " << sticker->player_name << endl;
  ss << "Birth date: " << sticker->birth_date << endl;
  ss << "National team: " << sticker->national_team << endl;
  ss << "Joined year: " << sticker->joined_year << endl;
  ss << "Player weight: " << sticker->player_weight << endl;
  ss << "Player height: " << sticker->player_height << endl;

  return ss.str();
}

ostream &operator<<(ostream &os, const Sticker &sticker)
{
  return os << Sticker::to_string((Sticker *)&sticker);
}
