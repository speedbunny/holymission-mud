inherit "obj/treasure";

#define FILE "/players/sauron/misc/obj/tools"
string *tools;

int gimme(string str) {
  int i;
  if(file_size(FILE)!=-1)
    tools=explode(read_file(FILE),"\n");
  else 
    tools=({});
  if(!str || str!="tools") {
    return 0;
  }
  else {
    for(i=0;i<sizeof(tools);i++) {
      if(file_size(tools[i]+".c")>0) {
        if(!present(tools[i]->query_name()),this_player()) {
          move_object(clone_object(tools[i]),this_player());
          write("You get a clone of "+tools[i]+".\n");
        }
      }
    }
    write("Junk this.\n");
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_id("tool_giver");
    set_name("giver");
    set_alias("apprentice tool giver");
    set_short("Apprentice tool giver");
    set_long(short()+".\nJust type 'gimme tools' to get lots of nice toys.\n");
    set_value(0);
  }
}

void init() {
  ::init();
  add_action("gimme","gimme");
}
