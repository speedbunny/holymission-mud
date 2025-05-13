/* Arch Demon Of Chaos */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("Zesranotae");
    set_level(65);
    set_alias("doc");
    set_alt_name("Zesranotae");
    set_al(-5000);
    set_race("demon");
    set_gender(1);
    set_chr(5);
    set_short("Arch Demon of Chaos Zesranotae");
    set_long("Zesranotae is the Arch DOC and for good reasons. The Troll\n"+
             "DOC are his best pals and you might find them around him!\n"+
             "Zesranotae is very well built and has very powerful abilities.\n"+
             "You may not be able to kill him!\n");
    set_aggressive(0);
    set_whimpy(50);
    load_chat(8,({
        "So, puny fleshlings want to visit me, eh?\n",
        "Take your smelly hides away from here!\n",
        "Die, so I may become more powerful! Muhahahahahahahahahaaaaaa!!!\n",
        "There's no moon to bark at here, so go back to you MUDplane!\n",
        "Zesranotae gives you the finger.\n",
        "You feel something probing your mind!\n",
        "Zesranotae walks back and forth looking at you.\n",
        "Arch DOC Zesronatae mentally communicates with someone higher up.\n",
         "Zesranotae kicks you!\n",
                  }));
    set_spell_mess1("Zesranotae slams your act!\n");
    set_spell_mess2("Zesranotae throws you across the room into the wall!\n");
    set_chance(30);
    set_spell_dam(50);
  }
}
