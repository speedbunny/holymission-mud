inherit "room/room";
object vult,egg;
reset (arg) {
if (!vult) {
vult=clone_object("obj/monster");
transfer(vult,this_object());
vult->set_name("vulture");
vult->set_short("vulture");
vult->set_long("An old vulture.\nShe seems to be guarding something.\n");
vult->set_level(20);
vult->set_ac(3);
vult->set_wc(3);
vult->set_aggressive(0);
vult->set_align(50);
vult->add_money(300);
egg=clone_object("obj/treasure");
transfer(egg,vult);
egg->set_id("golden egg");
egg->set_short("golden egg");
egg->set_long("A golden egg");
egg->set_value(500);
egg->set_weight(5);
}
if (arg) return;
set_light(3);
short_desc = "tree";
long_desc = 
"You are sitting in a strange looking tree.\n"
+"There is a nest on a branch, with something shiny in it.\n"
+"Unfortunately, there is also a vulture there.\n";
items = ({
"nest","A nest made of sticks and feathers.\nThere is something very shiny in it",
});
dest_dir = ({
"players/jake/goblin/gob4","down",
});
}
