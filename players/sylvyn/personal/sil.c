inherit "room/room";
int closed;

reset (arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Silas' Workroom";
    long_desc = 
        "You have entered a large cavern. Dripping water can be heard around you and\n"
        + "occasional tremors make themselves felt from the ground below. A small wooden\n"
        + "table stands in the middle of the cavern with a fitting wooden chair pulled up\n"
        + "to it. Large bookcases line the walls and a large winerack is situated in\n"
        + "one of the corners. Above the fireplace hangs a painting of immense size\n"
        + "with the flickering light of the fire giving it an eerie appearance. Here\n"
        + "Silas can be found brooding over new projects or simply playing the host to\n"
        + "guests who occasionally frequent this gloomy place.\n";

  items = ({
       "table","It's cluttered with all kinds of stuff, but a framed picture stands out",
       "stuff","Writing utensils, paper, etc",
       "picture","It depicts a panoramic view of Vienna",
       "chair","Built by IKEA, Model Sven",
       "bookcases","These huge wooden structures are filled with books",
       "books","Most of them delve into the occult and metaphysical subjects",
       "fireplace","A crackling fire is burning within it",
       "fire","You think you can see various images appearing within",
       "images","Various views of the sunken city of Rl'yeh appear in the fire",
       "winerack","It's filled with all kinds of wine",
       "wine","Mostly Austrian, German and Hungarian vintages",
       "painting","It's a painted image of the cover of Joy Division's 'Closer' album"
         });
    dest_dir = 
        ({
        "/room/church", "church",
        "/room/adv_guild", "guild",
        "/players/silas/caves/tunnel1", "castle",
        });
    smell = "The smell of burning incense wafts through the room.\n";
    ::reset();
}
int VALID()
{
    if (this_player()->query_real_name()!="silas") 
       return 0;
    return 1;
}
void move_out(object tp)
{
   tp->move_player("out of Silas' workroom#room/church");
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

