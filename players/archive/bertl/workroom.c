/* Bertls Workroom HM 24.11.94 */

inherit "room/room";

object board;



drinking(str)
{
  if(!str)
  {
    write("Drink what?");
    return 0;
  }
  if(str=="beer")
  {
      say(this_player()->query_name() + " fetches a bottle from the fridge and gupls down a beer.\n");
      tell_object(this_player(),"You burp happily.\n");
      command("burp",this_player());
      if(this_player()->query_immortal())
      {
        this_player()->heal_self(5);
      }
      this_player()->drink_alcohol(2);

      return 1;
  }
}

geting(str)
{
  if(!str)
  {
    write("What you wanna get?\n");
     return 1;
  }

   if(this_player()->query_real_name()=="bertl")
  {
    if(str=="rose")
    {
      move_object(clone_object("/players/bertl/obj/rose.c"),this_player());
      tell_object(this_player(),"You get a rose from the bush.\n");
      say(this_player()->query_name() + " gets a rose from the bush.\n");
      return 1;
    }

  }

}

display_clock()
{
  if("obj/tick"->qry_timer_value()<0)
     return 1;
    return "The clock shows midnight, and appears to have stopped";
  
  return "It is labeled in gothic lettering, from I to XII.\n"
       + "It currently shows the time to be "
       + ctime(82800-"obj/tick"->qry_timer_value())[11..15]
       + ".\nBelow it is inscribed: The world endeth at midnight";
}

reset(arg)
{  
   if(!arg)
   {
      set_light(1);
      property=({ "has_fire" });
      
      short_desc="A small chaotic room.";
      long_desc= "You have entered a chaotic looking room, Bertl's workroom.\n" +
                 "You see books and scrolls scattered all over table and floor.\n" +
                 "In front of the table is a comfortable chair.\n" +
                 "In one corner is a refrigerator filled up with beer. On one wall\n" +
                 "hangs a clock to remind you on the instability of the world.\n" +
                 "The other walls are covered with shelves filled up with books.\n" +
                 "Many exits are flying around leading in different directions.\n" +
                  "A bush with roses grows up between some of the stones in the floor\n\n";

      items=({
              "refrigerator","Its filled up with beer, maybee you shoud drink one",
              "table","Filled with many papers and maps of rooms",
              "roses","Home-grown red roses, they look very beatiful",
              "rose","Ask the owner for one, only he can get one",
              "floor","You can hardly see the floor through all the books and scrolls",
              "room","Isnt it that, what you call a chaos",
              "chair","Oh well, looks too comfortable, better not try it out",
              "book","There are books about many themes, mainly about programming",
              "shelves","There are many books standing on them",
              "beer","Maybee you shoud try to drink one",
              "clock","@@display_clock@@"
            });

      dest_dir=({
                 "/players/bertl/pit.c", "pit",
                 "/obj/tick", "tick",
                 "/room/jetty", "flowers",
                 "/room/purgatory","friedhof",
                 "/room/church.c", "church",
                 "/players/whisky/magic/mages_bar.c", "magebar",
                 "/players/matt/newworld/city/rooms/votebooth.c", "vote"
               });

      smell = "A smell the fine aroma of a good tabacco.";

      board = clone_object("/obj/board");
     board->set_name("Bertl's brain-helping");
      board->set_file("/players/bertl/inhalt_board");
      move_object(board,this_object());
   }
}

init()
{
 ::init();
   add_action("drinking","drink");
   add_action("geting","get");
}

