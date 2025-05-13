#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;
set_light(1);
short_desc = "Pit."; 
long_desc = "Well... Looks like that wasn't the correct letter to step on.\n"+
            "As you look up and see the ceiling far above you with light\n"+
            "streaming in through the hole you just made, you wonder how\n"+
            "you could survive such a fall. You stand up and set your mind on\n"+
            "how to get of here. You don't see any way out.\n"+
            "Large shadows dance around in the flickering light of a\n"+
            "torch on the wall. You are all alone. It's pretty creepy.\n";
        
items = ({
            "torch", "A torch burning with a bright light.",
            "hole", "It's WAY UP above you.",
            "walls", "They are dark and cold.",
            "wall", "It is dark and cold.",
            "ceiling", "Unless you can fly, there is no way for you to get back up there.",
});
}
init()
{
add_action("pull", "pull");
add_action("pull", "move");
add_action("touch", "touch");
::init();
}
touch(arg)
{
if(!arg || arg!="torch")
{
notify_fail("Touch what?\n");
}
else
{
write("You touch the torch and notice that it is quite loose in its place.\n");
}
return 1;
}
pull(arg) 
{
if(!arg)
{
notify_fail("There seems to be a direct object missing from that sentence.\n");
}
if(arg!="torch")
{ 
notify_fail("Pull what?\n"); 
}
else
{
write("As you pull the torch, the wall suddenly swirls around with you.\n");
say(TPN+ "pulls the torch on the wall and disappears.\n");
TP->move_player("somewhere#/players/etmol/grail/rooms/altar");
}
return 1;
}
