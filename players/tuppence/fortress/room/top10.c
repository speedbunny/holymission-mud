inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc= "Evil dark lords chambers";
        long_desc= "You have foolishly entered the Evil Dark Lord's chambers. There\n"+
	"are no windows in this room, it is stuffy and dusty.\n"+
	"A big stone table stands in the middle of the room with different\n"+
	"spell books and potions on it. Swords are hung up on the north\n"+
	"wall with different types of shields and staffs. A large four poster\n"+
	"bed stands by the east wall with a blood red drape hanging over it.\n"+
	"A large chest with a black aura around it sits next to the bed.\n";
	items=
	({
	  "table","Different potions, herbs, spell books, and wands are on this table",
	  "potions","Black and silver potions are on the stone table, they look evil",
	  "herbs","Different types of herbs lay on the stone table, they look deadly",
	  "books","Spell books lay on the big stone table, you can not understand the\n"+
	  "ancient writing in them",
	  "wands","Large and small wands lay on the stone table",
	  "swords","Short and long swords hang on the wall from great battles",
	  "shields","They look old and worn out",
	  "staffs","Magical staffs are hung neatly on the wall, for future use",
	  "bed","A big bed done up in all red sheets and pillows",
	  "drape","A large red drape hangs over the four poster bed",
	  "chest","It is large and has some kind of spell on it so no one but the evil\n"+
	  "dark lord can open it",
	});
clone_list = ({
1, 1, "lord", "players/tuppence/fortress/monster/lord", 0,
-1, 1, "amulet", "players/tuppence/fortress/armour/amulet", 0,
-1, 1, "cloak", "players/tuppence/fortress/armour/lcloak", 0,
-1, 1, "helmet", "players/tuppence/fortress/armour/lhelmet", 0,
});
	dest_dir=
	({
	  FROOM+"top9","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
