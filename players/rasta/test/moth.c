
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("moth");
    set_level(2);
    set_al(2);
    add_money(random(30));
    set_race("animal");
set_short("A sleeping moth");
    set_whimpy();
}
}
