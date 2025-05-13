inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("zalpur wizard");
set_alias("wizard");
set_short("A Zalpur Wizard");
set_long("The Zalpur Wizard is dressed in a black robe. He has a glowing red aura around\n"+
         "himself. This is the most powerful of all Zalpurs. He is highly skilled in combat\n"+
         "and magic. You definitaly do not want to mess with this individual.\n");
set_level(15);
set_hp(200);
set_gender(1);
}
