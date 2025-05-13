/* 190893 Galadriel: fixed error when target not logged in */
#define TPRN this_player()->query_short_name()
#define ob find_player(lower_case(to))
#define thrower find_player(lower_case(from))
id(str) { return str=="boomerang"; }
get() { return 1; }
drop() { return 0; }
short() { return "A boomerang"; }
long() {write("You can throw it to someone. Type 'throw"+
             " boomerang to <player>'.\n");}
string from,to;

query_value() { return 10; }


init() {
   add_action("throw","throw");
    }

throw(arg) {
	string dummy;
        sscanf(arg,"boomerang to %s",dummy);
        if(!dummy) return 0;
	to=capitalize(dummy);
	from=TPRN;
	if(to==from)	{
		write("You think about throwing it to yourself.\n"
		+"You decide it would be better to threw it to"
		+" someone else.\n");
		return 1;
		}
/* 190893 Galadriel: Check this _before_ the query_level! */
	if(!ob) {
		write("That player isn`t logged on.\n");
		return 1;
		}
	if(ob->query_level()>30) {
		write(to+" wouldn`t want to play. Wizards have better"
		+ " things to do.\n");
		return 1;
			}
	if (!present("boomerang",thrower)) {
		write("You have to be carrying it.\n");
		return 1;
			}
        tell_object(ob,"You see a boomerang spinning through the sky.\n"
        +"It has been thrown towards you by "+from+".\n");
	write("You throw the boomerang towards "+to+".\n");
        move_object(this_object(),"/players/portil/rooms/boomroom/boomroom");
        call_out("arc",6);
        return 1;
      }

arc() { 
	if(ob) {
        tell_object(ob,"The boomerang seems to bend round in its path.\n");
	}
	if(thrower) {
	write("The boomerang seems to bend round in its path.\n");
	}
        call_out("grab",6);
      }

grab() {
	if(!thrower && ob) {
		tell_object(ob,"The boomerang seems to fall to the floor"+
		" some distance away.\n");
		}
	if(ob && thrower) {
        tell_object(ob,"In the distance you notice the boomerang being "+
		"skillfully caught by "+from+".\n");
		}
	if(!thrower) {
		destruct(this_object());
	} else {
		write("You jump into the air and catch the boomerang.\n");
		move_object(this_object(),thrower);
		}
	return;
      }
