inherit "obj/weapon";

  reset(arg) {
  
  ::reset(arg);
  
  if (arg) return;
  
   set_name("hammer");
   set_short("Spiritual Hammer");
   set_long("This is the magical hammer of the clerics.\n");
   set_weight(3);
   set_class((this_player()->query_level()+this_player()->query_wis())/4);
   
  }
  
  drop() {
  
   write("Your hammer falls down on the bottom and fades away.\n");
   destruct(this_object());
   return 1;
   }
