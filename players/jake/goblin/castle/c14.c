inherit "room/room";
object hob,cape;
reset (arg) {
if (!hob) {
hob=clone_object("obj/monster");
hob->set_name("hob-goblin");
hob->set_short("hob-goblin dame");
hob->set_long("A female hob-goblin.\n");
hob->set_race("goblin");
hob->set_size(3);
hob->set_level(10);
hob->set_hp(400);
hob->set_alias("dame");
hob->set_al(100);
hob->add_money(250);
cape=clone_object("obj/armour");
cape->set_name("green cape");
cape->set_short("green cape");
cape->set_long("An ugly green cape.\n");
cape->set_size(3);
cape->set_alias("cape");
cape->set_weight(2);
cape->set_value(400);
cape->set_ac(1);
hob->init_command("wear green cape");
move_object(cape,hob);
move_object(hob,this_object());
}
if (arg) return;
set_light(1);
short_desc = "c14  North Hallway  E/W";
long_desc = "The hallway extends east and west.\n"
          + "A white carpet lines the floor, and a small doorway\n"
          + "is in the north wall.\n";
items = ({"floor","It is made of red stone",
          "ceiling","It is made of white stone",
          "wall","It is made of grey stone, and has a small doorway in it",
          "doorway","A small doorway into the castle stables",
          "carpet","A beautiful white carpet with muddy footprints coming from the north",
});
dest_dir = ({
     "players/jake/goblin/castle/c13","east",
     "players/jake/goblin/castle/c15","west",
     "players/jake/goblin/castle/s1","north",
});
}
