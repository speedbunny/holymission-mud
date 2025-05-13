inherit "room/room";
int closed;

reset (arg) {
    if (arg) return;
    set_light(1);
short_desc = "Calvyn's Lowly Workroom.";
    no_castle_flag = 0;
    long_desc = 
        "You have just entered Calvyn's workroom. It seems to be a warm\n"
"and cozy place to work on endless projects. There is a fire burning\n"
"across the room in a open-face stone fireplace. In front of the fire place\n"
"there is a large Lay-Z-Boy chair, big enough for two, where Calvyn can be\n"
"found most of the tyme. The south side of this room is nothing but a large\n"
"stained window, which you can see the entire landscape of Holy Mission.\n"
"On the other side of the room Calvyn's desk and computer can be found,\n" 
"cluttered with print-outs, cans, manuals, and junk. People sometimes wonder\n" 
"how he gets anything done over there.\n";
  items = ({
       "desk","A large mahogany desk cluttered with junk",
       "fire","A big inviting fire warms your soul",
       "fireplace","A large stone fireplace, big enough to throw someone in",
       "chair","A hugh Lay-Z-Boy chair, but you dare not sit in it.",
       "window","A large multi-colored stained window.",
       "landscape","You see the sites of Holy Mission. (Hey, is that Soozie down there?)",
       "computer","YES it's a Packard Bell (I know, I know, I know)",
       "print-outs","1001 reasons not to buy a Packard Bell",
       "cans","Drink Pepsi - Get Stuff",
       "can","Drink Pepsi - Get Stuff",
       "manuals","Trouble Shooting Packard Bells",
       "manual","Trouble Shooting Packard Bells",
"junk","I said JUNK! Are you deaf?",
       "floor","There is none! ACK! Your Falling!",
	});
    dest_dir = 
        ({
	"/room/church", "church",
	"/room/post", "post",
        "/room/adv_guild", "guild",
        "/players/silas/workroom", "silas",
        "/players/soozie/workroom", "soozie",
        "/players/baer/workroom", "baer",
        "/players/saffrin/guild/rooms/oldstart", "mguild",
        "/room/post", "post",
        });
    smell = "The smell of burning cedar envelopes you and makes you feel at home.\n";
    ::reset();
}
int VALID()
{
    if (this_player()->query_real_name()!="calvyn") 
       return 0;
    return 1;
}
void move_out(object tp)
{
   tp->move_player("out of Calvyn' workroom#room/church");
}

init()
{
  ::init();
  if (this_player()->query_real_name() != "calvyn" && closed == 1)
      call_out("move_out",1,this_player());
  if (this_player()->query_real_name() == "calvyn")
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
    say(this_player()->query_name() + " flicks his wrist and all is well.\n");
  return 1;
}

int do_close()
{
    if (!VALID()) return 0;
    closed = 1;
    write("You activate the force field.\n");
    say(this_player()->query_name() + " activates a force field with a flick of his wrist.\n");
   return 1;
}

