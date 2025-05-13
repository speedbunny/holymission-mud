inherit "room/room";
int i;
object rat;
reset (arg) {
for (i=0;i<4;i++) {
rat=clone_object("obj/monster");
rat->set_name("rat");
rat->set_short("brown rat");
rat->set_long("A small brown rat with big yellow teeth.\nHe has sharp claws and  long pink tail.\n");
rat->set_level(5);
rat->set_race("animal");
rat->set_al(100);
rat->set_aggressive(0);
move_object(rat,this_object());
}
if (arg) return;
set_light(2);
short_desc = "pantry";
long_desc =
 "A large pile of sacks of flour lie in the southeastern corner of the room.\n" +
 "A small table stands in the center of the room, piled high with various food\n" +
 "items, and flasks of drink.  Bunches of apples, onions, garlic, and\n" +
 "other spices and herbs hang from the ceiling by ropes.  You assume that\n" +
"this must be the castle pantry.\n";
items = ({
 "floor","You see the floor of the pantry.  It looks dusty",
 "table","You are looking at a small table piled high with vegetables, breads, and salted meats",
 "bunches","You see apples, onions, and other bunches of foods hanging from the ceiling on twine ropes",
 "food","You see lot's of food",
 "flour","You see large sacks of flour for baking in the corner",
});
dest_dir = ({
 "players/jake/goblin/castle/h5","north",
});
}
