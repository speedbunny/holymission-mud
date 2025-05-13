#include "/sys/defs.h"

int main(string str) {

    int i;
    string *manuals;

    manuals = ({
                "/doc",
                "/doc/efun/NEWPARSER",
                "/doc/efun",
                "/doc/lfun",
                "/doc/build",
                "/doc/w",
                "/doc/LPC",
                "/doc/rules",
                "/open",
                "/doc/guild",
                "/doc/magik",
                "/doc/abilities",
                "/doc/helpdir"          // keep this last in order !
              });

  if (!str) {
    write("Topics:\n");
    for (i = 0; i < sizeof(manuals); i++)
      write(manuals[i] + " ");
      write("\n");
      return 1;
  }

  str = "/" + str;
  i = 0;

  while(i < sizeof(manuals)) {
    if (file_size(manuals[i] + str) == -2) {
      write("Sub topics " + manuals[i] + str + ":\n");
      ls(manuals[i] + str + "/.");
      return 1;
    }
    if (file_size(manuals[i] + str) > 0) {
      write(manuals[i] + str + ":\n");
      this_player()->more(manuals[i] + str);
      return 1;
    }
    i++;
  }
  write("Not found.\n");

  return 1;
}

