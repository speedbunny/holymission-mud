/* SUNALLEY2.C */
/* 090793: Ethereal Cashimor: Search removed, function search not found */

inherit "room/room";
 
#define GUILD	 	"thief"			/* alles klar ? */
#define GM		"guild/master"
 
#define TP		this_player()
#define TPL		this_player()->query_level()
#define TPQN		this_player()->query_name()
#define TPMGD()		move_object(TP,gr)
#define TPIN()		say(TPQN+" "+TP->query_msgin()+".\n");
#define SAY(x)		tell_room(this_object(),x)
 
string gr;
int    gd;

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Sun alley";
        long_desc=
            "Sun alley runs east from here.\n" +
            "A manhole leads to the sewers.\n";
        dest_dir=({
            "players/moonchild/trollslayer/pathb","north",
	    "room/sunalley1","east",
            "/players/avatar/room/room1","west",
                 });
        items=({
            "manhole","Surprisingly it's not as dirty as you expected.\n"+
                      "You hear low voices coming from below",
              });
        smell="It smells like a real alley.";
    }
    gd=GM->query_number(GUILD);
    gr=GM->query_room(gd);
}

init() {
    ::init();
    add_action("down","down");
    add_action("open","open");
    add_action("close","close");
    add_action("knock","knock");
}
 
down() {
  if (TP->query_guild()==gd) {
      TP->move_player("somewhere#"+gr);
      return 1;
  }
  write("The manhole is locked from inside the sewer.\n");
  return 1;
}
 
open(str) {
  if (str=="manhole") {
     write("You can't manage to unlock the manhole lid.\n");
     say(TPQN+" gets red in the face.\n"+TPQN+" says: Damn @#$%\n");
     return 1;
  }
}
 
close(str) {
  if (str=="manhole") {
     write("Close a closed manhole ?\n");
     say(TPQN+" lays down on the ground to examine the manhole.\n");
     return 1;
  }
}
 
knock(str) {
 
  if (str!="manhole" && str!="at manhole") return; 

  tell_room(gr,"Up at the street, "+TPQN+" knocks at the manhole.\n"); 
  write("You knock at the manhole.\n");
/*
  return 1; 
*/

  if (TP->query_guild()==gd) {
     say(TPQN+" makes some gestures behind your back.\n");
     write("Welcome, brother, to the underworld.\n");
     TPMGD();	
     TPIN();	
     return 1;
  }
  if (TP->query_guild()==0 || TP->query_level()<=10) {
     say(TPQN+" trains "+TP->query_possessive()+" muscles at the manhole.\n");
     if (random(10)<=6) {
         write("Suddenly a tall thief stand before you.\n");
	 write("He eyes you suspiciously and whispers: Well ... follow me !\n");
	 say(TPQN+" leaves suddenly.\n");
	 TPMGD();
	 write("You arrive at a dimly lit place.\n");
	 TPIN();
	 return 1;
     }
     write("Knock knock ... nothing happens.\n");	
     return 1;
  }
 
  /* other guilds are not allowed ! */
  say(TPQN+" tries to break through the manhole with "+TP->query_possessive()+" head ...\n");
  write("Stop it, you only will hurt yourself.\n");
  return 1;
}









