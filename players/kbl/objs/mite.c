/* Cavern mite */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("mite");
    set_gender(random(2)+1);
    set_level(10);
    set_hp(random(80)+40);
    set_sp(random(40)+40);
    set_alias("mite");
    set_race("pixie");
    set_short("Cavern mite");
    set_long("A small brown looking creature that has sharp teeth.\n"+
             "Seems to be grinning continously\n");
    set_str(random(5)+9);
    set_dex(random(5)+9);
    set_wis(random(5)+9);
    set_int(random(5)+9);
    set_con(random(5)+9);
    set_chr(random(5)+9);
    set_ac(8);
    set_wc(10);
    set_aggressive(random(2));
    set_whimpy();
    set_move_at_reset();
    load_chat(8,({
        "Mite growls: Get out of my home!\n","Mite snickers: Your mama!\n",
        "Pixie mite pisses on your leg.\n","Mite laughs at you.\n",
        "Cavern mite runs circles around you.\n",
        "Mite barks: GET OUT!\n",
                  }));
    set_spell_mess1("Pixie mite slaps you");
    set_spell_mess2("Pixie mite slams you hard!");
    set_chance(5);
    set_spell_dam(15);
  }
}
