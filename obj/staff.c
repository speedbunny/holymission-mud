inherit "obj/treasure";

reset(arg) {
  if(!arg) {
    set_id("staff");
    set_alias("golden staff");
    set_short("A golden staff");
    set_long("This is the long lost staff of arcanarton.\n");
    set_value(300);
    set_weight(1);
  }
}

init() {
  ::init();
  add_action("attach","attach");
}

attach(arg) {
string a,b;
object gem;

  if(sscanf(arg,"%s to %s",a,b)==2) {
    if(a=="gem" && b=="staff") {
      if(gem=present("gem of arcanarton",this_player())) {
         write("You rebuild the scepter of arcanarton!!!!\n");
         say(this_player()->query_name()+" rebuilt a strange magical item.\n");
         destruct(gem);
         gem=clone_object("obj/treasure");
         gem->set_id("scepter of arcanarton");
         gem->set_alias("scepter");
         gem->set_short("Scepter of arcanarton");
         gem->set_long("A beautiful worked magic scepter.\n");
         gem->set_value(4000);
         gem->set_weight(2);
         move_object(gem,this_player());
         destruct(this_object());
         return 1;
      } else {
         write("You don't have the gem of arcanarton.\n");
         return 1;
      }
    }
  } 
  write("Attach what to what ?\n"); 
  return 1;
}
   
