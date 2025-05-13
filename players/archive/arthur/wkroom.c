

inherit "room/room";
    object mon0,me;

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "Hehehe, Tis Arth's Workroom";
    no_castle_flag = 0;
    long_desc = 
   "	There are many toys and gagets laying around, but you probably shouldn't\n"
   + "touch anything. Knowing Arthur, you may get hurt, or even killed by playing\n"
   + "with them. A general rule is to be careful when playing with any toy's laying\n"
   + "in this workroom.\n"
   + "\n";
    dest_dir = ({
        "/room/church", "church",
        });
    items = ({
     "toy",
     "Hum there's a whole gob of them laying around\n"
     + "",
     });
   }
   if (!mon0 || !living(mon0)) {
    mon0=clone_object("/players/arthur/area/items/sword");
    transfer(mon0,this_object());
   }
}

  exit() {
     if(!find_living("arthur"))
      return 1;
    me=find_living("arthur");
    tell_object(me,this_player()->query_real_name()+" leaves your workroom.\n");
    return 1;
   }
