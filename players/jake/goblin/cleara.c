inherit "room/room";
object wolf,rabbit;
reset (arg) {
if (!wolf || !rabbit) {
wolf=clone_object("obj/monster");
transfer(wolf,this_object());
wolf->set_name("wolf");
wolf->set_short("wolf");
wolf->set_long("This is a very hungry looking wolf.\nI think you have interrupted his dinner plans.\n");
wolf->set_level(5);
wolf->set_hp(150);
wolf->set_wc(3);
wolf->set_ac(1);
wolf->set_align(-100);
wolf->set_aggressive(1);
wolf->add_money(100);
wolf->set_race("animal");
rabbit=clone_object("obj/monster"); 
transfer(rabbit,this_object());
rabbit->set_name("rabbit");
rabbit->set_short("rabbit");
rabbit->set_long("A cute little bunny-rabbit.\nIt is relieved that you have come to save him from the wolf.\n");
rabbit->set_level(5);
rabbit->set_race("animal");
rabbit->set_align(100);
rabbit->add_money(50);
}
if (arg) return;
set_light(3);
short_desc = "cleara";
long_desc = "A small clearing surrounded by large trees.  Not much else to be seen \nIs here.  Maybe you should continue on with your adventure!\n";
items = ({
"trees","A thick growth of pine trees which surround this clearing",
});
dest_dir = ({
"players/jake/goblin/clear","north",
});
}
