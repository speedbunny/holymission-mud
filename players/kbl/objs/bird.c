inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("bird");
    set_level(2);
    set_alias("bird");
    set_alt_name("song bird");
    set_race("bird");
    set_short("Yellow song bird");
    set_long("A beautiful yellow house finch. Its eyes sparkle as it\n"+
             "darts about.\n");
    set_wc(2);
    set_ac(15);
    set_move_at_reset();
    load_chat(12,({
                  "Bird flies down to the ground.\n",
                  "Bird pecks at the ground looking for fallen berries.\n",
                  "Song bird flies up into the limbs.\n",
                  "Tweeeeeee, Tweeeeeee *snap* Cheeeeeew Cheeeeeeew\n",
                  "Bird cleans its wings\n",
                  "Bird ruffles its feathers\n",
                  "Bird flies in circles above the ground\n",
                  "Bird flies in circles around a branch\n",
                 }));
    set_gender(random(2)+1);
    set_chance(1);
    set_spell_mess1("Bird flies into your face!");
    set_spell_mess2("Bird pecks you hard!");
    set_spell_dam(5);
    add_money(random(5)+5);
  }
}
