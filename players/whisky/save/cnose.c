#define PPATH "/players/whisky/"
inherit "obj/armour";

  reset(arg) {
    ::reset(arg);
   
  if (arg) return;
  
  set_name("fnose");
  set_alias("nose");
  set_short("A clown-nose");
set_long("A red clown-nose with two tiny holes on it's side.\n");
  set_weight(1);
  set_type("nose");
  set_ac(0);
  set_value(20);
  }
  
   wear(arg) {
    object ob;
    ob=present("cord",environment());
    if (arg!="nose") return;
    if ((!ob) ||(!ob->query_nose())) {
      write("You try to wear the funny nose but it slips down your face.\n");
      say(this_player()->query_name()+" tries to wear the funny nose, but fails.\n");
     }
    else {
    worn_by=this_player();
    worn=1;
    write("You wear the funny clown-nose.\n");
    say(this_player()->query_name()+" wears the funny clown-nose.\n");
   return 1;
   }
   return 1;
   }
    
  drop() {
    write("Your clown-nose vanishes.\n");
    destruct(this_object());
    return 1;
    }
    
           
  
