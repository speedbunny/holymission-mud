/* the eastern road through the village after the fire is put out */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="You are on the eastern road through the village";
   long_desc="You are at the eastern road through the village. \n"
           + "North of you is a small beach where the villagers used to \n"
           + "moar their boats. East of you an important looking building \n"
           + "has survived the fire. The building to the south stands on \n"
           + "the verge of collapsing. Dirty mud slowly flows in from the square. \n";
   dest_dir=({"/players/uglymouth/vikings/harbour","north",
              "/players/uglymouth/vikings/house5","east",
              "/players/uglymouth/vikings/house4","south",
              "/players/uglymouth/vikings/villsquare","west", });
   items=({"beach","A black beach with two wrecks of rowing boats",
           "building","The eastern or the southern building?",
           "eastern building","As it looks important it is probably the chief's house",
           "southern building","It has been burned out very badly and can collapse any moment now",
           "mud","A sickly black suspension, creeping slowly along the road", });
   smell="You begin to notice some fresh air coming in among the stench of the fire. \n";

   replace_program("room/room");
   }
