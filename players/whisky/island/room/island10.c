 
  /* fixed by haplo on 3-27-95 */

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
    if (filter_live(this_object()) < 3)
    {
      CM("cancer");
      CM("red_dragon");
      CM("cancer");
      CM("blue_dragon");
    }
    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
        "S P L A S H ! ! ! ! You are landing on a sandbank in the sea. "
        + "The sun is glittering in the water and if you look down you see "
        + "some cancers snapping after your toes. To the east you see the "
        + "volcano rising up in the sky and you can hear it's rumbling "
       + "noise. If you look down you can see the water getting deeper.");
    items = ({
              "sandbank","A long sandbank",
              "water","Clear sea water",
              "volcano","A big firethrowing volcano"
            });
 }

init() {
  ::init();
  add_action("dive","dive");
  add_action("dive","down");
  add_action("swim","swim");
  }

int dive() 
{
    write("On this place the water isn't deep enough to dive down.\n");
    return 1;
}
    
  swim(arg) {
  call_out("swim1",2);
  return 1;
  }
  
  swim1() {
  write("You swim out in the wide ocean.\n");
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
