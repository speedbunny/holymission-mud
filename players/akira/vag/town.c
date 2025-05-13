inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("A burnt-out town");
long_desc=("This place is a mess! Most of the buildings are on fire.\n"+
           "The rest seem to have been blown apart. There are a number\n"+
           "of bodies in the streets, and the smell of burning flesh\n"+
           "hangs in the air. A few screems can still be heard, but you\n"+
           "can not really tell were they are coming from.\n");
items=({"buildings","They are all damaged, most are on fire.\n",
        "bodies", "They look to be dead humans.\n" });
clone_list=({1, 2, "indian","players/akira/mobs/indian",0});
::reset(tick);
dest_dir=({"players/akira/vag/field3", "north",
          "players/akira/vag/field2", "south",
          "players/akira/vag/rift2", "east",
          "players/akira/vag/town2", "west" });
property=({"vag_quest", "no_teleport"});
}
