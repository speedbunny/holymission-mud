#define OBJ "players/whisky/seaworld/obj/"

inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);

  if (arg) return;
     set_name("saw fish");
     set_alias("fish");
     set_race("fish");
     set_short("An aggressive saw fish");
     set_long("You see a big fish, which looks as it don't like strangers.\n");
     set_aggressive(1);
     set_level(18);
     set_has_gills();
     set_size(4);
     set_hp(500);
     set_spell_mess1("");   
     set_spell_mess2("C H U P ........The saw fish saw up your bones");   
     set_chance(9);
     set_spell_dam(60);
     move_object(clone_object(OBJ+"sawfish_saw"),this_object());
     move_object(clone_object(OBJ+"red_star"),this_object());
     command("wield saw");
}
