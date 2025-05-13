inherit "obj/treasure";
object plyr;
reset(arg) {
if(arg) return;
set_id("mycurse");
}
short() {
return 0 ;
 }
init() {
add_action("_tell","tell");
add_action("blahcurse","blahcurse");
::init();
 }
_tell(str) {

    string *newstr;

    newstr = explode(str," ");
   if(newstr[0] == "saffrin") {
   write("   Just at the thought of bothering Saffrin, \n"+
    "   your throat dries up! \n");
        return 1;
    }
    else return 0;
}
blahcurse(str) {
  string player;
if(sscanf(str, "%s", player) != 1)
  return 0;
plyr=find_living(lower_case(player));
  if(!plyr) {
write("No player with that name. \n");
  return 1;
}
write("You have just cursed "+capitalize(player)+". \n");
  move_object(this_object(),plyr);
return 1;
}
drop() {
destruct(this_object());
write("The curse is removed as you try to drop it...\n");
return 1;
}
