/* Standard random Elf */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("ole man");
    set_gender(1);
    set_level(50);
    set_hp(7000);
    set_sp(7000);
    set_al(5000);
    set_alias("elf");
    set_race("elf");
    set_alias("man");
    set_short("Ole man");
    set_long("A old man of elvin origin. His eyes are glazed over but you\n"+ 
             "you know he \"see's\" you. White loin cloth is all he wears\n");
    set_str(40);
    set_dex(40);
    set_wis(40);
    set_int(40);
    set_con(40);
    set_chr(40);
    set_aggressive(0);
    load_chat(8,({
           "Ole man smiles at you.\n","Ole man stretchs his old bones.\n",
           "Ole man sez: There's a tree house in the strangest place.\n"+
           "Ole man sez: A Troll Demon of Chaos can be bribed with dark crystal.\n",
           "Ole man sez: Scan the Parallel Plane of Chaos! Examines are useless!\n",
           "Ole man sez: Jump into the garbage pit!\n",
           "Ole man giggles\n","Ole man takes small glass from basket and"+
           " drinks water from it.\n",
           "Ole man searches the void with his mind.\n",
           "Ole man looks into the middle distance.\n",
           "Ole man says: Do you have a Black Heart gem?? I need it\n",
           "Ole man thinks: Have you been to the giant pines?\n",
           "Ole man grins at you.\n","Ole man yawns.\n",
           "Ole man looks up at you.\n","Ole man sits down in lotus position.\n",
           "Ole man scans the void with his mind.\n",
           "Arch DOC's private chambers is where you'll find the AnySlayer.\n",
                 }));
    set_spell_mess1("Ole man slaps your face!");
    set_spell_mess2("Ole man head butts you!");
    set_chance(10);
    set_spell_dam(30);
  }
}
