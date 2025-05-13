inherit "room/room";
object fox,claw;
reset (arg) {
if (!fox) {
fox=clone_object("obj/monster");
transfer(fox,this_object());
fox->set_name("fox");
fox->set_short("red fox");
fox->set_long("A rather large red fox.\n");
fox->set_level(5);
fox->set_align(100);
fox->set_alias("fox");
fox->set_race("animal");
fox->add_money(75);
claw=clone_object("obj/weapon");
;
transfer(claw,fox);
claw->set_name("fox claw");
claw->set_short("fox claw");
claw->set_alt_name("claw");
claw->set_value(200);
claw->set_weight(2);
claw->set_long("This is the claw of a fox.\n");
fox->init_command("wield fox claw");
}
if (arg) return;
set_light(0);
short_desc = "hole";
long_desc = "You work your way through the hole.\n"
+"You are in a large hole in the ground.\n"
;
items = ({
"wall","Dirt walls with strange scratch marks on them",  
"scratch marks","Looks like something has been digging at the walls",
});
dest_dir = ({"players/jake/goblin/hut3","out",
});
}
