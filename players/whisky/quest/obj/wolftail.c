inherit "obj/treasure";

  reset(arg) {
  
  if (arg) return;
  
   set_id("wolftail");
   set_alias("tail");
   set_short("A black wolftail");
   set_long("A long, black wolftail.\n");
   set_weight(1);
   set_value(100);
   
   }
   
 query_quest_item() { return 1; }
