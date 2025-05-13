inherit "room/room";
object dad,blade,arm;
reset (arg) {
if (!dad) {
dad=clone_object("obj/monster");
transfer(dad,this_object());
dad->set_name("goblin");
dad->set_short("father goblin");
dad->set_long("This is the father goblin.\nHe seems annoyed with you.\n");
dad->set_level(35);
dad->set_align(10);
dad->set_alias("father");
dad->set_aggressive(0);
dad->add_money(500);
dad->load_chat(20, ({"Grrrr..."}));
blade=clone_object("obj/weapon");
transfer(blade,dad);
blade->set_name("goblin blade");
blade->set_short("goblin blade");
blade->set_long("This is a goblin blade.\nIt is a fairly potent weapon.\n");
blade->set_wc(10);
blade->set_value(2000);
blade->set_weight(3);
dad->init_command("wield goblin blade");
arm=clone_object("obj/armour");
transfer(arm,dad);
arm->set_name("chainmail");
arm->set_short("chainmail");
arm->set_long("ordinary chainmail armour.");
arm->set_ac(3);
arm->set_weight(3);
arm->set_value(1000);
arm->set_alias("mail");
dad->init_command("wear chainmail");
}
if (arg) return;
set_light(3);
short_desc = "hut2b";
long_desc = 
"This is the basement of the goblin house.\n"
+"It is the workshop of the father goblin.\n"
+"It appears that he has just finished a new sword.\n"
+"There is a workbench with scattered tools and metals on it.\n";
items = ({
"bench","A normal looking workbench",
"tools","Metal working tools",
"metal","various kinds of metal for making weapons",
});
dest_dir = ({
"players/jake/goblin/hut2a","up",
});
}
