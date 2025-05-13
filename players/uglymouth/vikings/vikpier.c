/* the pier leading to the great hall */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="A wooden pier leading to the shore";
   long_desc="You're standing on a wooden pier, which leads to the shore. "
           + "The pier is covered with a thin layer of ice, so watch where you step. "
           + "A cold wind blows around you. The sea is dark blue and very cold. \n";
   dest_dir=({"/players/uglymouth/vikings/vikfield","west", });
   items=({"pier","A wooden pier where you can moar boats and ships",
           "shore","A rocky shore on which one big house is built",
           "house","A big house with a small dragon's head of red wood above the door",
           "ice","The ice is salty, so it must be very cold",
           "sea","The sea is quite calm, but very cold", });
   }

void init() {
   ::init();
   add_action("dive","dive");
   add_action("dive","swim");
   }

int dive() {
   write("You must be crazy to dive into the cold water, but it's your choice. \n");
   this_player()->move_player("into the sea#players/uglymouth/vikings/viksea");
   return 1;
   }
