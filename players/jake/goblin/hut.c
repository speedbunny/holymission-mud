inherit "room/room";
object goblin,helm,club;
reset (arg) {
if (!goblin) {
goblin=clone_object("obj/monster");
transfer(goblin,this_object());
goblin->set_name("fat goblin");
goblin->set_alias("goblin");
goblin->set_race("goblin");
goblin->set_male();
goblin->set_level(15);
goblin->set_short("fat goblin");
goblin->set_long("A really big goblin.\nHe is quite fat, and tough.\n");
helm=clone_object("obj/armour");
transfer(helm,goblin);
helm->set_name("helmet");
helm->set_short("helmet");
helm->set_class("helmet");
helm->set_value(150);
helm->set_weight(2);
helm->set_long("A goblin helmet.\n");
goblin->init_command("wear helmet");
club=clone_object("obj/weapon");
transfer(club,goblin);
club->set_name("club");
club->set_short("club");
club->set_long("A big wooden club.\n");
club->set_value(150);
club->set_weight(2);
goblin->init_command("wield club");
}
if (arg) return;
set_light(3);
short_desc = "hut";
long_desc = "A strange hut.\n"
+ "There is an incredible stench coming from this room.\n" + "There is a table and some old chairs in the northeastern corner.\n"
+ "There is a small window on the west wall.\n"
;
items = ({
"chair","An old rickety looking chair",
"table","An old rotting table",
"window","You look outside the window and see an army of orcs coming\n"+"in this direction",});
dest_dir = 
({
"players/jake/goblin/gob3","south",
});
}
