inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);

 if (arg) return;
    set_name("sword fish");
    set_alias("fish");
    set_race("fish");
    set_short("An aggressive sword fish");
    set_long("You see a big fish, which looks as it don't like strangers.\n");
    set_hp(350);
    set_aggressive(1);
    set_level(20);
    set_has_gills();
    set_size(4);
    set_spell_mess1("");   
    set_spell_mess2("The sword fish trust it's sword deep into your ribs");   
    set_chance(8);
    set_spell_dam(40);
    move_object(clone_object("players/whisky/seaworld/obj/swordfish_sword"),this_object());
    move_object(clone_object("players/whisky/seaworld/obj/blue_star"),this_object());
    command("wield sword");
}
