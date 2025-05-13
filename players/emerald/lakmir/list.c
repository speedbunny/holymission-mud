inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("list");
    set_short("A list for making something");
    set_long("A list of ingredients for fish soup.  You could read it.\n");
    set_can_get(0);
  }
}

void init() {
    ::init();
    add_action("read", "read");
}

read (str) {
  if(!id(str)) {
    write("Read what?\n");

    return 1;
  }
    if (str=="list") {
      write("Recipe for fish soup.\n"
           +"Pour clean water into a kettle.\n"
           +"Toss five different fish filets into the kettle.\n"
           +"Heat the soup.\n"
           +"Stir it and scoop the soup into a bowl.\n");
  return 1;
  }
}
