inherit "/obj/thing";

status is_open;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("cooking book");
    set_alias("book");
    set_alt_name("cook book");
    set_short("An old cooking book");
    set_long("It's an ancient tome. It seems that no one has disturbed its pages for\n"
            +"centuries. The illegible writing on the cover is in an druid hand.\n");
    set_weight(2);
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
    if (this_player()->query_wis() > 10)     
      write("Recipe for a fishsoup.\n"
           +"Pour clean water into a kettle.\n"
           +"Throw five different fillets into the kettle.\n"
           +"Stir it and scoop the soup into a bottle.\n");
    else write ("You are not wise enough to read druidisch!\n");
  else 
    write ("Cookbook.\n"
          +"To read the contents you must first open it.\n");
  return 1;
}

open (str) {
  if (!str || !id(str)) return 0;
  if (is_open) write("The book is already open.\n");
  else {
    write("The book is now open.\n");
    say(this_player()->query_name() + "opens a " + name + "\n");
    is_open = 1;
  }
  return 1;
}

close (str) {
  if (!str || !id(str)) return 0;
  if (!is_open) write("The book is already closed.\n");
  else {
    write("The book is now closed.\n");
    say(this_player()->query_name() + "close a " + name + "\n");
    is_open = 0;
  }
  return 1;
}
