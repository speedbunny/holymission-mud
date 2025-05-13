/* A waterfall with a cave behind it (how did you guess?) */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="You stand at the foot of a violent waterfall";
   long_desc="A deafening roar comes over you as you stand by the waterfall. \n"
           + "You feel the ground trembling as the water crashes into the pool. \n"
           + "From the pool flows a small stream east towards the sea. The pool \n"
           + "itself is formed by a rock basin. You're getting wet with the drops \n"
           + "of water which fly around everywhere. \n";
   dest_dir=({"/players/uglymouth/vikings/bay_nw","north",
              "/players/uglymouth/vikings/bay_m","east",
              "/players/uglymouth/vikings/bay_sw","south", });
   items=({"waterfall","Water is falling over the edge of a cliff very violently",
           "pool","The fresh and clear water of the fall is collected here",
           "stream","It discharges the excess water from the pool to the sea",
           "ledge","A small ledge surrounding the pool. You could walk it",
           "cave","The dark, hidden entrance of a cave waits hungry for you to enter",
           "basin","The basin is formed by rocks that lie on the beach and the cliff", });
   }

void init() {
   ::init();
   add_action("climb","climb");
   add_action("walk","walk");
   add_action("enter","enter");
   add_action("south","south");
   add_action("say_it","say");
   add_action("shout_it","shout");
   }

int climb(string str) {
   if(str!="basin" && str!="rocks") return 0;
   write("You climb on the rocks of the basin. There is a small but walkable ledge \n"
       + "surrounding the pool. The rocks are slippery because of the water. \n");
   say(this_player()->query_name()+" takes a look higher up, on the rocks. \n",this_player());;
   return 1;
   }

int walk(string str) {
   if(str!="ledge") return 0;
   if(random(10)<5) {
      write("You walk on the ledge, careful not to fall into the pool. \n"
          + "Suddenly your eye falls on a dark spot behind the waterfall, \n"
          + "that must be a hidden cave. \n");
      say(this_player()->query_name()+" tries acrobatics on the small ledge. \n",this_player());
      return 1;
      }
   write("The slippery rocks make you lose your balance. You tumble into the pool. \n");
   this_player()->move_player("the dry world, falling into the pool#players/uglymouth/vikings/pool");
   return 1;
   }

int enter(string str) {
   if(str!="cave" && str!="pool" && str!="basin") return 0;
   if(str=="cave") {
      write("You climb over the rocks into the cave behind the waterfall. \n");
      this_player()->move_player("through the waterfall#players/uglymouth/vikings/cave");
      return 1;
      }
   if(str=="pool" || str=="basin") {
      write("You see the sunlight break as the water closes above your head. \n");
      this_player()->move_player("into the pool#players/uglymouth/vikings/pool");
      return 1;
      }
   }

int south() {
   write("You jump over the stepping stones to the other side. \n");
   this_player()->move_player("over the stream south#players/uglymouth/vikings/bay_sw");
   return 1;
   }

int say_it(string str) {
   write("Your voice gets lost in the thunder of the waterfall. \n");
   say(this_player()->query_name() + " tries to say something. \n",this_player());
   return 1;
   }

int shout_it(string str) {
   write("Your voice is just hearable over the noise of the waterfall. \n");
   write("You shout: " + str + "\n");
   say(this_player()->query_name() + " shouts: " + str + "\n",this_player());
   return 1;
   }
