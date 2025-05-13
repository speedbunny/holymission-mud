inherit "room/room";
int closed;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Vapourspace";
    no_castle_flag = 0;
    long_desc = 
        "Greenish clouds propel lightning bolts through the dark blue sky into the\n"
        + "thick cloud cover below. Thunder can be heard all around you in the darkness\n"
        + "which is only intermittenly interrupted by the flashes of lightning. This\n"
        + "is Vapourspace, a place which encourages thought and speculation about all\n"
        + "of life's events and mysteries. Silas comes here when he needs to think\n"
        + "about either the game or other matters, and the powerful field of energy\n"
        + "which surrounds this place ensures that he can do so undisturbed.\n"
        + "\n";
    dest_dir = 
        ({
        });
}

query_light() {
    return 1;
}
int VALID()
{
    if (this_player()->query_real_name()!="silas") 
       return 0;
    return 1;
}
void move_out(object tp)
{
   tp->move_player("out of Vapourspace#room/church");
}

init()
{
  ::init();
  if (this_player()->query_real_name() != "silas" && closed == 1)
      call_out("move_out",1,this_player());
  if (this_player()->query_real_name() == "silas")
  {  
     add_action("do_open","open");
     add_action("do_close","close");
  }
}

int do_open()
{
    if (!VALID()) return 0;
    closed = 0;
    write("You dispel the force field.\n");
    say(this_player()->query_name() + " dispels a force field with the wave of a hand.\n");
  return 1;
}

int do_close()
{
    if (!VALID()) return 0;
    closed = 1;
    write("You activate the force field.\n");
    say(this_player()->query_name() + " activates a force field with the wave of a hand.\n");
   return 1;
}

