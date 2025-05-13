inherit "/room/room";

#include "/players/kryll/rooms/room_defs.h"

int bush_has_num[3];
int plant_has_num[5];
int i;
string *nums;
string msg;

void reset(int arg) {
  for(i=0; i<3; i++)
    bush_has_num[i] = random(5) + 3;
  for(i=0; i<5; i++)
    plant_has_num[i] = random(3) + 1;

  if(arg) return;
  nums = "/obj/share"->share_room_numbers();

  set_light(0);
  short_Desc = "A dark part of the forest";
  long_desc =
    "You have entered what appears to be a special garden of the "+
    "Ilkin Forest. It is special because it contains three bushes and  "+
    "five different plants that have grown from three to five feet "+
    "in height. You barely make out a trail leading south amidst "+
    "some bushes. "+
    "Beware of what lurks around you.\n";

  items = ({
    "forest","The dark part of the forest is tainted with evil",
    "trees","You feel like they are watching you",
    "bushes","These thorny bushes contain various types of flowers "+
             "and berries, although they all seem to have a dark "+
             "taint to them. Just look at each one to see what is on "+
             "it",
    "bush 1","@@bush_one@@",
    "bush 2","@@bush_two@@",
    "bush 3","@@bush_three@@",
    "plants","There are five plants wth various types of strange "+
             "looking fruits and flowers on them. Just look at "+
             "each one to see what is on it",
    "plant 1","@@plant_one@@",
    "plant 2","@@plant_two@@",
    "plant 3","@@plant_three@@",
    "plant 4","@@plant_four@@",
    "plant 5","@@plant_five@@",
    "trail","A trail leading west. Just go that direction",
  });

  smell = "Is that rotting leaves you smell?\n";
  hidden_dir = ({
    ILKIN_FOREST + "if10", "south",
  });

  ::reset(arg);
}

string bush_one(){
  return "The bush has "+nums[bush_has_num[0]]+" berries on it"
}

string bush_two() {
  return "The bush has "+nums[bush_has_num[1]]+" berries on it"
}

string bush_three() {
  return "The bush has "+nums[bush_has_num[2]]+" berries on it"
}

string plant_one() {
  return "The plant has "+nums[plant_has_num[0]]+" berries on it"
}

string plant_two() {
  return "The plant has "+nums[plant_has_num[1]]+" berries on it"
}

string plant_three() {
  return "The plant has "+nums[plant_has_num[2]]+" berries on it"
}

string plant_four() {
  return "The plant has "+nums[plant_has_num[3]]+" berries on it"
}

string plant_five() {
  return "The plant has "+nums[plant_has_num[4]]+" berries on it"
}
