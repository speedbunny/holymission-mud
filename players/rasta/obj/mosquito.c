
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("mosquito");
    set_level(2); 
    set_al(10); 
    set_race("animal"); 
set_short("A mosquito");
    set_whimpy(); 
    add_money(random(50)+10);
}
}
