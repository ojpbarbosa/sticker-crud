#include <sticker.h>
#include <string.h>

// constructors and destructors
Sticker::Sticker() : player_name(NULL), birth_date(NULL), national_team(NULL), joined_year(NULL), player_weight(0), player_height(0)
{
}

Sticker::Sticker(
    char *player_name,
    char *birth_date,
    char *national_team,
    unsigned int *joined_year,
    float player_weight,
    float player_height) : player_name(player_name), birth_date(birth_date), national_team(national_team), joined_year(joined_year), player_weight(player_weight), player_height(player_height)
{
}

Sticker::~Sticker()
{
  // free attributes from memory
  delete[] player_name;
  delete[] birth_date;
  delete[] national_team;
  delete joined_year;
}

char *Sticker::to_string()
{
}
