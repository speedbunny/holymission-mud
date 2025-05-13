inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Hall";
  long_desc =
"This room contains oil portraits of all of the ancient Counts of Bismarck "+
"Keep.  They are proud-faced men of strong build and stolid demeanor. A "+
"red carpet extends the length of the room going east and west.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-19.c","east",
    br+"/ch-17.c","west",
  });
items = ({
  "carpet",
  "A red carpet of welcome lines the hall",  "room",
  "A part of the northern hall",
  "counts",
  "The Counts of Bismarck Keep are portrayed in paintings here",
  "bismarck",
  "Castle Bismarck",
  "castle",
  "Castle Bismarck",
  "keep",
  "Castle Bismarck",
  "portraits",
  "Pictures of long dead leaders",
});
::reset(arg);
  replace_program("room/room");

}
