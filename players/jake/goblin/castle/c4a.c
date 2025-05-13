inherit "room/room";
object gob,sword,helm;
reset (arg) {
if (!gob) {
gob=clone_object("obj/monster");
transfer(gob,this_object());
gob->set_name("goblin guard");
gob->set_short("tower guard");
gob->set_level(15); 
gob->set_alt_name("guard");
gob->set_hp(900); 
gob->set_al(100);
gob->set_aggressive(0);
gob->add_money(500);
sword=clone_object("obj/weapon");
transfer(sword,gob);
sword->set_name("sword");
sword->set_short("sword");
sword->set_long("An ordinary looking sword.\n");
sword->set_weight(2);
sword->set_value(500);
sword->set_wc(2);
gob->init_command("wield sword");
helm=clone_object("obj/armour");
transfer(helm,gob);
helm->set_name("helmet");
helm->set_short("metal helmet");
helm->set_type("helmet");
helm->set_long("A metal helmet");
helm->set_size(3);
helm->set_ac(1);
helm->set_weight(2); 
helm->set_value(400);
gob->init_command("wear metal helmet");
}
if (arg) return;
set_light(3);
  short_desc = "bottom floor...south east tower";
  long_desc = 
               "This is the east side guard tower.\n"
            +  "The floor is of the same red stone as the hall.\n"
            +  "There are windows in each wall.\n"
            +  "A narrow set of wooden steps leading up.\n";
items = ({
         "floor","It is made of red stones",
         "ceiling","It is made of wood, probably oak",
         "wall","Grey stone walls.  There are small windows in each wall",
         "stairs","Small wooden steps leading up",
         "window","Looking out the window you can see the wall of the castle.\nIt looks very large and solid",
         "steps","Small wooden steps leading up",
});
dest_dir = ({
         "players/jake/goblin/castle/c4","northwest",
         "players/jake/goblin/castle/c4b","up",
});
}
