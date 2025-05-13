/* Bertl HM 6.5.96 */
inherit "obj/treasure";
 
 object plyr;

reset (arg) {
if (arg) return;
   set_id("Pillow");
   set_short("A soft pillow");
   set_alias("pillow");
   set_long("You see an soft pillow. You can either put your head on, or you \n"+
            "could try to throw it at someone.\n");
   set_value(10);
   set_weight(1);
}
init() {
   add_action("throw", "throw");
   ::init();
   }

throw(str) {
 string player;

  if (!str) 
    return 0;


   if(sscanf(str, "pillow at %s",player) != 1)
      return 0;

  plyr = find_living(lower_case(player));
    
    if (!plyr || 
        plyr->query_real_name() != "bertl" &&
        plyr->query_real_name() != "cassie" )
    {
        write("No one here with that name!\n");
        return 1;}

  tell_object(plyr,"You are hit on the head with a soft pillow.\n"+
  "You hear "+capitalize(this_player()->query_real_name())+" giggle.\n");
  write("You hit "+capitalize(player)+" on the head.\n");
   transfer(this_object(), plyr);

  return 1;
}
