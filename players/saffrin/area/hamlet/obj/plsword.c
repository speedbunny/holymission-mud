inherit "obj/weapon";
      
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Player's sword");
     set_long("This is a small wooden sword that is used by a stage player when they are\n"+
                    "performing swordplay.\n");
     set_class(1);
     set_weight(1);
     set_value(400);
  }
}
