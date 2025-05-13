
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("smelly skunk");
    set_alias("skunk");
    load_chat(8,({"Skunk sees you and lifts it's tail in defense.\n"}));
    set_level(6); 
    set_ac(2);
    set_wc(6);
    set_al(10); 
    set_race("animal"); 
    set_short("A fat skunk"); 
    set_long("You see a fat black skunk with a white stripe on its\n" +
	      "back. You should run now, or be sprayed!\n");
    set_spell_mess1("The skunk turns its bakc on you and aims");
    set_spell_mess2("Skunk sprays you with a foul smelling slime");
    add_money(25);
}
}
