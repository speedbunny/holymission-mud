
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("goat");
    set_level(3);
    set_al(2);
    add_money(random(50)+10);
    set_race("animal");
set_short("it's playing the giddy goat");
    set_whimpy(); 
}
}
