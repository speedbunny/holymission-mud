inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("racoon");
    set_level(2);
    set_alias("racoon");
    set_alt_name("plump racoon");
    set_race("racoon");
    set_short("Plump racoon");
    set_long("A well fed racoon. Its masked eyes and soft fur seem to\n"+
             "glow with a internal fire. Its keeping an eye on you.\n");
    set_wc(2);
    set_ac(2);
    set_move_at_reset();
    load_chat(5,({
                  "Racoon sniffs at the ground looking for something.\n",
                  "Racoon runs quickly past you.\n",
                  "Racoon licks its front paws.\n",
                  "Racoon jumps at a sound in the underbrush.\n",
                 }));
    set_gender(random(2)+1);
    set_chance(1);
    set_spell_mess1("Racoon jumps on you");
    set_spell_mess2("Racoon scratches you with its front paws!");
    set_spell_dam(10);
    add_money(random(20)+5);
  }
}
