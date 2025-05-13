inherit "obj/food";                                                             
                                                                                
reset() {                                                                       
  set_short("A lembas");
  set_long("These waffles are called lembas. It's a specialty of the Elves.\n");
  set_name("lembas");
  set_eater_mess("Very well, indeed!\n");
  set_eating_mess(" eats a whole lembas.\n");
  set_strength(100);
  set_value(5000);
}

init() {
::init();
  add_action("breaking","break");
} 

prevent_insert() { return 0; }

breaking(str) {
  object new;

  if(!id(str)) return;

  write("You break off a little piece of the waffle.\n");

  new=clone_object("obj/food");
  new->set_name("lembas");
  new->set_alias("piece");
  new->set_short("A piece of a lembas");
  new->set_long("These waffles are called lembas. It's a specialty of the "+
                "Elves.\nThis is only a small piece of a much bigger.");
  new->set_eater_mess("Very well, indeed!\n");
  new->set_eating_mess(" eats a piece of a lembas.\n");
  new->set_strength(10);
  new->set_value(500);
  this_object()->set_strength(strength-10);
  move_object(new,environment(this_object()));
  if(strength<=0) {
    destruct(this_object());
    write("It was the last piece.\n");
  }
  return 1;
}
