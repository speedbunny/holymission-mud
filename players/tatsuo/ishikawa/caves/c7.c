 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

  reset(arg)
{
  if(arg) return;

    set_light(1);
short_desc="Cave of the Serpent";
    long_desc= break_string(
  "You have entered a huge cavern. It is filled with stalagtites and stalagmites. "+
  "There is a reddish glow lighting this cavern and you can feel heat comming from "+
  "the northern end of the cavern.\n",65);
items=({"walls","They are smooth and grey. They appear to be made of granite.",
  "stalagtites","They are immense rock formations that hang from the ceiling.",
 "stalagmites","They are immense rock formations that are built up from the floor.",
 "floor","The floor is smooth grey rock."});

dest_dir=({CPATH+"c8","west",CPATH+"c6","east",CPATH+"c10","north"});
}
