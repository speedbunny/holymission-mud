
 
inherit "room/room";

#include "../island.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 3)
  {
     CM("cancer");
    CM("steel_dragon");
   }

  if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
        "You find yourself standing in the sea, the water is warm "
        + "and you can see a little island to the north with a big "
        + "volcano rising up in the sky. There is a big cloud of ash "
        + "around the top of the volcano and you can hear a strange "
        + "noise coming from there.");
    items = ({
               "water","Blue sea water",
               "volcano","A big firethrowing volcano"
            });   
    dest_dir = 
        ({
        PATH+"island4","northeast",
        PATH+"island2","northwest",
        PATH+"island3", "north",
        });
}
init() {
  ::init();
  add_action("dive","dive");
  add_action("dive","down");
  add_action("swim","swim");
 }

int dive(string arg) 
{
    write("On this place the water isn't deep enough to dive down.\n");
    return 1;
}
    
  swim(arg) {
  call_out("swim1",2);
  return 1;
  }
  
  swim1() {
   write("You swim out the wide ozean.\n");
   call_out("swim2",2);
   }
   
  swim2() {
   write("You swim and swim and feel your energie getting lower and lower.\n");
   call_out("swim3",2);
   }
   
  swim3() {
   write("Suddenly you feel your arms getting so tired that you sink down on the sea-bottom.\n");
   call_out("swim4",2);
   }
   
  swim4() {
   string where;
   where="sw"+(1+random(20));
   write("You suddenly find yourself on a different place\n");
   this_player()->move_player("swimming#players/whisky/seaworld/room/"+where+"");
   }
   
