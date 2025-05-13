inherit"room/room";

#define GM "guild/master"
#define this_guild GM->query_number("jedi") 

reset(arg) {
  if(arg) return;
  short_desc="Jedi innerguild's";
  long_desc="You are in the storage room of the Jedi guild.\n" +
	 "Only members of the guild can come here.\n"+
         "If you go down the stairs, you can enter the cape-room.\n"+
         "Here the property of the guild is stored in chests.\n";
  set_light(2);
  no_castle_flag=1;
  dest_dir=({
     "players/kelly/guild/caperoom","down",
  });
  
  items=({
     "chest","There is a label on it that says: Property of the guild",
     "chests","In this chest the property of the guild is stored",
  });

  if(find_call_out("clean_up")==-1)
    clean_up();
  if(!present("dispenser"))
    move_object(clone_object("players/kelly/obj/dispenser"),this_object());
}

init() {
  ::init();
  if(this_player()->query_guild()!=this_guild) {
    write("You are not allowed here.\n");
    this_player()->move_player("this holy place#players/kelly/guild/room");
  }
}

clean_up() {
object *ob;
int i;

  tell_room(this_object(),"The room is being cleaned.\n");
  ob=all_inventory(this_object());
  for (i=0;i<sizeof(ob);i++)
    if (!(living(ob[i]) && !ob[i]->query_npc()) && !ob[i]->id("dispenser")) 
      destruct(ob[i]);

  call_out("clean_up",1800);
}
