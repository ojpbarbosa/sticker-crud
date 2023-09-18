#include "stickers.h"
#include <fstream>
#include "sticker.h"
#include <iostream>

using namespace std;

// constructors and destructor
Stickers::Stickers(string filename) noexcept : filename(filename)
{
}

Stickers::~Stickers() noexcept
{
}

unsigned int Stickers::get_next_id() const
{
  unsigned int count = this->count();

  fstream file;
  file.open(this->filename, ios::in);

  Sticker *sticker = new Sticker();
  sticker->read_register(file, count - 1);

  file.close();

  return sticker->get_id() + 1;
}

unsigned int Stickers::count() const
{
  fstream file;
  file.open(this->filename, ios::in);

  if (!file.good())
  {
    return 0;
  }

  file.seekg(0, ios::end);
  unsigned int count = file.tellg() / Sticker::REGISTER_SIZE;
  file.close();

  return count;
}

bool Stickers::is_registered(Sticker *sticker) const
{
  fstream file;
  file.open(this->filename, ios::in);

  int offset = 0;

  while (file.good())
  {
    Sticker *s = new Sticker();
    s->read_register(file, offset++);

    if (s->get_id() == sticker->get_id() || s->get_player_name() == sticker->get_player_name())
    {
      return true;
    }
  }

  file.close();

  return false;
}

void Stickers::create(Sticker *sticker) const
{
  fstream file;
  file.open(this->filename, ios::out | ios::app);
  sticker->write_register(file);
  file.close();
}

void Stickers::update(Sticker *sticker) const
{
  vector<Sticker *> stickers = this->find_all();

  fstream file;
  file.open(this->filename, ios::out);

  for (Sticker *s : stickers)
  {
    if (s->get_id() == sticker->get_id())
    {
      sticker->write_register(file);
    }

    else
    {
      s->write_register(file);
    }
  }

  file.close();
}

Sticker *Stickers::find_by_id(unsigned int id) const
{
  Sticker *sticker = new Sticker();

  fstream file;
  file.open(this->filename, ios::in);

  int offset = 0;

  while (file.good())
  {
    sticker->read_register(file, offset++);

    if (sticker->get_id() == id)
    {
      return sticker;
    }
  }

  file.close();

  return nullptr;
}

Sticker *Stickers::find_by_player_name(string player_name) const
{
  Sticker *sticker = new Sticker();

  fstream file;
  file.open(this->filename, ios::in);

  int offset = 0;

  while (file.good())
  {
    sticker->read_register(file, offset++);

    if (sticker->get_player_name() == player_name)
    {
      return sticker;
    }
  }

  file.close();

  return nullptr;
}

vector<Sticker *> Stickers::find_all() const
{
  vector<Sticker *> stickers;

  fstream file;
  file.open(this->filename, ios::in);

  int offset = 0;

  while (file.good())
  {
    Sticker *sticker = new Sticker();
    sticker->read_register(file, offset++);

    if (sticker->get_id() == 0)
    {
      continue;
    }

    stickers.push_back(sticker);
  }

  file.close();

  return stickers;
}

void Stickers::exclude(Sticker *sticker) const
{
  vector<Sticker *> stickers = this->find_all();

  fstream file;
  file.open(this->filename, ios::out);

  for (Sticker *s : stickers)
  {
    if (s->get_id() == sticker->get_id() || s->get_player_name() == sticker->get_player_name())
    {
      continue;
    }

    s->write_register(file);
  }

  file.close();
}
