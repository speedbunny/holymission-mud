inherit "/obj/treasure";
    object ob;
reset(arg) {
  if (arg) return ;
    set_id("crowbar");
    set_alias("okbar");
    set_short("A crowbar");
    set_long("An iron crowbar.\n"+
             "maybe you can break something with it.\n");
    set_value(80);
    set_weight(4);
}
init() {
    ::init();
    add_action("break_cage","break");
    add_action("use","use");
    }
   break_cage(str) {
    if (str!="cage") {
       write("You fail and you get the feeling that this crowbar is only\n"+
             "for a special use.\n");
       return 1;
     }
    else {
          return; 
   }
  }
  use(str) {
    if (str=="crowbar") {
    write("How will you use the crowbar, to break something.\n");
    return 1;
  }
 }
query_quest_item() { return 1; }


drop() {
  write("Your crowbar falls on the floor and breaks into tiny pieces.\n");
ob=clone_object("players/whisky/garden/obj/b_crowbar");
  move_object(ob,this_player());
this_player()->command("drop crowbar");
  destruct(this_object());
  return 1;
  }

query_property()
{
  return "no_clean_up";
}
