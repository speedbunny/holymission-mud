inherit "obj/armour";

  reset(arg) {
     ::reset(arg);
     
  if (arg) return;
  
  set_name("fshoes");
  set_alias("shoes");
  set_short("A pair of dancing shoes");
  set_long("A nice pair of dancing shoes.\n");
  set_type("boot");
  set_ac(0);
  set_value(200);
  set_weight(2);
  
  }
  
  drop() {
   write("Your boots vanish.\n");
   destruct(this_object());
   return 1;
   }
   
  
  
  
