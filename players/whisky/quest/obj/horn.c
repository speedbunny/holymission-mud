inherit "obj/treasure";

  reset(arg) {
  
  if (arg) return;
  
  set_id("hhorn");
  set_alias("horn");
  set_short("A long brown horn");
  set_long("A long bone horn. It looks like hunters use it for the hunt.\n");
  set_weight(1);
  set_value(400);
  }
  
  init() {
    add_action("blow","blow");
    ::init();
    }
    
   blow(arg) {
     if (arg!="horn") return;
     write("T U U U U T you blow the horn.\n");
     say(this_player()->query_name()+" blows the horn.\n");
     return 1;
     }
     
  query_quest_item() { return 1; }
  
