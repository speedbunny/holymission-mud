inherit"players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Pyramid hallway\n";
long_desc="You are in a very old corridor. The walls are made from a sort of\n"+
          "limestone and the floor is very clean.\n";
dest_dir=({
"players/warlord/pyramid/p3","north",
"players/warlord/pyramid/p9","south",
         });
}
