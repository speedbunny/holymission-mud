inherit "obj/monster";

object cloak,boots,gloves,armor,sword;
reset (arg){
 ::reset(arg);
 if(!arg){
  set_name("eric");
  set_short("Eric");
  set_long("You see a large man with hair so black as to almost be blue.\n"+
           "He is dressed mostly in black, except for his longsword which\n"+
           "glows with a silverish light.  He stands ready to guard the\n"+
           "the unicorn from you.\n");
  set_level(50);
  set_gender(1);
  set_race("human");
  set_hp(12000);
  set_wc(65);
  set_ac(50);
  set_spell_mess1("Eric cleaves your skull with his sword.\n");
  set_spell_mess2("Eric slices through you armor and smiles.\n");
  set_chance(40);
  set_spell_dam(170);
  set_aggressive(1);
  sword=clone_object("players/ambrose/avalon/weapons/esword");
  armor=clone_object("players/ambrose/avalon/armour/earmor");
  cloak=clone_object("players/ambrose/avalon/armour/ecloak");
  gloves=clone_object("players/ambrose/avalon/armour/egloves");
  boots=clone_object("players/ambrose/avalon/armour/eboots");
  move_object(sword,this_object());
  move_object(armor,this_object());
  move_object(cloak,this_object());
  move_object(gloves,this_object());
  move_object(boots,this_object());
  init_command("powerup");
  }
 }
