inherit "/obj/thing";

reset(arg) {
  if (arg) return 1;
  set_name("rug");
  set_short("A rug");
  set_version(0);
  set_can_get(0);
}

set_version(version) {
  switch(version) {
    case 1: set_long("This elven floor covering is identifiable by the fine stitchwork and intricate patterns.\n"); 
    break;
    case 2:set_long("This expensive rug is embroidered with a halfling design.\n"); 
    break;
    case 3:set_long("This finely woven rug must have been imported from the Isles of Tagor.\n"); 
    break;
    case 4:set_long("This rug must have been woven by the skilled hands of Earl the Weaver.\n"); 
    break;
    default: set_long("This finely woven rug spans the entire room.\n");
  }
  return (this_object());
}

init() {
  ::init();
  add_action("burn","burn");
  add_action("burn","light");
}

burn(str) {
  string what,util;
  object outil;
  
  if (!str) return 0;
  
  util = 0;
  if (!id (str)) {
    if ((sscanf(str,"%s with %s",what,util)!=2)
     || !id(what))
    return 0;
  }
  
  if (util && (util!="torch") && (util!="lighted torch")) {
    if (outil=present(util,this_player())) {
      if (!outil->id("lighted_torch")){
        write("Why do you think, you can burn a "
            + query_name() + " with a "
            + outil->query_name() + ".\n");
        return 1;
      }
    } else {
        write("You have no "+ util +" to burn the " + query_name()+".\n");
      return 1;
    }
  } else {
    if (!present("lighted_torch",this_player())){
      say("You have nothing to burn it with!\n");
      write(this_player()->query_name() + " have nothing to burn the rug!\n");
      return 1;
    }
  }
  tell_room(environment(this_object()), "The rug quickly catches on fire and burns away.\n");
  environment(this_object())->rug_burn();
  destruct(this_object());
  return 1;
}
