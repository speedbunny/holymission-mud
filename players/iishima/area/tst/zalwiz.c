inherit "obj/monster";
object weapon;
reset(){
::reset();
set_name("zalpur wizard");
set_alias("wizard");
set_short("A Zalpur Wizard");
set_long("The Zalpur Wizard is dressed in a black robe. He has a glowing red aura around\n"+
         "himself. This is the most powerful of all Zalpurs. He is highly skilled in combat\n"+
         "and magic. You definitaly do not want to mess with this individual.\n");
set_level(15);
set_hp(200);
set_gender(1);
// load_weapon();
}

load_weapon(){
if(!weapon){
weapon=clone_object("players/iishima/area/weapons/zalsword.c");
move_object(weapon,this_object());
init_command("wield sword");
}
}
