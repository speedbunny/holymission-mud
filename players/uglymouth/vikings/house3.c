/* the house that gives access to the vikings' camp */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="A burned out warehouse";
   long_desc="You stand in what's left of the warehouse. \n"
           + "Some of the puddle that fills the square has flown into this "
           + "building. You can still make out the shape of some barrels and "
           + "crates. A stairway leads to the attic. \n";
   dest_dir=({"/players/uglymouth/vikings/villsquare","north",
              "/players/uglymouth/vikings/house3a","up", });
   items=({"puddle","In the shadows here it looks like moving slime",
           "barrels","Tarbarrels. But all the tar has burned away in the fire.",
           "crates","As you touch one it falls apart in ashes.",
           "stairway","As it stands in the centre, it survived the fire well enough to support you",
           "attic","It's in the shadows, upstairs", });
   smell="The smell of burned tar and the stench of the puddle turn your stomach inside out. \n";
   }

void init() {
   ::init();
   add_action("north","north");
   }

int north() {
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      this_player()->move_player("north#players/uglymouth/vikings/firesquare");
      return 1;
      }
   this_player()->move_player("north#players/uglymouth/vikings/villsquare");
   return 1;
   }
