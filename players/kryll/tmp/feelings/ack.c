/* CHANGES :
Date         Wiz          Description
-----------  -----------  ---------------------------------------------------
Jun 13 1997  Kryll        Converted to a bin system call.
 
*/

#include "/sys/defs.h"

int main(string str) {

  write("You ack.\n");
  say(TP->NAME + " acks.\n");
  return 1;
}

