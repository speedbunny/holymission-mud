
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("raccoon");
   	set_level(8);
   	set_size(2);
   	set_alias("raccoon");
   	load_chat(8,({"Raccoon looks at you for something to steal.\n"}));
   	set_short("A fat raccoon");
   	set_long("It is a cute little raccoon with a ringed tail.\n");
   	set_spell_mess1("The raccoon claws at you with its paws");
   	set_spell_mess2("The raccoon bites you hard");
  }
}
