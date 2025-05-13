inherit "room/room";

object obj;

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="The Entryhall of the cloister";
    long_desc="You're in the Entryhall of a forsaken cloister.\n"+
              "All that remains is a very old man that spends\n" +
              "his time listening to the calls of strangers.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/cloi2","west",
               "players/kelly/rooms/mythwood/top_rope","down",
             });
   obj=clone_object("players/kelly/monster/old_brother");
   move_object(obj,this_object());
}

