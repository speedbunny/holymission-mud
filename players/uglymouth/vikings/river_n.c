/* northern section of the borderriver */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="You walk upstream of a river";
   long_desc="You walk upstream of a river. \n"
           + "The water comes from between the rocks to the northeast and rushes down \n"
           + "to the south. The water looks cold and clear. A path runs along the river \n"
           + "and also forks off east and southeast into the dunes. \n";
   dest_dir=({"/players/uglymouth/vikings/well","northeast",
              "/players/uglymouth/vikings/open","east",
              "/players/uglymouth/vikings/dunes_w","southeast",
              "/players/uglymouth/vikings/river_s","south", });
   items=({"river","It's cold, fast and too wide too jump across",
           "water","Very cold but clear water. It's probably safe to drink",
           "rocks","Large rocks form a path to the stone hill where the river has its rise",
           "path","A very muddy path. Yuck!",
           "dunes","A dune range lies to the east", });

   smell="The air is cold and humid and smells a bit earthly. \n";
   }

void init() {
   ::init();
   add_action("swim","swim");
   add_action("swim","enter");
   add_action("jump","jump");
   add_action("jump","dive");
   add_action("drink","drink");
   }

int jump(string str) {
   if(!str || str=="river" || str=="water") {
      write("As you dive into the river the cold paralyzes you instantly! \n"
          + "Slowly you start to sink, deeper and deeper... \n"
          + "As you start to see your life pass by, you make a last effort of will \n"
          + "and with all the strength left in you, you force your arms and legs to move. \n"
          + "Using the last of your breath to make it back ashore, barely alive. \n");
      say(this_player()->query_name()+" jumps into the icecold river, surfaces after a long while\n",this_player());
      say("and, blue and half-frozen, only just manages to get out of the water.\n",this_player());
      this_player()->hit_player(random(10)+10);
      return 1;
      }
   return 0;
   }

int swim(string str) {
   if(!str || str=="river" || str=="water") {
      write("The moment your big toe feels the temperature of the water you know \n"
          + "that you do NOT want to take a swim here. \n");
      say(this_player()->query_name()+" feels the water and suddenly decides not to go swimming.\n",this_player());
      return 1;
      }
   return 0;
   }

int drink(string str) {
   if(str!="water") return 0;
   write("The water tastes good, but is VERY cold and you have to suppress \n"
       + "the cramps that your stomach wants to get into. \n");
   say(this_player()->query_name()+" drinks some water. Then you realize the rattling sound\n",this_player());
   say("is made by "+this_player()->query_possessive()+" teeth!\n",this_player());
   return 1;
   }
