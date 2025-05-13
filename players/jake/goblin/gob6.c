inherit "room/room";
object gob,spe;
reset (arg) {
if (!gob) {
gob=clone_object("obj/monster");
transfer(gob,this_object());
gob->set_name("dying goblin");
gob->set_short("dying goblin");
gob->set_long("A dying goblin\nHe is severely injured.\n");
gob->set_alias("goblin");
gob->set_level(20);
gob->set_hp(150);
gob->set_align(100);
gob->add_money(200);
spe=clone_object("obj/weapon");
transfer(spe,gob);
spe->set_name("spear");
spe->set_short("spear");
spe->set_long("A wooden spear.");
spe->set_wc(3);
spe->set_value(300);
spe->set_weight(2);
}
if (arg) return;
set_light(3);
short_desc = "gob6";
long_desc = "A small clearing surrounded by shrubs and trees.\n"
+ "Footsteps appear to lead right into part of the shrubs.\n";
items = ({
 "trees","Tall trees",
 "footsteps","These footsteps lead right towards a bush!",
 "bush","Maybe you can 'push' through the bush?",
});
dest_dir = ({
"players/jake/goblin/gob5","north",
});
}
