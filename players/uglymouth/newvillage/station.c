/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "An old mail-coach station";
  long_desc = "You've entered the old mail-coach station. The building itself has\n"
        + "fallen into decay, but the two platforms are still quite intact. They\n" 
        + "might even still be in use. If you wait long enough, maybe a coach\n"
        + "arrives to bring you to other places.\n";
  dest_dir = ({ PATH+"alley1","west" });
  items = ({"station","This station looks like it has been used a lot in the old days",
          "building","It's in a poor shape, with its collapsed roof and broken window hutters",
          "roof","Formerly a nice thatched roof, but its beams got rotten and it collapsed",
          "shutters","The hinges got rotten and broke. To one shutter a sign still is attached",
          "platforms","The platforms are used for passengers to get into the coach easily",
          "sign","There is something written on it, but the ink has bleached mostly",
          });
  }

void init() {
  ::init();
  add_action("read_sign","read");
  }

read_sign(string str) {
  if(str!="sign") return 0;
  write("You decipher the bleached text on the sign. You think it reads:\n"
      + "Coach service to main village:\n"
      + "   - Departure: every hour.\n"
      + "   - Cost     : 5 coins.\n");
  return 1;
  }

