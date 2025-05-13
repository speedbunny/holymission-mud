/* a road in the burning village */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="A road through the burning village";
   long_desc="You walk amidst the flames!! As the fire is everywhere \n"
           + "you make yourself as small as possible to protect yourself \n"
           + "from the flames. Through the smoke you see the village square \n"
           + "east and the safe coolness of the beach northwest. North and \n"
           + "south of you are buildings on fire. The heat is almost unbearable. \n";
   dest_dir=({
              "/players/uglymouth/vikings/firesquare","east",
              "/players/uglymouth/vikings/bay_se","northwest", });
   items=({"flames","I don't think this is the time to enjoy a campfire!",
           "fire","Everything around you is burning: a picture of what hell can be",
            "square","On the square the flames are less dense. You see someone there",
            "buildings","Fire blazes through every opening, eating the supporting structures away",
           "beach","The only safe place you can think of now", });
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("east","east");
   }

int east() {
   write("A gust of flames burns your hair away as you move to the square. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("east#players/uglymouth/vikings/firesquare");
   return 1;
   }
