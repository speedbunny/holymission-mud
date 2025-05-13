/* an example, our monster should have a talk and should wield a weapon */

inherit "obj/monster"; /* we take the standardobj */

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("cancer");
    set_alt_name("river cancer");
    set_level(2); 
   set_has_gills();
    set_size(1);
    set_hp(60); 
    set_race("fish"); 
    set_short("A big river cancer"); 
    set_long("You see a big cancer snapping after your toe.\n");
    load_chat(14,({
      "S n a p p \n", 
      "The cancer snapps after your toe\n"}));
    move_object(clone_object("players/whisky/lake/obj/claws"),
    this_object()); 
    init_command("wield claws"); 
}
}

