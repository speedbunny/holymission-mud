inherit "obj/treasure";

int page,gd;
string notes;

reset(arg) {
  if(!arg) {
    set_id("notebook");
    set_alias("bardnotebook");
    set_short("A notebook");
    set_long("The notebook of the Bards, it has 30 pages.\n");
    set_read("This is the notebook of the Bards.\n"
           + "Please return it to Taliesin if you find it.\n"
           + "Possible commands are:\n"
           + "write <line>\n"
           + "read page [<page>]\n"
           + "clear\n");
    set_info("This object will be saved after writing it.");
    set_weight(1);
    set_value(100);
    if(!restore_object("players/cashimor/save/notebook")) {
      page=1;
      notes=allocate(30);
      gd="players/cashimor/guild/room"->query_guild();
    }
  }
}

init() {
  ::init();
  add_action("set_page","setpage");
  add_action("write_line","write");
  add_action("clear_note","clear");
}

read(str) {
string wat;

  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  wat=explode(str," ");
  if(wat[0]!="page") return ::read(str);
  if(!present(this_object(),this_player())) {
    notify_fail("You don't have the notebook!\n");
    return 0;
  }
  notify_fail("Read which page?\n");
  if(sizeof(wat)==2) {
    if(sscanf(wat[1],"%d",page)!=1) return 0;
    if((page<1)||(page>30)) return 0;  
  }
  say(this_player()->query_name()+" reads a note of a notebook.\n");
  if(!notes[page-1]) {
    write("The note is empty.\n");
    return 1;
  }
  if(this_player()->query_guild()!=gd) {
    write("You see that the page is scribbled with bardic runes.\n");
    return 1;
  }
  write(notes[page-1]);
  return 1;
}

write_line(str) {
  if(!str) {
    notify_fail("Write what?\n");
    return 0;
  }
  if(!present(this_object(),this_player())) {
    notify_fail("You don't have the notebook!\n");
    return 0;
  }
  if(this_player()->query_guild()!=gd) {
    write("You seem unable to do that.\n");
    return 1;
  }
  say(this_player()->query_name()+" writes something in a notebook.\n");
  write("Ok.\n");
  if(!notes[page-1]) {
    notes[page-1]=str+"\n";
    save_object("players/cashimor/save/notebook");
    return 1;
  }
  notes[page-1]=notes[page-1]+str+"\n";
  save_object("players/cashimor/save/notebook");
  return 1;
}

clear_note() {
  if(!present(this_object(),this_player())) {
    notify_fail("You don't have the notebook!\n");
    return 0;
  }
  if(this_player()->query_guild()!=gd) {
    write("You're too unworthy for that!\n");
    return 1;
  }
  notes[page-1]=0;
  return 1;
}
