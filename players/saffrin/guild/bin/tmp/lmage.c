#include "/players/saffrin/guild/defs.h"

int main(string str) {
  if(str) {
    TP->guild_line(str);
    return 1;
  }
  else
  {
    write("Usage: lmage <message>\n");
    return 1;
  }
}
