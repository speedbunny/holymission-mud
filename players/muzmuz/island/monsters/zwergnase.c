inherit "obj/monster";

object hornsword;
object mail;
object shield;
object helm;
object boots;
object sprite;

reset (arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name ("Zwergnase");
  set_alias("zwergnase");
  set_race("dwarf");
  set_short("Ugly Zwergnase");
  set_long("This is the very dangerous Zwergnase, watch out !\n");
  set_level(40);
  set_aggressive (1);
  set_size (3);
  hornsword = clone_object("players/muzmuz/obj/hornsword");
  move_object(hornsword,this_object());
  init_command("wield sword");
  mail = clone_object("players/muzmuz/obj/mail");
  move_object(mail,this_object());
  init_command("wear mail");
  shield = clone_object("players/muzmuz/obj/shield");
  move_object(shield,this_object());
  init_command("wear shield");
  helm = clone_object("players/muzmuz/obj/helm");
  move_object(helm,this_object());
  sprite = clone_object("/players/muzmuz/island/sprite");
  move_object(sprite,this_object());
  init_command("wear helm");
   boots = clone_object ("players/muzmuz/obj/boots");
   move_object (boots,this_object());
   init_command ("wear boots");
 
return (1) ;
 }
 


