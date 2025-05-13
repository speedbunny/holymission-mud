inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In the woods";
long_desc=("\
\n\
  You have enter the wizard's domain.  This portion of the woods is owned by\n\
  the evil Zalpur Wizard.  He greatly detests intruders.  You see many body\n\
  parts of humans who came near him. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val7","south"});
clone_list = ({ 1, 1, "wizard", "players/iishima/area/monsters/zalwiz", 0,
               -1, 1, "sword", "players/iishima/area/weapons/zalsword.c", 0 });


::reset(arg);
replace_program("room/room");
}

