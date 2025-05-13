inherit "obj/treasure";

reset(arg)
{
    ::reset(arg);
    if (arg)
       return;
    set_name("sheet of fine parchment");
    set_alias("parchment");
    set_alt_name("sheet");
    set_short("Sheet of fine parchment");
    set_long("Upon this parchment is written the ingredients to many potions.\n"
      +"The writing is small and spidery but you think you could read it.\n");
    set_read(
      "Several recipes for poisons\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      +"Dragons' Venom\n"
      +"     1 part Powdered Unicorn's Horn\n"
      +"     4 parts Dragons' Blood\n"
      +"     1 part Eye of Newt\n"
      +"     3 parts Blackthorn root\n\n"
      +"Scorpions' Blood\n"
      +"     1 part Tail of Cockatrice\n"
      +"     1 part Eye of Newt\n"
      +"     3 parts Blackthorn root\n\n"
      +"Witches' Bane\n"
      +"     1 part Eye of Newt\n"
      +"     3 parts Blackthorn root\n\n"
      +"Basilisks' Eye\n"
      +"     3 parts Blackthorn root\n\n"
      +"Hemlock\n"
      +"     1 part Dragons' Blood\n"
      +"     1 part Tail of Cockatrice\n"
      +"     2 part Eye of Newt\n"
      +"     5 parts Blackthorn Root\n");
}

get()
{
    write("The parchment seems to be stuck on the table.\n"
	  + "You don't want to tear it.\n");
    return 0;
}
