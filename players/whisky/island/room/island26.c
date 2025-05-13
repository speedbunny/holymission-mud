
  /* fixed by haplo on 3-27-95 */
 
inherit "room/room";
#include "../island.h"

 
void reset(int arg) 
{
  if (filter_live(this_object()) < 3)
  {
    CM("cancer");
    CM("cancer");
  }
  if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
        "You find yourself standing in the sea, the water is warm... "
      + "and you can see a little island to the south with a big "
       + "volcano rising up in the sky...... "
     + "There is a big cloud of ash around the top of the volcano "
      + "and you can here a strange rumbling noise coming from there.... "
      + "There is a little sign standing in the water.");
    items = ({
               "water","Blue sea water",
               "sign","It reads: 'Swimming at own risk'",
              "volcano","A big volocano spewing molten lava"
            });   
}

init() {
  ::init();
  add_action("dive","dive");
  add_action("dive","down");
  add_action("swim","swim");
  }

  dive(arg) {
    write("On this place the water isn't deep enough to dive down.\n");
    return 1;
    }
    
  swim(arg) {
  call_out("swim1",2);
  return 1;
  }
  
  swim1() {
   write("You swim out the wide ocean.\n");
   call_out("swim2",2);
   }
   
  swim2() {
 write("You swim and swim and feel your energy getting lower and lower.\n");
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
