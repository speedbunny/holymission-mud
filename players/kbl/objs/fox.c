/* Random Fox */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("fox");
    set_level(8);
    set_alias("fox");
    set_race("fox");
    set_gender(random(2));
    set_short("Red fox");
    set_long("A very nice looking red fox. Big bushy tail and dark brown eyes.\n");
    set_chance(2);
    set_bat();
    set_spell_mess1("Fox scratches you bad!");
    set_spell_mess2("Fox bites you!");
    set_spell_dam(10);
  }
}

init()
{
  ::init();
}

set_bat()
{
    set_ac(5);
    set_wc(6);
    set_aggressive(random(2));
    set_whimpy();
    set_move_at_reset();
    load_chat(8,({
        "Red fox walks around slowly, looking you over\n",
        "Fox scratches its side\n",
        "Fox licks its right front paw\n",
        "Fox licks its left front paw\n",
        "Fox chases its tail playfully\n",
        "Red fox eats something disgusting\n",
         "Fox rolls around on the ground\n",
                  }));
}
