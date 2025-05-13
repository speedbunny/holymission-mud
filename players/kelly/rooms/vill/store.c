

inherit "/room/room";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "The Store";
         long_desc = "Inside Kasimir's Store\n";
         dest_dir =
         ({
             "/players/kelly/rooms/vill/shop","south",
         });
      }
}

int query_property(string arg)
{
    if (arg=="no_clean_up")
        return 1;
    return -1;
}

     
