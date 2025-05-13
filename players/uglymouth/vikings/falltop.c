/* Top of the waterfall. Isn't mist great to hide things? */
inherit "room/room";
string finder;

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="A cloud of fog surrounds the top of a waterfall";
   long_desc="You enter a cloud of dense fog. As you watch carefully \n"
           + "where you walk, you see the path ending at the edge of \n"
           + "of the cliff, the water rushing down violently. \n";
   dest_dir=({"/players/uglymouth/vikings/river_s","north", });
   items=({"cloud","You cannot see more than a few meters away",
           "fog","The thick fog soaks you to the bone",
           "path","The slippery rock path stops here",
           "cliff","A very steep cliff disappears in the fog. From the sound you think it's very deep",
           "waterfall","The water disappers down in the fog",
           "water","The water disappears down in the fog", });
   }

void init() {
   ::init();
   add_action("jump","jump");
   add_action("search","search");
   add_action("enter","enter");
   add_action("look_at_it","look");
   add_action("look_at_it","examine");
   }

int jump(string str) {
   if(!str || str=="down" || str=="waterfall") {
      write("Do you have a death-wish???? \n");
      say(this_player()->query_name()+" looks down, thinking about suicide",this_player());
      return 1;
      }
   return 0;
   }

search(str) {
   if(!str) {
      write("What do you want to search? \n");
      return 1;
      }
   if(str=="rocks" || str=="cliff" || str=="room") {
      write("You search the wet rocks, but find nothing. \n");
      say(this_player()->query_name()+" turns every stone upside down.",this_player());
      return 1;
      }
   if(str=="fog") {
      write("As you stare in the fog you vaguely see the form of a portal lighting up. \n");
      say(this_player()->query_name()+" stands daydreaming adventures.",this_player());
      finder=this_player()->query_real_name();
      return 1;
      }
   return 0;
   }

int enter(string str) {
   if(str!="portal") return 0;
   if(!this_player()->query_immortal()) {
      write("You are not yet worthy to use this portal. \n");
      return 1;
      }
   this_player()->move_player("through the portal#players/uglymouth/workroom");
   return 1;
   }

int look_at_it(string str) {
   if(str!="at portal" && str!="portal") return 0;
   if(finder!=this_player()->query_real_name()) return 0;
   write("As you try to focus on the portal, it starts to shimmer. \n"
       + "You wonder where it might lead. \n");
   return 1;
   }
