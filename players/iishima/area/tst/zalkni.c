inherit "obj/monster";
object weapon;
reset(){
::reset();
set_name("zalpur knight");
set_level(7);
set_alias("knight");
set_short("A Zalpur Knight");
set_race("Zalpur");
set_long("The Zalpur Knight is dressed in shiney, silver armour.  The reflection from what little bit of sunlight is shining through the tops of the trees is almost blinding.  This character looks very tough.  Knights are the second strongest class of Zalpurs. He is equiped with a powerful sword.\n");
set_hp(120);
set_level(8);
set_gender(1);
load_weapon();
}
load_weapon(){
if(!weapon){
weapon=clone_object("players/iishima/area/weapons/zalsword.c");
move_object(weapon,this_object());
init_command("wield sword");
}
}
