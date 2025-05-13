inherit"players/warlord/NEWSTUFF/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Pyramid hallway\n";
long_desc="You are in a very old corridor. The walls are made from a sort of\n"+
          "limestone and the floor is very clean.\n";
dest_dir=({
"players/warlord/pyramid/p2","east",
"players/warlord/pyramid/p10","upsoutheast",
"players/warlord/pyramid/p4","south",
         });
items=({
"corridor","The corridor is old and crumbling due to the limestone walls",
"limestone","The limestone is of a deep yellow color, showing its age",
"wall","The wall is made of limestone",
"walls","The walls are made of limestone",
"floor","The florr is very clean as if someone has been cleaning it",
        });
}
