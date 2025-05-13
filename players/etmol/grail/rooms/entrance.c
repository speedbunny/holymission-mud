#define TP this_player()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(1); 
short_desc = "Cave entrance"; 
long_desc = "A small entrance has been created here in the rock wall. You have no\n"+
           "doubts that the place where you can find the Grail awaits you in there\n"+
           "Of course if you're chicken or don't care about the Grail that much,\n"+
           "you can still turn back here.\n",           
            

items = ({
          "entrance", "Must have been a lot of work.",
          "rock", "Old, crumbling rock."
          "temple", "It lies behind this very opening.",
});
dest_dir = ({
             "/players/etmol/grail/rooms/hall", "east",
             "/players/etmol/grail/rooms/?", "west"
});
}
