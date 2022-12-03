#include <sticker.h>
#include <string.h>

// constructors and destructors
Sticker::Sticker()
{
  Sticker::player_name = "";
  Sticker::birth_date = "";
  Sticker::national_team = "";
  Sticker::joined_year = 0;
  Sticker::player_weight = 0.0;
  Sticker::player_height = 0.0;
}

Sticker::Sticker(
    char *player_name,
    char *birth_date,
    char *national_team,
    unsigned int *joined_year,
    float player_weight,
    float player_height)
{
  // allocate memory for attributes
  Sticker::player_name = new char[strlen(player_name) + 1];
  Sticker::birth_date = new char[strlen(birth_date) + 1];
  Sticker::national_team = new char[strlen(national_team) + 1];
  Sticker::joined_year = new unsigned int;

  // copy values to attributes
  strcpy(Sticker::player_name, player_name);
  strcpy(Sticker::birth_date, birth_date);
  strcpy(Sticker::national_team, national_team);

  *Sticker::joined_year = *joined_year;
  Sticker::player_weight = player_weight;
  Sticker::player_height = player_height;
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
