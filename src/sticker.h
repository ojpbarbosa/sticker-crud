#ifndef Sticker
#define Sricker

class Sticker
{
private:
  static char *player;
  static char *team;
  static char *field_position;
  static char *birthday;

  static float weight;
  static float height;

public:
  static char *toString();
};

#endif