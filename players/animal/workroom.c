#include "std.h"
 
#define MYNAME "Animal"
#define IS_ME (call_other(this_player(), "query_real_name", 0) == "animal")
#define NAME capitalize(call_other(this_player(), "query_real_name", 0))
 
int acc, busy;
 
reset(arg)
{
string name;
	name = find_player("animal");
	if(name) {
	tell_object(name,"Reset was called with "+arg+"\n");
	}
    if (!arg) set_light(1);
}
 
long(str)
{
       write("Animal's private area\n\n");
       write("   This room is a beautiful room. There are paintings of\n");
       write("   many different animals all over the walls. The paintings\n");
       write("   show how much Animal loves animals as they all are of him\n");
       write("   with his numerous pets. The number of pets is astounding.\n");
       write("   Animal's pet black panther is eating dinner.\n\n");
}
 
short()
{
        return "Animal's private area";
}
 
init()
{
string ok;
 
ok = call_other(this_player(), "query_level", 0);
if((busy) && !IS_ME && (ok<10000) && (acc != this_player()))
{
     write(MYNAME + " tells you: I am VERY busy right now. Please wait\n"
     + "till I call you, that means I have will have some time, ok?\n");
     move_object(this_player(),"room/church");
     call_other(this_player(),"look");
     tell_object(find_living("animal"), call_other(this_player(),
     "query_name", 0)
     + " attempted to enter your relaxing area.\n");
     return 1;
}
 
if(IS_ME)
{
    add_action("bring"); add_verb("bring");
    add_action("busy_toggle","bus");
    add_action("imprison");add_verb("imprison");
}
    acc=0;
    if(!IS_ME) say(MYNAME + " has permitted "+ NAME +
    " access to his domain.\n");
    add_action("north_room"); add_verb("north");
    add_action("south_room"); add_verb("south");
}
 
north_room()
{
         call_other(this_player(), "move_player",
         "north#players/animal/workroom");
         return 1;
}
 
south_room()
{
         call_other(this_player(), "move_player","south#room/post");
         return 1;
}
 
accept(who)
{
    acc = who;
    move_object(who, this_object());
    call_other(who, "look");
}
 
static bring(str)
{
int who;
 
   if(!str||str=="")
{
   write("Bring whom ?\n");
   return 1;
}
 
   who=find_player(str);
   if (!who)
{
    write("Not found.\n");
    return 1;
}
       acc=who;
       tell_object(who, MYNAME + " has permitted you access to his private "
        + "area.\n");
        tell_object(who,"You are now in Animal's presence look.\n");
        move_object(who, this_object());
        return 1;
}
 
imprison(str)
{
 int who;
 if(!str || str=="")
{
    write("Imprison whom?\n");
    return 1;
}
    who = find_player(str);
 if(!who)
{
    write("Living not found.\n");
    return 1;
}
    acc = who;
    move_object(who, "room/prison");
    write(str + " has been imprisoned.\n");
    return 1;
}
 
id(str)
{
    return str ==  "private area";
}
 
busy_toggle(str) {
                 if(str == "on") {
                 busy = 1;
                 write("You are now busy.\n");
                 return 1;
                 }
                 if(str == "off") {
                 busy = 0;
                 write("You are no longer busy.\n");
                 return 1;
                 }
                 write("ON or OFF MAN!\n");
                 return 1;
}
