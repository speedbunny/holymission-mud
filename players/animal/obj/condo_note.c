/* Changed by Ethereal Cashimor: bed removed */
inherit "obj/treasure";
 
get()
{
  write("It firmly attached to the front desk.\n");
  return 0;
}
 
reset(arg)
{
  string text;
  
  text = "\n To rent a Cabin:   rent <amount>\n" +
 " For Example:       rent 35\n\n" +
 "Miscellaneous Commands\n\n" +
 " To see info about rooms that are currently rented:  renters\n\n" +
 " To bring other players into your room: bring <player>\n" +
 " This tells the player he/she/it is welcome in your cabin.\n" +
 " If you change your mind about letting them in:  bring\n" +
 "\n" +
 " If time runs out and there is stuff in your cabin, it will thrown\n"+
 " into Animal's store, thats where you can retrieve your stuff. You\n"+
 " will be thrown out of the cabin also.  If the game crashes you will\n"+
 " be given the value in money for your lost goods at your next login.\n"+
        " NOTE: You do NOT need the key to get back in yer room.\n";
  set_id("note");
  set_alias("paper");
  set_short("A note attached to the front desk");
  set_long("There is some text written on it:\n"+text);
  set_read(text);
}
 
 

