inherit "obj/treasure";

reset(arg)
{
    ::reset(arg);
    if (arg) 
       return;
    set_name("sheet of fine vellum");
    set_alias("vellum");
    set_alt_name("sheet");
    set_short("Sheet of fine vellum");
    set_long("Upon this vellum is written the ingredients to many potions.\n"
      +"The writing is small and spidery but you think you could read it.\n");
    set_read(
      "Several recipes for poisons\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      +"Dragons' Breath\n"
      +"     2 parts Dragons' Blood\n"
      +"     1 part Eye of Newt\n"
      +"     4 parts Blackthorn root\n\n"
      +"Nightshade\n"
      +"     1 part Powdered Unicorns' Horn\n"
      +"     1 part Tail of Cockatrice\n"
      +"     3 parts Dragons' Blood\n"
      +"     2 part Eye of Newt\n"
      +"     8 parts Blackthorn root\n\n"
      +"Viper\n"
      +"     1 part Dragons' Blood\n"
      +"     4 parts Blackthorn root\n\n"
      +"Mandrake\n"
      +"     1 part Dragons' Blood\n"
      +"     2 parts Tail of Cockatrice\n"
      +"     2 parts Eye of Newt\n"
      +"     7 parts Blackthorn root\n");
}

get() {
    write("The vellum seems to be stuck on the wall.\n"
	  + "You don't want to rip it.\n");
    return 0;
}
