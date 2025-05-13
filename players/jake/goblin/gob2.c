inherit "room/room";
object gob,spe,she; 
reset (arg) {
if (!gob) {
gob=clone_object("obj/monster");
transfer(gob,this_object());
gob->set_name("goblin guard");
gob->set_alias("guard");               
gob->set_alias2("goblin");
gob->set_male();
gob->set_level(10);
gob->set_long("A goblin guard.\nHe is the guardian of the village.\n");
gob->set_align(100);
gob->set_aggressive(0);
spe=clone_object("obj/weapon");
transfer(spe,gob);
spe->set_name("spear");
spe->set_value(100); 
spe->set_weight(2);
spe->set_short("spear");
spe->set_long("This is a simple spear.\n");
gob->init_command("wield spear");
she=clone_object("obj/armour");
transfer(she,gob);
she->set_name("shield");
she->set_value(100);
she->set_weight(2);
she->set_class("shield");
she->set_size();
she->set_short("shield");
she->set_long("A goblin shield.\n");
gob->init_command("wear shield");
}
if (arg) return;
set_light(3);
short_desc = "gob2";
long_desc = "This is the entrance to the Goblin Village.\n"
+ "Many green and red vines entangle over the wall.\n"
+ "The vines seem to be supporting the wall.\n";
items = 
({
"wall","A wall made of rock.\nIt looks rather old.",
"vines","Heavily tangled red and green vines that grow over the wall."
});
dest_dir = ({
"players/jake/goblin/gob1","east",
"players/jake/goblin/gob3","west",
});
}
