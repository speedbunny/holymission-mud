inherit "room/room";
object beg;   
reset (arg) {
if (!beg) {
beg=clone_object("obj/monster");
transfer(beg,this_object());
beg->set_name("beggar");
beg->set_short("beggar");
beg->set_alias("goblin");
beg->set_long("This is a poor beggar goblin.\n");
beg->set_race("goblin");
beg->set_level(5);
beg->set_arms(2);
beg->set_align(500);
beg->set_aggressive(0);
}
if (arg) return;
set_light(3);
short_desc = "croad5";
long_desc = "The castle is now in sight.\n"
+ "The gates are to the north.\n"
+ "You see two rather large figures standing in front of the castle.\n"
+ "There is a thick growth of trees and shrubbery to either side of you.\n";
items = ({
"castle","The mighty Goblin Castle.\nWhy not go visit?",
"trees","Large evergreen trees",
"shrubbery","Various size and color hedges",
"gate","The castle gate.\nIt is directly north of you",
"figures","Two castle guards.\nThey are dressed in bright red and black,\nand appear to be carrying some sort of a large sword",
});
dest_dir = ({
"players/jake/goblin/croad4","south",
"players/jake/goblin/castle/gate.c","north",
});
}
