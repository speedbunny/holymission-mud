/* Coded by Blade on Holy Mission */
/* simple shadow cloner           */

object sh;

short() {return "sts";}
id(str) {return str=="sh";}

get() { return 1; }

init() {
     add_action("start","start");
}

start() {
    sh=clone_object("/players/blade/test/shad");
    sh->start_shadow(this_player());
    return 1;
}

