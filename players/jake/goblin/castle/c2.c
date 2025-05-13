inherit "room/room";
object hob,cape,dag;
reset (arg) {
if (!hob) {
hob=clone_object("obj/monster");
transfer(hob,this_object());
hob->set_name("hob-gobline");
hob->set_short("hob-goblin");
hob->set_long("This is a hob-goblin.  It is a rather large cousin of the goblin.\n");
hob->set_alias("goblin");
hob->set_race("goblin");
hob->set_level(20);
hob->set_size(3);
hob->set_al(100);
hob->add_money(500);
hob->set_aggressive(0);
cape=clone_object("obj/armour");
transfer(cape,hob);
cape->set_name("cape");
cape->set_short("cape");
cape->set_long("A red cape.\n");
cape->set_ac(1);
cape->set_type("cloak");
cape->set_value(500);
cape->set_size(3);
cape->set_weight(2);
hob->init_command("wear cape");
dag=clone_object("obj/weapon");
transfer(dag,hob);
dag->set_name("dagger");
dag->set_short("dagger");
dag->set_long("A small metal dagger.\n");
dag->set_weight(2);
dag->set_wc(1);
dag->set_value(500);
hob->init_command("wield dagger");
}
if (arg) return;
set_light(2);
short_desc = "c2";
long_desc = "The hall continues east and west.\n"
+ "A black carpet still extends to both ends of the hall.\n"
+ "A small window in the southern wall.\n";
items = ({ 
"floor","It is made of ruby red stones",
"ceiling","Made of white stones",
"window","Looking out the window, you can see the faint silouhette of the goblin village",
"wall","There is nothing on it.  It is made of grey stone",
"carpet","A black carpet that extends to both ends of the hall",
});
dest_dir = ({
"players/jake/goblin/castle/c1","west",
"players/jake/goblin/castle/c3","east",
});
}
