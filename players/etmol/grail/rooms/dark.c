#define TP this_player()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "Dark room"; 
long_desc = "It's pitch dark.\n";
            

items = ({
});
}
init()
{
add_action("search", "search");
add_action("open", "open");
::init();
}
search(arg)
{ 
if (!arg || arg!="room")
{
write("You search.\n");
}
else
{
write("You find a door.\n");
}
return 1;
}
open(arg)
{
if (!arg || arg!="door")
{
write("Open what?\n");
}
else
{
write("You open the door.\n");
TP->move_player("through a door#/players/etmol/grail/rooms/letter1");
}
return 1;
}