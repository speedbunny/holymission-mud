inherit "room/room";

reset (arg)
{
if(!arg)
{
set_light(1);
short_desc="The arena";
long_desc="This is a huge room with no exits. NO WIMPY HERE. Fight or die.\n";
dest_dir=({


});


}
}
 init()
{
 ::init();
}
int goto(string str)
{
if(!str) return 0;
this_player()->move_player("goes to the workroom#/ players/etmol/workroom");
return 1;
}

