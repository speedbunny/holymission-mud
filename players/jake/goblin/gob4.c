inherit "room/room";
object wgob,cane;
reset (arg) {
if (!wgob) {
wgob=clone_object("obj/monster");
transfer(wgob,this_object());
wgob->set_name("wandering goblin");
wgob->set_short("wandering goblin");
wgob->set_level(10);
wgob->set_alias("goblin");
wgob->set_race("goblin");
wgob->set_long("This is a wandering goblin.\nHe appears somewhat lost.\n");
wgob->set_size(3);
wgob->add_money(100);
wgob->set_align(199);
wgob->set_aggressive(0);
cane=clone_object("obj/weapon");
transfer(cane,wgob);
cane->set_name("cane");
cane->set_short("Walking cane");
cane->set_long("A walking cane");
cane->set_value(100);
cane->set_weight(2);
cane->set_wc(2);
}
if (arg) return;
set_light(3);
short_desc = "gob4";
long_desc = 
"The cobblestone path proceeds west and east.\n"
+ "A weird looking tree has grown through the middle of the path.\n" 
+ "To the north is a small shack, and what appears to be a shop is to the south.\n";
items = ({
"tree","A very strange looking tree\nMaybe you should try climbing it",
"shack","An old looking little house",  
"path","A path made of multi-colored stones",
});
dest_dir = 
({
"players/jake/goblin/gob3","east",
"players/jake/goblin/hut2","north",
"players/jake/goblin/gob5","west",
"players/jake/goblin/shop","south",
});
}
init () {
::init();
add_action("climb");add_verb("climb");
}
climb(str) {
if(str !="tree") return;
call_other(this_player(),"move_player","climbs tree#/players/jake/goblin/tree");
return 1;
}
