inherit "room/room";
object max;
 
reset(arg) 
{
    if(!arg)
    {
      set_light(1);
      short_desc = "Library";
      no_castle_flag = 0;
      long_desc = 
        short_desc+".\n"+
        "This is a the library, where people can come and get books just\n"+
        "by pulling them off the shelf.  Perhaps there is something\n"+
        "interesting to read.\n";
 
      items =
        ({
         "book","One of many books you could pull off of the shelf and read",
         "books","There are many books you could pull off of the shelf and read",
         "shelf","This is a shelf with many books on it...it seems as though it might move",
        }); 
 
    }
    if(!present("max"))
    {
      max = clone_object("/players/jewel/test/max");
      move_object(max, this_object());
    }
}        
