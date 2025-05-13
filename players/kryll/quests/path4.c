inherit "/room/room";

#include "actions.h"

static status has_solved;

// PROTOTYPES
nomask status query_has_solved();
nomask void set_has_solved(status val);
string extra_look();

nomask status query_has_solved() {
  return has_solved;
}

nomask void set_has_solved(status val) {
  has_solved = val;
}

void reset(int arg){
  clone_list = ({
    1, 1, "hobbe", HOBBE + "hobbe", 0,
  });

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "On a path";
  long_desc =
    "You're wandering on a path that follows alongside a slow, "+
    "meandering stream. You have arrived at Hobbe's mill. It is "+
    "a lovely mill, with its wheel in the stream to help power it. " +
    @@extra_look@@ + "Bushes line both sides of the path, making this "+
    "a pleasant, scenic journey. There are some large stones lying on "+
    "the ground.\n";

  items = ({
    "stones","Some heavy grey stones",
    "ground","You see some heavy stones lying in the grass",
    "grass","The fresh grass looks beautiful",
    "sky","You see the blue sky",
    "bushes","They line the path",
    "path","This path appears to lead south",
    "stream","You see a big blue stream which seems too deep to enter",
    "water","It looks cool and refreshing",
    "mill","The stone mill looks to be a good hundred years old",
    "wheel","The wheel helps to power the mill from the running water",
  });

  dest_dir = ({
    HOBBE + "path3", "north",
    HOBBE + "path5", "south",
  });
}

string extra_look() {
  string tmp;

  tmp = "";
  if(has_solved)
    tmp += "The wheel is turning under the water's power helping the "+
           "mill work. ";
  else
    tmp += "The wheel isn't turning currently. ";

  if(present("hobbe")) {
    tmp += "Hobbe is sitting on a nearby stump resting his tired bones. ";
  return tmp;
}

