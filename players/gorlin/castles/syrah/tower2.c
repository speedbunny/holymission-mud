
/* Gorlin, 4.4.1996 */

inherit "room/room";

void reset (int arg)
{
   ::reset (arg);
   if (arg) return;

   set_light(1);
   short_desc="In a slender tower";
   long_desc="You are standing in a mage's workroom. Several "+
             "cupboards at the walls are filled with animal skulls,  "+
             "small vials, bags and candles. A small desk and a  "+
             "chair are standing in front of a window. A pentagram "+
             "is painted on the floor. You can see "+
             "stairs leading up and down.\n";
   dest_dir=({
      "/players/gorlin/castles/syrah/tower1","down",
      "/players/gorlin/castles/syrah/tower3","up"
      });

   items=({
      "cupboards","They nearly burst with all that stuff on them",
      "desk","A working place of some mage",
      "chair","Just a chair",
      "skulls","They once belonged to various animals and monsters",
      "vials","They are filled with eyeballs, spiders' legs and all "+
         "that other usual stuff",
      "bags","They contain powders and ingrediants",
      "candles","There are really lots of them here",
      "pentagram","It is drawn in some kind of green paint"
      });
   smell="You smell dust in here... and some other unidentifiable "+
      "things.";
}

