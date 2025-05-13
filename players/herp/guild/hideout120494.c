/* 920408 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

#define GM	"guild/master"
#define GUILD	"thief"

inherit "room/room";
object board;
string picklock,poison;

init() {
  if (board) {
     move_object(board,"room/church");		/* just move it out */
     move_object(board,this_object());		/* now it's on 1st place */
  }
  add_action("no_quit","quit");			/* Don't do this */
}

reset(arg) {
int i,j,gd;
string dir;
string p_color,p_strength;
object p;

  if (!arg) {
     set_light(1);
     property = "no_teleport";
     short_desc="Thieves hideout";
     long_desc="You are in the thieves hideout.\n" +
	       "If you have spare stuff, leave it here,\n" +
	       "to be used by your fellow thieves.\n";
     gd=GM->query_number(GUILD);
     dir=GM->query_dir(gd);
     picklock=dir+"/picklock";
     poison=dir+"/poison";
     board=clone_object("obj/board");
     board->set_file(dir+"/board");
     board->set_name("thieves");
     board->set_short("the board of the thieves guild");
     move_object(board,this_object());
  }
#if 0
  if (!(present("ticket to herp")))
     for (i=0;i<random(3);i++) 
	 move_object(clone_object("players/herp/obj/ticket"),this_object());
#endif
  if (!(present("picklock")))
     for (i=0;i<random(3)+1;i++)
	move_object(clone_object(picklock),this_object());

  if (!(present("poison")))
     for (i=0;i<random(5)+1;i++) {
	move_object(p=clone_object(poison),this_object());
	p->set_name("poison");
	p->set_alias("potion");
	p->set_alt_name("flask");
	switch(random(5)) {
	case 0:	p_color="blue";  p_strength=1;  break;
	case 1:	p_color="red";   p_strength=5;  break;
	case 2:	p_color="white"; p_strength=10; break;
	case 3:	p_color="black"; p_strength=25; break;
	case 4: p_color="purple"; p_strength=35; break;
	}
	p->set_short("a flask with a "+p_color+" potion in it");
	p->set_long("The flask is full with a "+p_color+" liquid.\n");
	p->set_color(p_color);
	p->set_strength(p_strength);
     }
	

}

no_quit() {

  if (this_player()->query_wizard()) return;	/* wizzies are allowed */
  write("You don't want to leave the game this cowardly way.\n");
  return 1;

} 
  
