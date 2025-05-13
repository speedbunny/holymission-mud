inherit"room/room";

#define GM "guild/master"
#define this_guild GM->query_number("jedi")

reset(arg) {
  if(arg) return;
  short_desc="Jedi innerguild's";
  long_desc="You are in special room of the Jedi guild Only members of the \n"+
            "guild can come here. To the west lies the guild sanctuarium.\n"+
            "Upstairs is another room of the guild. You may also 'exchange'\n"+
            "a weapon here for a new lightsber of equal strength.\n";

  set_light(2);
  no_castle_flag=1;
  dest_dir=({
     "players/kelly/guild/inner","west",
     "players/kelly/guild/storage","up",
  });
  if(!present("ben"))
    move_object(clone_object("players/kelly/guild/ben"),this_object());
}

init() {
  ::init();
  if(this_player()->query_guild()!=this_guild) {
    write("You are not allowed here.\n");
    this_player()->move_player("this holy place#players/kelly/guild/room");
  }
  add_action ("exchange_weapon","exchange");
}


int exchange_weapon (string str) {
object ob;
object new;
int class;

  if (!str) {
    write ("exchange <weapons>\n");
    return 1;
  }  
  ob = present(str,this_player());
  if (!ob) {
    write ("You do not have that weapon to exchange.\n");
    return 1;
  }
  class = ob->weapon_class();
  destruct(ob);
  ob = present("handle",this_player());

  if (ob)
    destruct(ob);

  write ("You exchange "+str+" for a new lightsaber.\n");
  ob = clone_object("/players/kelly/guild/lightsaber");
  ob->set_class(class);
  ob->set_weight(1);
  move_object(ob,this_player());
  return 1;
}


