inherit "obj/treasure";

void reset(int arg) {
  if(arg) return;
  set_id("blue scroll");
  set_alias("scroll");
  set_short("A blue scroll");
  set_long("This blue scroll has something written on it.\n");
  set_value(2500);
  set_weight(1);
  set_read("It reads: change title <name> to change your title to <name>.\n"
	+ "Include your name somewhere in the title or it won't succeed.\n");
}

void init() {
  ::init();
  if((int)this_player()->query_level()<30)
    add_action("_change","change");
}

status _change(string str) {
  string pret, tit;
  object titobj;
  int len;
  if(!str || !sscanf(str, "title %s"
	+ capitalize((string)this_player()->query_real_name())
	+ "%s", pret, tit)) {
    notify_fail("Cast what?\n");
    return 0;
  }
  if(strstr(str, "^!")!=-1) {
    write("Ha. Yes, very clever. No way dude. And you lose your scroll.\n");
    shout((string)this_player()->query_name()
	+ " just tried to fake some autoloaders, but failed.\n");
    destruct(this_object());
  }
  pret=pret=="" ? "none" : extract(pret, 0, strlen(pret)-2);
  tit=tit=="" ? "none" : extract(tit, 1);
  log_file("moonchild.tit", ctime(time()) + ": " + (pret=="none" ? "" : pret)
	 + " " + capitalize((string)this_player()->query_real_name())
	+ " " + (tit=="none" ? "" : tit) + "\n");
  this_player()->set_pretitle(pret);
  this_player()->set_title(tit);
  while(titobj=present("Title", this_player()))
    destruct(titobj);
  titobj=clone_object("players/moonchild/gnome/shop/title");
  move_object(titobj, this_player());
  titobj->initialize();
  write("The scroll glows brightly as the spell takes effect.\n");
  write("Then the scroll disintegrates into nothing.\n");
  destruct(this_object());
  return 1;
}
