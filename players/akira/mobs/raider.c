inherit "obj/monster";
reset(arg){
::reset(arg);

set_name("Temporal Raider");
set_alias("raider");
set_short("Temporal Raider");
set_long("This is a evil vagabond that has become a Temporal Raider. He\n"+
         "uses his powers to travel through time and space to steel and\n"+
         "kill thouse weaker then himself. Should he ever find a vagabond\n"+
         "he would enjoy ripping there heart out!\n");
set_level(20);
set_number_of_arms(2);
set_wc(10);
set_ac(10);
set_aggressive(1);
move_object(clone_object("/players/akira/weapons/t_sword"), this_object());
move_object(clone_object("/players/akira/vag/armour/helm"), this_object());
move_object(clone_object("/players/akira/vag/armour/shield"), this_object());
move_object(clone_object("/players/akira/vag/armour/platemail"), this_object());
init_command("powerup");
}
