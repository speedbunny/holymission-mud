#define E environment
#define TP this_player()
#define TPN TP->query_name()
inherit "obj/treasure";
 
reset(arg) {
  if (!arg) {
     set_id("paper");
     set_short("An oily sheet of toilet-paper");
     set_long("A pink pleasant but oily sheet of toilet-paper.\n");
     set_value(1);
  }
}
 init() {
   ::init();
   add_action("clean","clean");
   add_action("clean","polish");
  }
 clean(str) {
    object ob;

    if (!str) { return; }
    ob=present("questkey",TP); 
     if(ob) {
      if (strstr(str,"key",0)!=-1)
      {
        write("You clean the key and polish the rust away.\n");
        say(TPN+" clean the key, and polishes the rust away.\n");
        move_object(clone_object("players/whisky/garden/obj/robe"),TP);
        move_object(clone_object("players/whisky/garden/obj/paper3"),TP);
        destruct(ob);
        destruct(this_object());
        return 1;
       }
       else {
        write("You clean the "+(str)+".\n");
        say(TPN+" cleans the "+(str)+".\n");
        TP->set_alignment("polished");
        move_object(clone_object("players/whisky/garden/obj/paper3"),TP);
        destruct(this_object());
       return 1;
       }
     return 1;
     }
   return 1;
  }
query_quest_item() { return 1; }
        


 
  drop() {
    write("As you try to drop the paper, it keeps sticking on your finger.\n");
  return 1;
  }
