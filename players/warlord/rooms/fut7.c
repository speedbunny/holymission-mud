

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/gsor");
move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A majestic bedroom";
    long_desc = 
          "This room is the bedroom to the Great sorceror. He has a bed and\n"+
          " large dresser on the east side. There is a sign on the wall.\n";
    items = 
          ({
          "bed","The is really huge and by the looks of it, it's well used!\n",
          "sign","WARNING: Do not go West,South or East unless you want to die!!\n",
          "dresser","This is a large dresser, but you see no drawers...\n",
          });
    dest_dir = 
        ({
        "players/warlord/rooms/fut6", "northeast",
        "players/warlord/rooms/fut5", "northwest",
        "players/warlord/rooms/fut8", "west",
        "players/warlord/rooms/fut9", "east",
        "players/warlord/rooms/fut10", "south",
        });
}

