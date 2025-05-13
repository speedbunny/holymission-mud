inherit "obj/weapon";
      
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("A jeweled sword");
     set_long("A longsword made from the strongest steel.  It has been tempered with a rare\n"+
                    "metal to make it appear gold in color.  Several gems sparkle at its hilt.\n");
     set_class(13);
     set_weight(3);
     set_value(5200);
  }
}
    
