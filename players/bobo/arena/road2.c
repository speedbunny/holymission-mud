inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The entrance to the colliseum.";
long_desc=
  "You have come to the entrance of the coliseum.  It is a "+
  "large stone tunnel with blood on the walls.  You can see "+
  "into the arena and it looks huge.  There is a metal gate "+
  "that hangs above the entrance to the arena.\n";
dest_dir=({
        "players/bobo/arena/a1.c","north",
        "players/bobo/arena/road1.c","south",
});
items=({
        "tunnel","This is a large hollowed out stone tunnel",
        "blood","There are smatterings of blood here and there along the walls",
        "arena","A very large arena where both gladiators and animals fight",
        "gate","The gate looks more like a portcullus and seems to be able to close off the entry",
});
replace_program("room/room");
}
