inherit "obj/treasure";

reset(arg) {

  if (!arg) {
    set_id("shroom");
    set_short("A Shroom");
    set_long("A delicious looking magic mushroom!\n");
    set_value(5);
    set_weight(1);
  }
}
     
  init() {
    add_action("eat","eat");
   ::init();
  }
  eat(arg) {
   if (arg != "shroom"){
        say(this_player()->query_name()+" eats a Shroom.\n");
    switch(random(2)){
    case 0:
     write("WHHEEEEEEEEEEEE !! Shroom!! Shroom!! Shroom!!.\n");
     say(this_player()->query_name()+" smiles deliriously.\n");
     break;
    case 1:
     write("Your head starts spinning at a million miles an hour");
     say(this_player()->query_name()+" is as high as a kite.\n");
     break;
    this_player()->eat_food(1);
    destruct(this_object());
    command("dream",this_player());
   return 1;
  }
}
}
