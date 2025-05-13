inherit "room/room";

reset(arg) {     
       
       set_light(1);
       short_desc="Seaworld's Commuter Port.";     
       long_desc="\
You have reached a pebbled beach.  The waves lap gently against the \
shore, and a slight breeze ruffles your hair.  There are some ropes \
and debris strewn around at your feet, and a crooked wooden sign is \
planted firmly in the ground. \n\n";

   dest_dir=({"/players/emerald/seaworld/room/rock", "south",
           });

  items=({"pebbles","Multicolored pebbles make up the beach",
          "beach","A pebbled beach",
          "sea","You see the blue sea and the waves rolling up the shore",
          "shore","The shore of the sea",
          "ropes","They look as if they may be used for securing sailing crafts",
          "debris","Bits of wood that look as if they may have come from sailing crafts",
          "ground","A multi-colored pebbled beach",
          "waves","They do not appear terribly rough.  Probably suitable "+
                  "for sailing on",
        });

::reset(arg);

}

void init(){
   add_action("_read","read"),
   ::init();
}


int _read(string str) {
   if(str!="sign") return 0;
   write("Wait here for the raft to the lands of the jedi!\n");
   return 1;
}


