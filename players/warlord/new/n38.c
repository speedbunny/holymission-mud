inherit"room/room";
object peng;
reset (arg) {
if (!peng) {
peng=clone_object("obj/monster");
peng->set_name("penguin");
peng->set_short("Penguin");
peng->set_long("You see a cute little penguin waddling around.\n");
peng->set_level(4);
peng->set_whimpy();
move_object(peng,this_object());
}
if (arg) return 1;
set_light(1);
short_desc="West side of pond\n";
long_desc="You see fairly thin ice under you. There is ice\n"+
"to the north, south and east of you. To the west are some snow\n"+
"covered trees.\n";
items=({"ice","The ice looks very thin here",
     });
dest_dir=({
"/players/warlord/new/n37","west",
"/players/warlord/new/n39","east",
"/players/warlord/new/n30","north",
"/players/warlord/new/n46","south",
          });
return 1;
}
