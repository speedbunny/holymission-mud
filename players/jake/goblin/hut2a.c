inherit "room/room";
object baby,nanny,brat,sword;
reset (arg) {
if (!baby || !nanny || !brat) {
baby=clone_object("obj/monster");
transfer(baby,this_object());
baby->set_name("baby goblin"); 
baby->set_short("baby goblin");
baby->set_level(5);
baby->set_alias("baby");
baby->set_long("A cute little baby goblin.\n");
baby->add_money(100);
baby->set_align(100);
baby->set_aggressive(0);
nanny=clone_object("obj/monster");
transfer(nanny,this_object());
nanny->set_name("nanny goblin");
nanny->set_short("nanny goblin");
nanny->set_long("This is a nanny goblin.\nShe watches the children while mom makes dinner.\n"); 
nanny->set_level(20);
nanny->set_align(10);
nanny->set_aggressive(0);
nanny->set_alias("nanny");
nanny->set_race("goblin");
nanny->add_money(300);
brat=clone_object("obj/monster");
transfer(brat,this_object());
brat->set_name("goblin brat");
brat->set_short("goblin brat");
brat->set_long("This is a young goblin.\nHe is a pain in the butt.\n");
brat->set_level(15);
brat->set_alias("brat");
brat->set_align(10); 
brat->set_aggressive(0);
brat->add_money(100);
sword=clone_object("obj/weapon");
transfer(sword,brat);
sword->set_name("wooden sword");
sword->set_short("wooden sword");
sword->set_long("An old wooden sword.\nIt is all but useless.\n");
sword->set_wc(1);
sword->set_value(100);
sword->set_weight(1);
brat->init_command("wield sword");
}
if (arg) return;
set_light(3);
short_desc = "hut2a";
long_desc =  
"You have entered what appears to be some kind of a nursery.\n"
+ "This room is a disaster.  There are toys all over the place.\n" 
+ "A nanny is trying to tend these children with little success.\n";
items = ({
"toys","little wooden toys all over the floor",
});
dest_dir = ({
"players/jake/goblin/hut2","south",
"players/jake/goblin/hut2b","down",
});
}
