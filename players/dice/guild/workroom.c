inherit "room/room";

int tick;
static string text;
reset(arg) {
  if(arg) return;
 property="no_fight";
  set_light(1);
  short_desc="Dice's workroom";
long_desc="  _       _   \n"+
          " (o)     (o)  \n"+
       "\n\n\n";
  dest_dir=({"room/church","chu",
	"room/adv_guild", "advg",
	"room/wiz_hall.c", "wizh",
	"players/dice/rooms/study","study",
        "players/acdc/office/wiz_office","wo",
        "players/acdc/office/player_office","po",
	"room/post", "post", });
}

init(){::init();
say(capitalize(this_player()->query_real_name())+" has entered Dice's workroom.\n");
}
