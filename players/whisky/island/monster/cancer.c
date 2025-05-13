/* an example, our monster should have a talk and should wield a weapon */

inherit "obj/monster"; /* we take the standardobj */

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("cancer");
    set_level(2); 
    set_size(1);
    set_hp(60); 
    set_race("fish"); 
    set_short("A big cancer"); 
    set_long("You see a big cancer snapping between your legs.\n");
    load_chat(14,({
      "S n a p p \n", /*it makes 8 talkes per reset */
      "The cancer snaps after your toe\n"}));
    move_object(clone_object("players/whisky/island/obj/claws"),
    this_object()); 
    init_command("wield claws"); 
}
}
