inherit "room/room";
object smurf,pillow;
reset (arg) {
if(!smurf) {
smurf=clone_object("obj/monster");
transfer(smurf,this_object());
smurf->set_name("lazy smurf");
smurf->set_short("lazy smurf");
smurf->set_long("This is Lazy smurf./nHe yawns and snuggles his pillow as you approach him.\n");
smurf->set_level(5);
smurf->set_hp(50);
smurf->set_align(100);
smurf->set_aggressive(0);
smurf->add_money(50);
smurf=clone_object("obj/monster",this_object());
