#include "/players/waldo/guild/defs.h"

int main(string str) {
  if(str) {
    TP->guild_line(str);
    return 1;
    }
    else
    { write("Usage : mage <message> = guild talk\n");
      write("      : mage/ <message> = guild emote\n");
      write("      : mages = who is on\n");
      return 1;
  }
}
