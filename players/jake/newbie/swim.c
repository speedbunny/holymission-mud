inherit "room/room";
object fish,guts;
reset (arg) {
if(!fish) {
fish=clone_object("obj/monster");
fish->set_name("fish");
fish->set_short("Gold fish");
fish->set_size(0);
fish->set_long("A pretty gold fish.\n");
fish->set_level(5);
fish->set_align(100);
fish->set_aggressive(0);
guts=clone_object("obj/treasure");
guts->set_id("fish guts");
