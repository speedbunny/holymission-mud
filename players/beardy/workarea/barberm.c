inherit "obj/monster";

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("Little Beardy the barber");
    set_alt_name("barber");
    set_alias("barber");
    set_short("huge Barber");
    set_long("A huge Barber and his knife is waiting\n"+
             "for YOU. Beware he is tough !\n");
    set_gender(1);
    set_hp(2000);
    set_level(20);
    set_al(-1000);
    set_aggressive(0);

    set_spell_mess1("TSCHAK ! What a tricky attack... ");
   set_chance(30);
    set_spell_dam(100);

    move_object(clone_object("/players/beardy/workarea/bknife"),this_object());
    init_command("wield knife");
    move_object(clone_object("/players/beardy/workarea/sfoam"),this_object());
  }
}
