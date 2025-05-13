
#define TO this_object()

inherit "obj/monster";

void reset(int arg) 
{
  ::reset(arg);

  if (arg) return;
    set_name("sea drake");
    set_alt_name("drake");
    set_level(68);
    set_has_gills();
    set_size(5);
    set_hp(4000);
    set_al(-400);
    set_alt_name("drake");
    set_race("drake");
    set_short("A huge red sea drake");
    set_long("A big red sea drake nearly 40 feet high\n"+
            "It's claws have the length from the half of a human feet.\n"+
             "It's eyes are bright as fire and its skin seems\n" +
             "stronger than steel plates.\n");
    set_ac(15);
    set_spell_mess1("");
    set_spell_mess2("The drake converts you to hash"); 
    set_chance(8); 
    set_spell_dam(random(160));
    move_object(clone_object("players/whisky/seaworld/obj/golden_star"),TO);
/*
    move_object(clone_object("/players/whisky/obj/hearo_potion"),TO);
*/
}

 hold (caller,time)
{
  return ::hold(caller,random(random(time)) );
}
run_away() { return 0; }
stop_fight() { return 0; }
