inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Pyramid hallway\n";
long_desc="You are in a very old corridor. The walls are made from a sort of limestone\n"+
     "and the floor is very clean. The north wall is bending light at a weird angle.\n";
dest_dir=({
"players/warlord/pyramid/p9","east",
"players/warlord/pyramid/p7","west",
         });
items=({"wall","The wall looks really weird, like its not real",
});
}
init () {
::init();
add_action("north","north");
}
north() {
/* Fixed wrong exit. Airborne 10.21.94 */
this_player()->move_player("enters a secret chamber#players/warlord/rooms/mumroom");
return 1;
}
