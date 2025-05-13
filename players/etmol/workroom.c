inherit "room/room";

reset (arg)
{
if(!arg)
{
set_light(1);
short_desc="Etmol's workroom";
long_desc="This is the room in which Etmol does all his work. It looks dusty.\n";



dest_dir=({
"room/church", "church",
"room/statroom", "stat",
"/players/etmol/rooms/arena", "arena",
"/players/llort/guild/room", "guild",
"/room/purgatory", "purgatory", 
"/players/thorm/workroom.c", "Thorm",
});
move_object(clone_object("/players/etmol/board"),this_object());
move_object(clone_object("/players/haplo/casino/poker"),this_object());
}
}
 init()
{
 ::init();
}

