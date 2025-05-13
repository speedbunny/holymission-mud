inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="DEAD end!\n";
long_desc="You have walked into a really bare hallway. There are footprints\n"+
          "all over the place in the dust going in every direction.\n"+
          "The walls and floor are dusty.\n";
items=({
"floor","There are footprints all over the place",
"footprints","You see tiny little footprints in the dust going everywhere",
"wall","There are three walls here north, south and east. Which one?",
"walls","There are three walls here north,south and east. Which one?",
"north wall","As you look closely at the wall you notice that it's fake",
"south wall","As you look closely at the wall you notice that it's fake",
"east wall","This wall is covered in dust from top to bottom",
});
dest_dir=({
"players/warlord/drac/drachall2","west",
});
}
init () {
::init() ;
add_action("north","north");
add_action("south","south");
}
north() {
this_player()->move_player("through the wall#players/warlord/rooms/ghouroom");
return 1;
}
south () {
this_player()->move_player("through the wall#players/warlord/pyramid/p2");
return 1;
}
