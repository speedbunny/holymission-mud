inherit "obj/thing";
string name, file;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("feather");
  set_short("A pointed feather");
  set_long("This is Uglymouth's correctional feather.\n"
    + "It is filled with red ink.\n");
}

void init() {
  ::init();
  add_action("set_wiz_name","name");
  add_action("do_write","write");
}

int set_wiz_name(string str) {
  if(this_player()->query_real_name() != "uglymouth")
    destruct(this_object());

  if(!str) {
    if(!file) {
      write("You haven't opened a journal yet.\n");
      return 1;
    }
    write("You are currently writing in a journal about "+name+".\n");
    return 1;
  }
  name = lower_case(str);
  file = "/players/uglymouth/bugs/"+name+".log";
  write("You open a journal about "+name+".\n");
  return 1;
}

int do_write(string str) {
  if(this_player()->query_real_name() != "uglymouth")
    destruct(this_object());

  if(!str) return 0;
  if(!file) {
    write("You haven't opened a journal yet.\n");
    return 1;
  }
  write_file(file, str + "\n");
  write("Done.\n");
  return 1;
}
