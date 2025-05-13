
#define OBJ "players/whisky/seaworld/obj/"

inherit "/obj/npc";

void reset(int arg) 
{
  ::reset(arg);

  if (arg) return;
    set_name("octopus");
    set_alias("fish");
    set_race("fish");
    set_short("A big octopus");
    set_long("You see a really big octopus staring at you angrily.\n");
    set_aggressive(1);
    set_level(16);
    set_has_gills();
    set_size(4);
    set_spell_mess1("");   
    set_spell_mess2("The octopus spreads some inc on you");   
    set_chance(8);
    set_wc(6);
    set_attacks(8);
    set_attacks_change(50);
    set_spell_dam(random(40));
    move_object(clone_object(OBJ+"chest2"),this_object());
    move_object(clone_object(OBJ+"green_star"),this_object());
}
