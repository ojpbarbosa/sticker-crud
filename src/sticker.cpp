#include "sticker.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define throw(...)

// constructors and destructor
Sticker::Sticker() noexcept : id(0), foil(false), player({"", "", "", 0, 0.0, 0.0})
{
}

Sticker::Sticker(
    unsigned int id,
    bool foil,
    string player_name,
    string birth_date,
    string national_team,
    unsigned int joined_year,
    float player_weight,
    float player_height) throw(invalid_argument)
{
  this->set_id(id);
  this->set_foil(foil);
  this->set_player_name(player_name);
  this->set_player_birth_date(birth_date);
  this->set_player_national_team(national_team);
  this->set_player_joined_year(joined_year);
  this->set_player_weight(player_weight);
  this->set_player_height(player_height);
}

Sticker::~Sticker() noexcept
{
}

// getters
unsigned int Sticker::get_id() const
{
  return this->id;
}

bool Sticker::get_foil() const
{
  return this->foil;
}

string Sticker::get_player_name() const
{
  return this->player.name;
}

string Sticker::get_player_birth_date() const
{
  return this->player.birth_date;
}

string Sticker::get_player_national_team() const
{
  return this->player.national_team;
}

unsigned int Sticker::get_player_joined_year() const
{
  return this->player.joined_year;
}

float Sticker::get_player_weight() const
{
  return this->player.weight;
}

float Sticker::get_player_height() const
{
  return this->player.height;
}

// setters
void Sticker::set_id(unsigned int id) throw(invalid_argument)
{
  if (id < 0)
  {
    throw invalid_argument("ID tem que ser maior que 0!");
  }

  this->id = id;
}

void Sticker::set_foil(bool foil) throw(invalid_argument)
{
  if (foil != true && foil != false)
  {
    throw invalid_argument("Brilhante tem que ser true ou false!");
  }

  this->foil = foil;
}

void Sticker::set_player_name(string player_name) throw(invalid_argument)
{
  if (player_name.empty())
  {
    throw invalid_argument("Nome do jogador não pode ser vazio!");
  }

  if (player_name.length() > 71)
  {
    throw invalid_argument("Nome do jogador tem que ter no máximo 70 caracteres!");
  }

  this->player.name = player_name;
}

void Sticker::set_player_birth_date(string birth_date) throw(invalid_argument)
{
  if (birth_date.empty())
  {
    throw invalid_argument("Data de nascimento do jogador não pode ser vazia!");
  }

  if (birth_date.length() != 10)
  {
    throw invalid_argument("Data de nascimento do jogador tem que ter 10 caracteres!");
  }

  if (birth_date.length() != 10 || birth_date[2] != '-' || birth_date[5] != '-')
  {
    throw invalid_argument("Data de nascimento do jogador tem que estar no formato dd-mm-aaaa!");
  }

  if (birth_date[0] < '0' || birth_date[0] > '3' || birth_date[1] < '0' || birth_date[1] > '9')
  {
    throw invalid_argument("Dia de nascimento do jogador tem que estar entre 01 e 31!");
  }

  if (birth_date[3] < '0' || birth_date[3] > '1' || birth_date[4] < '0' || birth_date[4] > '9')
  {
    throw invalid_argument("Mês de nascimento do jogador tem que estar entre 01 e 12!");
  }

  this->player.birth_date = birth_date;
}

void Sticker::set_player_national_team(string national_team) throw(invalid_argument)
{
  if (national_team.empty())
  {
    throw invalid_argument("Seleção do jogador não pode ser vazio!");
  }

  if (national_team.length() > 31)
  {
    throw invalid_argument("Seleção do jogador tem que ter no máximo 30 caracteres!");
  }

  this->player.national_team = national_team;
}

void Sticker::set_player_joined_year(unsigned int joined_year) throw(invalid_argument)
{
  if (joined_year < 0)
  {
    throw invalid_argument("Ano de ingresso do jogador tem que ser maior que 0!");
  }

  this->player.joined_year = joined_year;
}

void Sticker::set_player_weight(float player_weight) throw(invalid_argument)
{
  if (player_weight < 0)
  {
    throw invalid_argument("Peso do jogador tem que ser maior que 0!");
  }

  this->player.weight = player_weight;
}

void Sticker::set_player_height(float player_height) throw(invalid_argument)
{
  if (player_height < 0)
  {
    throw invalid_argument("Altura do jogador tem que ser maior que 0!");
  }

  this->player.height = player_height;
}

void Sticker::read_register(fstream &file, int offset) noexcept
{
  file.seekg(offset * Sticker::REGISTER_SIZE, ios::beg);

  file.read((char *)&this->id, sizeof(unsigned int));
  file.read((char *)&this->foil, sizeof(bool));

  char player_name[71];
  file.read(player_name, sizeof(char) * 71);
  this->player.name = player_name;

  char birth_date[11];
  file.read(birth_date, sizeof(char) * 11);
  this->player.birth_date = birth_date;

  char national_team[31];
  file.read(national_team, sizeof(char) * 31);
  this->player.national_team = national_team;

  file.read((char *)&this->player.joined_year, sizeof(int));
  file.read((char *)&this->player.weight, sizeof(float));
  file.read((char *)&this->player.height, sizeof(float));
}

void Sticker::write_register(fstream &file) const
{
  file.write((char *)&this->id, sizeof(int));
  file.write((char *)&this->foil, sizeof(bool));
  file.write(this->player.name.c_str(), sizeof(char) * 71);
  file.write(this->player.birth_date.c_str(), sizeof(char) * 11);
  file.write(this->player.national_team.c_str(), sizeof(char) * 31);
  file.write((char *)&this->player.joined_year, sizeof(int));
  file.write((char *)&this->player.weight, sizeof(float));
  file.write((char *)&this->player.height, sizeof(float));
}

ostream &operator<<(ostream &os, const Sticker &sticker)
{
  os << "==== Figurinha ====" << endl;
  os << "ID................: " << sticker.id << endl;
  os << "Dourada...........: " << ((sticker.foil) ? "Sim" : "Não") << endl;
  os << "===== Jogador =====" << endl;
  os << "Nome..............: " << sticker.player.name << endl;
  os << "Data de nascimento: " << sticker.player.birth_date << endl;
  os << "Seleção...........: " << sticker.player.national_team << endl;
  os << "Ano de ingresso...: " << sticker.player.joined_year << endl;
  os << "Peso..............: " << sticker.player.weight << "kg" << endl;
  os << "Altura............: " << sticker.player.height << "m" << endl;

  return os;
}
