#include "/sys/defs.h"

int main(string str) {

  if (!str) {
    write("emote what ?\n");
    return 1;
  }
  say(TO->RNAME + " " + str + "\n",0,TO,
      "Someone " + str + "\n");
  write("Ok.\n");

  return 1;
}

