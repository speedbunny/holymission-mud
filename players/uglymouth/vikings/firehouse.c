/* Only dangerous to leave it *grin* */
inherit "room/room";

status elemental_died;

void reset(int arg) {
   elemental_died = 0;
   if(arg) return;

   set_light(1);
   short_desc="The ground floor of the burning warehouse";
   long_desc="You're at the ground floor of the burning warehouse. \n"
           + "It doesn't burn as badly as you'd expect, leaving the centre of \n"
           + "the room free of flames. At the sides many crates and barrels stand \n"
           + "burning, their contents already unfit for any use whatsoever. \n";
   dest_dir=({"/players/uglymouth/vikings/fireattic","up",
              "/players/uglymouth/vikings/firesquare","north", });
   items=({"warehouse","It was used to store all kinds of tools and prepared food",
           "tools","You see the remains of nets burning and a barrel of tar burst open, ablaze",
           "food","You see some crates with what must have been salted fish of some sort",
           "room","One big room for storage with stairs leading up",
           "stairs","As they are in the middle of the room, they've not yet taken flame",
           "crates","Wooden crates, containing obviously dry stuff as they burn very brightly",
           "barrels","Burning wooden barrels, by their smell mainly containing salted fish and tar",
           "contents","They are already so far burned that they're no longer recognisable", });
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("north","north");
   }

int north() {
   if( !present("elemental") && !elemental_died ) {
      write("As you reach for the doorway, a giant fist of fire shoots out \n"
          + "from the glowing ashes and knocks you back. \n");
      transfer(clone_object("/players/uglymouth/vikings/monsters/felemental"),this_object());
      elemental_died = 1;
      return 1;
      }
   write("You slip carefully north, but take some minor \n"
       + "burns of the intense heat which is radiated. \n");
   this_player()->hit_player(random(5)+1);
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      this_player()->move_player("north#players/uglymouth/vikings/firesquare");
      return 1;
      }
   this_player()->move_player("north#players/uglymouth/vikings/villsquare");
   return 1;
   }
