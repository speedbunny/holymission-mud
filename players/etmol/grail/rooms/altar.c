#define TP this_player()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "Altar"; 
long_desc = "This is a very small room.\nThere is only a dusty altar here"+
            "with a golden cross above it.\n",

items = ({
          "altar", "A golden altar with a shining cross above it.",
          "cross", "A bright cross."
});
}
init()
{
add_action("touch", "touch");
::init();
}
touch(arg)
{ 
if (!arg || arg!="cross")
{
write("Touch what?");
}
else
{
write("Ok.\n");
write("You touch the cross. You black out for a second, and when you\n");
write("can see again, you find yourself in a familiar place.\n");
TP->move_player("somewhere.#/room/church");
}
return 1;
}