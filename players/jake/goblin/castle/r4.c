inherit "room/room";
object knight,armour,sword;
reset (arg) {
knight=clone_object("obj/monster");
transfer(knight,this_object());
knight->set_name("black knight");
knight->set_short("black knight"); 
knight->set_long("A large black knight.\nHe looks down at you with a grim smile.\nHe obviously thinks he is tougher than you.\n");
knight->set_alias("knight");
knight->set_level(20);
knight->set_hp(1000);
knight->set_al(0);
knight->set_race("goblin");
knight->set_size(3);
armour=clone_object("obj/armour");
transfer(armour,knight);
armour->set_name("black plate");
armour->set_short("black plate");
armour->set_long("A black as night platemail.\nIt looks very strong, and heavy.\n");
armour->set_ac(3);
armour->set_weight(5);
armour->set_size(3);
armour->set_value(2000);
sword=clone_object("obj/weapon");
transfer(sword,knight);
sword->set_name("black longsword");
sword->set_short("black longsword");
sword->set_long("A very large and strong looking longsword.\nIt looks heavy.\n");
sword->set_wc(16);
sword->set_weight(5);
sword->set_value(5000);
knight->init_command("wield black longsword");
if (arg) return;
set_light(2);
short_desc = "armoury";
long_desc = "There are shields and swords lining the walls of this room.\n"
 + "A black carpet covers the floor.\n" 
 + "A large knight is here, suiting up for battle.\n";
items = ({
 "carpet","A tattered looking black carpet.\nIt looks like many feet have walked across it",
 "walls","Grey stone walls with various shields and swords hanging on them",
 "shields","Numerous colorful shields adorning the walls.\nMany have pictures of dragons on them, while others have pictures of birds and rabbits",
 "swords","Shortswords, longswords, and regular swords are hung on the wall for the knights to use for battles",
 "floor","A red stone floor",
});
dest_dir = ({
 "players/jake/goblin/castle/r3","west",
});
}
