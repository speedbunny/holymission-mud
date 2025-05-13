inherit "obj/treasure";

   reset(arg) {
   
   if (arg) return;
   
   set_id("patience_sign");
   set_alias("sign");
   set_short("A wooden sign");
   set_long(
            "You see a wooden sign pointing to the south.\n");
   set_weight(1000);
   }
   
   init() {
    add_action("destruct","destruct");
    add_action("south","south");
    add_action("south","enter");
    ::init();
    }
    
    destruct() {
      if ((!this_player()->query_real_name()=="moonchild") || (!this_player()->query_real_name()=="patience")) return;
      destruct(this_object());
      return 1;
      }
    south() { 
    
      this_player()->move_player("south#players/patience/smilequest/guardroom");
      
    return 1; 
    
    }
