
/* Gorlin, 4.4.1996 */

inherit "room/room";

void reset (int arg)
{
   ::reset (arg);
   if (arg) return;

   set_light(1);
   short_desc="In a slender tower";
   long_desc="You are standing in the reception chamber inside "+
             "the tower. The room is somewhat in disarray, clothing "+
             "and other stuff lying around on the floor. A large "+
             "and comfortable armchair is standing in the middle of "+
             "the room. You can see stairs leading up.\n";
   dest_dir=({
      "/players/gorlin/castles/syrah/valley","out",
      "/players/gorlin/castles/syrah/tower2","up"
      });

   items=({
      "clothing","You notice a label: 'Syrah' on one of them",
      "armchair","A stuffed armchair. It looks very comfortable",
      });
   smell="You smell dust in here.";
}

