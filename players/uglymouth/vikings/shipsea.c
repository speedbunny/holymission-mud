/* the entrance to the ship */
inherit "room/room";

void reset(int arg) {

   if(arg) return 0;

   set_light(1);
   short_desc="A part of the sea near the bay";
   long_desc="This is a calm part of the sea near the bay. \n"
           + "The water is clear and blue and has a nice temperature. The sunlight is \n"
           + "reflected on the sea's surface in glittering patterns of gold. \n";
   dest_dir=({"/players/uglymouth/vikings/campbeach","southwest", });
   items=({"sea","A blue sea",
           "water","Salty sea water is clear to look at",
           "sun","It shines nice and warm", });

   ("/players/uglymouth/vikings/ship")->dummy();
   replace_program("room/room");
   }
