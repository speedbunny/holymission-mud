
inherit "obj/monster"; 
    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("monkey");
    set_level(11); 
    set_ac(2);
    set_wc(6);
    set_al(10); 
    set_race("animal"); 
    set_short("A little monkey"); 
    set_long("You see a vine climbing monkey. He jumps from\n" +
              "vine to vine quickly and excitedly.  He is a\n" +
	      "cute little monkey.\n");
    set_spell_mess1("Squeeeaaakkkkkkkk");
    set_spell_mess2("Squeeeaaaaakkkkkkkkk");
    add_money(5);
}
}
