inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Deck.\n";
long_desc=
"This is the deck in the back of the house. To the south you\n"+
"can the in ground swimming pool. To the west is stairs leading\n"+
"to the backyard. On the deck against the wall is the barbaque.\n";
dest_dir=({
"players/warlord/house/pool1","pool",
"players/warlord/house/back1","west",
"players/warlord/house/den","house",
});
}
