#include "sticker.h"

int main()
{
  Sticker *sticker = new Sticker(
      "Cristiano Ronaldo",
      "5 February 1985",
      "Portugal",
      2003,
      83.0,
      185.0);

  cout << *sticker << endl;

  return 0;
}
