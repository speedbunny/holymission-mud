
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("monkey");
    set_level(12); 
    set_ac(2);
    set_wc(6);
    set_al(10); 
    set_race("animal"); 
    set_short("A little monkey"); 
    set_long("You see a cute brown-eyed island-monkey.\n" +
               "frightend looking at you.\n");
    set_whimpy(90);
    set_spell_mess1("Squeeeeeeekkkkkkkkk");
    set_spell_mess2("Squeeeeeeekkkkkkkkk");
    move_object(clone_object("players/whisky/island/obj/banana"),
    this_object()); 
    move_object(clone_object("players/whisky/island/obj/monkey_fur"),
    this_object());
}
}
