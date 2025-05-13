inherit "/obj/thing";

int is_open;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("newspaper");
    set_alt_name("paper");
    set_short("A newspaper");
    set_long("It's an newspaper from today.\n");
    set_weight(1);
  } else {
    if (!environment(environment(this_object()))) 
      destruct(this_object());
  }
  is_open = 0;
}

init() {
    ::init();
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
}

read (str) {
  if (!str || !id(str)) return 0;
  if (is_open)
    write("\n"
      +"       C O O K   W A N T E D !\n"
      +"       =======================\n\n"
      +"Because Druid Lakmir's cook died in performance of her\n"
      +"function Druid Lakmir's manager searches a new cook.\n"
      +"If you are intersted to do this job, go to the manager\n"
      +"and speak about the job with him.\n");
  else 
    write ("Newspaper.\n"
          +"To read the contents you must first open it.\n");
  return 1;
}

open (str) {
  if (!str || !id(str)) return 0;
  if (is_open) write("The " + name + " is already open.\n");
  else {
    write("The " + name + " is now open.\n");
    say(this_player()->query_name() + "opens a " + name + "\n");
    is_open = 1;
  }
  return 1;
}

close (str) {
  if (!str || !id(str)) return 0;
  if (!is_open) write("The " + name + " is already closed.\n");
  else {
    write("The " + name + " is now closed.\n");
    say(this_player()->query_name() + "closes a " + name + "\n");
    is_open = 0;
  }
  return 1;
}
