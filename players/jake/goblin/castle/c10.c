inherit "room/room";
object maid,brush;
reset (arg) {
if (!maid) {
maid=clone_object("obj/monster");
maid->set_name("goblin maid");
maid->set_short("goblin maid");
maid->set_level(10);
maid->set_alias("maid");
maid->set_hp(500);
maid->set_long("A goblin maid.  Her job is to clean up the castle.\n");
maid->set_al(100);
maid->set_race("goblin");
brush=clone_object("obj/treasure");
brush->set_id("scrub brush");
brush->set_short("scrub brush");
brush->set_value(400);
brush->set_weight(2);
brush->set_long("An ordinary looking scrup brush.\nIt is used to scrub floors and walls.\n");
move_object(brush,maid);
move_object(maid,this_object());
}
if (arg) return;
set_light(3);
short_desc = "c10...north hallway..maid, E/W";
long_desc =
 "This hallway goes east and west.\n"
+ "There is a white carpet that extends the length of the hall.\n"
+ "A small window in the north wall.\n";
items = ({
"floor","It is made of ruby-red stone",
"ceiling","Pure white stone make the ceiling",
"wall","Made of grey stone",
"window","You see a large clearing behind the castle",
"carpet","A beautiful white carpet",
});
dest_dir = ({
"players/jake/goblin/castle/c11","west",
"players/jake/goblin/castle/c9","east",
});
}
