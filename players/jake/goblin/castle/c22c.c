inherit "room/room";
object gob,sword,shield;
reset(arg) {
if (!gob) {
gob=clone_object("obj/monster");
gob->set_name("commander-in-chief");
gob->set_short("commander-in-chief");
gob->set_alt_name("chief");
gob->set_alias("goblin");
gob->set_size(3);
gob->set_long("A goblin commander-in-chief.\nHe is the commander of the outside guards.\n");
gob->set_level(20);
gob->set_hp(1000);
gob->set_al(100);
gob->set_race("goblin");
gob->set_aggressive(0);
gob->add_money(500);
sword=clone_object("obj/weapon");
sword->set_name("longsword");
sword->set_short("longsword");
sword->set_wc(4);
sword->set_weight(4);
sword->set_value(900);
gob->init_command("wield longsword");
shield=clone_object("obj/armour");
shield->set_name("shield");
shield->set_short("guard shield");
shield->set_size(3);
shield->set_type("shield");
shield->set_alias("shield");
shield->set_ac(1);
shield->set_long("This is a guard shield.\nA huge gold dragon is pictured on it.\n");
shield->set_value(800); 
shield->set_weight(2);
gob->init_command("wear guard shield");
move_object(shield,gob);
move_object(sword,gob);
move_object(gob,this_object());
}
if (arg) return;
set_light(3);
short_desc = "c22c  Top of S/W tower";
long_desc =
  "The top of the guard tower.\n"
+ "The room is empty except for a small chair.\n"
+ "A small set of stairs leads back down the tower.\n" 
+ "There are windows in each of the four walls.\n";
items = ({
 "wall","Walls made of grey stone with small windows in them",
 "ceiling","The ceiling is made of wood, with bright red tile",
 "floor","The floor is made of solid oak",
 "chair","A small wooden chair",
 "steps","A narrow set of stairs leading down",
 "window","A beautiful view of the whole mud-land.\nYou see vast forests of trees, along with numerous paths.\nOff in the distance you can see the goblin village",
});
dest_dir = ({
 "players/jake/goblin/castle/c22b","down",
});
}
